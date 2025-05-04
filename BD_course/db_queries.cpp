#include "db_queries.h"

QVariant db_queries::ExecuteSelectQuery_SingleData(const QString &queryStr, const QString &login) {
    if (!db.isOpen() && !db.open()) {
        qCritical() << "Database connection failed!";
        return QVariant();
    }

    QSqlQuery query(db);
    if (!query.prepare(queryStr)) {
        qCritical() << "Prepare failed:" << query.lastError().text();
        return QVariant();
    }

    query.addBindValue(login);

    if (!query.exec()) {
        qCritical() << "Execution failed:" << query.lastError().text()
        << "\nQuery:" << queryStr;
        return QVariant();
    }

    return query.next() ? query.value(0) : QVariant();
}
QVector<QVariant> db_queries::ExecuteSelectQuery_UserHashPassword(const QString &login) {
    QVector<QVariant> result;

    if (!db.isOpen() && !db.open()) {
        qCritical() << "Database connection failed!";
        return result;
    }

    QSqlQuery query(db);
    if (!query.prepare("SELECT пароль, соль FROM Пользователь WHERE логин = ?")) {
        qCritical() << "Prepare failed:" << query.lastError().text();
        return result;
    }

    query.addBindValue(login);

    if (!query.exec()) {
        qCritical() << "Execution failed:" << query.lastError().text();
        return result;
    }

    if (query.next()) {
        result.append(query.value(0));  // пароль (hash)
        result.append(query.value(1));  // соль
    } else {
        qDebug() << "Пользователь не найден при попытке получить пароль и соль.";
    }

    return result;
}
QByteArray db_queries::hashPassword(const QString &password, const QByteArray &salt){
    QByteArray passwordWithSalt = password.toUtf8() + salt;
    return QCryptographicHash::hash(passwordWithSalt, QCryptographicHash::Sha256).toHex();
}
QByteArray db_queries::generateSalt(int length) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    QByteArray salt;
    salt.reserve(length);

    for (int i = 0; i < length; ++i) {
        salt.append(alphanum[QRandomGenerator::global()->bounded(sizeof(alphanum) - 1)]);
    }

    return salt;
}
bool db_queries::verifyPassword(const QString &login, const QString &password) {
    if (!db.isOpen()) {
        qDebug() << "Database not open";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("SELECT пароль, соль FROM Пользователь WHERE логин = :логин");
    query.bindValue(":логин", login);

    if (!query.exec() || !query.next()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }

    QByteArray storedHash = query.value(0).toByteArray();
    QByteArray salt = query.value(1).toByteArray();
    QByteArray inputHash = hashPassword(password, salt);

    return (inputHash == storedHash);
}
Book db_queries::parseBook(const QSqlQuery& query){
    Book book;
    book.book_id = query.value(0).toInt();
    book.title = query.value(1).toString();
    book.author = query.value(2).toString();
    book.type = query.value(3).toString();
    book.genre = query.value(4).toString();
    book.price = query.value(5).toInt();
    book.publisher = query.value(6).toString();
    book.release_year = query.value(7).toInt();
    book.coverPath = query.value(8).toString();
    return book;
}

QVector<Book> db_queries::getBooksFromQuery(const QString sqlText,const QVariantList& params){
    QVector<Book> books;
    QSqlQuery query(db);
    if (!query.prepare(sqlText)) {
        qCritical() <<  "Prepare failed:" << query.lastError().text();
        return books;
    }
    for (int i = 0; i < params.size(); ++i) {
        query.bindValue(i, params[i]);
    }
    if (!query.exec()) {
        qDebug() << "(getBooksFromQuery) Error executing query:" << query.lastError().text();
        return books;
    }
    while (query.next()) {
        books.append(parseBook(query));
    }
    qDebug() << "Books in cart:" << books.size(); //debug
    qDebug() << "Running query with params:" << params;
    return books;
}

QVector<Book> db_queries::getAllBooks() {
    return getBooksFromQuery("SELECT Инвентарный_номер, Название_книги, Автор, Вид_книги, Тематика, Цена, Издательство, Год_издания, Обложка FROM Книга", {});
}
Book db_queries::getBookById(int bookID) {
    QVector<Book> result = getBooksFromQuery(
        "SELECT Инвентарный_номер, Название_книги, Автор, Вид_книги, Тематика, Цена, Издательство, Год_издания, Обложка FROM Книга WHERE Инвентарный_номер = ?",
        {bookID}
        );
    return result.isEmpty() ? Book{} : result.first();
}
QVector<Book> db_queries::getBooksFromCart(int userID) {
    return getBooksFromQuery(R"(
    SELECT
        Книга.Инвентарный_номер,
        Книга.Название_книги,
        Книга.Автор,
        Книга.Вид_книги,
        Книга.Тематика,
        Книга.Цена,
        Книга.Издательство,
        Книга.Год_издания,
        Книга.Обложка
    FROM Корзина
    JOIN Книга ON Корзина.id_книги = Книга.Инвентарный_номер
    WHERE Корзина.id_пользователя = ?
)", {userID});
}

QString db_queries::getBookInfo(int bookID){
    QString info;
    if (!db.isOpen() && !db.open()) {
        qCritical() << "Database connection failed!";
        return info;
    }
    QSqlQuery query(db);
    if (!query.prepare("SELECT Информация FROM Книга WHERE Инвентарный_номер = ?")) {
        qCritical() << "Prepare failed:" << query.lastError().text();
        return info;
    }
    query.addBindValue(bookID);
    if (!query.exec()) {
        qCritical() << "Execution failed:" << query.lastError().text();
        return info;
    }
    if (query.next()) {
        info = query.value(0).toString();
    }
    return info;
}

bool db_queries::isBookInCart(int userId, int bookId) {
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM Корзина WHERE id_пользователя = ? AND id_книги = ?");
    query.addBindValue(userId);
    query.addBindValue(bookId);

    if (!query.exec()) {
        qWarning() << "Ошибка проверки корзины:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}

bool db_queries::incrementBookInCart(int userID, int bookID){
    QSqlQuery query(db);
    query.prepare(R"(UPDATE Корзина
                        SET Количество = Количество + 1
                        WHERE id_пользователя = ? AND id_книги = ?)");
    query.addBindValue(userID);
    query.addBindValue(bookID);

    if (!query.exec()) {
        qWarning() << "Ошибка увеличения количества в корзине:" << query.lastError().text();
        return false;
    }

    return query.numRowsAffected() > 0;
}
bool db_queries::removeBookFromCart(int userID, int bookID){
    if (!db.isOpen() && !db.open()) {
        qCritical() << "Database connection failed!";
        return false;
    }
    QSqlQuery query(db);
    if (!query.prepare("DELETE FROM Корзина WHERE id_пользователя = ? AND id_книги = ?")) {
        qCritical() << "Prepare failed:" << query.lastError().text();
        return false;
    }
    query.addBindValue(userID);
    query.addBindValue(bookID);
    if (!query.exec()) {
        qCritical() << "Execution failed:" << query.lastError().text();
        return false;
    }
    return true;
}
