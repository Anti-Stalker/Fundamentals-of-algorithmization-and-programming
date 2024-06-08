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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QPushButton *add;
    QTreeView *treeView;
    QPushButton *erase;
    QSpinBox *val;
    QPushButton *changeType;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(1200, 1000);
        graphicsView = new QGraphicsView(main_window);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1200, 1000));
        label = new QLabel(main_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(820, 20, 66, 17));
        add = new QPushButton(main_window);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(890, 120, 88, 25));
        treeView = new QTreeView(main_window);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(20, 10, 621, 951));
        erase = new QPushButton(main_window);
        erase->setObjectName(QString::fromUtf8("erase"));
        erase->setGeometry(QRect(890, 160, 88, 25));
        val = new QSpinBox(main_window);
        val->setObjectName(QString::fromUtf8("val"));
        val->setGeometry(QRect(890, 20, 44, 26));
        val->setMaximum(300);
        changeType = new QPushButton(main_window);
        changeType->setObjectName(QString::fromUtf8("changeType"));
        changeType->setGeometry(QRect(890, 320, 88, 25));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "main_window", nullptr));
        label->setText(QCoreApplication::translate("main_window", "value", nullptr));
        add->setText(QCoreApplication::translate("main_window", "Add", nullptr));
        erase->setText(QCoreApplication::translate("main_window", "erase", nullptr));
        changeType->setText(QCoreApplication::translate("main_window", "changeType", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
