#include "bookcardwidget.h"

#include "ui_bookcardwidget.h"
BookCardWidget::BookCardWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::BookCardWidget), m_bookId(-1)
{
    ui->setupUi(this);

    // Кнопка "Подробнее…" всегда
    connect(ui->detailsButton, &QPushButton::clicked, this, [=](){
        emit detailsRequested(m_bookId);
    });

    // По умолчанию — показываем режим магазина
    setMode(StoreMode);
}

BookCardWidget::~BookCardWidget() {
    delete ui;
}

void BookCardWidget::setBookInfo(const Book &book) {
    ui->titleLabel->setText(book.title);
    ui->authorLabel->setText(book.author);
    ui->genreLabel->setText(book.genre);
    ui->priceLabel->setText(QString::number(book.price) + " ₽");
    m_bookId = book.book_id;
    this->setStyleSheet("QWidget { padding: 10 px; }");

    QString imagePath = QCoreApplication::applicationDirPath() + "/" + book.coverPath;
    if (!book.coverPath.isEmpty()) {
        QPixmap pix(imagePath);
        ui->coverLabel->setPixmap(pix.scaled(100, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->coverLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }
}
void BookCardWidget::setMode(DisplayMode mode) {
    // Отключаем старые слоты
    ui->actionButton->disconnect();

    switch(mode) {
    case StoreMode:
        ui->actionButton->setText("В корзину");
        ui->orderDateLabel->setVisible(false);
        connect(ui->actionButton, &QPushButton::clicked, this, [=](){
            emit addToCart(m_bookId);
        });
        ui->actionButton->setVisible(true);
        ui->singleOrderButton->setVisible(false);
        break;

    case CartMode:
        ui->actionButton->setText("Удалить из корзины");
        ui->orderDateLabel->setVisible(false);
        connect(ui->actionButton, &QPushButton::clicked, this, [=](){
            emit removeFromCart(m_bookId);
        });
        ui->actionButton->setVisible(true);
        ui->singleOrderButton->setVisible(true);
        connect(ui->singleOrderButton, &QPushButton::clicked, this, [=]() {
            emit singleOrderRequested(m_bookId);
        });
        break;

    case OrderMode:
        ui->actionButton->setVisible(false);
        ui->singleOrderButton->setVisible(false);
        ui->orderDateLabel->setVisible(false);
        break;

    case ArchiveMode:
        ui->actionButton->setVisible(false);
        ui->singleOrderButton->setVisible(false);
        ui->orderDateLabel->setVisible(true);
        break;
    }

}
