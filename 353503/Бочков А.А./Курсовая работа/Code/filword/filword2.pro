QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bor.cpp \
    level.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    qmessagequestion.cpp

HEADERS += \
    bor.h \
    level.h \
    mainwindow.h \
    player.h \
    qmessagequestion.h

FORMS += \
    level.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../russian-nouns.txt \
    ../untitled3/resource/фон2.jpeg \
    ../Документы/Статистика.txt \
    russian-nouns.txt \
    Статистика.txt \
    фон2.jpeg
