/********************************************************************************
** Form generated from reading UI file 'recorddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDDIALOG_H
#define UI_RECORDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RecordDialog
{
public:
    QLabel *pEasyLidersLabel;
    QLabel *pMediumLidersLaber;
    QLabel *pHardLidersLabel;
    QLabel *pEasyN1Label;
    QLabel *pEasyN2Label;
    QLabel *pEasyN3Label;
    QLabel *pMediumN2Label;
    QLabel *pMediumN1Label;
    QLabel *pMediumN3Label;
    QLabel *pHardN2Label;
    QLabel *pHardN1Label;
    QLabel *pHardN3Label;
    QPushButton *pDoneButton;

    void setupUi(QDialog *RecordDialog)
    {
        if (RecordDialog->objectName().isEmpty())
            RecordDialog->setObjectName(QString::fromUtf8("RecordDialog"));
        RecordDialog->resize(640, 300);
        RecordDialog->setMinimumSize(QSize(640, 300));
        RecordDialog->setMaximumSize(QSize(640, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        RecordDialog->setWindowIcon(icon);
        pEasyLidersLabel = new QLabel(RecordDialog);
        pEasyLidersLabel->setObjectName(QString::fromUtf8("pEasyLidersLabel"));
        pEasyLidersLabel->setGeometry(QRect(80, 40, 80, 30));
        QFont font;
        font.setPointSize(7);
        pEasyLidersLabel->setFont(font);
        pEasyLidersLabel->setFrameShape(QFrame::WinPanel);
        pEasyLidersLabel->setAlignment(Qt::AlignCenter);
        pMediumLidersLaber = new QLabel(RecordDialog);
        pMediumLidersLaber->setObjectName(QString::fromUtf8("pMediumLidersLaber"));
        pMediumLidersLaber->setGeometry(QRect(280, 40, 80, 30));
        pMediumLidersLaber->setFont(font);
        pMediumLidersLaber->setFrameShape(QFrame::WinPanel);
        pMediumLidersLaber->setAlignment(Qt::AlignCenter);
        pHardLidersLabel = new QLabel(RecordDialog);
        pHardLidersLabel->setObjectName(QString::fromUtf8("pHardLidersLabel"));
        pHardLidersLabel->setGeometry(QRect(480, 40, 80, 30));
        pHardLidersLabel->setFont(font);
        pHardLidersLabel->setFrameShape(QFrame::WinPanel);
        pHardLidersLabel->setAlignment(Qt::AlignCenter);
        pEasyN1Label = new QLabel(RecordDialog);
        pEasyN1Label->setObjectName(QString::fromUtf8("pEasyN1Label"));
        pEasyN1Label->setGeometry(QRect(20, 90, 20, 20));
        pEasyN1Label->setFont(font);
        pEasyN2Label = new QLabel(RecordDialog);
        pEasyN2Label->setObjectName(QString::fromUtf8("pEasyN2Label"));
        pEasyN2Label->setGeometry(QRect(20, 135, 20, 20));
        pEasyN2Label->setFont(font);
        pEasyN3Label = new QLabel(RecordDialog);
        pEasyN3Label->setObjectName(QString::fromUtf8("pEasyN3Label"));
        pEasyN3Label->setGeometry(QRect(20, 180, 20, 20));
        pEasyN3Label->setFont(font);
        pMediumN2Label = new QLabel(RecordDialog);
        pMediumN2Label->setObjectName(QString::fromUtf8("pMediumN2Label"));
        pMediumN2Label->setGeometry(QRect(220, 135, 20, 20));
        pMediumN2Label->setFont(font);
        pMediumN1Label = new QLabel(RecordDialog);
        pMediumN1Label->setObjectName(QString::fromUtf8("pMediumN1Label"));
        pMediumN1Label->setGeometry(QRect(220, 90, 20, 20));
        pMediumN1Label->setFont(font);
        pMediumN3Label = new QLabel(RecordDialog);
        pMediumN3Label->setObjectName(QString::fromUtf8("pMediumN3Label"));
        pMediumN3Label->setGeometry(QRect(220, 180, 20, 20));
        pMediumN3Label->setFont(font);
        pHardN2Label = new QLabel(RecordDialog);
        pHardN2Label->setObjectName(QString::fromUtf8("pHardN2Label"));
        pHardN2Label->setGeometry(QRect(420, 135, 20, 20));
        pHardN2Label->setFont(font);
        pHardN1Label = new QLabel(RecordDialog);
        pHardN1Label->setObjectName(QString::fromUtf8("pHardN1Label"));
        pHardN1Label->setGeometry(QRect(420, 90, 20, 20));
        pHardN1Label->setFont(font);
        pHardN3Label = new QLabel(RecordDialog);
        pHardN3Label->setObjectName(QString::fromUtf8("pHardN3Label"));
        pHardN3Label->setGeometry(QRect(420, 180, 20, 20));
        pHardN3Label->setFont(font);
        pDoneButton = new QPushButton(RecordDialog);
        pDoneButton->setObjectName(QString::fromUtf8("pDoneButton"));
        pDoneButton->setGeometry(QRect(510, 250, 75, 24));
        pDoneButton->setFont(font);

        retranslateUi(RecordDialog);
        QObject::connect(pDoneButton, SIGNAL(clicked()), RecordDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(RecordDialog);
    } // setupUi

    void retranslateUi(QDialog *RecordDialog)
    {
        RecordDialog->setWindowTitle(QCoreApplication::translate("RecordDialog", "MineSweeper - Record", nullptr));
        pEasyLidersLabel->setText(QCoreApplication::translate("RecordDialog", "Easy liders", nullptr));
        pMediumLidersLaber->setText(QCoreApplication::translate("RecordDialog", "Medium liders", nullptr));
        pHardLidersLabel->setText(QCoreApplication::translate("RecordDialog", "Hard liders", nullptr));
        pEasyN1Label->setText(QCoreApplication::translate("RecordDialog", "1.", nullptr));
        pEasyN2Label->setText(QCoreApplication::translate("RecordDialog", "2.", nullptr));
        pEasyN3Label->setText(QCoreApplication::translate("RecordDialog", "3.", nullptr));
        pMediumN2Label->setText(QCoreApplication::translate("RecordDialog", "2.", nullptr));
        pMediumN1Label->setText(QCoreApplication::translate("RecordDialog", "1.", nullptr));
        pMediumN3Label->setText(QCoreApplication::translate("RecordDialog", "3.", nullptr));
        pHardN2Label->setText(QCoreApplication::translate("RecordDialog", "2.", nullptr));
        pHardN1Label->setText(QCoreApplication::translate("RecordDialog", "1.", nullptr));
        pHardN3Label->setText(QCoreApplication::translate("RecordDialog", "3.", nullptr));
        pDoneButton->setText(QCoreApplication::translate("RecordDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordDialog: public Ui_RecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDDIALOG_H
