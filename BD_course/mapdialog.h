#ifndef MAPDIALOG_H
#define MAPDIALOG_H

#include <QDialog>
#include <QWebEngineView>
#include <QWebChannel>

QT_BEGIN_NAMESPACE
namespace Ui { class MapDialog; }
QT_END_NAMESPACE

class WebBridge;

class MapDialog : public QDialog {
    Q_OBJECT

public:
    explicit MapDialog(QWidget *parent = nullptr);
    ~MapDialog();
    QString getSelectedAddress();

signals:
    void addressConfirmed(const QString &coords);

private:
    Ui::MapDialog *ui;
    QWebEngineView *webView;
    WebBridge *bridge;
    QString selectedAddress;
//public slots:
//    void on_сonfirmClicked();
};

class WebBridge : public QObject {
    Q_OBJECT
public:
    explicit WebBridge(QObject *parent = nullptr) : QObject(parent) {}

signals:
    void locationSelected(const QString &coords);

public slots:
    void receiveCoords(const QString &coords) {
        emit locationSelected(coords);
    }
};
#endif // MAPDIALOG_H
