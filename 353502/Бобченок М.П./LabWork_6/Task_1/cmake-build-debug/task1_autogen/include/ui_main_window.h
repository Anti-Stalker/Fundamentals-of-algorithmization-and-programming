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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QGraphicsView *graphicsView;
    QLineEdit *footStep;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *height;
    QLabel *label_3;
    QLineEdit *eyeColor;
    QLabel *label_4;
    QLineEdit *isFast;
    QPushButton *set;
    QPushButton *setFromConsole;
    QLineEdit *inanswer;
    QLabel *text;
    QPushButton *answer;
    QPushButton *setByPtr;
    QPushButton *setByLink;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(2560, 1600);
        graphicsView = new QGraphicsView(main_window);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 2560, 1600));
        footStep = new QLineEdit(main_window);
        footStep->setObjectName(QString::fromUtf8("footStep"));
        footStep->setGeometry(QRect(130, 260, 121, 25));
        label = new QLabel(main_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 270, 66, 17));
        label_2 = new QLabel(main_window);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 320, 66, 17));
        height = new QLineEdit(main_window);
        height->setObjectName(QString::fromUtf8("height"));
        height->setGeometry(QRect(130, 310, 121, 25));
        label_3 = new QLabel(main_window);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 370, 66, 17));
        eyeColor = new QLineEdit(main_window);
        eyeColor->setObjectName(QString::fromUtf8("eyeColor"));
        eyeColor->setGeometry(QRect(130, 360, 121, 25));
        label_4 = new QLabel(main_window);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 420, 66, 17));
        isFast = new QLineEdit(main_window);
        isFast->setObjectName(QString::fromUtf8("isFast"));
        isFast->setGeometry(QRect(130, 410, 121, 25));
        set = new QPushButton(main_window);
        set->setObjectName(QString::fromUtf8("set"));
        set->setGeometry(QRect(40, 520, 88, 25));
        setFromConsole = new QPushButton(main_window);
        setFromConsole->setObjectName(QString::fromUtf8("setFromConsole"));
        setFromConsole->setGeometry(QRect(40, 620, 131, 25));
        inanswer = new QLineEdit(main_window);
        inanswer->setObjectName(QString::fromUtf8("inanswer"));
        inanswer->setGeometry(QRect(500, 580, 371, 61));
        inanswer->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"font: 400 20pt \"Ubuntu\";\n"
"border: 4px solid black;"));
        text = new QLabel(main_window);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(380, 260, 1171, 231));
        text->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"font: 400 20pt \"Ubuntu\";\n"
"border: 4px solid black;"));
        answer = new QPushButton(main_window);
        answer->setObjectName(QString::fromUtf8("answer"));
        answer->setGeometry(QRect(380, 600, 88, 25));
        setByPtr = new QPushButton(main_window);
        setByPtr->setObjectName(QString::fromUtf8("setByPtr"));
        setByPtr->setGeometry(QRect(40, 670, 131, 25));
        setByLink = new QPushButton(main_window);
        setByLink->setObjectName(QString::fromUtf8("setByLink"));
        setByLink->setGeometry(QRect(40, 720, 131, 25));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "main_window", nullptr));
        footStep->setInputMask(QCoreApplication::translate("main_window", "99", nullptr));
        label->setText(QCoreApplication::translate("main_window", "footStep", nullptr));
        label_2->setText(QCoreApplication::translate("main_window", "height", nullptr));
        height->setInputMask(QCoreApplication::translate("main_window", "999", nullptr));
        height->setText(QString());
        label_3->setText(QCoreApplication::translate("main_window", "eyeColor", nullptr));
        eyeColor->setInputMask(QCoreApplication::translate("main_window", "A", nullptr));
        eyeColor->setText(QString());
        label_4->setText(QCoreApplication::translate("main_window", "isFast", nullptr));
        isFast->setInputMask(QCoreApplication::translate("main_window", "B", nullptr));
        isFast->setText(QString());
        set->setText(QCoreApplication::translate("main_window", "set", nullptr));
        setFromConsole->setText(QCoreApplication::translate("main_window", "setFromConsole", nullptr));
        text->setText(QString());
        answer->setText(QCoreApplication::translate("main_window", "Answer", nullptr));
        setByPtr->setText(QCoreApplication::translate("main_window", "setByPtr", nullptr));
        setByLink->setText(QCoreApplication::translate("main_window", "setByLink", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
