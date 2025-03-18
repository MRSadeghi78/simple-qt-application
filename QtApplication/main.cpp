#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QUrl>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Set the file path to Main.qml
    QString qmlPath = QDir::currentPath() + "/QtApplication/Main.qml"; // Ensure the QML file is in the same directory

    engine.load(QUrl::fromLocalFile(qmlPath));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
