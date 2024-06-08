    QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    gamescene.cpp \
    main.cpp \
    menuscene.cpp \
    view.cpp

HEADERS += \
    Point.h \
    game.h \
    gamescene.h \
    menuscene.h \
    view.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/back_description.png \
    images/back_text.png \
    images/bg_beach.png \
    images/bg_gameover.png \
    images/bg_pause.png \
    images/cursor.png \
    images/frame.png \
    images/left_description.png \
    images/mute_text.png \
    images/numbers.png \
    images/options_text.png \
    images/pause_description.png \
    images/quit_text.png \
    images/restart_text.png \
    images/right_description.png \
    images/rotate_description.png \
    images/score.png \
    images/speedup_description.png \
    images/start_text.png \
    images/tetris_title.png \
    images/tiles(1).png \
    images/unmute_text.png

RESOURCES += \
    resource.qrc
