#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QDir>
#include <QDebug>
#include <QRect>

// 错误类型
enum errorCode {
    CONN_SUCCESS,
    CONN_TIMEOUT,
    DISCONN,
    TRANSFERERR,
    TRY_RECONN,
    SKIPFILE,
    OTHER
};

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0);
    QString currentPath();
    void savePath(QString path);
//    void saveWindowGeometry(QByteArray geo);
//    QByteArray windowGeometry();
    void saveWindowGeometry(QRect geo);
    QRect windowGeometry();
    void saveThemeColor(QString color);
    QString themeColor();
    void saveShowTermsOnStart(bool show);
    bool showTermsOnStart();
    QString buddyName();
    void saveBuddyName(QString name);
    void saveNickname(QString mac, QString nickname);
    QString nickname(QString mac);
    void saveIconPath(QString path);
    QString iconPath();

signals:

public slots:

private:
    QSettings mSettings;

};

#endif // SETTINGS_H
