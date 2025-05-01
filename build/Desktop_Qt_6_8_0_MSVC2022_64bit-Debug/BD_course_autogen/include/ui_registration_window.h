/********************************************************************************
** Form generated from reading UI file 'registration_window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_WINDOW_H
#define UI_REGISTRATION_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registration_window
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *loginLabel;
    QLineEdit *loginLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwordLabel;
    QLineEdit *passwordLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *registrationLabel;
    QLineEdit *registrationLine;
    QHBoxLayout *horizontalLayout_4;
    QLabel *errorLabel;
    QRadioButton *radioButton;
    QPushButton *AutorisationButton;
    QCommandLinkButton *RegistrationButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *registration_window)
    {
        if (registration_window->objectName().isEmpty())
            registration_window->setObjectName("registration_window");
        registration_window->resize(572, 498);
        centralwidget = new QWidget(registration_window);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 351, 241));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 40, 361, 241));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        loginLabel = new QLabel(layoutWidget);
        loginLabel->setObjectName("loginLabel");

        horizontalLayout->addWidget(loginLabel);

        loginLine = new QLineEdit(layoutWidget);
        loginLine->setObjectName("loginLine");

        horizontalLayout->addWidget(loginLine);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        passwordLabel = new QLabel(layoutWidget);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(passwordLabel);

        passwordLine = new QLineEdit(layoutWidget);
        passwordLine->setObjectName("passwordLine");
        passwordLine->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_2->addWidget(passwordLine);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        registrationLabel = new QLabel(layoutWidget);
        registrationLabel->setObjectName("registrationLabel");

        horizontalLayout_3->addWidget(registrationLabel);

        registrationLine = new QLineEdit(layoutWidget);
        registrationLine->setObjectName("registrationLine");
        registrationLine->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_3->addWidget(registrationLine);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        errorLabel = new QLabel(layoutWidget);
        errorLabel->setObjectName("errorLabel");

        horizontalLayout_4->addWidget(errorLabel);

        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName("radioButton");

        horizontalLayout_4->addWidget(radioButton);


        verticalLayout->addLayout(horizontalLayout_4);

        AutorisationButton = new QPushButton(layoutWidget);
        AutorisationButton->setObjectName("AutorisationButton");

        verticalLayout->addWidget(AutorisationButton);


        verticalLayout_2->addLayout(verticalLayout);

        RegistrationButton = new QCommandLinkButton(layoutWidget);
        RegistrationButton->setObjectName("RegistrationButton");

        verticalLayout_2->addWidget(RegistrationButton);

        registration_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(registration_window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 572, 25));
        registration_window->setMenuBar(menubar);
        statusbar = new QStatusBar(registration_window);
        statusbar->setObjectName("statusbar");
        registration_window->setStatusBar(statusbar);

        retranslateUi(registration_window);

        QMetaObject::connectSlotsByName(registration_window);
    } // setupUi

    void retranslateUi(QMainWindow *registration_window)
    {
        registration_window->setWindowTitle(QCoreApplication::translate("registration_window", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("registration_window", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        loginLabel->setText(QCoreApplication::translate("registration_window", "\320\233\320\276\320\263\320\270\320\275  ", nullptr));
        loginLine->setText(QString());
        passwordLabel->setText(QCoreApplication::translate("registration_window", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        registrationLabel->setText(QCoreApplication::translate("registration_window", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        errorLabel->setText(QCoreApplication::translate("registration_window", "<html><head/><body><p><span style=\" color:#ff0000;\">error message!</span></p></body></html>", nullptr));
        radioButton->setText(QCoreApplication::translate("registration_window", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        AutorisationButton->setText(QCoreApplication::translate("registration_window", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        RegistrationButton->setText(QCoreApplication::translate("registration_window", "\320\235\320\265\321\202 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260? \320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registration_window: public Ui_registration_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_WINDOW_H
