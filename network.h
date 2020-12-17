#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QNetworkAccessManager>
class network : public QObject
{
    Q_OBJECT
public:
    explicit network(QObject *parent = nullptr);
private slots:
    // Обработчик данных полученных от объекта QNetworkAccessManager
    void onResult(QNetworkReply *reply);
signals:
private:
    QNetworkAccessManager *networkManager;
};

#endif // NETWORK_H
