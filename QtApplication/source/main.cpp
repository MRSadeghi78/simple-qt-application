#include "NetworkManager.h"
#include "ApplicationManager.h"
#include "TimerManager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QUrl>
#include <QDir>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // new
    qmlRegisterType<TimerManager>("com.yourcompany.timer", 1, 0, "TimerManager");
    qmlRegisterType<ApplicationManager>("com.yourcompany.system", 1, 0, "ApplicationManager");
    qmlRegisterType<NetworkManager>("com.yourcompany.network", 1, 0, "NetworkManager");

    NetworkManager networkManager; // Create an instance of NetworkManager to handle network operations.
    QString qmlContent = networkManager.fetchQML("Main.qml");

    if (qmlContent.isEmpty()) {
        qDebug() << "Failed to load QML file.";
        return -1;
    }

    // Load QML content into engine
    QQmlApplicationEngine engine;
    engine.loadData(qmlContent.toUtf8());
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
