#include "NetworkManager.h"
#include "TimerManager.h"
#include "ApplicationManager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    

    NetworkManager networkManager; // Create an instance of NetworkManager to handle network operations.
    TimerManager timerManager;
    ApplicationManager appManager;
    
    QString qmlContent = networkManager.fetchQML("Main.qml");

    if (qmlContent.isEmpty()) {
        qDebug() << "Failed to load QML file.";
        return -1;
    }

    // Load QML content into engine
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("timerManager", &timerManager);
    engine.rootContext()->setContextProperty("appManager", &appManager);
    engine.rootContext()->setContextProperty("networkManager", &networkManager);

    engine.loadData(qmlContent.toUtf8());
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
