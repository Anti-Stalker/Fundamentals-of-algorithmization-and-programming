#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bst.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_insertButton_clicked();
    void on_removeButton_clicked();
    void on_findButton_clicked();
    void on_preOrderButton_clicked();
    void on_inOrderButton_clicked();
    void on_postOrderButton_clicked();

    void on_singleChildNodesButton_clicked();

private:
    Ui::MainWindow *ui;
    BST tree;
};
#endif // MAINWINDOW_H
