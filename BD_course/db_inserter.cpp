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

std::pair<int, int> db_inserter::insertUser(const QString& login, const QString& password) {
    if (!db.isOpen() && !db.open()) {
        qCritical() << "Database connection failed";
        return {-1, 1};
    }

    db.transaction();

    try {
        QSqlQuery checkQuery(db);
        if (!checkQuery.prepare("SELECT COUNT(*) FROM Пользователь WHERE логин = ?")) {
            db.rollback();
            return {-1, 2};
        }

        checkQuery.addBindValue(login);
        if (!checkQuery.exec() || !checkQuery.next()) {
            db.rollback();
            return {-1, 2};
        }

        if (checkQuery.value(0).toInt() > 0) {
            db.rollback();
            return {-1, 3}; // Пользователь уже существует
        }

        QByteArray salt = db_queries::generateSalt(32);
        QByteArray hashedPassword = db_queries::hashPassword(password, salt);

        QSqlQuery insertQuery(db);
        if (!insertQuery.prepare(
                "INSERT INTO Пользователь (логин, пароль, соль, роль) "
                "VALUES (?, ?, ?, ?)")) {
            db.rollback();
            return {-1, 4};
        }
        QString role = "покупатель";
        insertQuery.addBindValue(login);
        insertQuery.addBindValue(hashedPassword);
        insertQuery.addBindValue(salt);
        insertQuery.addBindValue(role);

        if (!insertQuery.exec()) {
            db.rollback();
            return {-1, 4};
        }

        QSqlQuery idQuery(db);
        if (!idQuery.prepare("SELECT id FROM Пользователь WHERE логин = ?")) {
            db.rollback();
            return {-1, 5};
        }

        idQuery.addBindValue(login);
        if (!idQuery.exec() || !idQuery.next()) {
            db.rollback();
            return {-1, 5};
        }

        int userId = idQuery.value(0).toInt();

        if (!db.commit()) {
            db.rollback();
            return {-1, 6};
        }

        return {userId, 0}; // Успешно, возвращаем userID
    } catch (...) {
        db.rollback();
        return {-1, 7};
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
bool db_inserter::logLogin(int userID) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO Лог_входа (id_пользователя, время_входа) VALUES (?, ?)");
    query.addBindValue(userID);
    query.addBindValue(QDateTime::currentDateTime().toString(Qt::ISODate));

    if (!query.exec()) {
        qDebug() << "Ошибка при записи входа:" << query.lastError().text();
        return false;
    }
    return true;
}
