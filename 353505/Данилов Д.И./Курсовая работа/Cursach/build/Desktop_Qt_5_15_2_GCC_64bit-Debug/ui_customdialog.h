/********************************************************************************
** Form generated from reading UI file 'customdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMDIALOG_H
#define UI_CUSTOMDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CustomDialog
{
public:
    QPushButton *pDoneButton;
    QLabel *pRowsNumberLabel;
    QLabel *pColsNumberLabel;
    QLabel *pMinesNumberLabel;
    QSpinBox *pRowsNumberSpinBox;
    QSpinBox *pColsNumberSpinBox;
    QSpinBox *pMinesNumberSpinBox;

    void setupUi(QDialog *CustomDialog)
    {
        if (CustomDialog->objectName().isEmpty())
            CustomDialog->setObjectName(QString::fromUtf8("CustomDialog"));
        CustomDialog->resize(301, 184);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        CustomDialog->setWindowIcon(icon);
        pDoneButton = new QPushButton(CustomDialog);
        pDoneButton->setObjectName(QString::fromUtf8("pDoneButton"));
        pDoneButton->setGeometry(QRect(210, 150, 75, 24));
        QFont font;
        font.setPointSize(8);
        pDoneButton->setFont(font);
        pRowsNumberLabel = new QLabel(CustomDialog);
        pRowsNumberLabel->setObjectName(QString::fromUtf8("pRowsNumberLabel"));
        pRowsNumberLabel->setGeometry(QRect(20, 20, 171, 20));
        QFont font1;
        font1.setPointSize(7);
        pRowsNumberLabel->setFont(font1);
        pColsNumberLabel = new QLabel(CustomDialog);
        pColsNumberLabel->setObjectName(QString::fromUtf8("pColsNumberLabel"));
        pColsNumberLabel->setGeometry(QRect(20, 60, 171, 20));
        pColsNumberLabel->setFont(font1);
        pMinesNumberLabel = new QLabel(CustomDialog);
        pMinesNumberLabel->setObjectName(QString::fromUtf8("pMinesNumberLabel"));
        pMinesNumberLabel->setGeometry(QRect(20, 100, 181, 20));
        pMinesNumberLabel->setFont(font1);
        pRowsNumberSpinBox = new QSpinBox(CustomDialog);
        pRowsNumberSpinBox->setObjectName(QString::fromUtf8("pRowsNumberSpinBox"));
        pRowsNumberSpinBox->setGeometry(QRect(210, 20, 71, 22));
        pRowsNumberSpinBox->setFont(font1);
        pRowsNumberSpinBox->setMinimum(10);
        pRowsNumberSpinBox->setMaximum(40);
        pColsNumberSpinBox = new QSpinBox(CustomDialog);
        pColsNumberSpinBox->setObjectName(QString::fromUtf8("pColsNumberSpinBox"));
        pColsNumberSpinBox->setGeometry(QRect(210, 60, 71, 22));
        pColsNumberSpinBox->setFont(font1);
        pColsNumberSpinBox->setMinimum(10);
        pColsNumberSpinBox->setMaximum(25);
        pMinesNumberSpinBox = new QSpinBox(CustomDialog);
        pMinesNumberSpinBox->setObjectName(QString::fromUtf8("pMinesNumberSpinBox"));
        pMinesNumberSpinBox->setGeometry(QRect(210, 100, 71, 22));
        pMinesNumberSpinBox->setFont(font1);
        pMinesNumberSpinBox->setMinimum(1);
        pMinesNumberSpinBox->setMaximum(999);
        pMinesNumberSpinBox->setValue(10);

        retranslateUi(CustomDialog);

        QMetaObject::connectSlotsByName(CustomDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomDialog)
    {
        CustomDialog->setWindowTitle(QCoreApplication::translate("CustomDialog", "MineSweeper - custom", nullptr));
        pDoneButton->setText(QCoreApplication::translate("CustomDialog", "OK", nullptr));
        pRowsNumberLabel->setText(QCoreApplication::translate("CustomDialog", "Enter number of rows(10~40)", nullptr));
        pColsNumberLabel->setText(QCoreApplication::translate("CustomDialog", "Enter number of cols(10~25)", nullptr));
        pMinesNumberLabel->setText(QCoreApplication::translate("CustomDialog", "Enter number of mines(1~999)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomDialog: public Ui_CustomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMDIALOG_H
