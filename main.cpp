#include <qglobal.h>
#include <QtWidgets/QApplication>
#include <QTranslator>
#include <QLocale>
#include <QDebug>

#include "qtsingleapplication.h"
#include "qmlapplicationviewer.h"
#include "guibehind.h"
#include "duktowindow.h"


int main(int argc, char *argv[])
{
//    QApplication::setGraphicsSystem("raster");

    #if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    #endif

    QtSingleApplication app(argc, argv);
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    // 国际化
    QString locale = QLocale::system().name();
    QTranslator trans_global, trans_menu;
    if(locale == "zh_CN"){
        trans_global.load(":/qml/kylin-ipmsg_zh_CN.qm");
        trans_menu.load(":/qml/qt_zh_CN.qm");
        app.installTranslator(&trans_global);
        app.installTranslator(&trans_menu);
    }

    // 单例判断
    if (app.isRunning()) {
        app.sendMessage("FOREGROUND");
        return 0;
    }

    app.setWindowIcon(QIcon("/usr/share/pixmaps/kylin-ipmsg.png"));

    DuktoWindow viewer;
//    app.setActivationWindow(&viewer, true);

    GuiBehind gb(&viewer);

    viewer.showExpanded();
    viewer.raise();
    app.installEventFilter(&gb);

    return app.exec();
}
