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

signals:
    void detailsRequested(int bookId); // для перехода на подробности

private:
    Ui::BookCardWidget *ui;
    int m_bookId;
};

#endif // BOOKCARDWIDGET_H
