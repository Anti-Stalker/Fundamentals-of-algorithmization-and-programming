#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"j_stack.h"
#include"hash.h"
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

private:
    Ui::MainWindow *ui;
    Hash *h1=new Hash(16);
    Hash *h2=new Hash(64);
    Hash *h3=new Hash(128);
    Hash *h4=new Hash(2048);
    j_stack vec1;
     j_stack vec2;
};
#endif // MAINWINDOW_H
