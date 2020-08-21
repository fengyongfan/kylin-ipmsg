#ifndef PLATFORM_H
#define PLATFORM_H

#include <qglobal.h>
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

class QString;


class Platform
{
public:
    static QString getSystemUsername();
    static QString getHostname();
    static QString getPlatformName();
    static QString getAvatarPath();
    static QString getDefaultPath();

    Platform() {}
#if defined(Q_OS_UNIX)
    static QString getLinuxAvatarPath();
#elif defined(Q_WS_MAC)
    static QString getMacTempAvatarPath();
#elif defined(Q_WS_WIN)
    static QString getWinTempAvatarPath();
#endif
};

#endif // PLATFORM_H
