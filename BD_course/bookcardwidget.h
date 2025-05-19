#ifndef BOOKCARDWIDGET_H
#define BOOKCARDWIDGET_H

#include <QWidget>
#include "book.h" // структура с информацией о книге

namespace Ui {
class BookCardWidget;
}

class BookCardWidget : public QWidget {
    Q_OBJECT

public:
    explicit BookCardWidget(QWidget *parent = nullptr);
    ~BookCardWidget();
    void setBookInfo(const Book &book);

    enum DisplayMode { StoreMode, CartMode, OrderMode, ArchiveMode };
    void setMode(DisplayMode mode);

signals:
    void detailsRequested(int bookId);
    void addToCart(int bookID);
    void removeFromCart(int bookId);
    void singleOrderRequested(int bookId);

private:
    Ui::BookCardWidget *ui;
    int m_bookId;
};

#endif // BOOKCARDWIDGET_H
