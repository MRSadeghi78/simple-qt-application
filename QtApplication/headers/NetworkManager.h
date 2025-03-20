#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QNetworkAccessManager>
#include <QString>
#include <QObject>

/**
 * NetworkManager class.
 * Handles network operations to fetch QML content from a specified server.
 */
class NetworkManager : public QObject {
    Q_OBJECT

public:
    NetworkManager(); // Constructor
    QString fetchQML(const QString& filename); // Method to fetch QML content by filename.
    Q_INVOKABLE void sendShutdownRequest();  // Method to send a shutdown request to the server

private:
    QNetworkAccessManager manager; // Network access manager to handle requests.
};

#endif // NETWORKMANAGER_H
