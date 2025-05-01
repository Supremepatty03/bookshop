#ifndef DB_INSERTER_H
#define DB_INSERTER_H
#include <QApplication>
#include <QtSql>
#include <QSqlQuery>
class db_inserter
{
public:
    explicit db_inserter(QSqlDatabase &database) : db(database) {}
    int insertUser(const QString& username, const QString& password);
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
