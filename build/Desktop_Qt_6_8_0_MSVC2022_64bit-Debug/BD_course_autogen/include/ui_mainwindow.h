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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
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
    QPushButton *confirmOrderButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_4;
    QLineEdit *currentAddressLine;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *addNewAdressButton;
    QWidget *page_profile;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *secondNameLine;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLineEdit *nameLine;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QLineEdit *lastNameLine;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QLineEdit *phoneLine;
    QWidget *horizontalLayoutWidget_11;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QComboBox *cityCombo;
    QWidget *horizontalLayoutWidget_12;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_12;
    QComboBox *categoryCombo;
    QPushButton *orderAllButton_2;
    QLabel *label_3;
    QPushButton *saveProfileButton;
    QPushButton *outProfileButton;
    QWidget *page_usersOrders;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_5;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *lineEdit_5;
    QPushButton *returnFromUsersOrderButton;
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
        scrollArea_4->setGeometry(QRect(20, 240, 991, 361));
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
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 989, 519));
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
        lineEdit_3->setGeometry(QRect(20, 200, 991, 43));
        lineEdit_3->setFont(font);
        lineEdit_3->setReadOnly(true);
        orderCancelButton = new QPushButton(page_order);
        orderCancelButton->setObjectName("orderCancelButton");
        orderCancelButton->setGeometry(QRect(920, 210, 81, 21));
        confirmOrderButton = new QPushButton(page_order);
        confirmOrderButton->setObjectName("confirmOrderButton");
        confirmOrderButton->setGeometry(QRect(790, 130, 221, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sitka")});
        font2.setPointSize(11);
        confirmOrderButton->setFont(font2);
        horizontalLayoutWidget = new QWidget(page_order);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 120, 338, 37));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_4 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setMinimumSize(QSize(120, 0));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sitka")});
        font3.setPointSize(14);
        lineEdit_4->setFont(font3);
        lineEdit_4->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_4);

        currentAddressLine = new QLineEdit(horizontalLayoutWidget);
        currentAddressLine->setObjectName("currentAddressLine");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Sitka")});
        font4.setPointSize(12);
        currentAddressLine->setFont(font4);
        currentAddressLine->setReadOnly(true);

        horizontalLayout_2->addWidget(currentAddressLine);

        horizontalLayoutWidget_2 = new QWidget(page_order);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(19, 159, 341, 35));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        addNewAdressButton = new QPushButton(horizontalLayoutWidget_2);
        addNewAdressButton->setObjectName("addNewAdressButton");
        QFont font5;
        font5.setPointSize(11);
        addNewAdressButton->setFont(font5);

        horizontalLayout_3->addWidget(addNewAdressButton);

        stackedWidget_2->addWidget(page_order);
        page_profile = new QWidget();
        page_profile->setObjectName("page_profile");
        horizontalLayoutWidget_7 = new QWidget(page_profile);
        horizontalLayoutWidget_7->setObjectName("horizontalLayoutWidget_7");
        horizontalLayoutWidget_7->setGeometry(QRect(470, 110, 251, 71));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(horizontalLayoutWidget_7);
        label_7->setObjectName("label_7");

        horizontalLayout_9->addWidget(label_7);

        secondNameLine = new QLineEdit(horizontalLayoutWidget_7);
        secondNameLine->setObjectName("secondNameLine");

        horizontalLayout_9->addWidget(secondNameLine);

        horizontalLayoutWidget_8 = new QWidget(page_profile);
        horizontalLayoutWidget_8->setObjectName("horizontalLayoutWidget_8");
        horizontalLayoutWidget_8->setGeometry(QRect(470, 200, 251, 71));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(horizontalLayoutWidget_8);
        label_8->setObjectName("label_8");

        horizontalLayout_10->addWidget(label_8);

        nameLine = new QLineEdit(horizontalLayoutWidget_8);
        nameLine->setObjectName("nameLine");

        horizontalLayout_10->addWidget(nameLine);

        horizontalLayoutWidget_9 = new QWidget(page_profile);
        horizontalLayoutWidget_9->setObjectName("horizontalLayoutWidget_9");
        horizontalLayoutWidget_9->setGeometry(QRect(470, 290, 251, 71));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget_9);
        label_9->setObjectName("label_9");

        horizontalLayout_11->addWidget(label_9);

        lastNameLine = new QLineEdit(horizontalLayoutWidget_9);
        lastNameLine->setObjectName("lastNameLine");

        horizontalLayout_11->addWidget(lastNameLine);

        horizontalLayoutWidget_10 = new QWidget(page_profile);
        horizontalLayoutWidget_10->setObjectName("horizontalLayoutWidget_10");
        horizontalLayoutWidget_10->setGeometry(QRect(470, 370, 251, 71));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalLayoutWidget_10);
        label_10->setObjectName("label_10");

        horizontalLayout_12->addWidget(label_10);

        phoneLine = new QLineEdit(horizontalLayoutWidget_10);
        phoneLine->setObjectName("phoneLine");

        horizontalLayout_12->addWidget(phoneLine);

        horizontalLayoutWidget_11 = new QWidget(page_profile);
        horizontalLayoutWidget_11->setObjectName("horizontalLayoutWidget_11");
        horizontalLayoutWidget_11->setGeometry(QRect(470, 460, 251, 71));
        horizontalLayout_13 = new QHBoxLayout(horizontalLayoutWidget_11);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(horizontalLayoutWidget_11);
        label_11->setObjectName("label_11");

        horizontalLayout_13->addWidget(label_11);

        cityCombo = new QComboBox(horizontalLayoutWidget_11);
        cityCombo->setObjectName("cityCombo");

        horizontalLayout_13->addWidget(cityCombo);

        horizontalLayoutWidget_12 = new QWidget(page_profile);
        horizontalLayoutWidget_12->setObjectName("horizontalLayoutWidget_12");
        horizontalLayoutWidget_12->setGeometry(QRect(470, 550, 251, 71));
        horizontalLayout_14 = new QHBoxLayout(horizontalLayoutWidget_12);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(horizontalLayoutWidget_12);
        label_12->setObjectName("label_12");

        horizontalLayout_14->addWidget(label_12);

        categoryCombo = new QComboBox(horizontalLayoutWidget_12);
        categoryCombo->setObjectName("categoryCombo");

        horizontalLayout_14->addWidget(categoryCombo);

        orderAllButton_2 = new QPushButton(page_profile);
        orderAllButton_2->setObjectName("orderAllButton_2");
        orderAllButton_2->setGeometry(QRect(470, 630, 111, 41));
        label_3 = new QLabel(page_profile);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(330, 60, 611, 31));
        QFont font6;
        font6.setPointSize(11);
        font6.setBold(true);
        font6.setItalic(true);
        label_3->setFont(font6);
        saveProfileButton = new QPushButton(page_profile);
        saveProfileButton->setObjectName("saveProfileButton");
        saveProfileButton->setGeometry(QRect(640, 630, 80, 22));
        outProfileButton = new QPushButton(page_profile);
        outProfileButton->setObjectName("outProfileButton");
        outProfileButton->setGeometry(QRect(330, 110, 80, 22));
        stackedWidget_2->addWidget(page_profile);
        page_usersOrders = new QWidget();
        page_usersOrders->setObjectName("page_usersOrders");
        scrollArea_5 = new QScrollArea(page_usersOrders);
        scrollArea_5->setObjectName("scrollArea_5");
        scrollArea_5->setGeometry(QRect(70, 250, 991, 361));
        sizePolicy.setHeightForWidth(scrollArea_5->sizePolicy().hasHeightForWidth());
        scrollArea_5->setSizePolicy(sizePolicy);
        scrollArea_5->setTabletTracking(true);
        scrollArea_5->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        scrollArea_5->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        scrollArea_5->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea_5->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        scrollArea_5->setWidgetResizable(true);
        scrollArea_5->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName("scrollAreaWidgetContents_5");
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 989, 519));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents_5->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_5->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents_5->setMinimumSize(QSize(989, 519));
        scrollAreaWidgetContents_5->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout_11 = new QVBoxLayout(scrollAreaWidgetContents_5);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_12->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);

        verticalLayout_11->addLayout(verticalLayout_12);

        scrollArea_5->setWidget(scrollAreaWidgetContents_5);
        lineEdit_5 = new QLineEdit(page_usersOrders);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(70, 210, 991, 43));
        lineEdit_5->setFont(font);
        lineEdit_5->setReadOnly(true);
        returnFromUsersOrderButton = new QPushButton(page_usersOrders);
        returnFromUsersOrderButton->setObjectName("returnFromUsersOrderButton");
        returnFromUsersOrderButton->setGeometry(QRect(970, 220, 80, 22));
        stackedWidget_2->addWidget(page_usersOrders);

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

        stackedWidget_2->setCurrentIndex(3);
        AvailableBooks->setCurrentIndex(0);
        cartBooks->setCurrentIndex(0);


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
        confirmOrderButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201 \320\264\320\276\321\201\321\202\320\260\320\262\320\272\320\270:", nullptr));
        currentAddressLine->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260 \320\276\321\202\321\201\321\203\321\202\321\201\321\202\320\262\321\203\320\265\321\202", nullptr));
        addNewAdressButton->setText(QCoreApplication::translate("MainWindow", "+ \320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\271", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\321\200\320\276\320\264", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        orderAllButton_2->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\270 \320\267\320\260\320\272\320\260\320\267\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\320\265 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \321\201\320\265\320\261\320\265. \320\236\320\275\320\260 \320\275\321\203\320\266\320\275\320\260 \320\264\320\273\321\217 \320\264\320\276\321\201\321\202\320\260\320\262\320\272\320\270 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        saveProfileButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        outProfileButton->setText(QCoreApplication::translate("MainWindow", "\320\222 \320\272\320\260\321\202\320\260\320\273\320\276\320\263", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\277\320\276\320\272\321\203\320\277\320\276\320\272", nullptr));
        returnFromUsersOrderButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
