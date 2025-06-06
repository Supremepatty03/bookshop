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
    void loadProfileCombos();
    void saveUserProfile();
    void showUserOrders();
    void showAdminBookList();
    void populateComboBoxes();
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
    QString on_addNewAdressButton ();
    void on_orderCancelButton();
    void on_confirmOrderButton(int bookID);
    void on_profileButton();
    void on_outProfileButton();
    void on_returnFromUsersOrderButton();
    void onDeleteBook(int bookId);
    void on_addButton_clicked();
    void on_addDeclinedButton();
    void on_AdminButton();
};
#endif // MAINWINDOW_H
