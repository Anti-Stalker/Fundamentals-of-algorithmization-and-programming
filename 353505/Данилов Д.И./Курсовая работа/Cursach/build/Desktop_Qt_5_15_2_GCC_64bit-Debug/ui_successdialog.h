/********************************************************************************
** Form generated from reading UI file 'successdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCCESSDIALOG_H
#define UI_SUCCESSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SuccessDialog
{
public:
    QLabel *PTitleLabel;
    QLabel *pNameLabel;
    QLineEdit *pNameEdit;
    QPushButton *pDoneButton;

    void setupUi(QDialog *SuccessDialog)
    {
        if (SuccessDialog->objectName().isEmpty())
            SuccessDialog->setObjectName(QString::fromUtf8("SuccessDialog"));
        SuccessDialog->resize(400, 207);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SuccessDialog->setWindowIcon(icon);
        PTitleLabel = new QLabel(SuccessDialog);
        PTitleLabel->setObjectName(QString::fromUtf8("PTitleLabel"));
        PTitleLabel->setGeometry(QRect(70, 20, 241, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(13);
        font.setBold(true);
        PTitleLabel->setFont(font);
        PTitleLabel->setAlignment(Qt::AlignCenter);
        pNameLabel = new QLabel(SuccessDialog);
        pNameLabel->setObjectName(QString::fromUtf8("pNameLabel"));
        pNameLabel->setGeometry(QRect(20, 100, 191, 16));
        QFont font1;
        font1.setPointSize(10);
        pNameLabel->setFont(font1);
        pNameEdit = new QLineEdit(SuccessDialog);
        pNameEdit->setObjectName(QString::fromUtf8("pNameEdit"));
        pNameEdit->setGeometry(QRect(240, 100, 113, 22));
        QFont font2;
        font2.setPointSize(7);
        pNameEdit->setFont(font2);
        pDoneButton = new QPushButton(SuccessDialog);
        pDoneButton->setObjectName(QString::fromUtf8("pDoneButton"));
        pDoneButton->setEnabled(true);
        pDoneButton->setGeometry(QRect(280, 150, 75, 24));
        pDoneButton->setFont(font2);
        pDoneButton->setFocusPolicy(Qt::StrongFocus);
        pDoneButton->setFlat(false);

        retranslateUi(SuccessDialog);

        pDoneButton->setDefault(false);


        QMetaObject::connectSlotsByName(SuccessDialog);
    } // setupUi

    void retranslateUi(QDialog *SuccessDialog)
    {
        SuccessDialog->setWindowTitle(QCoreApplication::translate("SuccessDialog", "MineSweeper - success", nullptr));
        PTitleLabel->setText(QCoreApplication::translate("SuccessDialog", "Congratilations!\n"
"You win", nullptr));
        pNameLabel->setText(QCoreApplication::translate("SuccessDialog", "Please enter your name:", nullptr));
        pNameEdit->setText(QCoreApplication::translate("SuccessDialog", "Guest", nullptr));
        pDoneButton->setText(QCoreApplication::translate("SuccessDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuccessDialog: public Ui_SuccessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCESSDIALOG_H
