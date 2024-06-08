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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTextBrowser *showtext;
    QGridLayout *gridLayout;
    QSpinBox *push_backspinbox;
    QPushButton *capacitybutton;
    QSpinBox *atspinbox;
    QSpinBox *erasespinbox;
    QSpinBox *resizespinbox;
    QPushButton *endbutton;
    QPushButton *resizebutton;
    QPushButton *emptybutton;
    QPushButton *atbutton;
    QPushButton *pop_backbutton;
    QPushButton *push_backbutton;
    QPushButton *clearbutton;
    QPushButton *erasebutton;
    QPushButton *sizebutton;
    QPushButton *beginbutton;
    QTextBrowser *mini;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(785, 413);
        centralwidget = new QWidget(main_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setGeometry(QRect(0, 80, 771, 241));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        showtext = new QTextBrowser(centralwidget);
        showtext->setObjectName(QString::fromUtf8("showtext"));
        showtext->setMaximumSize(QSize(16777215, 55));

        gridLayout_2->addWidget(showtext, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        push_backspinbox = new QSpinBox(centralwidget);
        push_backspinbox->setObjectName(QString::fromUtf8("push_backspinbox"));
        push_backspinbox->setToolTipDuration(-1);
        push_backspinbox->setValue(4);

        gridLayout->addWidget(push_backspinbox, 0, 1, 1, 1);

        capacitybutton = new QPushButton(centralwidget);
        capacitybutton->setObjectName(QString::fromUtf8("capacitybutton"));

        gridLayout->addWidget(capacitybutton, 0, 8, 1, 1);

        atspinbox = new QSpinBox(centralwidget);
        atspinbox->setObjectName(QString::fromUtf8("atspinbox"));

        gridLayout->addWidget(atspinbox, 1, 3, 1, 1);

        erasespinbox = new QSpinBox(centralwidget);
        erasespinbox->setObjectName(QString::fromUtf8("erasespinbox"));

        gridLayout->addWidget(erasespinbox, 0, 6, 1, 1);

        resizespinbox = new QSpinBox(centralwidget);
        resizespinbox->setObjectName(QString::fromUtf8("resizespinbox"));

        gridLayout->addWidget(resizespinbox, 0, 3, 1, 1);

        endbutton = new QPushButton(centralwidget);
        endbutton->setObjectName(QString::fromUtf8("endbutton"));

        gridLayout->addWidget(endbutton, 0, 4, 1, 1);

        resizebutton = new QPushButton(centralwidget);
        resizebutton->setObjectName(QString::fromUtf8("resizebutton"));

        gridLayout->addWidget(resizebutton, 0, 2, 1, 1);

        emptybutton = new QPushButton(centralwidget);
        emptybutton->setObjectName(QString::fromUtf8("emptybutton"));

        gridLayout->addWidget(emptybutton, 1, 7, 1, 1);

        atbutton = new QPushButton(centralwidget);
        atbutton->setObjectName(QString::fromUtf8("atbutton"));

        gridLayout->addWidget(atbutton, 1, 2, 1, 1);

        pop_backbutton = new QPushButton(centralwidget);
        pop_backbutton->setObjectName(QString::fromUtf8("pop_backbutton"));

        gridLayout->addWidget(pop_backbutton, 1, 5, 1, 1);

        push_backbutton = new QPushButton(centralwidget);
        push_backbutton->setObjectName(QString::fromUtf8("push_backbutton"));

        gridLayout->addWidget(push_backbutton, 0, 0, 1, 1);

        clearbutton = new QPushButton(centralwidget);
        clearbutton->setObjectName(QString::fromUtf8("clearbutton"));

        gridLayout->addWidget(clearbutton, 0, 7, 1, 1);

        erasebutton = new QPushButton(centralwidget);
        erasebutton->setObjectName(QString::fromUtf8("erasebutton"));

        gridLayout->addWidget(erasebutton, 0, 5, 1, 1);

        sizebutton = new QPushButton(centralwidget);
        sizebutton->setObjectName(QString::fromUtf8("sizebutton"));

        gridLayout->addWidget(sizebutton, 1, 8, 1, 1);

        beginbutton = new QPushButton(centralwidget);
        beginbutton->setObjectName(QString::fromUtf8("beginbutton"));

        gridLayout->addWidget(beginbutton, 1, 4, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 2);

        mini = new QTextBrowser(main_window);
        mini->setObjectName(QString::fromUtf8("mini"));
        mini->setGeometry(QRect(0, 10, 191, 41));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        push_backspinbox->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        capacitybutton->setText(QCoreApplication::translate("main_window", "capacity()", nullptr));
        endbutton->setText(QCoreApplication::translate("main_window", "end()", nullptr));
        resizebutton->setText(QCoreApplication::translate("main_window", "resize()", nullptr));
        emptybutton->setText(QCoreApplication::translate("main_window", "empty()", nullptr));
        atbutton->setText(QCoreApplication::translate("main_window", "at()", nullptr));
        pop_backbutton->setText(QCoreApplication::translate("main_window", "pop_back()", nullptr));
        push_backbutton->setText(QCoreApplication::translate("main_window", "push_back()", nullptr));
        clearbutton->setText(QCoreApplication::translate("main_window", "clear()", nullptr));
        erasebutton->setText(QCoreApplication::translate("main_window", "erase()", nullptr));
        sizebutton->setText(QCoreApplication::translate("main_window", "size()", nullptr));
        beginbutton->setText(QCoreApplication::translate("main_window", "begin()", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
