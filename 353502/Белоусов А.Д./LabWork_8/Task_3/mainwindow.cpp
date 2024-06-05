#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    munordered_map<std::string, int> check_mun_map(1024);

    check_mun_map["vladymtsev"] = 69;
    check_mun_map["chaikin"] = -1;
    check_mun_map["ganusevich"] = 420;
    qDebug() << check_mun_map["vladymtsev"];
    check_mun_map["chaikin"] = check_mun_map["vladymtsev"];
    qDebug() << check_mun_map["chaikin"];
    check_mun_map.erase("vladymtsev");
    qDebug() << check_mun_map.contains("vladymtsev");
    check_mun_map.rehash(512);
    qDebug() << check_mun_map["ganusevich"];

    qDebug() << "=======================================";

    mmap<int, int> m;
    m[13] = 37;
    qDebug() << m[13];
    m[14] = 38;
    qDebug() << m[14];
    m[15] = 39;
    qDebug() << m[15];
    m[16] = 40;
    qDebug() << m[16];

    qDebug() << "=======================================";

    mset<int> s;
    s.insertVal(5);
    s.insertVal(8);
    s.insertVal(9);
    s.insertVal(11);

    qDebug() << (s.findVal(5) != s.end());
    qDebug() << (s.findVal(6) != s.end());
    qDebug() << (s.findVal(8) != s.end());
}

MainWindow::~MainWindow()
{
    delete ui;
}

