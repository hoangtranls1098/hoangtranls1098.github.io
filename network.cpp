#include "network.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>
network::network(QObject *parent) : QObject(parent)
{
         networkManager = new QNetworkAccessManager();
       // Connect networkManager response to the handler
       connect(networkManager, &QNetworkAccessManager::finished, this, &network::onResult);
       // We get the data, namely JSON file from a site on a particular url
       networkManager->get(QNetworkRequest(QUrl("https://api.covid19api.com/summary")));
}

void network::onResult(QNetworkReply *reply)
{   qDebug()<<"root";
    qDebug()<<reply->readAll();
//     if(!reply->error()){

//          QJsonDocument document = QJsonDocument::fromJson(reply->readAll());

//             QJsonObject root = document.object();
//     qDebug()<<root;
//     }
}
