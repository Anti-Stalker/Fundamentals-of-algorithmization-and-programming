QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arrow.cpp \
    background.cpp \
    baraban.cpp \
    car.cpp \
    game.cpp \
    key.cpp \
    letters.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    prize.cpp \
    prizeimage.cpp

HEADERS += \
    arrow.h \
    background.h \
    baraban.h \
    car.h \
    game.h \
    key.h \
    letters.h \
    mainwindow.h \
    player.h \
    prize.h \
    prizeimage.h

FORMS += \
    game.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    tasks.txt
