#include "mainwindow.h"
#include "./ui_mainwindow.h"

class Test{
public:
    Test() = default;

    int field;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    //Vector<Pair<QString, Pair<int,short>>> vec;

    Vector<int> vec;

    //auto ex = Pair<QString, Pair<int,short>>("1",Pair<int, short>(10, 100));

    //vec.push_back(ex);

    //qDebug() << vec[0].first;

    int fill_to = 6;

    for(int i = 0; i < fill_to; ++i){
        vec.push_back(i);
    }



    // vec.erase(1);
    // vec.pop_back();

    for(auto el : vec){
        qDebug() << el;
    }
    qDebug() << vec.size();
}

MainWindow::~MainWindow()
{
    delete ui;
}
