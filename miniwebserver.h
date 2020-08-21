#ifndef MINIWEBSERVER_H
#define MINIWEBSERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QStringList>
#include <QDateTime>
#include <QFile>
#include <QImage>
#include <QBuffer>

#include "guibehind.h"


class MiniWebServer : public QTcpServer
{
    Q_OBJECT

public:
    MiniWebServer();

protected:
    virtual void incomingConnection(qintptr handle);

private slots:
     void readClient();
     void discardClient();

private:
     QByteArray mAvatarData;

};

#endif // MINIWEBSERVER_H
