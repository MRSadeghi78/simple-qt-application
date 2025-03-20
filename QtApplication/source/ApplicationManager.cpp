#include "../headers/ApplicationManager.h"
#include <QCoreApplication>

ApplicationManager::ApplicationManager(QObject *parent) : QObject(parent) {
}

void ApplicationManager::exitApplication() {
    // Implementation to shutdown the application and perhaps send network shutdown commands
    QCoreApplication::quit();
}
