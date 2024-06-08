QT       += core gui quick quick3d

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    createorderwindow.cpp \
    heapsort.cpp \
    main.cpp \
    mainwindow.cpp \
    orders.cpp \
    volume.cpp \
    xor_crypt.cpp

HEADERS += \
    createorderwindow.h \
    heapsort.h \
    mainwindow.h \
    orders.h \
    stl_reader.h \
    volume.h \
    xor_crypt.h

FORMS += \
    createorderwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc


# OTHER_FILES += \
#     doc/src/*.*

# CONFIG += qmltypes

DISTFILES +=
