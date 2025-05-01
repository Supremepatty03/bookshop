#include "bookcardwidget.h"
#include "ui_bookcardwidget.h"

BookCardWidget::BookCardWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::BookCardWidget)
{
    ui->setupUi(this);

    // Устанавливаем размер и поведение
    this->setMinimumHeight(150);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    connect(ui->detailsButton, &QPushButton::clicked, this, [=]() {
        emit detailsRequested(m_bookId);
    });
}

BookCardWidget::~BookCardWidget() {
    delete ui;
}

void BookCardWidget::setBookInfo(const Book &book) {
    ui->titleLabel->setText(book.title);
    ui->authorLabel->setText(book.author);
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

