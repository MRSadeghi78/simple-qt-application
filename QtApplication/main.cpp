#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QUrl>
#include <QDir>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>

void fetchQML(QNetworkAccessManager &manager, const QString &filename, QString &qmlContent) {
    QUrl url("http://localhost:15555/api/v1/getQML");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Create the JSON payload
    QJsonObject json;
    json["filename"] = filename;
    QNetworkReply *reply = manager.post(request, QJsonDocument(json).toJson());

    // Wait for the reply
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec(); // Blocks here until the request is finished

    // Handle the response
    if (reply->error() == QNetworkReply::NoError) {
        // Read the QML content from the server response
        QByteArray response = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(response);
        QJsonObject responseObject = doc.object();
        if (responseObject.contains("content")) {
            qmlContent = responseObject["content"].toString();
        } else {
            qmlContent = "";
        }
    } else {
        qmlContent = "";
        qDebug() << "Error fetching QML: " << reply->errorString();
    }

    reply->deleteLater();
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // Set up the network manager
    QNetworkAccessManager manager;

    QString qmlContent;
    fetchQML(manager, "Main.qml", qmlContent);  // Fetch the QML file from the server

    if (qmlContent.isEmpty()) {
        qDebug() << "Failed to load QML file.";
        return -1;
    }

    // Load QML content into engine
    QQmlApplicationEngine engine;
    engine.loadData(qmlContent.toUtf8());
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
