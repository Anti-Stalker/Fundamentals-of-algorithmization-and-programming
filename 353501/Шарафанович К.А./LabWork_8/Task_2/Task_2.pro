QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17



SOURCES += \
    lib/listheap.cpp \
    main.cpp \
    mainwindow.cpp \
    static_lib/arrayheap.cpp

HEADERS += \
    lib/listheap.h \
    lib/listnode.h \
    mainwindow.h \
    static_lib/arrayheap.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += targe

SUBDIRS += \
    lib/list.pro \
    static_lib/arrayheap.pro

DISTFILES += \
    lib/liblistheap.so.1 \
    lib/liblistheap.so.1.0 \
    lib/qmake.stash \
    static_lib/qmake.stash
