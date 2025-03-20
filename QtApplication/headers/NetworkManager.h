#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QNetworkAccessManager>
#include <QString>

/**
 * NetworkManager class.
 * Handles network operations to fetch QML content from a specified server.
 */
class NetworkManager{

public:
    NetworkManager(); // Constructor
    QString fetchQML(const QString& filename); // Method to fetch QML content by filename.

private:
    QNetworkAccessManager manager; // Network access manager to handle requests.
};

#endif // NETWORKMANAGER_H
