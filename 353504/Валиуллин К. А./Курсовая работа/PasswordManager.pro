QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database/editdatabasewidget.cpp \
    database/hashingmanager.cpp \
    database/recentdatabasemanager.cpp \
    database/unlockdatabasewidget.cpp \
    database/welcomewidget.cpp \
    database/createdatabasewidget.cpp \
    database/settingsmanager.cpp \
    dbmanagement/databasedecryptor.cpp \
    dbmanagement/databaseeditor.cpp \
    dbmanagement/databaseencryptor.cpp \
    dbmanagement/databaseshortcutsselecter.cpp \
    notes/addnewnotewidget.cpp \
    notes/editexistnotewidget.cpp \
    groups/addnewgroupwidget.cpp \
    groups/editexistgroupwidget.cpp \
    dbmanagement/databasecontroller.cpp \
    dbmanagement/databasecreator.cpp \
    dbmanagement/databasedisplay.cpp \
    dbmanagement/databasegroupscreator.cpp \
    dbmanagement/databasegroupseditor.cpp \
    dbmanagement/databasegroupsremover.cpp \
    dbmanagement/databasenotescreator.cpp \
    dbmanagement/databasenoteseditor.cpp \
    dbmanagement/databasenotesremover.cpp \
    other/deletegroupwarning.cpp \
    other/checkifdatabaseexistwarning.cpp \
    other/aboutprogramwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    aes256/AES256.cpp \
    aes256/AES256_Base.cpp \
    aes256/AES256_PRNG.cpp \
    aes256/S_Box.cpp


HEADERS += \
    database/hashingmanager.h \
    database/recentdatabasemanager.h \
    database/unlockdatabasewidget.h \
    dbmanagement/databasedecryptor.h \
    dbmanagement/databaseeditor.h \
    dbmanagement/databaseencryptor.h \
    dbmanagement/databaseshortcutsselecter.h \
    notes/addnewnotewidget.h \
    notes/editexistnotewidget.h \
    structures/EnumWidgets.h \
    structures/GroupData.h \
    structures/NodeData.h \
    database/editdatabasewidget.h \
    database/welcomewidget.h \
    database/createdatabasewidget.h \
    database/settingsmanager.h \
    groups/addnewgroupwidget.h \
    groups/editexistgroupwidget.h \
    dbmanagement/databasecontroller.h \
    dbmanagement/databasecreator.h \
    dbmanagement/databasedisplay.h \
    dbmanagement/databasegroupscreator.h \
    dbmanagement/databasegroupseditor.h \
    dbmanagement/databasegroupsremover.h \
    dbmanagement/databasenotescreator.h \
    dbmanagement/databasenoteseditor.h \
    dbmanagement/databasenotesremover.h \
    other/deletegroupwarning.h \
    other/checkifdatabaseexistwarning.h \
    other/aboutprogramwidget.h \
    mainwindow.h \
    aes256/AES256.hpp \
    aes256/AES256_Base.hpp \
    aes256/AES256_PRNG.hpp \
    aes256/Byte_Block.hpp \
    aes256/Padding_Type.hpp \
    aes256/S_Box.hpp


FORMS += \
    gui/aboutprogramwidget.ui \
    gui/checkifdatabaseexistwarning.ui \
    gui/addnewgroupwidget.ui \
    gui/addnewnotewidget.ui \
    gui/createdatabasewidget.ui \
    gui/editdatabasewidget.ui \
    gui/deletegroupwarning.ui \
    gui/editexistgroupwidget.ui \
    gui/editexistnotewidget.ui \
    gui/mainwindow.ui \
    gui/unlockdatabasewidget.ui \
    gui/welcomewidget.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    toolBarImages.qrc
