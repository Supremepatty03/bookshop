#include <QApplication>
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
};

#endif // BOOK_H
