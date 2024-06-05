#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


    t11=new LSHT(16);
    t12=new LSHT(64);
    t13=new LSHT(128);
    t14=new LSHT(2048);

    t21=new QFSHT(16);
    t22=new QFSHT(64);
    t23=new QFSHT(128);
    t24=new QFSHT(2048);

    gen.seed(time(NULL));
    scene=new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    on_pushButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print()
{
    //long long t = *std::max_element(result,result+8);
    //qDebug()<<t;
    qreal scale;
    //qDebug()<<scale;

    int sceneHeight = 850;
    scale=850.0/std::max(result[0],result[4]);
    lt1=new QGraphicsRectItem(0,sceneHeight - scale*result[0],50,scale*result[0]);

    qt1=new QGraphicsRectItem(70,sceneHeight - scale*result[4],50,scale*result[4]);

    scale=850.0/std::max(result[1],result[5]);
    lt2=new QGraphicsRectItem(160,sceneHeight - scale*result[1],50,scale*result[1]);
    qt2=new QGraphicsRectItem(230,sceneHeight - scale*result[5],50,scale*result[5]);
    scale=850.0/std::max(result[2],result[6]);
    lt3=new QGraphicsRectItem(320,sceneHeight - scale*result[2],50,scale*result[2]);
    qt3=new QGraphicsRectItem(390,sceneHeight - scale*result[6],50,scale*result[6]);
    scale=850.0/std::max(result[3],result[7]);
    lt4=new QGraphicsRectItem(480,sceneHeight - scale*result[3],50,scale*result[3]);
    qt4=new QGraphicsRectItem(550,sceneHeight - scale*result[7],50,scale*result[7]);
    //qt1->co

    lt1->setBrush(QColor("orange"));
    lt2->setBrush(QColor("orange"));
    lt3->setBrush(QColor("orange"));
    lt4->setBrush(QColor("orange"));
    qt1->setBrush(Qt::darkBlue);
    qt2->setBrush(Qt::darkBlue);
    qt3->setBrush(Qt::darkBlue);
    qt4->setBrush(Qt::darkBlue);



    scene->addItem(lt1);
    scene->addItem(lt2);
    scene->addItem(lt3);
    scene->addItem(lt4);
    scene->addItem(qt1);
    scene->addItem(qt2);
    scene->addItem(qt3);
    scene->addItem(qt4);


    for(int i=0;i<8;i++)
    add_item(i);
}

void MainWindow::testing()
{
    QElapsedTimer timer;
    timer.start();
    for(int i=0;i<16;i++)
    {
        t11->get(test[i].first);
    }
    result[0]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<64;i++)
    {
        t12->get(test[i].first);
    }
    result[1]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<128;i++)
    {
        t13->get(test[i].first);
    }
    result[2]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<2048;i++)
    {
        t14->get(test[i].first);
    }
    result[3]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<16;i++)
    {
        t21->get(test[i].first);
    }
    result[4]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<64;i++)
    {
        t22->get(test[i].first);
    }
    result[5]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<128;i++)
    {
        t23->get(test[i].first);
    }
    result[6]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<2048;i++)
    {
        t24->get(test[i].first);
    }
    result[7]=timer.nsecsElapsed();

    print();
}

void MainWindow::add_item(int i)
{
    QTableWidgetItem *it=new QTableWidgetItem ();
    it->setTextAlignment(Qt::AlignCenter);
    it->setText(QString::fromStdString(std::to_string(result[i])));
    ui->tableWidget->setItem(i,0,it);

}

void MainWindow::on_pushButton_clicked()
{
    for(int i=0;i<2048;i++)
        test[i]={gen(),gen()};
    t11->clear();
    t12->clear();
    t13->clear();
    t14->clear();
    t21->clear();
    t22->clear();
    t23->clear();
    t24->clear();
    scene->clear();

    QElapsedTimer timer;
    timer.start();
    for(int i=0;i<16;i++)
    {
        t11->insert(test[i].first,test[i].second);
    }
    result[0]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<64;i++)
    {
        t12->insert(test[i].first,test[i].second);
    }
    result[1]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<128;i++)
    {
        t13->insert(test[i].first,test[i].second);
    }
    result[2]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<2048;i++)
    {
        t14->insert(test[i].first,test[i].second);
    }
    result[3]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<16;i++)
    {
        t21->insert(test[i].first,test[i].second);
    }
    result[4]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<64;i++)
    {
        t22->insert(test[i].first,test[i].second);
    }
    result[5]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<128;i++)
    {
        t23->insert(test[i].first,test[i].second);
    }
    result[6]=timer.nsecsElapsed();

    timer.start();
    for(int i=0;i<2048;i++)
    {
        t24->insert(test[i].first,test[i].second);
    }
    result[7]=timer.nsecsElapsed();


    testing();
}

