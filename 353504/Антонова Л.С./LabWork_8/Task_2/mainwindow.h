#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTreeView>
#include <QStandardItem>
#include <DinLibrary/dinlibrary.h>
#include <StatLibrary/statlibrary.h>

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

private:
    Ui::MainWindow *ui;
    PriorityQueue <int> binHeap;
};
#endif // MAINWINDOW_H
