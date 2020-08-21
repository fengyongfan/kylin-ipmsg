#ifndef QMLAPPLICATIONVIEWER_H
#define QMLAPPLICATIONVIEWER_H
#include <qglobal.h>

#include <QCoreApplication>
#include <QGuiApplication>
#include <QQuickView>

class QmlApplicationViewer : public QQuickView
{
    Q_OBJECT

public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit QmlApplicationViewer(QWindow *parent = 0);
    virtual ~QmlApplicationViewer();

    static QmlApplicationViewer *create();

    void setMainQmlFile(const QString &file);
    void addImportPath(const QString &path);

    // Note that this will only have an effect on Fremantle.
    void setOrientation(ScreenOrientation orientation);

    void showExpanded();

private:
    explicit QmlApplicationViewer(QQuickView *view, QWindow *parent);
    class QmlApplicationViewerPrivate *d;
};

QGuiApplication *createApplication(int &argc, char **argv);

#endif // QMLAPPLICATIONVIEWER_H
