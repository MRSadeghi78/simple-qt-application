#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include <QObject>

/**
 * @class ApplicationManager
 * @brief Manages application-level actions such as exiting and cleaning up project files.
 *
 * ApplicationManager provides functionality to control application behavior,
 * including exiting the application and removing all project-related files.
 * This class is designed to be used within a Qt application environment.
 */
class ApplicationManager : public QObject {
    Q_OBJECT  // Enables Qt features like signals and slots

public:
    /**
     * @brief Constructs the ApplicationManager object.
     * @param parent The parent QObject, default is nullptr for top-level objects.
     */
    explicit ApplicationManager(QObject *parent = nullptr);

    /**
     * @brief Destroys the ApplicationManager object.
     */
    virtual ~ApplicationManager();

    /**
     * @brief Exits the application.
     *
     * This function quits the application by stopping the main event loop,
     * effectively shutting down the application.
     */
    Q_INVOKABLE void exitApplication();

    /**
     * @brief Deletes all files within the project directory and exits the application.
     *
     * This function is intended for complete cleanup of the application's running
     * environment, removing all project files and then exiting. Use with caution
     * as it will delete all files in the project directory permanently.
     */
    Q_INVOKABLE void eraseProject();
};

#endif // APPLICATIONMANAGER_H
