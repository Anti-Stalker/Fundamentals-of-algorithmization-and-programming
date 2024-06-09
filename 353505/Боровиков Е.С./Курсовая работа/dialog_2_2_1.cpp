#include "dialog_2_2_1.h"
#include "ui_dialog_2_2_1.h"

Dialog_2_2_1::Dialog_2_2_1(int h,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_2_2_1)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #FFFFFF;");
    scene = new QGraphicsScene(-700,-350,1400,700,this);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());
    led = new Led_3(h);
    QColor iceColor("#B0E0E6"); // Цвет льда
    led->setBrush(iceColor); // Устанавливаем кисть
    led->setPen(QPen(iceColor));
    voda = new Led_3();
    people = new People_3();
    scene->addItem(people);
    scene->addItem(voda);
    scene->addItem(led);
    QTimer::singleShot(2000, this, [=]() {
        // Вывод сообщения в виде окна
        QMessageBox::information(this, "Информация", "Человек не провалился!");

        // Закрытие сообщения и диалогового окна
        close();
    });
}

Dialog_2_2_1::~Dialog_2_2_1()
{
    delete ui;
}



