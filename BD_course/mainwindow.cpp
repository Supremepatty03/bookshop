#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include "book.h"
#include "registration_window.h"
#include <QMainWindow>
#include "ui_registration_window.h"
#include "registration_window.h"
#include "db_inserter.h"
#include "registration_service.h"
#include "db_queries.h"
#include "bookcardwidget.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent, QSqlDatabase &database)
    : QMainWindow(parent),
    db(database),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_login_success(int userID) {
    this->userID = userID;
    this->showMaximized();

    db_queries query_manager(db);

    // Настраиваем scrollArea
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // Получаем книги
    QVector<Book> books = query_manager.getAllBooks();

    // Новый контейнер + layout
    QWidget *container = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(container);
    layout->setSpacing(15);
    layout->setContentsMargins(10,10,10,10);

    // Добавляем карточки
    for (const Book &book : books) {
        BookCardWidget *card = new BookCardWidget;
        card->setBookInfo(book);
        card->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        layout->addWidget(card);

        connect(card, &BookCardWidget::detailsRequested,
                this, &MainWindow::on_detailsRequested);
    }
    layout->addStretch();

    // Вешаем на scrollArea
    ui->scrollArea->setWidget(container);
}
void MainWindow::on_detailsRequested(int bookID){
    db_queries query_manager(db);

    QString info = query_manager.getBookInfo(bookID);

    QMessageBox::information(
        this,
        "Информация о книге",          // заголовок окна
        info.isEmpty() ? "Нет описания." : info  // сообщение
        );
}
void MainWindow::on_cartButton(int userID){
    db_queries query_manager(db);


}
