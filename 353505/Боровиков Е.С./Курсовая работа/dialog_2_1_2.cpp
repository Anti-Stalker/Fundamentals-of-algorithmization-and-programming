#include "dialog_2_1_2.h"
#include "ui_dialog_2_1_2.h"

Dialog_2_1_2::Dialog_2_1_2(int h,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_2_1_2)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #FFFFFF;");
    scene = new QGraphicsScene(-700,-350,1400,700,this);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());
    led = new Led_2(h);
    QColor iceColor("#B0E0E6"); // Цвет льда
    led->setBrush(iceColor); // Устанавливаем кисть
    led->setPen(QPen(iceColor));
    voda = new Led_2();
    people = new People_2();
    scene->addItem(people);
    scene->addItem(voda);
    scene->addItem(led);
    QTimer::singleShot(1000, this, [=]() {
        // Создание анимации для проваливания человека под лед
        QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
        animation->setItem(people); // Установка анимируемого объекта

        // Добавление кадра анимации
        animation->setTimeLine(new QTimeLine(4000)); // Длительность анимации 2 секунды
        animation->timeLine()->setFrameRange(0, 100); // Задание диапазона кадров

        // Установка стартового и конечного состояний объекта
        QPointF start(people->x(), 0); // Начальная позиция человека
        QPointF end(people->x(), 140); // Конечная позиция человека (под лед)
        animation->setPosAt(0, start); // Установка стартового состояния
        animation->setPosAt(1, end); // Установка конечного состояния

        // Запуск анимации
        animation->timeLine()->start();

        // Создание таймера для вывода сообщения о провале под лед в конце анимации
        QTimer::singleShot(3500, this, [=]() {
            // Вывод сообщения о провале под лед
            QMessageBox::information(this, "Информация", "Человек провалился под лед!");

            // Закрытие диалогового окна
            close();
        });
    });
}

Dialog_2_1_2::~Dialog_2_1_2()
{
    delete ui;
}



