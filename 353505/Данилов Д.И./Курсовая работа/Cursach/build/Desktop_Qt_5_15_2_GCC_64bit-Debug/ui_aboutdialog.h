/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QLabel *pAboutLabel;
    QPushButton *pCloseButton;

    void setupUi(QWidget *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(333, 156);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AboutDialog->setWindowIcon(icon);
        pAboutLabel = new QLabel(AboutDialog);
        pAboutLabel->setObjectName(QString::fromUtf8("pAboutLabel"));
        pAboutLabel->setGeometry(QRect(10, 0, 291, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(10);
        pAboutLabel->setFont(font);
        pAboutLabel->setLineWidth(5);
        pAboutLabel->setWordWrap(true);
        pCloseButton = new QPushButton(AboutDialog);
        pCloseButton->setObjectName(QString::fromUtf8("pCloseButton"));
        pCloseButton->setGeometry(QRect(220, 120, 75, 24));
        QFont font1;
        font1.setPointSize(8);
        pCloseButton->setFont(font1);
        pCloseButton->setAutoDefault(true);

        retranslateUi(AboutDialog);
        QObject::connect(pCloseButton, SIGNAL(clicked()), AboutDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QWidget *AboutDialog)
    {
        AboutDialog->setWindowTitle(QCoreApplication::translate("AboutDialog", "MineSweeper - About", nullptr));
        pAboutLabel->setText(QCoreApplication::translate("AboutDialog", "Course project \n"
"software design\n"
"made by Danilau Dzmitry\n"
"classic MineSweeper game", nullptr));
        pCloseButton->setText(QCoreApplication::translate("AboutDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
