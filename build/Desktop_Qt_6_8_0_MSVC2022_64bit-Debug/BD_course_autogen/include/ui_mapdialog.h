/********************************************************************************
** Form generated from reading UI file 'mapdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPDIALOG_H
#define UI_MAPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelAddress;
    QTextEdit *textAddres;
    QPushButton *confirmButton;

    void setupUi(QDialog *MapDialog)
    {
        if (MapDialog->objectName().isEmpty())
            MapDialog->setObjectName("MapDialog");
        MapDialog->resize(640, 475);
        verticalLayoutWidget = new QWidget(MapDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 20, 571, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labelAddress = new QLabel(verticalLayoutWidget);
        labelAddress->setObjectName("labelAddress");

        horizontalLayout->addWidget(labelAddress);

        textAddres = new QTextEdit(verticalLayoutWidget);
        textAddres->setObjectName("textAddres");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textAddres->sizePolicy().hasHeightForWidth());
        textAddres->setSizePolicy(sizePolicy);
        textAddres->setMaximumSize(QSize(16777215, 26));
        textAddres->setReadOnly(true);

        horizontalLayout->addWidget(textAddres);


        verticalLayout->addLayout(horizontalLayout);

        confirmButton = new QPushButton(verticalLayoutWidget);
        confirmButton->setObjectName("confirmButton");

        verticalLayout->addWidget(confirmButton);


        retranslateUi(MapDialog);

        QMetaObject::connectSlotsByName(MapDialog);
    } // setupUi

    void retranslateUi(QDialog *MapDialog)
    {
        MapDialog->setWindowTitle(QCoreApplication::translate("MapDialog", "Dialog", nullptr));
        labelAddress->setText(QCoreApplication::translate("MapDialog", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\271 \320\260\320\264\321\200\320\265\321\201", nullptr));
        confirmButton->setText(QCoreApplication::translate("MapDialog", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapDialog: public Ui_MapDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPDIALOG_H
