QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog_1_1.cpp \
    dialog_1_2.cpp \
    dialog_1_3.cpp \
    dialog_2_1_1.cpp \
    dialog_2_1_2.cpp \
    dialog_2_2_1.cpp \
    dialog_2_2_2.cpp \
    dialog_2_3_1.cpp \
    dialog_2_3_2.cpp \
    icedata.cpp \
    main.cpp \
    firstwindow.cpp

HEADERS += \
    dialog_1_1.h \
    dialog_1_2.h \
    dialog_1_3.h \
    dialog_2_1_1.h \
    dialog_2_1_2.h \
    dialog_2_2_1.h \
    dialog_2_2_2.h \
    dialog_2_3_1.h \
    dialog_2_3_2.h \
    firstwindow.h \
    icedata.h

FORMS += \
    dialog_1_1.ui \
    dialog_1_2.ui \
    dialog_1_3.ui \
    dialog_2_1_1.ui \
    dialog_2_1_2.ui \
    dialog_2_2_1.ui \
    dialog_2_2_2.ui \
    dialog_2_3_1.ui \
    dialog_2_3_2.ui \
    firstwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
