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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QLineEdit *s1;
    QLineEdit *s2;
    QLineEdit *s3;
    QLabel *label;
    QLabel *label_2;
    QPushButton *len;
    QPushButton *cpy;
    QPushButton *ncpy;
    QSpinBox *spinBox;
    QPushButton *cat;
    QPushButton *ncat;
    QPushButton *ncmp;
    QPushButton *cmp;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(696, 380);
        s1 = new QLineEdit(main_window);
        s1->setObjectName(QString::fromUtf8("s1"));
        s1->setGeometry(QRect(40, 50, 231, 25));
        s2 = new QLineEdit(main_window);
        s2->setObjectName(QString::fromUtf8("s2"));
        s2->setGeometry(QRect(40, 90, 231, 25));
        s3 = new QLineEdit(main_window);
        s3->setObjectName(QString::fromUtf8("s3"));
        s3->setGeometry(QRect(320, 70, 231, 25));
        label = new QLabel(main_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 70, 16, 17));
        label_2 = new QLabel(main_window);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 20, 66, 17));
        len = new QPushButton(main_window);
        len->setObjectName(QString::fromUtf8("len"));
        len->setGeometry(QRect(40, 210, 88, 25));
        cpy = new QPushButton(main_window);
        cpy->setObjectName(QString::fromUtf8("cpy"));
        cpy->setGeometry(QRect(180, 210, 88, 25));
        ncpy = new QPushButton(main_window);
        ncpy->setObjectName(QString::fromUtf8("ncpy"));
        ncpy->setGeometry(QRect(180, 260, 88, 25));
        spinBox = new QSpinBox(main_window);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(600, 240, 44, 26));
        cat = new QPushButton(main_window);
        cat->setObjectName(QString::fromUtf8("cat"));
        cat->setGeometry(QRect(310, 210, 88, 25));
        ncat = new QPushButton(main_window);
        ncat->setObjectName(QString::fromUtf8("ncat"));
        ncat->setGeometry(QRect(310, 260, 88, 25));
        ncmp = new QPushButton(main_window);
        ncmp->setObjectName(QString::fromUtf8("ncmp"));
        ncmp->setGeometry(QRect(430, 260, 88, 25));
        cmp = new QPushButton(main_window);
        cmp->setObjectName(QString::fromUtf8("cmp"));
        cmp->setGeometry(QRect(430, 210, 88, 25));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "main_window", nullptr));
        label->setText(QCoreApplication::translate("main_window", "->", nullptr));
        label_2->setText(QCoreApplication::translate("main_window", "Strings", nullptr));
        len->setText(QCoreApplication::translate("main_window", "strlen", nullptr));
        cpy->setText(QCoreApplication::translate("main_window", "strcpy", nullptr));
        ncpy->setText(QCoreApplication::translate("main_window", "strncpy", nullptr));
        cat->setText(QCoreApplication::translate("main_window", "strcat", nullptr));
        ncat->setText(QCoreApplication::translate("main_window", "strncat", nullptr));
        ncmp->setText(QCoreApplication::translate("main_window", "strncmp", nullptr));
        cmp->setText(QCoreApplication::translate("main_window", "strcmp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
