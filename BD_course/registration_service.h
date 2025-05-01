#ifndef REGISTRATION_SERVICE_H
#define REGISTRATION_SERVICE_H
#include <QApplication>
#include <QtSql>
#include <QSqlQuery>

class Registration_service
{
public:
    Registration_service(QSqlDatabase &database) : db(database) {}
    std::pair<int, QString> registerUser(const QString &username,
                                         const QString &password,
                                         const QString &confirmPassword,
                                         const QString &role = "покупатель");
    QSqlDatabase &db;
};

#endif // REGISTRATION_SERVICE_H
