//#include "infor_each_country.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "network.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
/*---------------------------------------------------------------------------------*/

network a;

    engine.load(url);

    return app.exec();
}
