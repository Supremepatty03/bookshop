#include <QApplication>
#include <QDate>
#ifndef BOOK_H
#define BOOK_H

struct Book
{
    int book_id;
    QString title;
    QString author;
    QString type;
    QString genre;
    double price;
    QString publisher;
    int release_year;
    QString coverPath;
    QDate orderDate;
};

#endif // BOOK_H
