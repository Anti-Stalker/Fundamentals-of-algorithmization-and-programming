#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "PriorityTree.h"
#include "ArrayHeap.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

    PriorityTree<long> * tree;

public:
    MainWindow(QWidget* = nullptr);
    ~MainWindow();

    void refresh();
private slots:
    void on_pushBtn_clicked();
    void on_popBtn_clicked();


    void on_pushButton_2_clicked();

protected:
    Ui::MainWindow *ui;
};
