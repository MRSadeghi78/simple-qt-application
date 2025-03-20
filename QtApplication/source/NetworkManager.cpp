#include "NetworkManager.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QDebug>

NetworkManager::NetworkManager() {} // Constructor

/**
 * Fetches QML content from a remote server.
 *
 * @param manager Reference to QNetworkAccessManager managing network requests.
 * @param filename Name of the file to fetch.
 * @return String containing the QML content.
 */
QString NetworkManager::fetchQML(const QString& filename) {
    QUrl url("http://localhost:15555/api/v1/getQML"); // URL of the QML content server.
    QNetworkRequest request(url); // Create a request object.
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json"); // Set content type of the request.

    // Prepare JSON payload with filename.
    QJsonObject json;
    json["filename"] = filename;
    QNetworkReply *reply = manager.post(request, QJsonDocument(json).toJson()); // Send POST request.

    // Use an event loop to wait synchronously for the reply.
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString qmlContent; // Variable to store QML content.
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll(); // Read response data.
        QJsonDocument doc = QJsonDocument::fromJson(response); // Convert response to JSON.
        QJsonObject responseObject = doc.object();
        if (responseObject.contains("content")) {
            qmlContent = responseObject["content"].toString(); // Extract QML content.
        }
    } else {
        qDebug() << "Error fetching QML: " << reply->errorString(); // Log error.
        qmlContent = "";
    }

    reply->deleteLater(); // Cleanup reply object.
    return qmlContent;
}

void NetworkManager::sendShutdownRequest() {
    QUrl url("http://localhost:15555/api/shutdown");  // URL for the shutdown endpoint
    QNetworkRequest request(url);
    QNetworkReply* reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Server shutdown request sent successfully.";
    } else {
        qDebug() << "Failed to send shutdown request:" << reply->errorString();
    }

    reply->deleteLater();
}
