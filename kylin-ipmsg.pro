include(qmlapplicationviewer/qmlapplicationviewer.pri)

QT += core gui network

lessThan(QT_MAJOR_VERSION, 5) {
 QT += declarative
} else {
 QT += widgets quick qml
}

#for nullptr
greaterThan(QT_MAJOR_VERSION, 4): CONFIG += c++11

VERSION = 1.0.12

TRANSLATIONS = kylin-ipmsg_zh_CN.ts

TARGET = kylin-ipmsg

target.path = /usr/bin
target.source += $$TARGET
icon.path = /usr/share/pixmaps
icon.files = kylin-ipmsg.png
desktop.path = /usr/share/applications/
desktop.files = kylin-ipmsg.desktop

INSTALLS += target \
    icon \
    desktop

SOURCES += main.cpp \
    guibehind.cpp \
    platform.cpp \
    buddylistitemmodel.cpp \
    duktoprotocol.cpp \
    miniwebserver.cpp \
    ipaddressitemmodel.cpp \
    recentlistitemmodel.cpp \
    settings.cpp \
    destinationbuddy.cpp \
    duktowindow.cpp \
    theme.cpp \
    chatwidget.cpp \
    ktcpserver.cpp \
    ksocket.cpp

HEADERS += \
    guibehind.h \
    platform.h \
    buddylistitemmodel.h \
    peer.h \
    miniwebserver.h \
    ipaddressitemmodel.h \
    recentlistitemmodel.h \
    settings.h \
    destinationbuddy.h \
    duktoprotocol.h \
    duktowindow.h \
    theme.h \
    chatwidget.h \
    ksocket.h

FORMS += \
    chatwidget.ui

RESOURCES += \
    qml.qrc

include(qtsingleapplication/qtsingleapplication.pri)

lupdate_only{
    SOURCES = qml/dukto/*.qml
}
