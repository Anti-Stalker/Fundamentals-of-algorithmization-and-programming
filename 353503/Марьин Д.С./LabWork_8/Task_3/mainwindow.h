#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rb_tree.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
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
    void on_On_insert_2_clicked();

    void on_On_delete_clicked();

    void on_On_ExtractMax_clicked();

    void on_On_print_clicked();

    void on_On_clear_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    RB_Tree<int,std::string> map;
};
#endif // MAINWINDOW_H
