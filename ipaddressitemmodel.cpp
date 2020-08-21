#include "ipaddressitemmodel.h"


IpAddressItemModel::IpAddressItemModel() :
    QStandardItemModel(NULL)
{
    QHash<int, QByteArray> roleNames;
    roleNames[Ip] = "ip";
    setItemRoleNames(roleNames);

    refreshIpList();
}

/*
* Summary: add a ip address
* Parameters:
*   ip: ip address
* Return :
*/
void IpAddressItemModel::addIp(QString ip)
{
    QStandardItem* it = new QStandardItem();
    it->setData(ip, IpAddressItemModel::Ip);
    appendRow(it);
}

/*
* Summary: refresh ip list
* Return :
*/
void IpAddressItemModel::refreshIpList()
{
    clear();

    QList<QHostAddress> addrs = QNetworkInterface::allAddresses();
    for (int i = 0; i < addrs.length(); i++)
        if ((addrs[i].protocol() == QAbstractSocket::IPv4Protocol) && (addrs[i].toString() != "127.0.0.1")){
            addIp(addrs[i].toString());
            if (addrs[i].toString().contains("192.168")) {
                this->myIp = addrs[i].toString();
                qDebug() << addrs[i].toString();
                break;
            }
        }
}
