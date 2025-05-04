#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "book.h"
#include <QMainWindow>
#include <QtSql>
#include <QSqlQuery>
#include <QWebEngineView>
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
    void refreshCart();
    void showBooksForOrder(const QVector<Book>& booksToOrder);
private:
    Ui::MainWindow *ui;
    int userID;
    QSqlDatabase &db;
    QWebEngineView *webView = nullptr;
public slots:
    void on_login_success(int userID);
    void on_detailsRequested(int bookID);
    void on_cartButton();
    void on_lobbyButton();
    void on_addToCart(int bookID);
    void on_removeFromCart(int bookId);
    void on_singleOrderRequested(int bookID);

};
#endif // MAINWINDOW_H
