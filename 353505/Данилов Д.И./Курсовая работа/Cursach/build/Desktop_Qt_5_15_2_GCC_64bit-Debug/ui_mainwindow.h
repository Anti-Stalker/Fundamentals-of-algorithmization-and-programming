/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <graphics.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *pActionEasyLevel;
    QAction *pActionMediumLevel;
    QAction *pActionHardLevel;
    QAction *pActionCustomLevel;
    QAction *pActionPause;
    QAction *pActionRestart;
    QAction *pActionRecord;
    QAction *pActionAbout;
    QWidget *pCentralWidget;
    QVBoxLayout *pMainLayout;
    QHBoxLayout *pGameInfoLayout;
    QLabel *pMineLabel;
    QLabel *pTimeLabel;
    GraphicsWidget *pGraphics;
    QMenuBar *pMenuBar;
    QMenu *pMenuStart;
    QMenu *pMenuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(344, 412);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(11);
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1.000000000000000);
        pActionEasyLevel = new QAction(MainWindow);
        pActionEasyLevel->setObjectName(QString::fromUtf8("pActionEasyLevel"));
        pActionMediumLevel = new QAction(MainWindow);
        pActionMediumLevel->setObjectName(QString::fromUtf8("pActionMediumLevel"));
        pActionHardLevel = new QAction(MainWindow);
        pActionHardLevel->setObjectName(QString::fromUtf8("pActionHardLevel"));
        pActionCustomLevel = new QAction(MainWindow);
        pActionCustomLevel->setObjectName(QString::fromUtf8("pActionCustomLevel"));
        pActionPause = new QAction(MainWindow);
        pActionPause->setObjectName(QString::fromUtf8("pActionPause"));
        pActionRestart = new QAction(MainWindow);
        pActionRestart->setObjectName(QString::fromUtf8("pActionRestart"));
        pActionRecord = new QAction(MainWindow);
        pActionRecord->setObjectName(QString::fromUtf8("pActionRecord"));
        pActionAbout = new QAction(MainWindow);
        pActionAbout->setObjectName(QString::fromUtf8("pActionAbout"));
        pCentralWidget = new QWidget(MainWindow);
        pCentralWidget->setObjectName(QString::fromUtf8("pCentralWidget"));
        pCentralWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pCentralWidget->sizePolicy().hasHeightForWidth());
        pCentralWidget->setSizePolicy(sizePolicy);
        pMainLayout = new QVBoxLayout(pCentralWidget);
        pMainLayout->setSpacing(0);
        pMainLayout->setObjectName(QString::fromUtf8("pMainLayout"));
        pMainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        pMainLayout->setContentsMargins(0, 0, 0, 0);
        pGameInfoLayout = new QHBoxLayout();
        pGameInfoLayout->setSpacing(0);
        pGameInfoLayout->setObjectName(QString::fromUtf8("pGameInfoLayout"));
        pGameInfoLayout->setSizeConstraint(QLayout::SetFixedSize);
        pGameInfoLayout->setContentsMargins(12, -1, 12, -1);
        pMineLabel = new QLabel(pCentralWidget);
        pMineLabel->setObjectName(QString::fromUtf8("pMineLabel"));
        pMineLabel->setMaximumSize(QSize(16777215, 42));

        pGameInfoLayout->addWidget(pMineLabel);

        pTimeLabel = new QLabel(pCentralWidget);
        pTimeLabel->setObjectName(QString::fromUtf8("pTimeLabel"));
        pTimeLabel->setMaximumSize(QSize(16777215, 42));

        pGameInfoLayout->addWidget(pTimeLabel);


        pMainLayout->addLayout(pGameInfoLayout);

        pGraphics = new GraphicsWidget(pCentralWidget);
        pGraphics->setObjectName(QString::fromUtf8("pGraphics"));
        pGraphics->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pGraphics->sizePolicy().hasHeightForWidth());
        pGraphics->setSizePolicy(sizePolicy1);
        pGraphics->setMinimumSize(QSize(344, 344));

        pMainLayout->addWidget(pGraphics);

        MainWindow->setCentralWidget(pCentralWidget);
        pMenuBar = new QMenuBar(MainWindow);
        pMenuBar->setObjectName(QString::fromUtf8("pMenuBar"));
        pMenuBar->setGeometry(QRect(0, 0, 344, 24));
        pMenuStart = new QMenu(pMenuBar);
        pMenuStart->setObjectName(QString::fromUtf8("pMenuStart"));
        pMenuHelp = new QMenu(pMenuBar);
        pMenuHelp->setObjectName(QString::fromUtf8("pMenuHelp"));
        MainWindow->setMenuBar(pMenuBar);

        pMenuBar->addAction(pMenuStart->menuAction());
        pMenuBar->addAction(pMenuHelp->menuAction());
        pMenuStart->addAction(pActionEasyLevel);
        pMenuStart->addAction(pActionMediumLevel);
        pMenuStart->addAction(pActionHardLevel);
        pMenuStart->addAction(pActionCustomLevel);
        pMenuStart->addSeparator();
        pMenuStart->addAction(pActionPause);
        pMenuStart->addAction(pActionRestart);
        pMenuHelp->addAction(pActionRecord);
        pMenuHelp->addSeparator();
        pMenuHelp->addAction(pActionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mine Sweeper", nullptr));
        pActionEasyLevel->setText(QCoreApplication::translate("MainWindow", "Easy(E)", nullptr));
        pActionMediumLevel->setText(QCoreApplication::translate("MainWindow", "Medium(M)", nullptr));
        pActionHardLevel->setText(QCoreApplication::translate("MainWindow", "Hard(H)", nullptr));
        pActionCustomLevel->setText(QCoreApplication::translate("MainWindow", "Custom(C)", nullptr));
        pActionPause->setText(QCoreApplication::translate("MainWindow", "Pause(P)", nullptr));
        pActionRestart->setText(QCoreApplication::translate("MainWindow", "Restart(R)", nullptr));
        pActionRecord->setText(QCoreApplication::translate("MainWindow", "Record(R)", nullptr));
        pActionAbout->setText(QCoreApplication::translate("MainWindow", "About(A)", nullptr));
        pMineLabel->setText(QCoreApplication::translate("MainWindow", "MINES:999", nullptr));
        pTimeLabel->setText(QCoreApplication::translate("MainWindow", "TIME:999", nullptr));
        pMenuStart->setTitle(QCoreApplication::translate("MainWindow", "Start(S)", nullptr));
        pMenuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help(H)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
