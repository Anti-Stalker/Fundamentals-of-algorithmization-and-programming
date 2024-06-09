#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlineedit.h"
#include <QMainWindow>

struct Toy
{
public:
    int _age = 0;
    double _price = 0;
    QString _name = "";
    bool _isForChildern = true;

    Toy() : _age(0), _price(0), _isForChildern(true), _name("") {}
    Toy(int _age,
          double _price,
          bool _isForChildern,
          QString _name
          ) : _age(_age), _price(_price), _isForChildern(_isForChildern), _name(_name) {}
};

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
    void on_ButtonTask_1_clicked();

    void on_pushButton_clicked();

    void on_CreateButton_clicked();

    void on_Task_3_clicked();

    void on_Task_4_clicked();

private:
    QString PrintInfo(const Toy& item);
    bool CheckNum(QLineEdit *line);


    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
