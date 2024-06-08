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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QListWidget *demoMethodsList;
    QPushButton *popButton;
    QSpinBox *insertedElComboBox;
    QPushButton *pushButton;
    QLabel *label;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *insertButton;
    QPushButton *fillButton;
    QListWidget *queue1Widget;
    QListWidget *queue2Widget;
    QStatusBar *statusbar;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(861, 742);
        centralwidget = new QWidget(main_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setGeometry(QRect(0, 0, 861, 741));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 30, 861, 711));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 851, 651));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        demoMethodsList = new QListWidget(gridLayoutWidget);
        demoMethodsList->setObjectName(QString::fromUtf8("demoMethodsList"));
        demoMethodsList->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"font: 400 15pt \"Ubuntu\";\n"
"border: 2px solid black;"));

        gridLayout->addWidget(demoMethodsList, 0, 0, 1, 4);

        popButton = new QPushButton(gridLayoutWidget);
        popButton->setObjectName(QString::fromUtf8("popButton"));
        popButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"font: 400 15pt \"Ubuntu\";\n"
"border: 2px solid black;"));

        gridLayout->addWidget(popButton, 1, 1, 1, 1);

        insertedElComboBox = new QSpinBox(gridLayoutWidget);
        insertedElComboBox->setObjectName(QString::fromUtf8("insertedElComboBox"));
        insertedElComboBox->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"font: 400 15pt \"Ubuntu\";\n"
"border: 2px solid black;"));

        gridLayout->addWidget(insertedElComboBox, 1, 3, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"font: 400 15pt \"Ubuntu\";\n"
"border: 2px solid black;"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayoutWidget_2 = new QWidget(tab_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 20, 851, 651));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        insertButton = new QPushButton(gridLayoutWidget_2);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));
        insertButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"font: 400 15pt \"Ubuntu\";\n"
"border: 2px solid black;"));

        gridLayout_2->addWidget(insertButton, 1, 2, 1, 1);

        fillButton = new QPushButton(gridLayoutWidget_2);
        fillButton->setObjectName(QString::fromUtf8("fillButton"));
        fillButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"font: 400 15pt \"Ubuntu\";\n"
"border: 2px solid black;"));

        gridLayout_2->addWidget(fillButton, 1, 0, 1, 2);

        queue1Widget = new QListWidget(gridLayoutWidget_2);
        queue1Widget->setObjectName(QString::fromUtf8("queue1Widget"));
        queue1Widget->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"font: 400 15pt \"Ubuntu\";\n"
"border: 2px solid black;"));

        gridLayout_2->addWidget(queue1Widget, 0, 0, 1, 1);

        queue2Widget = new QListWidget(gridLayoutWidget_2);
        queue2Widget->setObjectName(QString::fromUtf8("queue2Widget"));
        queue2Widget->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"font: 400 15pt \"Ubuntu\";\n"
"border: 2px solid black;"));

        gridLayout_2->addWidget(queue2Widget, 0, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());
        statusbar = new QStatusBar(main_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 22));

        retranslateUi(main_window);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "main_window", nullptr));
        popButton->setText(QCoreApplication::translate("main_window", "Pop", nullptr));
        pushButton->setText(QCoreApplication::translate("main_window", "Push", nullptr));
        label->setText(QCoreApplication::translate("main_window", "\320\222\321\201\321\202\320\260\320\262\320\273\321\217\320\265\320\274\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("main_window", "Queue", nullptr));
        insertButton->setText(QCoreApplication::translate("main_window", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\321\213 \320\262\321\202\320\276\321\200\320\276\320\271 \320\276\321\207\320\265\321\200\320\265\320\264\320\270", nullptr));
        fillButton->setText(QCoreApplication::translate("main_window", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\276\321\207\320\265\321\200\320\265\320\264\320\270 \321\201\320\273\321\203\321\207\320\260\320\271\320\275\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("main_window", "Task", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
