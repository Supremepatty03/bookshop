#ifndef DB_CONNECTOR_H
#define DB_CONNECTOR_H
#include <QSqlDatabase>
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
struct DB_config {
    QString database_path = QCoreApplication::applicationDirPath() + "/" + "bookshop1.db";
};
class db_connector {
public:
    static bool init_connection(DB_config default_config);
    static QSqlDatabase& database();
    static void close_connection();
    static QSqlDatabase get_database();

private:
    static QSqlDatabase m_db;
    static bool m_initialized;
};

#endif // DB_CONNECTOR_H
