#include "mapdialog.h"
#include "ui_mapdialog.h"
#include <QWebChannel>
#include <QFile>
#include <QUrl>
#include <QDebug>
#include <QWebEngineView>
#include <QWebEngineSettings>

MapDialog::MapDialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::MapDialog),
    webView(new QWebEngineView(this)),
    bridge(new WebBridge(this))
{
    ui->setupUi(this);

    ui->verticalLayout->insertWidget(0, webView);

    connect(ui->confirmButton, &QPushButton::clicked, this, [this]{
        emit addressConfirmed(selectedAddress);
        this->accept();
    });

    connect(bridge, &WebBridge::locationSelected, this, [this](const QString &coords){
        selectedAddress = coords;
        ui->textAddres->setText(coords);
    });

    QWebChannel *channel = new QWebChannel(webView->page());
    channel->registerObject("bridge", bridge);
    webView->page()->setWebChannel(channel);

    webView->page()->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);
    webView->page()->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    webView->page()->settings()->setAttribute(QWebEngineSettings::JavascriptCanOpenWindows, true);

    QString htmlPath = QCoreApplication::applicationDirPath() + "/sdek_widget.html";

    QFile file(htmlPath);
    if (!file.exists()) {
        qDebug() << "HTML не найден по пути:" << htmlPath;
        return;
    }

    qDebug() << "Загрузка HTML из:" << htmlPath;

    connect(webView, &QWebEngineView::loadFinished, this, [](bool ok) {
        if (ok) {
            qDebug() << "Карта успешно загружена.";
        } else {
            qDebug() << "Ошибка загрузки карты!";
        }
    });

    webView->load(QUrl::fromLocalFile(htmlPath));
}

QString MapDialog::getSelectedAddress() {
    return selectedAddress;
}
MapDialog::~MapDialog() {
    if (webView) {
        webView->stop();           // Остановить загрузки
        webView->setHtml("");      // Очистить содержимое
        webView->deleteLater();    // Безопасное удаление
        webView = nullptr;
    }

    delete ui;
}
#include "mapdialog.moc"
