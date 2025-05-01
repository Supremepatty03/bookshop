#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include "db_inserter.h"
#include "db_queries.h"
#include "registration_service.h"
#include "db_inserter.h"

std::pair<int, QString> Registration_service::registerUser(const QString &username,
                                                           const QString &password,
                                                           const QString &confirmPassword,
                                                           const QString &role) {
    // Проверка паролей
    if (password != confirmPassword) {
        return {-1, "Пароли не совпадают!"};
    }

    // Проверка валидности роли
    if (role != "покупатель" && role != "админ") {
        return {-1, "Недопустимая роль пользователя!"};
    }

    db_queries queryManager(db);

    // Проверка существования пользователя
    QVariant count = queryManager.ExecuteSelectQuery_SingleData(
        "SELECT COUNT(*) FROM Пользователь WHERE логин = ?", username);

    if (!count.isValid()) {
        return {-1, "Ошибка проверки пользователя!"};
    }

    if (count.toInt() > 0) {
        return {-1, "Пользователь с таким логином уже существует!"};
    }

    // Генерация соли и хеша
    QByteArray salt = queryManager.generateSalt(32);
    QByteArray hashedPassword = queryManager.hashPassword(password, salt);

    // Вставка нового пользователя
    QSqlQuery query(db);
    query.prepare("INSERT INTO Пользователь (логин, пароль, соль, роль) "
                  "VALUES (?, ?, ?, ?)");
    query.addBindValue(username);
    query.addBindValue(hashedPassword);
    query.addBindValue(salt);
    query.addBindValue(role);

    if (!query.exec()) {
        qDebug() << "Registration error:" << query.lastError().text();
        return {-1, "Ошибка регистрации: " + query.lastError().text()};
    }

    // Получение ID нового пользователя
    QVariant id = queryManager.ExecuteSelectQuery_SingleData(
        "SELECT id FROM Пользователь WHERE логин = ?", username);

    if (!id.isValid()) {
        return {-1, "Ошибка получения ID пользователя!"};
    }

    return {id.toInt(), ""};
}
