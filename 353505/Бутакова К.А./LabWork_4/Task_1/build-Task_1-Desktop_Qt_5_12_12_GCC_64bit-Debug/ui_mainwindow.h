/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSpinBox *spinBox;
    QPushButton *pushButton_enter;
    QLabel *Message;
    QPushButton *pushButton_restart;
    QLabel *label_n;
    QTextEdit *textEdit;
    QLabel *label_speed;
    QLabel *label_ans;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(270, 30, 81, 25));
        spinBox->setMinimum(1);
        spinBox->setMaximum(2147483647);
        pushButton_enter = new QPushButton(centralwidget);
        pushButton_enter->setObjectName(QString::fromUtf8("pushButton_enter"));
        pushButton_enter->setGeometry(QRect(450, 30, 121, 24));
        Message = new QLabel(centralwidget);
        Message->setObjectName(QString::fromUtf8("Message"));
        Message->setGeometry(QRect(70, 30, 261, 21));
        pushButton_restart = new QPushButton(centralwidget);
        pushButton_restart->setObjectName(QString::fromUtf8("pushButton_restart"));
        pushButton_restart->setGeometry(QRect(590, 30, 201, 24));
        label_n = new QLabel(centralwidget);
        label_n->setObjectName(QString::fromUtf8("label_n"));
        label_n->setGeometry(QRect(80, 80, 121, 16));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(80, 120, 631, 201));
        textEdit->setAutoFillBackground(false);
        textEdit->setReadOnly(true);
        label_speed = new QLabel(centralwidget);
        label_speed->setObjectName(QString::fromUtf8("label_speed"));
        label_speed->setGeometry(QRect(80, 340, 351, 71));
        label_ans = new QLabel(centralwidget);
        label_ans->setObjectName(QString::fromUtf8("label_ans"));
        label_ans->setGeometry(QRect(90, 430, 401, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_enter->setText(QApplication::translate("MainWindow", "ok", nullptr));
        Message->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 n:", nullptr));
        pushButton_restart->setText(QApplication::translate("MainWindow", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\270 \320\275\320\260\321\207\320\260\321\202\321\214 \321\201\320\275\320\260\321\207\320\260\320\273\320\260", nullptr));
        label_n->setText(QString());
        label_speed->setText(QString());
        label_ans->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
