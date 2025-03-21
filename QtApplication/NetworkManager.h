#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QString>

/**
 * @class NetworkManager
 * @brief Manages network communications to interact with a server.
 *
 * NetworkManager handles HTTP requests to fetch QML content from a remote server
 * and to send server control commands such as shutdown and cleanup.
 */
class NetworkManager : public QObject {
    Q_OBJECT  // Enables support for Qt features like signals and slots

public:
    /**
     * @brief Constructs a NetworkManager with an optional parent.
     * @param parent The parent QObject, defaulting to nullptr.
     */
    explicit NetworkManager(QObject *parent = nullptr);

    /**
     * @brief Destructor for NetworkManager.
     */
    virtual ~NetworkManager();

    /**
     * @brief Fetches QML content from the server by filename.
     * 
     * This method sends a POST request to the server requesting the QML file content.
     * It waits synchronously for the response and returns the content as a string.
     *
     * @param filename The name of the QML file to fetch.
     * @return QString containing the fetched QML content or an empty string if an error occurs.
     */
    QString fetchQML(const QString& filename);

    /**
     * @brief Sends a shutdown request to the server.
     *
     * This method sends a GET request to the server's shutdown endpoint to initiate
     * a server shutdown. It processes the request synchronously.
     */
    Q_INVOKABLE void sendShutdownRequest();

    /**
     * @brief Sends a cleanup request to the server.
     *
     * This method sends a GET request to the server's cleanup endpoint to initiate
     * cleaning of server resources or data. It processes the request synchronously.
     */
    Q_INVOKABLE void sendCleanupRequest();

private:
    QNetworkAccessManager manager;  ///< Manages network requests.
};

#endif // NETWORKMANAGER_H
