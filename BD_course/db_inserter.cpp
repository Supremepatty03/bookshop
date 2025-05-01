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
                "VALUES (:логин, :пароль, :соль, 'покупатель')")) {
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
