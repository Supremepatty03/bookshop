#ifndef DB_INSERTER_H
#define DB_INSERTER_H
#include <QApplication>
#include <QtSql>
#include <QSqlQuery>
#include "book.h"
class db_inserter
{
public:
    explicit db_inserter(QSqlDatabase &database) : db(database) {}
    std::pair<int, int> insertUser(const QString& login, const QString& password);
    bool putBookInCart(const int userID, const int bookID);
    bool putBookInOrder(const int userID, const int bookID);
    bool saveUserProfile(int userID, const QString& name, const QString& lastName,
                         const QString& secondName, const QString& phone,
                         const QString& city, const QString& category);
    bool logLogin(int userID);
private:
    QSqlDatabase &db;
};


class UserRepository {
public:
    explicit UserRepository(QSqlDatabase &database) : db(database) {}
    std::optional<int> getUserId(const QString &username);

private:
    QSqlDatabase &db;
};
#endif // DB_INSERTER_H
