QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

SOURCES += \
    priorityqueue.cpp

HEADERS += \
    priorityqueue.h

unix {
    target.path = $$[QT_INSTALL_LIBS]
}
!isEmpty(target.path): INSTALLS += target
