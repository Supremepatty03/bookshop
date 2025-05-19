#ifndef DB_QUERIES_H
#define DB_QUERIES_H
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include "book.h"

class db_queries
{
public:
    explicit db_queries(QSqlDatabase &database) : db(database) {}

    QVariant ExecuteSelectQuery_SingleData(const QString &StrQuery, const QString &loginText);
    QVector<QVariant> ExecuteSelectQuery_UserHashPassword(const QString &login);
    static QByteArray hashPassword(const QString &password, const QByteArray &salt);
    static QByteArray generateSalt(int length);
    bool verifyPassword(const QString &login, const QString &password);
    QVector<Book> getAllBooks();
    Book getBookById(int bookID);
    QString getBookInfo(int bookID);
    Book parseBook (const QSqlQuery& query);
    QVector<Book> getBooksFromQuery(const QString sqlText,const QVariantList& params);
    QVector<Book> getBooksFromCart(int userID);
    bool isBookInCart(int userID, int bookID);
    bool incrementBookInCart(int userID, int bookID);
    bool removeBookFromCart(int userID, int bookID);
    bool getUserProfile(int userID, QMap<QString, QString>& profileData);
    QVector<Book> getUserPurchases(int userID);
private:
    QSqlDatabase &db;
};

#endif // DB_QUERIES_H
