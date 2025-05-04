#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include "book.h"
#include <QMainWindow>
#include "db_inserter.h"
#include "db_queries.h"
#include "bookcardwidget.h"
#include <QMessageBox>
#include <QWebEngineView>
#include <QWebEngineSettings>

MainWindow::MainWindow(QWidget *parent, QSqlDatabase &database)
    : QMainWindow(parent),
    db(database),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lobbyButton, &QPushButton::clicked, this, &MainWindow::on_lobbyButton);
    connect(ui->cartButton, &QPushButton::clicked, this, &MainWindow::on_cartButton);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_login_success(int userID) {
    this->userID = userID;
    this->showMaximized();
    ui->stackedWidget_2->setCurrentWidget(ui->page_3);
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
        card->setMode(BookCardWidget::StoreMode);
        card->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        connect(card, &BookCardWidget::addToCart, this, &MainWindow::on_addToCart);
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

void MainWindow::refreshCart(){
    db_queries queryManager(db);
    // Очищаем layout перед добавлением новых карточек
    QLayoutItem *child;
    while ((child = ui->verticalLayout_7->takeAt(0)) != nullptr) {
        if (child->widget()) delete child->widget();
        delete child;
    }

    QVector<Book> cartBooks = queryManager.getBooksFromCart(userID);

    for (const Book& book : cartBooks) {
        BookCardWidget *card = new BookCardWidget;
        card->setBookInfo(book);
        card->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        card->setMode(BookCardWidget::CartMode);
        connect(card, &BookCardWidget::removeFromCart, this, &MainWindow::on_removeFromCart);
        connect(card, &BookCardWidget::singleOrderRequested, this, &MainWindow::on_singleOrderRequested);

        ui->verticalLayout_7->addWidget(card);
        connect(card, &BookCardWidget::detailsRequested,
                this, &MainWindow::on_detailsRequested);
    }
    qDebug() << "Books in cart2:" << cartBooks.size();
    qDebug() << "userID passed to getBooksFromCart:" << userID;
}

void MainWindow::on_cartButton() {
    ui->stackedWidget_2->setCurrentWidget(ui->page_4);
    refreshCart();
    ui->verticalLayout_7->addStretch();
    ui->scrollArea_3->setWidgetResizable(true);
}
void MainWindow::on_lobbyButton(){
    ui->stackedWidget_2->setCurrentWidget(ui->page_3);
}

void MainWindow::on_addToCart(int bookID){
    int userID = this->userID;
    db_inserter insertManager(db);
    if(!insertManager.putBookInCart(userID, bookID))
    {
        QMessageBox::information(
            this,
            "Информация о добавлении",          // заголовок окна
            "Ошибка добавления!"  // сообщение
            );
    }
    else{
        QMessageBox::information(
            this,
            "Информация о добавлении",          // заголовок окна
            "Добавлено успешно!"  // сообщение
            );
        on_cartButton();
    }
}
void MainWindow::on_removeFromCart(int bookID) {
    db_queries queryManager(db);
    if(!(queryManager.removeBookFromCart(userID, bookID))){
        QMessageBox::information(
            this, "Информация о удалении", "Произошла внутренняя ошибка при удалении из корзины!");
    }
    else{refreshCart();}
}
void MainWindow::showBooksForOrder(const QVector<Book>& booksToOrder) {
    // Очищаем предыдущий контент layout
    QLayoutItem *child;
    while ((child = ui->verticalLayout_9->takeAt(0)) != nullptr) {
        if (child->widget()) delete child->widget();
        delete child;
    }

    // Добавляем карточки книг в layout
    for (const Book& book : booksToOrder) {
        BookCardWidget *card = new BookCardWidget;
        card->setBookInfo(book);
        card->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        // В режиме заказа скрываем кнопки действия
        card->setMode(BookCardWidget::OrderMode);

        ui->verticalLayout_9->addWidget(card);
    }

    ui->verticalLayout_9->addStretch();
}
void MainWindow::on_singleOrderRequested(int bookID) {
    ui->stackedWidget_2->setCurrentWidget(ui->page_order);

    db_queries queryManager(db);
    QVector<Book> books;
    books.append(queryManager.getBookById(bookID));

    showBooksForOrder(books);

    QString htmlPath = QCoreApplication::applicationDirPath() + "/sdek_widget.html";
    if (webView) {
        ui->verticalLayout_9->removeWidget(webView);
        webView->deleteLater();
        webView = nullptr;
    }

    webView = new QWebEngineView(this);
    webView->page()->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);
    webView->page()->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    webView->load(QUrl::fromLocalFile(htmlPath));
    ui->verticalLayout_9->addWidget(webView);
    webView->setStyleSheet("background-color: lightblue;"); //debug
    qDebug() << "HTML loaded from:" << htmlPath;
}
