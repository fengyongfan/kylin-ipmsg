#include "destinationbuddy.h"
#include "buddylistitemmodel.h"


DestinationBuddy::DestinationBuddy(QObject *parent) :
    QObject(parent)
{
}

/*
* Summary: fill friend from item
* Parameters:
*   item: friend item
* Return :
*/
void DestinationBuddy::fillFromItem(QStandardItem *item)
{
    mIp = item->data(BuddyListItemModel::Ip).toString();
    mPort = item->data(BuddyListItemModel::Port).toInt();
    mIptext = item->data(BuddyListItemModel::Iptext).toString();
    mUsername = item->data(BuddyListItemModel::Username).toString();
    mSystem = item->data(BuddyListItemModel::System).toString();
    mPlatform = item->data(BuddyListItemModel::Platform).toString();
    mGenericAvatar = item->data(BuddyListItemModel::GenericAvatar).toString();
    mAvatar = item->data(BuddyListItemModel::Avatar).toString();
    mOsLogo = item->data(BuddyListItemModel::OsLogo).toString();
    mShowBack = item->data(BuddyListItemModel::ShowBack).toString();
    emit ipChanged();
    emit portChanged();
    emit iptextChanged();
    emit usernameChanged();
    emit systemChanged();
    emit platformChanged();
    emit genericAvatarChanged();
    emit avatarChanged();
    emit osLogoChanged();
    emit showBackChanged();
}

