#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "datastore.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();
    DataStore dt;
    context->setContextProperty("dataStore",&dt);
    engine.load(QUrl(QStringLiteral("qrc:/datastore.qml")));
    return app.exec();
}
