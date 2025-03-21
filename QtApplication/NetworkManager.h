#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QNetworkAccessManager>
#include <QString>
#include <QObject>

/**
 * NetworkManager class.
 * Handles network operations to fetch QML content from a specified server.
 */
class NetworkManager: public QObject{
    Q_OBJECT

public:
    explicit NetworkManager(QObject *parent = nullptr);
    virtual ~NetworkManager();

    QString fetchQML(const QString& filename); // Method to fetch QML content by filename.
    Q_INVOKABLE void sendShutdownRequest();
    Q_INVOKABLE void sendCleanupRequest();

private:
    QNetworkAccessManager manager; // Network access manager to handle requests.
};

#endif // NETWORKMANAGER_H
