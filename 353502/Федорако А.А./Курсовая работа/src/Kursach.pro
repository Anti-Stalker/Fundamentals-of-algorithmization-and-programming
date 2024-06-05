QT += core gui
QT += widgets
QT += sql
QT += core
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basketwidget.cpp \
    data.cpp \
    main.cpp \
    mainwindow.cpp \
    product.cpp \
    productsort.cpp \
    productwidget.cpp \
    projectappearance.cpp \
    stringprocessing.cpp

HEADERS += \
    basketwidget.h \
    data.h \
    mainwindow.h \
    product.h \
    productsort.h \
    productwidget.h \
    projectappearance.h \
    stringprocessing.h

FORMS += \
    basketwidget.ui \
    mainwindow.ui \
    productwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Data/Picture/Product/Шоколад_Merci_finest_selection_250г_Германия.jpg \
    Data/Picture/Product/Шоколад_Merci_finest_selection_250г_Германия.jpg \
    Data/Picture/Product/Шоколад_Merci_finest_selection_250г_Германия.jpg \
    Data/Picture/Product/Шоколад_Merci_finest_selection_250г_Германия.jpg \
    Data/Picture/Product/Шоколад_Merci_finest_selection_250г_Германия.jpg \
    Data/Picture/Product/Шоколад_Nestle_молочный_белый_кокос_вафля_82г.jpg \
    Data/Picture/Product/Шоколад_Nestle_молочный_белый_кокос_вафля_82г.jpg \
    Data/Picture/Product/Шоколад_Nestle_молочный_белый_кокос_вафля_82г.jpg \
    Data/Picture/Product/Шоколад_Nestle_молочный_белый_кокос_вафля_82г.jpg \
    Data/Picture/Product/Шоколад_Nestle_молочный_белый_кокос_вафля_82г.jpg \
    Data/Picture/Product/Шоколад_Ritter_sport_альпийское_молоко_100г_Германия.jpg \
    Data/Picture/Product/Шоколад_Ritter_sport_альпийское_молоко_100г_Германия.jpg \
    Data/Picture/Product/Шоколад_Ritter_sport_альпийское_молоко_100г_Германия.jpg \
    Data/Picture/Product/Шоколад_Ritter_sport_альпийское_молоко_100г_Германия.jpg \
    Data/Picture/Product/Шоколад_Коммунарка_молочный_сливки_100г_РБ.jpg \
    Data/Picture/Product/Шоколад_Коммунарка_молочный_сливки_100г_РБ.jpg \
    Data/Picture/Product/Шоколад_Коммунарка_молочный_сливки_100г_РБ.jpg \
    Data/Picture/Product/Шоколад_Коммунарка_молочный_сливки_100г_РБ.jpg \
    Data/Picture/Product/Шоколад_Любимая_Аленка_молочный_200г_РБ.jpg \
    Data/Picture/Product/Шоколад_Любимая_Аленка_молочный_200г_РБ.jpg \
    Data/Picture/Product/Шоколад_Любимая_Аленка_молочный_200г_РБ.jpg \
    Data/Picture/Product/Шоколад_Любимая_Аленка_молочный_200г_РБ.jpg \
    Data/Picture/Product/Шоколад_Мишка_на_Поляне_100г_РБ.jpg \
    Data/Picture/Product/Шоколад_Мишка_на_Поляне_100г_РБ.jpg \
    Data/Picture/Product/Шоколад_Мишка_на_Поляне_100г_РБ.jpg \
    Data/Picture/Product/Шоколад_Мишка_на_Поляне_100г_РБ.jpg \
    Data/Picture/Product/Шоколадный_батончик_Snickers_51г.jpg \
    Data/Picture/Product/Шоколадный_батончик_Snickers_51г.jpg \
    Data/Picture/Product/Шоколадный_батончик_Snickers_51г.jpg \
    Data/Picture/Product/Шоколадный_батончик_Snickers_51г.jpg \
    Data/TextInformation/products.txt \
    README.md \
    README.md \
    ащт
