QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17



INCLUDEPATH += libs

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mystring.cpp

HEADERS += \
    mainwindow.h \
    mystring.h \
    ui_mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    myString.pro \
    myString.pro \
    myString.pro \
    myString.pro
