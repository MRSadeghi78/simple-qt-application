#include "NetworkManager.h"
#include "TimerManager.h"
#include "ApplicationManager.h"
#include "USBManager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>

/**
 * @brief Entry point for the Qt application.
 *
 * Sets up the application environment, initializes managers for network,
 * timing, application control, and USB devices, and loads the QML UI.
 *
 * @param argc Number of arguments
 * @param argv Array of argument strings
 * @return Integer exit code for the application
 */
int main(int argc, char *argv[])
{
    // Enable high DPI scaling for devices with high pixel density screens.
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // Initialize the GUI application with provided arguments.
    QGuiApplication app(argc, argv);

    // Create manager instances to handle various functionalities.
    NetworkManager networkManager; // Manages network operations.
    TimerManager timerManager;     // Manages timing functionalities.
    ApplicationManager appManager; // Handles application-wide actions.
    USBManager usbManager;         // Manages USB device interactions.

    // Fetch the main QML content from the network.
    QString qmlContent = networkManager.fetchQML("Main.qml");

    // Check if the QML content was successfully loaded.
    if (qmlContent.isEmpty()) {
        qDebug() << "Failed to load QML file.";
        return -1; // Exit if no content is loaded.
    }

    // Setup the QML application engine.
    QQmlApplicationEngine engine;

    // Register manager objects with the QML context so they can be used in QML.
    engine.rootContext()->setContextProperty("timerManager", &timerManager);
    engine.rootContext()->setContextProperty("appManager", &appManager);
    engine.rootContext()->setContextProperty("networkManager", &networkManager);
    engine.rootContext()->setContextProperty("usbManager", &usbManager);

    // Load the QML content into the application engine.
    engine.loadData(qmlContent.toUtf8());

    // Check if the root object is successfully created.
    if (engine.rootObjects().isEmpty()) {
        return -1; // Exit if no root object, indicating an issue with QML loading.
    }

    // Enter the main event loop.
    return app.exec();
}
