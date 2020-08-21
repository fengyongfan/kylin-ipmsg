#ifndef PEER_H
#define PEER_H

#include <QtNetwork/QHostInfo>

class Peer
{

public:
    Peer() { }

    QString username;
    QString system;
    QString platform;
    QHostAddress address;
    QString mac;
    qint16 port;

    inline Peer(QHostAddress a, QString n, qint16 p) {
        QStringList data = n.split(" ");

        if(data.size() >= 5){
            username = data.at(1);
            system = data.at(2);
            mac = data.at(3);
            platform = data.at(4);
        }

        address = a;
        port = p;
    }
};

#endif // PEER_H
