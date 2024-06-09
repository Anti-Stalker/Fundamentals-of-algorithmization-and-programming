#include "dialog_2_3_1.h"
#include "ui_dialog_2_3_1.h"

Dialog_2_3_1::Dialog_2_3_1(int tol, int h, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_2_3_1)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #FFFFFF;");
    scene = new QGraphicsScene(-700,-350,1400,700,this);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());
    led = new Led_5(tol);

    healthBar = new HealthBar(h);

    QColor iceColor("#B0E0E6"); // Цвет льда
    led->setBrush(iceColor); // Устанавливаем кисть
    led->setPen(QPen(iceColor));
    voda = new Led_5();
    people = new People_5();
    dom = new FiveFloorBuilding();
    scene->addItem(dom);
    scene->addItem(people);
    scene->addItem(voda);
    scene->addItem(led);

    scene->addItem(healthBar);

    people->setPos(123,-376);

    QTimer::singleShot(1000, this, [=]() {
        // Создание анимации для проваливания человека под лед
        QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
        animation->setItem(people);

        // Длительность анимации 2 секунды
        animation->setTimeLine(new QTimeLine(2000));

        // Задаем кадры анимации
        animation->timeLine()->setFrameRange(0, 100);

        // Начальное положение (человек находится внутри дома)
        QPointF startInside(120, -376);

        // Конечное положение (человек вылезает из окна)
        QPointF endOutside(60, -376);

        // Первый кадр: человек вылезает из окна
        animation->setPosAt(0, startInside);

        // Второй кадр: человек перемещается горизонтально вправо
        animation->setPosAt(0.5, endOutside);

        // Третий кадр: человек падает вертикально вниз
        QPointF endFall(70, 110);
        animation->setPosAt(1, endFall);

        // Запускаем анимацию
        animation->timeLine()->start();

        // Вычисляем урон по формуле h * 3

        // Обновляем здоровье

        QTimer::singleShot(2000, this, [=]() {
          healthBar->updateHealth(h);
        });

        // Создаем таймер для вывода сообщения о провале под лед в конце анимации
        QTimer::singleShot(3000, this, [=]() {
            // Выводим сообщение о провале под лед
            if(h<100){
            QMessageBox::information(this, "Информация", "Человек не провалился под лед!");
            }else if (h == 100){
                 QMessageBox::information(this, "Информация", "Человек не выжил");
            }
            // Закрываем диалоговое окно
            close();
        });

    });
}

Dialog_2_3_1::~Dialog_2_3_1()
{
    delete ui;
}



