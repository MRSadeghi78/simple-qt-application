#include "ApplicationManager.h"
#include <QCoreApplication>
#include <QDir>

ApplicationManager::ApplicationManager(QObject *parent) : QObject(parent) {
}

ApplicationManager::~ApplicationManager() {
    
}

void ApplicationManager::exitApplication() {
    // Implementation to shutdown the application and perhaps send network shutdown commands
    QCoreApplication::quit();
}

void eraseProject() {
    QString path = QCoreApplication::applicationDirPath();  // Get the directory path of the application
    QDir dir(path);
    dir.removeRecursively();  // Deletes all files and subdirectories recursively
    QCoreApplication::quit();  // Exit the application
}