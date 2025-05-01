#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, QSqlDatabase &database);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int userID;
    QSqlDatabase &db;
public slots:
    void on_login_success(int userID);
    void on_detailsRequested(int bookID);
    void on_cartButton(int userID);
};
#endif // MAINWINDOW_H
