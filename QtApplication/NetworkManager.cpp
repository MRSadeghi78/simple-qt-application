#include "NetworkManager.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QDebug>

/**
 * Constructor for the NetworkManager class.
 * Initializes the object with a given parent.
 * 
 * @param parent The parent QObject.
 */
NetworkManager::NetworkManager(QObject *parent) : QObject(parent) {
    // Constructor implementation, which is currently empty.
}

/**
 * Destructor for the NetworkManager class.
 */
NetworkManager::~NetworkManager() {
    // Destructor implementation, which is currently empty.
}

/**
 * Fetches QML content from a remote server by sending a POST request.
 * 
 * @param filename The name of the QML file to fetch.
 * @return QString containing the QML content, or an empty string if an error occurs.
 */
QString NetworkManager::fetchQML(const QString& filename) {
    QUrl url("http://localhost:15555/api/v1/getQML"); // URL of the QML content server.
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Prepare JSON payload with filename.
    QJsonObject json;
    json["filename"] = filename;
    QNetworkReply *reply = manager.post(request, QJsonDocument(json).toJson());

    // Use an event loop to wait synchronously for the reply.
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString qmlContent; // Variable to store QML content.
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(response);
        QJsonObject responseObject = doc.object();
        qmlContent = responseObject.contains("content") ? responseObject["content"].toString() : "";
    } else {
        qDebug() << "Error fetching QML: " << reply->errorString();
    }

    reply->deleteLater();
    return qmlContent;
}

/**
 * Sends a shutdown request to the server.
 */
void NetworkManager::sendShutdownRequest() {
    QUrl url("http://localhost:15555/api/shutdown");
    QNetworkRequest request(url);
    QNetworkReply* reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Server shutdown request sent successfully.";
    } else {
        qDebug() << "Failed to send shutdown request: " << reply->errorString();
    }

    reply->deleteLater();
}

/**
 * Sends a cleanup request to the server.
 */
void NetworkManager::sendCleanupRequest() {
    QUrl url("http://localhost:15555/api/cleanup");
    QNetworkRequest request(url);
    QNetworkReply* reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Server cleanup request sent successfully.";
    } else {
        qDebug() << "Failed to send cleanup request: " << reply->errorString();
    }

    reply->deleteLater();
}
