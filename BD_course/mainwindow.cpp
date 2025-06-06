#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include "book.h"
#include <QMainWindow>
#include "db_inserter.h"
#include "db_queries.h"
#include "bookcardwidget.h"
#include "./ui_bookcardwidget.h"
#include <QMessageBox>
#include <QWebEngineView>
#include <QWebEngineSettings>
#include "mapdialog.h"


MainWindow::MainWindow(QWidget *parent, QSqlDatabase &database)
    : QMainWindow(parent),
    db(database),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lobbyButton, &QPushButton::clicked, this, &MainWindow::on_lobbyButton);
    connect(ui->cartButton, &QPushButton::clicked, this, &MainWindow::on_cartButton);
    connect(ui->profileButton, &QPushButton::clicked, this, &MainWindow::on_profileButton);
    connect(ui->addDeclinedButton, &QPushButton::clicked, this, &MainWindow::on_addDeclinedButton);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_login_success(int userID) {
    this->userID = userID;
    this->showMaximized();

    db_inserter inserter(db);
    inserter.logLogin(userID); // лог входа

    ui->stackedWidget_2->setCurrentWidget(ui->page_3);

    db_queries query_manager(db);
    QString role = query_manager.getUserRole(userID);

    // Настраиваем scrollArea
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    QVector<Book> books = query_manager.getAllBooks();

    QWidget *container = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(container);
    layout->setSpacing(15);
    layout->setContentsMargins(10,10,10,10);

    for (const Book &book : books) {
        BookCardWidget *card = new BookCardWidget;
        card->setBookInfo(book);

        // Выбор режима по роли
        if (role == "админ") {
            card->setMode(BookCardWidget::AdminMode);
            connect(card, &BookCardWidget::deleteBookRequested, this, &MainWindow::onDeleteBook);
            connect(ui->AdminButton, &QPushButton::clicked, this, &MainWindow::on_AdminButton);
            ui->AdminButton->setVisible(true);
            ui->cartButton->setVisible(false);

        } else {
            card->setMode(BookCardWidget::StoreMode);
            connect(card, &BookCardWidget::addToCart, this, &MainWindow::on_addToCart);
            ui->AdminButton->setVisible(false);
        }

        connect(card, &BookCardWidget::detailsRequested, this, &MainWindow::on_detailsRequested);

        layout->addWidget(card);
    }
    layout->addStretch();

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
            "Ошибка добавления"  // сообщение
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
    connect(ui->addNewAdressButton, &QPushButton::clicked, this, &MainWindow::on_addNewAdressButton);
    connect(ui->orderCancelButton, &QPushButton::clicked, this, &MainWindow::on_orderCancelButton);
    connect(ui->confirmOrderButton, &QPushButton::clicked, this, [=]() {
        on_confirmOrderButton(bookID);  // bookID известен тут
    });
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
}
QString MainWindow::on_addNewAdressButton() {
    MapDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        QString selected = dlg.getSelectedAddress();
        qDebug() << "Выбранный адрес:" << selected;
        ui->currentAddressLine->setText(selected);
        return selected;
    }
}
void MainWindow::on_orderCancelButton(){

    ui->stackedWidget_2->setCurrentWidget(ui->page_4);
}
void MainWindow::on_confirmOrderButton(int bookID){
    db_inserter insertManager(db);
    QString baseText = "Пока отсутствует";
    if (ui->currentAddressLine->text() == "" || ui->currentAddressLine->text() == baseText) {
        QMessageBox::warning(this, "Ошибка", "Сначала выберите адрес на карте!");
        return;
    }
    if(!insertManager.putBookInOrder(userID, bookID))
    {
        QMessageBox::information(
            this,
            "Информация о заказе",          // заголовок окна
            "Ошибка заказа"  // сообщение
            );
    }
    else{
        QMessageBox::information(
            this,
            "Информация о заказе",          // заголовок окна
            "Заказ прошел успешно!"  // сообщение
            );
        on_cartButton();
    }
}
void MainWindow::loadProfileCombos() {
    QSqlQuery cityQuery("SELECT Название_города FROM Город", db);
    while (cityQuery.next()) {
        ui->cityCombo->addItem(cityQuery.value(0).toString());
    }

    QSqlQuery categoryQuery("SELECT Категория FROM Категория", db);
    while (categoryQuery.next()) {
        ui->categoryCombo->addItem(categoryQuery.value(0).toString());
    }
}
void MainWindow::saveUserProfile() {
    QString name = ui->nameLine->text().trimmed();
    QString lastName = ui->lastNameLine->text().trimmed();
    QString secondName = ui->secondNameLine->text().trimmed();
    QString phone = ui->phoneLine->text().trimmed();
    QString city = ui->cityCombo->currentText().trimmed();
    QString category = ui->categoryCombo->currentText().trimmed();

    if (name.isEmpty() || lastName.isEmpty() || phone.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните все обязательные поля!");
        return;
    }

    db_inserter inserter(db);
    if (!inserter.saveUserProfile(userID, name, lastName, secondName, phone, city, category)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить профиль!");
        return;
    }

    QMessageBox::information(this, "Успех", "Профиль сохранён!");
}
void MainWindow::on_profileButton() {
    connect(ui->saveProfileButton, &QPushButton::clicked, this, &MainWindow::saveUserProfile);
    connect(ui->outProfileButton, &QPushButton::clicked, this, &MainWindow::on_outProfileButton);
    connect(ui->orderAllButton_2, &QPushButton::clicked, this, &MainWindow::showUserOrders);
    connect(ui->returnFromUsersOrderButton, &QPushButton::clicked, this, &MainWindow::on_returnFromUsersOrderButton);

    loadProfileCombos();

    db_queries queryManager(db);
    QMap<QString, QString> profileData;

    if (queryManager.getUserProfile(userID, profileData)) {
        ui->nameLine->setText(profileData["name"]);
        ui->lastNameLine->setText(profileData["lastName"]);
        ui->secondNameLine->setText(profileData["secondName"]);
        ui->phoneLine->setText(profileData["phone"]);

        int cityIndex = ui->cityCombo->findText(profileData["city"]);
        if (cityIndex >= 0) ui->cityCombo->setCurrentIndex(cityIndex);

        int categoryIndex = ui->categoryCombo->findText(profileData["category"]);
        if (categoryIndex >= 0) ui->categoryCombo->setCurrentIndex(categoryIndex);
    } else {
        QMessageBox::information(this, "Профиль", "Профиль не найден. Вы можете заполнить его и сохранить.");
    }

    ui->stackedWidget_2->setCurrentWidget(ui->page_profile);
}
void MainWindow::on_outProfileButton(){
    ui->stackedWidget_2->setCurrentWidget(ui->page_3);
}
void MainWindow::showUserOrders() {
    ui->stackedWidget_2->setCurrentWidget(ui->page_usersOrders);

    // 1. Очистка layout
    QLayoutItem *child;
    while ((child = ui->verticalLayout_12->takeAt(0)) != nullptr) {
        if (QWidget *w = child->widget()) delete w;
        delete child;
    }

    // 2. Получаем данные
    db_queries queries(db);
    QVector<Book> orders = queries.getUserPurchases(userID);
    ui->scrollArea_5->setWidgetResizable(true);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->scrollAreaWidgetContents_5->setMinimumSize(0, 0);
    ui->scrollAreaWidgetContents_5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
  // 3. Добавляем карточки
    for (const Book &b : orders) {
        BookCardWidget *card = new BookCardWidget;
        card->setMode(BookCardWidget::ArchiveMode);
        card->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        card->setBookInfo(b);
        ui->verticalLayout_12->addWidget(card);
        connect(card, &BookCardWidget::detailsRequested, this, &MainWindow::on_detailsRequested);


    }

    ui->verticalLayout_12->addStretch();
}
void MainWindow::on_returnFromUsersOrderButton(){
    ui->stackedWidget_2->setCurrentWidget(ui->page_profile);
}
void MainWindow::onDeleteBook(int bookId) {
    db_queries query_manager(db);
    query_manager.deleteBook(bookId); // напиши такую функцию в db_queries
    on_login_success(userID); // обновляем отображение
}
void MainWindow::populateComboBoxes() {
    ui->authorComboBox->clear();
    ui->typeComboBox->clear();
    ui->topicComboBox->clear();
    ui->publisherComboBox->clear();
    QSqlQuery query;

    // Автор
    query.exec("SELECT Автор FROM Автор");
    while (query.next()) {
        ui->authorComboBox->addItem(query.value(0).toString());
    }

    // Вид книги
    query.exec("SELECT Название_вида FROM Вид_книги");
    while (query.next()) {
        ui->typeComboBox->addItem(query.value(0).toString());
    }

    // Тематика
    query.exec("SELECT Тематика_книги FROM Тематика_книги");
    while (query.next()) {
        ui->topicComboBox->addItem(query.value(0).toString());
    }

    // Издательство
    query.exec("SELECT Название_издательства FROM Издательство");
    while (query.next()) {
        ui->publisherComboBox->addItem(query.value(0).toString());
    }
}
void MainWindow::on_addButton_clicked() {

    QString title = ui->titleLineEdit->text().trimmed();
    QString author = ui->authorComboBox->currentText().trimmed();
    QString type = ui->typeComboBox->currentText().trimmed();
    QString topic = ui->topicComboBox->currentText().trimmed();
    double price = ui->priceSpinBox->value();
    QString publisher = ui->publisherComboBox->currentText().trimmed();
    int year = ui->yearSpinBox->value();
    int stock = ui->stockSpinBox->value();
    QString cover = ui->coverLineEdit->text().trimmed();
    QString info = ui->infoTextEdit->toPlainText().trimmed();

    if (title.isEmpty() || author.isEmpty() || type.isEmpty() || topic.isEmpty() ||
        price <= 0 || publisher.isEmpty() || year <= 0 || stock <= 0 ||
        cover.isEmpty() || info.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены и корректны.");
        return;
    }

    // Вставка в БД
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO Книга (Название_книги, Автор, Вид_книги, Тематика,
                           Цена, Издательство, Год_издания,
                           Кол_во_купленных, Кол_во_оставшихся,
                           Обложка, Информация)
        VALUES (?, ?, ?, ?, ?, ?, ?, 0, ?, ?, ?)
    )");

    query.addBindValue(title);
    query.addBindValue(author);
    query.addBindValue(type);
    query.addBindValue(topic);
    query.addBindValue(price);
    query.addBindValue(publisher);
    query.addBindValue(year);
    query.addBindValue(stock);
    query.addBindValue(cover);
    query.addBindValue(info);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить книгу: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Книга успешно добавлена.");
        this->close();
    }
}
void MainWindow::on_AdminButton(){
    populateComboBoxes();
    ui->stackedWidget_2->setCurrentWidget(ui->page_addBook);
}
void MainWindow::on_addDeclinedButton(){
    ui->stackedWidget_2->setCurrentWidget(ui->page_3);
}
