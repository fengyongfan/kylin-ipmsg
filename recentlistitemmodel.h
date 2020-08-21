#ifndef RECENTLISTITEMMODEL_H
#define RECENTLISTITEMMODEL_H

#include <QStandardItemModel>
#include <QDateTime>


class RecentListItemModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit RecentListItemModel();
    void addRecent(QString name, QString value, QString type, QString sender, qint64 size, QString senderIp);

    enum RecentRoles {
        Name = Qt::UserRole + 1,
        Value,
        Type,
        TypeIcon,
        DateTime,
        Sender,
        Size,
        Mac
    };
};

#endif // RECENTLISTITEMMODEL_H
