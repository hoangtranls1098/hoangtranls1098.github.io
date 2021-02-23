#include "animal.h"
#include <QGuiApplication>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    AnimalModel model;
    model.addAnimal(Animal("Wolf","Medium"));
    model.addAnimal(Animal("Polar bear", "Large"));
    model.addAnimal(Animal("Quoll", "Small"));

    QQuickView view;
    QQmlContext *root = view.rootContext();
    root->setContextProperty("model123",&model);
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();
    return app.exec();
}
