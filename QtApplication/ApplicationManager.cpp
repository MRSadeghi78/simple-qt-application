#include "ApplicationManager.h"
#include <QCoreApplication>

ApplicationManager::ApplicationManager(QObject *parent) : QObject(parent) {
}

ApplicationManager::~ApplicationManager() {
    
}

void ApplicationManager::exitApplication() {
    // Implementation to shutdown the application and perhaps send network shutdown commands
    QCoreApplication::quit();
}
