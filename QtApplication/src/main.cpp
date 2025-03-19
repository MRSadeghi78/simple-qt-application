#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "NetworkManager.h"

/**
 * Main function of the Qt Application.
 * Initializes the application and loads QML content fetched from a server.
 * 
 * @param argc Argument count
 * @param argv Argument vector
 * @return Application exit status
 */
int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // Enable high DPI scaling for high-resolution displays.
    QGuiApplication app(argc, argv); // Create a GUI application instance.

    NetworkManager networkManager; // Create an instance of NetworkManager to handle network operations.
    QString qmlContent = networkManager.fetchQML("Main.qml"); // Fetch QML content from the FastAPI server.

    if (qmlContent.isEmpty()) {
        qDebug() << "Failed to load QML file."; // Log an error if no QML content is fetched.
        return -1; // Exit the application with an error status.
    }

    QQmlApplicationEngine engine; // Create a QML application engine.
    engine.loadData(qmlContent.toUtf8()); // Load the QML content into the engine.
    if (engine.rootObjects().isEmpty()) {
        return -1; // Exit if no root QML objects are loaded.
    }

    return app.exec(); // Start the event loop.
}
