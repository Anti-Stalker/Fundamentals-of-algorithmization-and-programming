#ifndef DIALOG_2_1_1_H
#define DIALOG_2_1_1_H

#include <QDialog>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include <QTimer>
#include <QMessageBox>

namespace Ui {
class Dialog_2_1;
}

class Led : public QGraphicsRectItem{
public:
    Led(int h){
        setRect(-700, 200,1400, h);
        setBrush(Qt::blue);
    }

    Led(){
        setRect(-700, 210,1400,140);
        setBrush(Qt::blue);
    }
};

class People : public QGraphicsItem{
public :
    People(QGraphicsItem *parent = nullptr) : QGraphicsItem(parent) {}

    QRectF boundingRect() const override {
        return QRectF(-25, 70, 50, 100); // Прямоугольник, описывающий границы объекта
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        Q_UNUSED(option);
        Q_UNUSED(widget);

        // Устанавливаем толщину пера
        QPen pen;
        pen.setWidth(4);
        painter->setPen(pen);

        // Рисуем голову
        painter->setBrush(Qt::black);
        painter->drawEllipse(-10, 80, 20, 20); // Голова (круг)

        // Рисуем туловище
        painter->drawLine(0, 100, 0, 160); // Тело

        // Рисуем руки
        painter->drawLine(0, 100, -20, 130); // Левая рука
        painter->drawLine(0, 100, 20, 130); // Правая рука

        // Рисуем ноги
        painter->drawLine(0, 160, -15, 200); // Левая нога
        painter->drawLine(0, 160, 15, 200); // Правая нога
    }
};

class Dialog_2_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_2_1(int h,QWidget *parent = nullptr);
    ~Dialog_2_1();

private:
    Ui::Dialog_2_1 *ui;
    QGraphicsScene * scene;
    Led *led;
    Led * voda;
    People * people;
};

#endif // DIALOG_2_1_1_H
