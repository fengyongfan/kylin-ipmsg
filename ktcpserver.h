#ifndef KTCPSERVER_H
#define KTCPSERVER_H

#include <QObject>
#include <QtNetwork>

class KTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    KTcpServer();

protected:
    void incomingConnection(int socketDescriptor);
};

#endif // KTCPSERVER_H
