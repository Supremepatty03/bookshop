#include "db_connector.h"
#include <QDebug>

QSqlDatabase db_connector::m_db;
bool db_connector::m_initialized = false;

bool db_connector::init_connection(DB_config default_config) {
    if (m_initialized) return true;

    // 1. Проверка доступности драйвера
    if (!QSqlDatabase::isDriverAvailable("QSQLITE")) {
        qCritical() << "SQLite driver not available";
        return false;
    }

    // 2. Создаем подключение
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(default_config.database_path);

    // 3. Открываем соединение
    if (!m_db.open()) {
        qCritical() << "Connection error:" << m_db.lastError().text();
        return false;
    }

    m_initialized = true;
    qDebug() << "Successfully connected to database";
    return true;
}

QSqlDatabase& db_connector::database() {
    if (!m_initialized)
        qFatal("Database not initialized!");
    return m_db;
}

void db_connector::close_connection() {
    if (m_db.isOpen())
        m_db.close();
    m_initialized = false;
}
QSqlDatabase db_connector::get_database(){
    return m_db;
}
