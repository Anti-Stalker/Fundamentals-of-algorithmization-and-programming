QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    algorithms.cpp \
    animationcontrol.cpp \
    battleinterface.cpp \
    characterstatus.cpp \
    chatacterunit.cpp \
    combatlogic.cpp \
    combatzone.cpp \
    datahub.cpp \
    levelcoordinator.cpp \
    levelinterface.cpp \
    levelmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    mapcell.cpp \
    menuinterface.cpp \
    traininginterface.cpp

HEADERS += \
    algorithms.h \
    animationcontrol.h \
    battleinterface.h \
    characterstatus.h \
    chatacterunit.h \
    combatlogic.h \
    combatzone.h \
    datahub.h \
    levelcoordinator.h \
    levelinterface.h \
    levelmanager.h \
    mainwindow.h \
    mapcell.h \
    menuinterface.h \
    traininginterface.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Assets/background/background.png \
    Assets/character/archer/attack/archer_attack_01.gif \
    Assets/character/archer/attack/archer_attack_02.gif \
    Assets/character/archer/attack/archer_attack_03.gif \
    Assets/character/archer/attack/archer_attack_04.gif \
    Assets/character/archer/bow/archer_bow_01.gif \
    Assets/character/archer/bow/archer_bow_02.gif \
    Assets/character/archer/bow/archer_bow_03.gif \
    Assets/character/archer/bow/archer_bow_04.gif \
    Assets/character/archer/die/archer_dead.png \
    Assets/character/archer/die/archer_die.gif \
    Assets/character/archer/magic/leather_armor_magic_01.gif \
    Assets/character/archer/magic/leather_armor_magic_02.gif \
    Assets/character/archer/magic/leather_armor_magic_03.gif \
    Assets/character/archer/magic/leather_armor_magic_04.gif \
    Assets/character/archer/moving/archer_move_01.gif \
    Assets/character/archer/moving/archer_move_02.gif \
    Assets/character/archer/moving/archer_move_03.gif \
    Assets/character/archer/moving/archer_move_04.gif \
    Assets/character/archer/standing/archer_standing_01.png \
    Assets/character/archer/standing/archer_standing_02.png \
    Assets/character/archer/standing/archer_standing_03.png \
    Assets/character/archer/standing/archer_standing_04.png \
    Assets/character/armor/attack/plate_armor_attack_01.gif \
    Assets/character/armor/attack/plate_armor_attack_02.gif \
    Assets/character/armor/attack/plate_armor_attack_03.gif \
    Assets/character/armor/attack/plate_armor_attack_04.gif \
    Assets/character/armor/die/plate_armor_dead_01.png \
    Assets/character/armor/die/plate_armor_die_01.gif \
    Assets/character/armor/knife_attack/plate_armor_knife_01.gif \
    Assets/character/armor/knife_attack/plate_armor_knife_02.gif \
    Assets/character/armor/knife_attack/plate_armor_knife_03.gif \
    Assets/character/armor/knife_attack/plate_armor_knife_04.gif \
    Assets/character/armor/moving/plate_armor_moving_01.gif \
    Assets/character/armor/moving/plate_armor_moving_02.gif \
    Assets/character/armor/moving/plate_armor_moving_03.gif \
    Assets/character/armor/moving/plate_armor_moving_04.gif \
    Assets/character/armor/standing/plate_armor_standing_01.png \
    Assets/character/armor/standing/plate_armor_standing_02.png \
    Assets/character/armor/standing/plate_armor_standing_03.png \
    Assets/character/armor/standing/plate_armor_standing_04.png \
    Assets/character/skeleton/attack/skeleton_attack_01.gif \
    Assets/character/skeleton/attack/skeleton_attack_02.gif \
    Assets/character/skeleton/attack/skeleton_attack_03.gif \
    Assets/character/skeleton/attack/skeleton_attack_04.gif \
    Assets/character/skeleton/die/skeleton_dead_01.png \
    Assets/character/skeleton/die/skeleton_die_01.gif \
    Assets/character/skeleton/moving/skeleton_move_01.gif \
    Assets/character/skeleton/moving/skeleton_move_02.gif \
    Assets/character/skeleton/moving/skeleton_move_03.gif \
    Assets/character/skeleton/moving/skeleton_move_04.gif \
    Assets/character/skeleton/standing/skeleton_standing_01.png \
    Assets/character/skeleton/standing/skeleton_standing_02.png \
    Assets/character/skeleton/standing/skeleton_standing_03.png \
    Assets/character/skeleton/standing/skeleton_standing_04.png \
    Assets/character/soldier/attack/soldier_attack_01.gif \
    Assets/character/soldier/attack/soldier_attack_02.gif \
    Assets/character/soldier/attack/soldier_attack_03.gif \
    Assets/character/soldier/attack/soldier_attack_04.gif \
    Assets/character/soldier/bow/chain_armor_bow_01.gif \
    Assets/character/soldier/bow/chain_armor_bow_02.gif \
    Assets/character/soldier/bow/chain_armor_bow_03.gif \
    Assets/character/soldier/bow/chain_armor_bow_04.gif \
    Assets/character/soldier/die/soldier_dead.png \
    Assets/character/soldier/die/soldier_die.gif \
    Assets/character/soldier/knife_attack/chain_armor_attack_knife_01.gif \
    Assets/character/soldier/knife_attack/chain_armor_attack_knife_02.gif \
    Assets/character/soldier/knife_attack/chain_armor_attack_knife_03.gif \
    Assets/character/soldier/knife_attack/chain_armor_attack_knife_04.gif \
    Assets/character/soldier/magic/chain_armor_magic_01.gif \
    Assets/character/soldier/magic/chain_armor_magic_02.gif \
    Assets/character/soldier/magic/chain_armor_magic_03.gif \
    Assets/character/soldier/magic/chain_armor_magic_04.gif \
    Assets/character/soldier/moving/soldier_move_01.gif \
    Assets/character/soldier/moving/soldier_move_02.gif \
    Assets/character/soldier/moving/soldier_move_03.gif \
    Assets/character/soldier/moving/soldier_move_04.gif \
    Assets/character/soldier/standing/soldier_stand_01.png \
    Assets/character/soldier/standing/soldier_stand_02.png \
    Assets/character/soldier/standing/soldier_stand_03.png \
    Assets/character/soldier/standing/soldier_stand_04.png \
    Assets/tutorial/archer.png \
    Assets/tutorial/move&attack.png \
    Assets/tutorial/skeleton.png \
    Assets/tutorial/soldier.png
