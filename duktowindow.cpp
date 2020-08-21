#include "duktowindow.h"
#include "guibehind.h"
#include "platform.h"
#include "settings.h"

DuktoWindow::DuktoWindow(QWindow *parent) :
    QmlApplicationViewer(parent), mGuiBehind(NULL){

    this->setTitle(tr("Kylin Ipmsg"));
    this->setIcon(QIcon("/usr/share/pixmaps/kylin-ipmsg.png"));

//    this->setWindowTitle(tr("Kylin Ipmsg"));
//    setWindowTitle("麒麟传书");
//    setWindowIcon(QIcon("/usr/share/pixmaps/kylin-ipmsg.png"));
    QString iconPath = "/usr/share/icons/ukui-icon-theme-default/64x64/apps/kylin-ipmsg.png";
    QFileInfo fi(iconPath);
    if (!fi.exists()) {
        iconPath = "/usr/share/icons/kylin-icon-theme/64x64/apps/kylin-ipmsg.png";
        fi.setFile(iconPath);
        if (!fi.exists()) {
            iconPath = "/usr/share/pixmaps/kylin-ipmsg.png";
        }
    }

    this->setIcon(QIcon(iconPath));

    setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);

    setMaximumWidth(420);
    setMinimumWidth(330);
}

/*
* Summary: set gui reference
* Parameters:
*   ref: gui behind object
* Return :
*/
void DuktoWindow::setGuiBehindReference(GuiBehind* ref){
    mGuiBehind = ref;
}

/*
* Summary:  close event
* Parameters:
*   qt close event
* Return :
*/
void DuktoWindow::closeEvent(QCloseEvent *){
//    mGuiBehind->settings()->saveWindowGeometry(saveGeometry());
    mGuiBehind->settings()->saveWindowGeometry(frameGeometry());
    mGuiBehind->close();

    exit(0);
}
