#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bin_search_tree.h"
#include <QMessageBox>
#include <QTreeWidgetItem>
#include "node.h"

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

    void updWidget(QTreeWidgetItem *item,Node * v);
    void showTree();
    bool check_key();
    bool check_str();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    BST t;
    int key;
    QString str;
};
#endif // MAINWINDOW_H
