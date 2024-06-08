/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;
    QSpinBox *spinBox_2;
    QStatusBar *statusbar;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(800, 600);
        centralwidget = new QWidget(main_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setGeometry(QRect(0, 0, 751, 521));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 751, 521));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        spinBox = new QSpinBox(gridLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout->addWidget(spinBox, 1, 3, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 2, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        tableWidget = new QTableWidget(gridLayoutWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 4);

        spinBox_2 = new QSpinBox(gridLayoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        gridLayout->addWidget(spinBox_2, 2, 3, 1, 1);

        statusbar = new QStatusBar(main_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 22));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "main_window", nullptr));
        pushButton->setText(QCoreApplication::translate("main_window", "insert", nullptr));
        label->setText(QCoreApplication::translate("main_window", "\320\232\320\273\321\216\321\207:", nullptr));
        label_2->setText(QCoreApplication::translate("main_window", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("main_window", "remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
