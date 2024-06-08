#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rbtree.h"
#include"set.h"
#include "map.h"
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    RBTree<int,char> tree;
    set<int> *s=new set<int>();
    map <int,char> m;
    int tmp1=0;
    int tmp2=0;
    char k1;
};
#endif // MAINWINDOW_H
