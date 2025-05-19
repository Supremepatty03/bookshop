#include <QApplication>
#include "db_inserter.h"
#include "db_queries.h"


std::optional<int> UserRepository::getUserId(const QString &username) {
    db_queries Query_manager(db);
    QString queryStr = "SELECT id FROM Пользователь WHERE логин = :логин";
    QVariant ID_result = Query_manager.ExecuteSelectQuery_SingleData(queryStr, username);
    if (ID_result.isValid()) {
        bool ok;
        return ID_result.toInt(&ok);
    }
    return std::nullopt;
}

int db_inserter::insertUser(const QString& login, const QString& password) {
    if (!db.isOpen() && !db.open()) {
        qCritical() << "Database connection failed";
        return 1;
    }

    // Начинаем транзакцию
    db.transaction();

    try {
        // 1. Проверка существования пользователя
        QSqlQuery checkQuery(db);
        if (!checkQuery.prepare("SELECT COUNT(*) FROM Пользователь WHERE логин = ?")) {
            qCritical() << "Prepare check failed:" << checkQuery.lastError().text();
            db.rollback();
            return 2;
        }

        checkQuery.addBindValue(login);

        if (!checkQuery.exec()) {
            qCritical() << "Check query failed:" << checkQuery.lastError().text();
            db.rollback();
            return 2;
        }

        if (!checkQuery.next()) {
            db.rollback();
            return 2;
        }

        if (checkQuery.value(0).toInt() > 0) {
            db.rollback();
            return 3;
        }

        // 2. Генерация соли и хеша
        QByteArray salt = db_queries::generateSalt(32);
        QByteArray hashedPassword = db_queries::hashPassword(password, salt);

        // 3. Вставка пользователя
        QSqlQuery insertQuery(db);
        if (!insertQuery.prepare(
                "INSERT INTO Пользователь (логин, пароль, соль, роль) "
                "VALUES (:логин, :пароль, :соль, 'покупатель')"))
        {
            qCritical() << "Prepare insert failed:" << insertQuery.lastError().text();
            db.rollback();
            return 4;
        }

        insertQuery.bindValue(":логин", login);
        insertQuery.bindValue(":пароль", hashedPassword);
        insertQuery.bindValue(":соль", salt);

        if (!insertQuery.exec()) {
            qCritical() << "Insert failed:" << insertQuery.lastError().text();
            db.rollback();
            return 4;
        }

        // Фиксируем транзакцию
        if (!db.commit()) {
            qCritical() << "Commit failed";
            db.rollback();
            return 4;
        }

        return 0;
    } catch (...) {
        db.rollback();
        return 4;
    }
}
bool db_inserter::putBookInCart(const int userID, const int bookID) {
    db_queries queryManager(db);
    qDebug() << "userid = " << userID;
    if (queryManager.isBookInCart(userID, bookID)) {
        return queryManager.incrementBookInCart(userID, bookID);
    } else {
        QSqlQuery insertQuery(db);
        if (!insertQuery.prepare(
                "INSERT INTO Корзина (id_пользователя, id_книги) "
                "VALUES (:user_id, :book_id)"))
        {
            qCritical() << "Prepare insert failed:" << insertQuery.lastError().text();
            return false;
        }

        insertQuery.bindValue(":user_id", userID);
        insertQuery.bindValue(":book_id", bookID);

        if (!insertQuery.exec()) {
            qCritical() << "Insert failed:" << insertQuery.lastError().text();
            return false;
        }

        return true;
    }
}
bool db_inserter::putBookInOrder(const int userID, const int bookID) {
    QSqlQuery query(db);
    QString date = QDate::currentDate().toString(Qt::ISODate);

    if (!query.prepare(R"(
        INSERT INTO Книга_у_покупателя (id_пользователя, Книга, Дата_покупки)
        VALUES (:user_id, :book_id, :purchase_date)
    )")) {
        qCritical() << "Ошибка подготовки запроса:" << query.lastError().text();
        return false;
    }

    query.bindValue(":user_id", userID);
    query.bindValue(":book_id", bookID);
    query.bindValue(":purchase_date", date);

    if (!query.exec()) {
        qCritical() << "Ошибка вставки в Книга_у_покупателя:" << query.lastError().text();
        return false;
    }

    return true;
}
bool db_inserter::saveUserProfile(int userID, const QString& name, const QString& lastName,
                                  const QString& secondName, const QString& phone,
                                  const QString& city, const QString& category)
{
    QSqlQuery query(db);
    query.prepare(R"(
        INSERT INTO Покупатель (Фамилия, Имя, Отчество, Город, Телефон, Категория, id_пользователя)
        VALUES (:lastName, :firstName, :secondName, :city, :phone, :category, :userID)
        ON CONFLICT(id_пользователя) DO UPDATE SET
            Фамилия = excluded.Фамилия,
            Имя = excluded.Имя,
            Отчество = excluded.Отчество,
            Город = excluded.Город,
            Телефон = excluded.Телефон,
            Категория = excluded.Категория;
    )");

    query.bindValue(":lastName", lastName);
    query.bindValue(":firstName", name);
    query.bindValue(":secondName", secondName);
    query.bindValue(":city", city);
    query.bindValue(":phone", phone);
    query.bindValue(":category", category);
    query.bindValue(":userID", userID);

    if (!query.exec()) {
        qWarning() << "Ошибка сохранения профиля:" << query.lastError().text();
        return false;
    }

    return true;
}

