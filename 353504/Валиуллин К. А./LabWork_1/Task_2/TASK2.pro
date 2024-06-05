QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogcircle.cpp \
    dialoghexagon.cpp \
    dialogoval.cpp \
    dialogrectangle.cpp \
    dialogrhombus.cpp \
    dialogsetxy.cpp \
    dialogsquare.cpp \
    dialogstar.cpp \
    dialogtriangle.cpp \
    figure.cpp \
    figurecircle.cpp \
    figurehexagon.cpp \
    figureoval.cpp \
    figurerectangle.cpp \
    figurerhombus.cpp \
    figuresquare.cpp \
    figurestar5.cpp \
    figurestar6.cpp \
    figurestar8.cpp \
    figuretriangle.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    dialogcircle.h \
    dialoghexagon.h \
    dialogoval.h \
    dialogrectangle.h \
    dialogrhombus.h \
    dialogsetxy.h \
    dialogsquare.h \
    dialogstar.h \
    dialogtriangle.h \
    figure.h \
    figurecircle.h \
    figurehexagon.h \
    figureoval.h \
    figurerectangle.h \
    figurerhombus.h \
    figuresquare.h \
    figurestar5.h \
    figurestar6.h \
    figurestar8.h \
    figuretriangle.h \
    mainwindow.h

FORMS += \
    dialogcircle.ui \
    dialoghexagon.ui \
    dialogoval.ui \
    dialogrectangle.ui \
    dialogrhombus.ui \
    dialogsetxy.ui \
    dialogsquare.ui \
    dialogstar.ui \
    dialogtriangle.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
