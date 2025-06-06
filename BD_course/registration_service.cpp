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
    if (password != confirmPassword) {
        return {-1, "Пароли не совпадают!"};
    }

    if (role != "покупатель" && role != "админ") {
        return {-1, "Недопустимая роль пользователя!"};
    }

    db_inserter inserter(db);
    auto [userID, errorCode] = inserter.insertUser(username, password);

    if (userID == -1) {
        QString errorMessage;
        switch (errorCode) {
        case 1: errorMessage = "Ошибка подключения к базе данных."; break;
        case 2: errorMessage = "Ошибка проверки пользователя."; break;
        case 3: errorMessage = "Пользователь с таким логином уже существует."; break;
        case 4: errorMessage = "Ошибка при добавлении пользователя."; break;
        case 5: errorMessage = "Ошибка получения ID пользователя."; break;
        case 6: errorMessage = "Ошибка фиксации транзакции."; break;
        default: errorMessage = "Неизвестная ошибка."; break;
        }
        return {-1, errorMessage};
    }

    return {userID, ""};
}
