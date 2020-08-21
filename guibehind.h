#ifndef GUIBEHIND_H
#define GUIBEHIND_H

#include <QObject>
#include <QNetworkInterface>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QHostInfo>
#include <QQuickView>
#include <QQmlProperty>
#include <QQmlContext>
#include <QDesktopServices>
#include <QFileDialog>
#include <QApplication>
#include <QDesktopWidget>
#include <QStringList>
#include <QThread>
#include <QHash>
#include <QIcon>
#include <QTimer>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>

#include "buddylistitemmodel.h"
#include "recentlistitemmodel.h"
#include "ipaddressitemmodel.h"
#include "theme.h"
#include "chatwidget.h"
#include "peer.h"
#include "ksocket.h"

#define NETWORK_PORT 9696
#define UDP_BROADCAST 0x01
#define UDP_UNICAST 0x02
#define UDP_GOODBYE 0x03

class MiniWebServer;
class Settings;
class DuktoWindow;
class QNetworkAccessManager;
class QNetworkReply;
class DuktoProtocol;
class KTcpServer;


class GuiBehind : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentPath READ currentPath NOTIFY currentPathChanged)
    Q_PROPERTY(QString iconPath READ iconPath WRITE setIconPath NOTIFY iconPathChanged)

public:
    explicit GuiBehind(DuktoWindow* view);
    virtual ~GuiBehind();

    // 管理所有的Tcp连接
    QMap<QString, KSocket *> sockets;
    // 好友列表界面model
    BuddyListItemModel mBuddiesList;
    // 管理所有的聊天窗口
    QMap<QString, ChatWidget *> cws;
    QMap<QString, QStringList> tmpMsgs;

    inline Settings* settings() { return mSettings; }
    QString currentPath();
    void setCurrentPath(QString path);
    QString sizeHuman(qint64 size);
    void close();

    QString iconPath();
    void setIconPath(QString path);

    ChatWidget * createCW(QString mac);

signals:
    void currentPathChanged();
    void iconPathChanged();

public slots:
    void periodicHello();
    void peerListAdded(Peer peer);
    void peerListRemoved(Peer peer);

    void openDestinationFolder();
    void refreshIpList();
    void changeDestinationFolder();
    void showSendPage(QString ip_mac);
    void changeThemeColor(QString color);

    void receiveTextComplete(QString text, QString mac);
    void receiveFileComplete(QStringList *files, qint64 totalSize, QString dir, QString mac);
    void reSaveCw(QString ip);
    void newMsgAlert(QString mac);
    void removeRecentItem(QString mac);
    void msgAlert();

private:
    DuktoWindow *mView;
    QTimer *mPeriodicHelloTimer;
    MiniWebServer *mMiniWebServer;
    Settings *mSettings;
    RecentListItemModel mRecentList;
    IpAddressItemModel mIpAddresses;
    DuktoProtocol *mDuktoProtocol;
    Theme mTheme;

    int cwx;
    int cwy;
    int timeFlag;
    QTimer *alertTimer;
    QIcon iconDukto;
    QIcon iconBlank;
};


class DuktoProtocol : public QObject
{
    Q_OBJECT

public:
    DuktoProtocol(GuiBehind *gb);
    virtual ~DuktoProtocol();
    void initialize();
    void sayHello(QHostAddress dest);
    void sayGoodbye();

    // 废弃的KSocket列表
    QList<KSocket *> discardSockets;

    GuiBehind *gbehind;

    QString pSystemSignature;

public slots:
    void newUdpData();
    void newIncomingConnection(qintptr socketDescriptor);
    void newOutgoingConnection(QString targetIP, QString remoteID, ChatWidget *cw);
    void updateRemoteID(QString, KSocket*);
    void updateSockets(QString pRemoteID);
    void addUpBuddy(QString, QString);

    // 绑定聊天窗口和socket
    void connectSocketAndChatWidget(ChatWidget *);

signals:
    void peerListAdded(Peer peer);
    void peerListRemoved(Peer peer);

private:
    QString getSystemSignature();
    QString getMac();
    void sendToAllBroadcast(QByteArray *packet);
    void handleMessage(QByteArray &data, QHostAddress &sender);

    QUdpSocket *mSocket;
    KTcpServer *mTcpServer;

    QHash<QString, Peer> mPeers;
};


class KTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    KTcpServer();

protected:
    void incomingConnection(qintptr socketDescriptor);

signals:
    void newConn(qintptr socketDescriptor);
};

#endif // GUIBEHIND_H
