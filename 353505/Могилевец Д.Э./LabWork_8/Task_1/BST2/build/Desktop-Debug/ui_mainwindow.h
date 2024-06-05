/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *resLAbel;
    QPushButton *inorderButton;
    QTableWidget *tableWidget;
    QPushButton *insertSubtreeButton;
    QPushButton *balanceButton;
    QPushButton *removeSubtreeButton;
    QPushButton *postorderButton;
    QLineEdit *infoLineEdit;
    QTreeWidget *treeWidget;
    QPushButton *insertElmentButton;
    QPushButton *addStringButton;
    QPushButton *insertButton;
    QPushButton *LCAButton;
    QLabel *label_3;
    QPushButton *inputButton;
    QPushButton *removeStringButton;
    QPushButton *removeButton;
    QPushButton *findButton;
    QPushButton *preorderButton;
    QLabel *label_4;
    QLineEdit *lineEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1098, 499);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 1091, 491));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 1, 1, 2);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 3, 1, 1);

        resLAbel = new QPlainTextEdit(gridLayoutWidget);
        resLAbel->setObjectName("resLAbel");

        gridLayout->addWidget(resLAbel, 1, 3, 1, 2);

        inorderButton = new QPushButton(gridLayoutWidget);
        inorderButton->setObjectName("inorderButton");

        gridLayout->addWidget(inorderButton, 4, 2, 1, 1);

        tableWidget = new QTableWidget(gridLayoutWidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 20)
            tableWidget->setRowCount(20);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem20);
        tableWidget->setObjectName("tableWidget");

        gridLayout->addWidget(tableWidget, 0, 0, 6, 1);

        insertSubtreeButton = new QPushButton(gridLayoutWidget);
        insertSubtreeButton->setObjectName("insertSubtreeButton");

        gridLayout->addWidget(insertSubtreeButton, 7, 1, 1, 1);

        balanceButton = new QPushButton(gridLayoutWidget);
        balanceButton->setObjectName("balanceButton");

        gridLayout->addWidget(balanceButton, 3, 1, 1, 1);

        removeSubtreeButton = new QPushButton(gridLayoutWidget);
        removeSubtreeButton->setObjectName("removeSubtreeButton");

        gridLayout->addWidget(removeSubtreeButton, 7, 2, 1, 1);

        postorderButton = new QPushButton(gridLayoutWidget);
        postorderButton->setObjectName("postorderButton");

        gridLayout->addWidget(postorderButton, 5, 1, 1, 1);

        infoLineEdit = new QLineEdit(gridLayoutWidget);
        infoLineEdit->setObjectName("infoLineEdit");

        gridLayout->addWidget(infoLineEdit, 2, 4, 1, 1);

        treeWidget = new QTreeWidget(gridLayoutWidget);
        treeWidget->setObjectName("treeWidget");

        gridLayout->addWidget(treeWidget, 0, 1, 1, 4);

        insertElmentButton = new QPushButton(gridLayoutWidget);
        insertElmentButton->setObjectName("insertElmentButton");

        gridLayout->addWidget(insertElmentButton, 8, 1, 1, 1);

        addStringButton = new QPushButton(gridLayoutWidget);
        addStringButton->setObjectName("addStringButton");

        gridLayout->addWidget(addStringButton, 6, 1, 1, 1);

        insertButton = new QPushButton(gridLayoutWidget);
        insertButton->setObjectName("insertButton");

        gridLayout->addWidget(insertButton, 2, 1, 1, 1);

        LCAButton = new QPushButton(gridLayoutWidget);
        LCAButton->setObjectName("LCAButton");

        gridLayout->addWidget(LCAButton, 8, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 3, 1, 1);

        inputButton = new QPushButton(gridLayoutWidget);
        inputButton->setObjectName("inputButton");

        gridLayout->addWidget(inputButton, 5, 2, 1, 1);

        removeStringButton = new QPushButton(gridLayoutWidget);
        removeStringButton->setObjectName("removeStringButton");

        gridLayout->addWidget(removeStringButton, 6, 2, 1, 1);

        removeButton = new QPushButton(gridLayoutWidget);
        removeButton->setObjectName("removeButton");

        gridLayout->addWidget(removeButton, 3, 2, 1, 1);

        findButton = new QPushButton(gridLayoutWidget);
        findButton->setObjectName("findButton");

        gridLayout->addWidget(findButton, 2, 2, 1, 1);

        preorderButton = new QPushButton(gridLayoutWidget);
        preorderButton->setObjectName("preorderButton");

        gridLayout->addWidget(preorderButton, 4, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 4, 3, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 4, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270:", nullptr));
        label_2->setText(QString());
        inorderButton->setText(QCoreApplication::translate("MainWindow", "inOrderTraversal", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        insertSubtreeButton->setText(QCoreApplication::translate("MainWindow", "insertSubtree", nullptr));
        balanceButton->setText(QCoreApplication::translate("MainWindow", "balance", nullptr));
        removeSubtreeButton->setText(QCoreApplication::translate("MainWindow", "removeSubtree", nullptr));
        postorderButton->setText(QCoreApplication::translate("MainWindow", "postOrderTraversal", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        insertElmentButton->setText(QCoreApplication::translate("MainWindow", "insertElement", nullptr));
        addStringButton->setText(QCoreApplication::translate("MainWindow", "addStringToTable", nullptr));
        insertButton->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        LCAButton->setText(QCoreApplication::translate("MainWindow", "LCA", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202 \320\264\320\273\321\217 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270:", nullptr));
        inputButton->setText(QCoreApplication::translate("MainWindow", "inputFromTable", nullptr));
        removeStringButton->setText(QCoreApplication::translate("MainWindow", "removeStringFromTable", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "remove", nullptr));
        findButton->setText(QCoreApplication::translate("MainWindow", "find", nullptr));
        preorderButton->setText(QCoreApplication::translate("MainWindow", "preOrderTraversal", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\222\321\202\320\276\321\200\320\276\320\271 \320\264\320\273\321\217 LCA \320\270\320\273\320\270 \320\272\320\273\321\216\321\207 \320\264\320\273\321\217 \320\262\321\201\321\202\320\260\320\262\320\272\320\270 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
