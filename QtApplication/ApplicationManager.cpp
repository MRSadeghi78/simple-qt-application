#include "ApplicationManager.h"
#include <QCoreApplication>
#include <QDir>

/**
 * @brief Constructs the ApplicationManager object.
 * 
 * @param parent Parent object in the QObject hierarchy. Default is nullptr.
 */
ApplicationManager::ApplicationManager(QObject *parent) : QObject(parent) {
    // Constructor implementation, currently empty.
}

/**
 * @brief Destructor for the ApplicationManager.
 */
ApplicationManager::~ApplicationManager() {
    // Destructor implementation, currently empty.
}

/**
 * @brief Exits the application by quitting the main event loop.
 */
void ApplicationManager::exitApplication() {
    // Quit the main application event loop, effectively shutting down the application.
    QCoreApplication::quit();
}

/**
 * @brief Deletes the project directory and all its contents, then exits the application.
 * 
 * This function first ascends to the parent directory of the application's executable,
 * then recursively deletes all files and subdirectories starting from there.
 */
void ApplicationManager::eraseProject() {
    // Get the directory path of the application's executable.
    QString path = QCoreApplication::applicationDirPath();
    
    // Create a QDir object starting at the executable's directory.
    QDir dir(path);

    // Move up one directory level to include all project files.
    dir.cdUp();

    // Recursively delete all files and subdirectories in the directory.
    dir.removeRecursively();

    // Exit the application after cleanup.
    QCoreApplication::quit();
}
