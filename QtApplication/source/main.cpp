#include "NetworkManager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    

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
