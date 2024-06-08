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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *popbackButton_2;
    QPushButton *clearButton;
    QPushButton *popfrontButton;
    QLabel *label;
    QPushButton *pushfrontButton;
    QPushButton *pushbackButton;
    QSpinBox *spinBox;
    QStatusBar *statusbar;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(800, 600);
        centralwidget = new QWidget(main_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setGeometry(QRect(0, 0, 801, 551));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 801, 551));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        popbackButton_2 = new QPushButton(gridLayoutWidget);
        popbackButton_2->setObjectName(QString::fromUtf8("popbackButton_2"));

        gridLayout->addWidget(popbackButton_2, 1, 1, 1, 1);

        clearButton = new QPushButton(gridLayoutWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout->addWidget(clearButton, 4, 0, 1, 2);

        popfrontButton = new QPushButton(gridLayoutWidget);
        popfrontButton->setObjectName(QString::fromUtf8("popfrontButton"));

        gridLayout->addWidget(popfrontButton, 2, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 400 20pt \"Ubuntu\";"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        pushfrontButton = new QPushButton(gridLayoutWidget);
        pushfrontButton->setObjectName(QString::fromUtf8("pushfrontButton"));

        gridLayout->addWidget(pushfrontButton, 2, 0, 1, 1);

        pushbackButton = new QPushButton(gridLayoutWidget);
        pushbackButton->setObjectName(QString::fromUtf8("pushbackButton"));

        gridLayout->addWidget(pushbackButton, 1, 0, 1, 1);

        spinBox = new QSpinBox(gridLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout->addWidget(spinBox, 3, 0, 1, 2);

        statusbar = new QStatusBar(main_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 22));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "main_window", nullptr));
        popbackButton_2->setText(QCoreApplication::translate("main_window", "pop_back", nullptr));
        clearButton->setText(QCoreApplication::translate("main_window", "clear", nullptr));
        popfrontButton->setText(QCoreApplication::translate("main_window", "pop_front", nullptr));
        label->setText(QString());
        pushfrontButton->setText(QCoreApplication::translate("main_window", "push_front", nullptr));
        pushbackButton->setText(QCoreApplication::translate("main_window", "push_back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
