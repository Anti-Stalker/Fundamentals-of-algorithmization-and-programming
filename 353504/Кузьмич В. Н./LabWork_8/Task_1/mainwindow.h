#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tree.h"
#include "qstandarditemmodel.h"
#include "qtreeview.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_InOrder_clicked();

    void on_pushButton_PreOrder_clicked();

    void on_pushButton_PostOrder_clicked();

    void on_pushButton_balanse_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    Tree tree;
    void Widg(QStandardItem* parentItem, Node* node);
    QStandardItemModel * model;
};
#endif // MAINWINDOW_H
