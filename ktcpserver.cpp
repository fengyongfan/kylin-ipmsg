#include "guibehind.h"


KTcpServer::KTcpServer()
{
    this->setMaxPendingConnections(200);
}

/*
* Summary: incoming a new connection
* Parameters:
*   socketdescriptor: qt socket descriptor
* Return :
*/
void KTcpServer::incomingConnection(qintptr socketDescriptor){
    qDebug() << "incomingConnection" << socketDescriptor;
    emit newConn(socketDescriptor);
}
