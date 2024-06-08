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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QSpinBox *key;
    QLabel *label_2;
    QPushButton *add;
    QTreeView *treeView;
    QPushButton *erase;
    QPushButton *find;
    QTextBrowser *textBrowser;
    QPushButton *direct;
    QPushButton *back;
    QPushButton *byKey;
    QPushButton *leaves;
    QSpinBox *val;
    QPushButton *eraseSubTree;
    QPushButton *findPar;
    QSpinBox *second;
    QSpinBox *first;

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
        key = new QSpinBox(main_window);
        key->setObjectName(QString::fromUtf8("key"));
        key->setGeometry(QRect(890, 60, 44, 26));
        key->setMaximum(300);
        label_2 = new QLabel(main_window);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(820, 60, 66, 17));
        add = new QPushButton(main_window);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(890, 120, 88, 25));
        treeView = new QTreeView(main_window);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(20, 10, 621, 951));
        erase = new QPushButton(main_window);
        erase->setObjectName(QString::fromUtf8("erase"));
        erase->setGeometry(QRect(890, 160, 88, 25));
        find = new QPushButton(main_window);
        find->setObjectName(QString::fromUtf8("find"));
        find->setGeometry(QRect(890, 200, 88, 25));
        textBrowser = new QTextBrowser(main_window);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(690, 760, 471, 192));
        direct = new QPushButton(main_window);
        direct->setObjectName(QString::fromUtf8("direct"));
        direct->setGeometry(QRect(890, 300, 88, 25));
        back = new QPushButton(main_window);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(890, 340, 88, 25));
        byKey = new QPushButton(main_window);
        byKey->setObjectName(QString::fromUtf8("byKey"));
        byKey->setGeometry(QRect(890, 380, 88, 25));
        leaves = new QPushButton(main_window);
        leaves->setObjectName(QString::fromUtf8("leaves"));
        leaves->setGeometry(QRect(890, 470, 88, 25));
        val = new QSpinBox(main_window);
        val->setObjectName(QString::fromUtf8("val"));
        val->setGeometry(QRect(890, 20, 44, 26));
        val->setMaximum(300);
        eraseSubTree = new QPushButton(main_window);
        eraseSubTree->setObjectName(QString::fromUtf8("eraseSubTree"));
        eraseSubTree->setGeometry(QRect(1060, 120, 101, 25));
        findPar = new QPushButton(main_window);
        findPar->setObjectName(QString::fromUtf8("findPar"));
        findPar->setGeometry(QRect(1060, 160, 101, 25));
        second = new QSpinBox(main_window);
        second->setObjectName(QString::fromUtf8("second"));
        second->setGeometry(QRect(1120, 200, 44, 26));
        first = new QSpinBox(main_window);
        first->setObjectName(QString::fromUtf8("first"));
        first->setGeometry(QRect(1060, 200, 44, 26));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "main_window", nullptr));
        label->setText(QCoreApplication::translate("main_window", "value", nullptr));
        label_2->setText(QCoreApplication::translate("main_window", "key", nullptr));
        add->setText(QCoreApplication::translate("main_window", "Add", nullptr));
        erase->setText(QCoreApplication::translate("main_window", "erase", nullptr));
        find->setText(QCoreApplication::translate("main_window", "find", nullptr));
        direct->setText(QCoreApplication::translate("main_window", "direct", nullptr));
        back->setText(QCoreApplication::translate("main_window", "back", nullptr));
        byKey->setText(QCoreApplication::translate("main_window", "byKey", nullptr));
        leaves->setText(QCoreApplication::translate("main_window", "leaves", nullptr));
        eraseSubTree->setText(QCoreApplication::translate("main_window", "eraseSubTree", nullptr));
        findPar->setText(QCoreApplication::translate("main_window", "findPar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
