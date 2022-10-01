#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "iostream"
#include "Handler.h"
#include "Karbar.h"
#include "darslist.h"
#include "darsmodel.h"
#include "azmoonlist.h"
#include "azmoonmodel.h"
#include "daneshjoolist.h"
#include "daneshjoomodel.h"

// ta inja

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<DarsModel>("Darsha",1,0,"DarsModel");
    qmlRegisterUncreatableType<DarsList>("Darsha",1,0,"DarsList",
    QStringLiteral("DarsList should not be created in QML"));



    qmlRegisterType<AzmoonModel>("Azmoonha",1,0,"AzmoonModel");
    qmlRegisterUncreatableType<AzmoonList>("Azmoonha",1,0,"AzmoonList" ,
    QStringLiteral("AzmoonList should not be created in QML"));

    qmlRegisterType<DaneshjooModel>("Daneshjooha",1,0,"DaneshjooModel");
    qmlRegisterUncreatableType<DaneshjooList>("Daneshjooha",1,0,"DaneshjooList",
     QStringLiteral ("Daneshjooha should not be created in QML"));


    DarsList darsList;
    AzmoonList azmoonList;
    DaneshjooList daneshjooList ;
    QQmlApplicationEngine engine;

    Handler MyHandler;

    MyHandler.ReadAllInformation();


    //
    auto root_contex = engine.rootContext();
    root_contex->setContextProperty("MyHandler" , &MyHandler);






    engine.rootContext()->setContextProperty(QStringLiteral("daneshjooList"),&daneshjooList);
    engine.rootContext()->setContextProperty(QStringLiteral("azmoonList"),&azmoonList);
    engine.rootContext()->setContextProperty(QStringLiteral("darsList") , &darsList);
    // engine.load(QUrl(QLatin1String("qrc:/AsliDaneshjoo.qml")));
      //    if(engine.rootObjects().isEmpty() )
     //     {
     //         return -1;
      //    }





    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
            &app, [url](QObject *obj, const QUrl &objUrl) {
       if (!obj && url == objUrl)
           QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);



    engine.load(url);

    return app.exec();
}
