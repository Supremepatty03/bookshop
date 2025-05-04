/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QPushButton *profileButton;
    QPushButton *cartButton;
    QStackedWidget *AvailableBooks;
    QWidget *page;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QWidget *page_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QWidget *page_4;
    QLabel *label_2;
    QPushButton *lobbyButton;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_7;
    QStackedWidget *cartBooks;
    QWidget *page_7;
    QWidget *page_8;
    QLineEdit *lineEdit_2;
    QPushButton *orderAllButton;
    QWidget *page_order;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *lineEdit_3;
    QPushButton *orderCancelButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1600, 818);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        stackedWidget_2 = new QStackedWidget(centralwidget);
        stackedWidget_2->setObjectName("stackedWidget_2");
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        profileButton = new QPushButton(page_3);
        profileButton->setObjectName("profileButton");
        profileButton->setGeometry(QRect(1210, 10, 80, 22));
        cartButton = new QPushButton(page_3);
        cartButton->setObjectName("cartButton");
        cartButton->setGeometry(QRect(1110, 10, 80, 22));
        AvailableBooks = new QStackedWidget(page_3);
        AvailableBooks->setObjectName("AvailableBooks");
        AvailableBooks->setGeometry(QRect(170, 160, 991, 521));
        page = new QWidget();
        page->setObjectName("page");
        page->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 991, 511));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setTabletTracking(true);
        scrollArea->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        scrollArea->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 989, 519));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setMinimumSize(QSize(989, 519));
        scrollAreaWidgetContents->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);

        verticalLayout->addLayout(verticalLayout_3);

        scrollArea->setWidget(scrollAreaWidgetContents);
        AvailableBooks->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        AvailableBooks->addWidget(page_2);
        layoutWidget = new QWidget(page_3);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(170, 120, 991, 59));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic UI")});
        font.setPointSize(22);
        font.setBold(false);
        lineEdit->setFont(font);
        lineEdit->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(page_3);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1091, 49));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Viner Hand ITC")});
        font1.setPointSize(26);
        label->setFont(font1);
        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        label_2 = new QLabel(page_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 1091, 49));
        label_2->setFont(font1);
        lobbyButton = new QPushButton(page_4);
        lobbyButton->setObjectName("lobbyButton");
        lobbyButton->setGeometry(QRect(1100, 10, 80, 22));
        scrollArea_3 = new QScrollArea(page_4);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setGeometry(QRect(30, 140, 991, 511));
        sizePolicy.setHeightForWidth(scrollArea_3->sizePolicy().hasHeightForWidth());
        scrollArea_3->setSizePolicy(sizePolicy);
        scrollArea_3->setTabletTracking(true);
        scrollArea_3->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        scrollArea_3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        scrollArea_3->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea_3->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        scrollArea_3->setWidgetResizable(true);
        scrollArea_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 989, 519));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents_3->setMinimumSize(QSize(989, 519));
        scrollAreaWidgetContents_3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        cartBooks = new QStackedWidget(scrollAreaWidgetContents_3);
        cartBooks->setObjectName("cartBooks");
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        page_7->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        cartBooks->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        cartBooks->addWidget(page_8);

        verticalLayout_7->addWidget(cartBooks);


        verticalLayout_6->addLayout(verticalLayout_7);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);
        lineEdit_2 = new QLineEdit(page_4);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(30, 100, 991, 43));
        lineEdit_2->setFont(font);
        lineEdit_2->setReadOnly(true);
        orderAllButton = new QPushButton(page_4);
        orderAllButton->setObjectName("orderAllButton");
        orderAllButton->setGeometry(QRect(930, 110, 80, 22));
        stackedWidget_2->addWidget(page_4);
        page_order = new QWidget();
        page_order->setObjectName("page_order");
        scrollArea_4 = new QScrollArea(page_order);
        scrollArea_4->setObjectName("scrollArea_4");
        scrollArea_4->setGeometry(QRect(30, 110, 991, 571));
        sizePolicy.setHeightForWidth(scrollArea_4->sizePolicy().hasHeightForWidth());
        scrollArea_4->setSizePolicy(sizePolicy);
        scrollArea_4->setTabletTracking(true);
        scrollArea_4->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        scrollArea_4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        scrollArea_4->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea_4->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        scrollArea_4->setWidgetResizable(true);
        scrollArea_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 989, 569));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents_4->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_4->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents_4->setMinimumSize(QSize(989, 519));
        scrollAreaWidgetContents_4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents_4);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);

        verticalLayout_8->addLayout(verticalLayout_9);

        scrollArea_4->setWidget(scrollAreaWidgetContents_4);
        lineEdit_3 = new QLineEdit(page_order);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(30, 70, 991, 43));
        lineEdit_3->setFont(font);
        lineEdit_3->setReadOnly(true);
        orderCancelButton = new QPushButton(page_order);
        orderCancelButton->setObjectName("orderCancelButton");
        orderCancelButton->setGeometry(QRect(920, 80, 80, 22));
        stackedWidget_2->addWidget(page_order);

        verticalLayout_2->addWidget(stackedWidget_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1600, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget_2->setCurrentIndex(2);
        AvailableBooks->setCurrentIndex(0);
        cartBooks->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        profileButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        cartButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\200\320\267\320\270\320\275\320\260", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\262\320\260\321\200\321\213", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "BookShop", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "BookShop", nullptr));
        lobbyButton->setText(QCoreApplication::translate("MainWindow", "\320\222 \320\272\320\260\321\202\320\260\320\273\320\276\320\263", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\200\320\267\320\270\320\275\320\260", nullptr));
        orderAllButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\320\265", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213 \320\267\320\260\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202\320\265 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\265 \320\277\320\276\320\267\320\270\321\206\320\270\320\270:", nullptr));
        orderCancelButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
