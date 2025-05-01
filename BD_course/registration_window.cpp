#include "registration_window.h"
#include <QMainWindow>
#include "ui_registration_window.h"
#include "registration_window.h"
#include "db_inserter.h"
#include "registration_service.h"
#include "db_queries.h"

registration_window::registration_window(QWidget *parent, QSqlDatabase &database) :
    QMainWindow(parent),
    db(database),
    ui(new Ui::registration_window)
{
    ui->setupUi(this);
    ui->errorLabel->setVisible(false);
    ui->registrationLabel->setVisible(false);
    ui->registrationLine->setVisible(false);
    ui->errorLabel->setStyleSheet("QLabel { color : red; }");

    // Создаем главное окно и подключаем слот
    mainWindow = new MainWindow(nullptr, db);
    connect(this, &registration_window::login_successful,
            mainWindow, &MainWindow::on_login_success);

    connect(ui->AutorisationButton, &QPushButton::clicked, this, &registration_window::on_AutorisationButton_clicked);
}
registration_window::~registration_window()
{
    delete ui;
}
void registration_window::on_radioButton_clicked() {
    if (ui->radioButton->isChecked()) {
        ui->passwordLine->setEchoMode(QLineEdit::Normal); // Показать текст
        ui->registrationLine->setEchoMode(QLineEdit::Normal);
    } else {
        ui->passwordLine->setEchoMode(QLineEdit::Password); // Скрыть текст
        ui->registrationLine->setEchoMode(QLineEdit::Password);
    }
}
void registration_window::noDBConnection() {
    ui->errorLabel->setVisible(true);
    ui->errorLabel->setText("Нет связи с базой данных!");
}

void registration_window::performSecondAction() {
    Registration_service regService(db);

    QString username = ui->loginLine->text();
    QString password = ui->passwordLine->text();
    QString confirmPassword = ui->registrationLine->text();

    // Регистрируем как покупателя по умолчанию
    auto [userID, errorMsg] = regService.registerUser(username, password, confirmPassword);

    if (userID == -1) {
        ui->errorLabel->setText(errorMsg);
        ui->errorLabel->setVisible(true);
        return;
    }

    emit login_successful(userID);
    this->close();
}
void registration_window::on_AutorisationButton_clicked() {
    db_queries Query_manager(db);
    int userID;
    bool ok;

    if (isFirstClick_RegAuth) {
        // Режим авторизации
        QString loginText = ui->loginLine->text();
        QString passwordText = ui->passwordLine->text();

        if (loginText.isEmpty() || passwordText.isEmpty()) {
            ui->errorLabel->setText("Заполните все поля.");
            ui->errorLabel->setVisible(true);
            return;
        }

        // Получаем ID пользователя
        QString queryStr1 = "SELECT id FROM Пользователь WHERE логин = ?";
        QVariant ID_result = Query_manager.ExecuteSelectQuery_SingleData(queryStr1, loginText);

        if (ID_result.isValid()) {
            userID = ID_result.toInt(&ok);

            // Получаем хеш пароля и соль
            QVector<QVariant> passwordResult = Query_manager.ExecuteSelectQuery_UserHashPassword(loginText);

            if (passwordResult.size() >= 2) {
                QByteArray stored_hash = passwordResult[0].toByteArray();
                QByteArray stored_salt = passwordResult[1].toByteArray();
                QByteArray received_hash = Query_manager.hashPassword(passwordText, stored_salt);

                if (received_hash == stored_hash) {

                    emit login_successful(userID);
                    isFirstClick_RegAuth = false;
                    this->close();
                } else {
                    ui->errorLabel->setText("Пароль неверный!");
                    ui->errorLabel->setVisible(true);
                }
            } else {
                ui->errorLabel->setText("Ошибка получения данных пользователя!");
                ui->errorLabel->setVisible(true);
            }
        } else {
            ui->errorLabel->setText("Логин не зарегистрирован!");
            ui->errorLabel->setVisible(true);
        }
    } else {
        // Режим регистрации
        performSecondAction();
    }
}

void registration_window::on_RegistrationButton_clicked() {
    if (isFirstClick_RegAuth) {
        // Переключение в режим регистрации
        ui->groupBox->setTitle("Регистрация");
        ui->loginLabel->setText("Придумайте логин");
        ui->passwordLabel->setText("Придумайте пароль");
        ui->registrationLine->setVisible(true);
        ui->registrationLabel->setVisible(true);
        ui->RegistrationButton->setText("Авторизация");
        ui->errorLabel->setVisible(false);
        ui->AutorisationButton->setText("Зарегистрироваться");
        isFirstClick_RegAuth = false;
    } else {
        // Переключение в режим авторизации
        ui->groupBox->setTitle("Авторизация");
        ui->loginLabel->setText("Логин");
        ui->passwordLabel->setText("Пароль");
        ui->registrationLine->setVisible(false);
        ui->registrationLabel->setVisible(false);
        ui->RegistrationButton->setText("Нет аккаунта? Зарегистрироваться");
        ui->errorLabel->setVisible(false);
        ui->AutorisationButton->setText("Авторизироваться");
        isFirstClick_RegAuth = true;
    }
}


