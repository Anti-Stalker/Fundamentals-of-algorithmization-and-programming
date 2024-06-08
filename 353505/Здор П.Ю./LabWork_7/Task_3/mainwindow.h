#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <hash.h>
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
    void displ();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Hash *h=new Hash(10);
    j_stack vec1;
    j_stack vec2;
};
#endif // MAINWINDOW_H
