/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *keySpinBox;
    QLabel *label_2;
    QPushButton *mapRemoveButton;
    QLabel *mapResLabel;
    QLabel *label;
    QSpinBox *valSpinBox;
    QPushButton *mapContainsButton;
    QPushButton *mapInsertButton;
    QPushButton *mapClearButton;
    QTableWidget *mapTable;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *setLabel;
    QPushButton *setRemoveButton;
    QLabel *label_3;
    QPushButton *setContainsButton;
    QSpinBox *setValSpinBox;
    QLabel *setResLabel;
    QPushButton *setInsertButton;
    QPushButton *setClearButton;
    QLabel *label_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(713, 552);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 711, 551));
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 711, 521));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        keySpinBox = new QSpinBox(gridLayoutWidget);
        keySpinBox->setObjectName("keySpinBox");

        gridLayout->addWidget(keySpinBox, 0, 3, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 4, 1, 1);

        mapRemoveButton = new QPushButton(gridLayoutWidget);
        mapRemoveButton->setObjectName("mapRemoveButton");

        gridLayout->addWidget(mapRemoveButton, 1, 1, 1, 1);

        mapResLabel = new QLabel(gridLayoutWidget);
        mapResLabel->setObjectName("mapResLabel");

        gridLayout->addWidget(mapResLabel, 1, 2, 1, 4);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 2, 1, 1);

        valSpinBox = new QSpinBox(gridLayoutWidget);
        valSpinBox->setObjectName("valSpinBox");

        gridLayout->addWidget(valSpinBox, 0, 5, 1, 1);

        mapContainsButton = new QPushButton(gridLayoutWidget);
        mapContainsButton->setObjectName("mapContainsButton");

        gridLayout->addWidget(mapContainsButton, 2, 1, 1, 1);

        mapInsertButton = new QPushButton(gridLayoutWidget);
        mapInsertButton->setObjectName("mapInsertButton");

        gridLayout->addWidget(mapInsertButton, 0, 1, 1, 1);

        mapClearButton = new QPushButton(gridLayoutWidget);
        mapClearButton->setObjectName("mapClearButton");

        gridLayout->addWidget(mapClearButton, 3, 1, 1, 1);

        mapTable = new QTableWidget(gridLayoutWidget);
        if (mapTable->columnCount() < 2)
            mapTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        mapTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        mapTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        mapTable->setObjectName("mapTable");

        gridLayout->addWidget(mapTable, 0, 0, 4, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayoutWidget_3 = new QWidget(tab_2);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(0, 0, 711, 521));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        setLabel = new QLabel(gridLayoutWidget_3);
        setLabel->setObjectName("setLabel");

        gridLayout_3->addWidget(setLabel, 2, 2, 2, 3);

        setRemoveButton = new QPushButton(gridLayoutWidget_3);
        setRemoveButton->setObjectName("setRemoveButton");

        gridLayout_3->addWidget(setRemoveButton, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_3);
        label_3->setObjectName("label_3");

        gridLayout_3->addWidget(label_3, 0, 2, 1, 1);

        setContainsButton = new QPushButton(gridLayoutWidget_3);
        setContainsButton->setObjectName("setContainsButton");

        gridLayout_3->addWidget(setContainsButton, 2, 0, 1, 1);

        setValSpinBox = new QSpinBox(gridLayoutWidget_3);
        setValSpinBox->setObjectName("setValSpinBox");

        gridLayout_3->addWidget(setValSpinBox, 0, 3, 1, 2);

        setResLabel = new QLabel(gridLayoutWidget_3);
        setResLabel->setObjectName("setResLabel");

        gridLayout_3->addWidget(setResLabel, 1, 2, 1, 3);

        setInsertButton = new QPushButton(gridLayoutWidget_3);
        setInsertButton->setObjectName("setInsertButton");

        gridLayout_3->addWidget(setInsertButton, 0, 0, 1, 1);

        setClearButton = new QPushButton(gridLayoutWidget_3);
        setClearButton->setObjectName("setClearButton");

        gridLayout_3->addWidget(setClearButton, 3, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_3);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_4, 2, 1, 2, 1);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265:", nullptr));
        mapRemoveButton->setText(QCoreApplication::translate("MainWindow", "erase", nullptr));
        mapResLabel->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207:", nullptr));
        mapContainsButton->setText(QCoreApplication::translate("MainWindow", "contains", nullptr));
        mapInsertButton->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        mapClearButton->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        QTableWidgetItem *___qtablewidgetitem = mapTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = mapTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Map", nullptr));
        setLabel->setText(QString());
        setRemoveButton->setText(QCoreApplication::translate("MainWindow", "erase", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\262\321\201\321\202\320\260\320\262\320\273\321\217\320\265\320\274\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260:", nullptr));
        setContainsButton->setText(QCoreApplication::translate("MainWindow", "contains", nullptr));
        setResLabel->setText(QString());
        setInsertButton->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        setClearButton->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\241\320\260\320\274 \321\201\320\265\321\202:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Set", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
