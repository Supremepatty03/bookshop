#include "bookcardwidget.h"
#include <QDir>
#include <QFile>
#include "ui_bookcardwidget.h"
BookCardWidget::BookCardWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::BookCardWidget), m_bookId(-1)
{
    ui->setupUi(this);

    connect(ui->detailsButton, &QPushButton::clicked, this, [=](){
        emit detailsRequested(m_bookId);
    });
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
    ui->orderDateLabel->setText(book.orderDate.toString("dd.MM.yyyy"));
    m_bookId = book.book_id;
    setStyleSheet("QWidget { padding: 10px; }");

    if (!book.coverPath.isEmpty()) {
        QDir dir(QCoreApplication::applicationDirPath());
        QString imagePath = dir.filePath(book.coverPath);
        qDebug() << "Loading cover from:" << imagePath;

        if (QFile::exists(imagePath)) {
            QPixmap pix(imagePath);
            if (!pix.isNull()) {
                ui->coverLabel->setPixmap(
                    pix.scaled(ui->coverLabel->size(),
                               Qt::KeepAspectRatio,
                               Qt::SmoothTransformation)
                    );
                ui->coverLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                return;
            }
            qWarning() << "Pixmap is null for" << imagePath;
        } else {
            qWarning() << "Cover file not found at" << imagePath;
        }
    }
    // если нечего показать
    ui->coverLabel->setText("Нет обложки");
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

    case AdminMode:
        ui->actionButton->setText("Удалить книгу");
        ui->actionButton->setVisible(true);
        ui->singleOrderButton->setVisible(false);
        ui->orderDateLabel->setVisible(false);
        connect(ui->actionButton, &QPushButton::clicked, this, [=]() {
            emit deleteBookRequested(m_bookId);
        });
        break;
    }
}
