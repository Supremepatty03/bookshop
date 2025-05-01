#ifndef REGISTRATION_WINDOW_H
#define REGISTRATION_WINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QtSql>
#include <QSqlQuery>

namespace Ui {
class registration_window;
}

class registration_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit registration_window(QWidget *parent, QSqlDatabase &database);
    ~registration_window();
    void noDBConnection();

private slots:
    void on_radioButton_clicked();
    void on_AutorisationButton_clicked();      // Слот для кнопки авторизации
    void on_RegistrationButton_clicked();      // Слот для кнопки регистрации
    void performSecondAction();

private:
    Ui::registration_window *ui;       // Флаг для отслеживания режима (авторизация/регистрация)
    MainWindow *mainWindow;                    // Указатель на главное окно приложения
    bool isFirstClick_RegAuth = true;
    QSqlDatabase &db;
signals:
    void login_successful (int user_id);
};
#endif // REGISTRATION_WINDOW_H
