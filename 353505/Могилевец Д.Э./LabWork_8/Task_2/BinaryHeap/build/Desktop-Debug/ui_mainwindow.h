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
#include <QtWidgets/QTreeWidget>
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
    QTreeWidget *treeWidgetArrHeap;
    QPushButton *insertInArrHeap;
    QSpinBox *spinBox;
    QPushButton *extractMaxArrHeap;
    QLabel *arrHeapLabel;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QTreeWidget *treeWidgetListHeap;
    QPushButton *insertInLisstHeap;
    QSpinBox *spinBox_2;
    QPushButton *extractMaxListHeap;
    QLabel *listHeapLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(790, 661);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 789, 659));
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 791, 631));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        treeWidgetArrHeap = new QTreeWidget(gridLayoutWidget);
        treeWidgetArrHeap->headerItem()->setText(0, QString());
        treeWidgetArrHeap->setObjectName("treeWidgetArrHeap");

        gridLayout->addWidget(treeWidgetArrHeap, 0, 0, 1, 4);

        insertInArrHeap = new QPushButton(gridLayoutWidget);
        insertInArrHeap->setObjectName("insertInArrHeap");

        gridLayout->addWidget(insertInArrHeap, 1, 0, 1, 1);

        spinBox = new QSpinBox(gridLayoutWidget);
        spinBox->setObjectName("spinBox");

        gridLayout->addWidget(spinBox, 1, 1, 1, 1);

        extractMaxArrHeap = new QPushButton(gridLayoutWidget);
        extractMaxArrHeap->setObjectName("extractMaxArrHeap");

        gridLayout->addWidget(extractMaxArrHeap, 1, 2, 1, 1);

        arrHeapLabel = new QLabel(gridLayoutWidget);
        arrHeapLabel->setObjectName("arrHeapLabel");

        gridLayout->addWidget(arrHeapLabel, 1, 3, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayoutWidget_2 = new QWidget(tab_2);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 791, 631));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        treeWidgetListHeap = new QTreeWidget(gridLayoutWidget_2);
        treeWidgetListHeap->headerItem()->setText(0, QString());
        treeWidgetListHeap->setObjectName("treeWidgetListHeap");

        gridLayout_2->addWidget(treeWidgetListHeap, 0, 0, 1, 4);

        insertInLisstHeap = new QPushButton(gridLayoutWidget_2);
        insertInLisstHeap->setObjectName("insertInLisstHeap");

        gridLayout_2->addWidget(insertInLisstHeap, 1, 0, 1, 1);

        spinBox_2 = new QSpinBox(gridLayoutWidget_2);
        spinBox_2->setObjectName("spinBox_2");

        gridLayout_2->addWidget(spinBox_2, 1, 1, 1, 1);

        extractMaxListHeap = new QPushButton(gridLayoutWidget_2);
        extractMaxListHeap->setObjectName("extractMaxListHeap");

        gridLayout_2->addWidget(extractMaxListHeap, 1, 2, 1, 1);

        listHeapLabel = new QLabel(gridLayoutWidget_2);
        listHeapLabel->setObjectName("listHeapLabel");

        gridLayout_2->addWidget(listHeapLabel, 1, 3, 1, 1);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        insertInArrHeap->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        extractMaxArrHeap->setText(QCoreApplication::translate("MainWindow", "extractMax", nullptr));
        arrHeapLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\274\320\260\321\201\321\201\320\270\320\262\320\265", nullptr));
        insertInLisstHeap->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        extractMaxListHeap->setText(QCoreApplication::translate("MainWindow", "extractMax", nullptr));
        listHeapLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\235\320\260 \321\201\320\277\320\270\321\201\320\272\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
