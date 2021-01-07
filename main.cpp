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

	/*xin chao toi la issue 1
	toi thuoc forder Soure2*/
	/*toi la issue 3
	toi nam trong forder Source
	23333333333
	*/
}
