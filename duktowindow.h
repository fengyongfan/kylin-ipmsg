#ifndef DUKTOWINDOW_H
#define DUKTOWINDOW_H

#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QDebug>
#include <QQuickWindow>

#include "qmlapplicationviewer/qmlapplicationviewer.h"

class GuiBehind;

class DuktoWindow : public QmlApplicationViewer
{
    Q_OBJECT

public:
    explicit DuktoWindow(QWindow *parent = 0);
    void setGuiBehindReference(GuiBehind* ref);

protected:
    void closeEvent(QCloseEvent *event);

signals:

public slots:

private:
    GuiBehind *mGuiBehind;
};

#endif // DUKTOWINDOW_H
