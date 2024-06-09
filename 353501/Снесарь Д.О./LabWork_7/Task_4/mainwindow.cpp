#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_pushButton_2_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillTables()
{

}


void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();

    if(ui->comboBox->currentIndex() == 0)
        ui->textBrowser->append(QString::fromStdString(a.display()));
    if(ui->comboBox->currentIndex() == 1)
        ui->textBrowser->append(QString::fromStdString(b.display()));
    if(ui->comboBox->currentIndex() == 2)
        ui->textBrowser->append(QString::fromStdString(c.display()));
    if(ui->comboBox->currentIndex() == 3)
        ui->textBrowser->append(QString::fromStdString(d.display()));




}


void MainWindow::on_pushButton_2_clicked()
{
     ui->textBrowser->clear();
    a.clear();
    b.clear();
    c.clear();
    d.clear();
    QVector<QPair<int, int>> v;
    for (int i = 0; i < 2048; ++i) {
        v.push_back(qMakePair(QRandomGenerator::global()->bounded(1, 10000), QRandomGenerator::global()->bounded(1, 100)));
    }

    for (int i = 0; i < 16; ++i) {
        a.insertNode(v[i].first, v[i].second);
    }
    for (int i = 0; i < 64; ++i) {
        b.insertNode(v[i].first, v[i].second);
    }
    for (int i = 0; i < 128; ++i) {
        c.insertNode(v[i].first, v[i].second);
    }
    for (int i = 0; i < 2048; ++i) {
        d.insertNode(v[i].first, v[i].second);
    }

    QElapsedTimer timer;

    int resOfa = 0;
    timer.start();
    for (int i = 0; i < 3000; ++i) {
        a.get(v[i % 16].first);
    }
    resOfa = timer.nsecsElapsed();

    int resOfb = 0;
    timer.start();
    for (int i = 0; i < 3000; ++i) {
        b.get(v[i % 64].first);
    }
    resOfb = timer.nsecsElapsed();

    int resOfc = 0;
    timer.start();
    for (int i = 0; i < 3000; ++i) {
        c.get(v[i % 128].first);
    }
    resOfc = timer.nsecsElapsed();

    int resOfd = 0;
    timer.start();
    for (int i = 0; i < 3000; ++i) {
        d.get(v[i % 2048].first);
    }
    resOfd = timer.nsecsElapsed();


    QGraphicsView *view = ui->graphicsView;
    QGraphicsScene *scene = new QGraphicsScene(this);
    view->setScene(scene);

    QGraphicsRectItem *aa = new QGraphicsRectItem(0, -sqrt(resOfa), 50, sqrt(resOfa));
    QGraphicsRectItem *bb = new QGraphicsRectItem(150, -sqrt(resOfb), 50, sqrt(resOfb));
    QGraphicsRectItem *cc = new QGraphicsRectItem(350, -sqrt(resOfc), 50, sqrt(resOfc));
    QGraphicsRectItem *dd = new QGraphicsRectItem(500, -sqrt(resOfd), 50, sqrt(resOfd));
    scene->addItem(aa);
    scene->addItem(bb);
    scene->addItem(cc);
    scene->addItem(dd);





}

