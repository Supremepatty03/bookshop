/********************************************************************************
** Form generated from reading UI file 'bookcardwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKCARDWIDGET_H
#define UI_BOOKCARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookCardWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *coverLabel;
    QVBoxLayout *textLayout;
    QLabel *titleLabel;
    QLabel *genreLabel;
    QLabel *authorLabel;
    QLabel *priceLabel;
    QVBoxLayout *buttonLayout;
    QPushButton *detailsButton;
    QPushButton *actionButton;
    QPushButton *singleOrderButton;

    void setupUi(QWidget *BookCardWidget)
    {
        if (BookCardWidget->objectName().isEmpty())
            BookCardWidget->setObjectName("BookCardWidget");
        BookCardWidget->resize(787, 426);
        QFont font;
        font.setPointSize(12);
        BookCardWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(BookCardWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        coverLabel = new QLabel(BookCardWidget);
        coverLabel->setObjectName("coverLabel");
        coverLabel->setMinimumSize(QSize(100, 150));
        coverLabel->setScaledContents(true);

        horizontalLayout->addWidget(coverLabel);

        textLayout = new QVBoxLayout();
        textLayout->setObjectName("textLayout");
        titleLabel = new QLabel(BookCardWidget);
        titleLabel->setObjectName("titleLabel");
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        titleLabel->setFont(font1);

        textLayout->addWidget(titleLabel);

        genreLabel = new QLabel(BookCardWidget);
        genreLabel->setObjectName("genreLabel");

        textLayout->addWidget(genreLabel);

        authorLabel = new QLabel(BookCardWidget);
        authorLabel->setObjectName("authorLabel");

        textLayout->addWidget(authorLabel);


        horizontalLayout->addLayout(textLayout);

        priceLabel = new QLabel(BookCardWidget);
        priceLabel->setObjectName("priceLabel");

        horizontalLayout->addWidget(priceLabel);

        buttonLayout = new QVBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        detailsButton = new QPushButton(BookCardWidget);
        detailsButton->setObjectName("detailsButton");

        buttonLayout->addWidget(detailsButton);

        actionButton = new QPushButton(BookCardWidget);
        actionButton->setObjectName("actionButton");

        buttonLayout->addWidget(actionButton);

        singleOrderButton = new QPushButton(BookCardWidget);
        singleOrderButton->setObjectName("singleOrderButton");

        buttonLayout->addWidget(singleOrderButton);


        horizontalLayout->addLayout(buttonLayout);


        retranslateUi(BookCardWidget);

        QMetaObject::connectSlotsByName(BookCardWidget);
    } // setupUi

    void retranslateUi(QWidget *BookCardWidget)
    {
        genreLabel->setText(QString());
        detailsButton->setText(QCoreApplication::translate("BookCardWidget", "\320\237\320\276\320\264\321\200\320\276\320\261\320\275\320\265\320\265...", nullptr));
        actionButton->setText(QCoreApplication::translate("BookCardWidget", "\320\222 \320\272\320\276\321\200\320\267\320\270\320\275\321\203", nullptr));
        singleOrderButton->setText(QCoreApplication::translate("BookCardWidget", "\320\227\320\260\320\272\320\260\320\267\320\260\321\202\321\214 \320\264\320\276\321\201\321\202\320\260\320\262\320\272\321\203", nullptr));
        (void)BookCardWidget;
    } // retranslateUi

};

namespace Ui {
    class BookCardWidget: public Ui_BookCardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKCARDWIDGET_H
