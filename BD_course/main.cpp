#include "mainwindow.h"
#include "registration_window.h"
#include "db_connector.h"
#include <QApplication>
#include "registration_window.h"
#include "db_connector.h"
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    qDebug() << "SQL Driver Path: " << QLibraryInfo::path(QLibraryInfo::PluginsPath);
    QApplication a(argc, argv);

    qDebug() << "Available drivers:" << QSqlDatabase::drivers();
    DB_config Default_config;
    qDebug() << Default_config.database_path;
    if (!db_connector::init_connection(Default_config)) {
        qDebug()<<("Error,Database connection failed!Check:n1. SQLite driver exists in pluginsn2. Database file permissionsn3. File path validity");
    }
    QSqlDatabase db = db_connector::get_database();
    registration_window regWin(nullptr, db);
    regWin.show();
    return a.exec();
}
