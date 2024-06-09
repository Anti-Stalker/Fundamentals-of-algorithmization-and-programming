#ifndef DIALOG_2_2_1_H
#define DIALOG_2_2_1_H

#include <QDialog>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include <QTimer>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QGraphicsItemAnimation>
#include <QTimeLine>

namespace Ui {
class Dialog_2_2_1;
}

class Led_3 : public QGraphicsRectItem{
public:
    Led_3(int h){
        setRect(-700, 200,1400, h);
        setBrush(Qt::blue);
    }

    Led_3(){
        setRect(-700, 210,1400,140);
        setBrush(Qt::blue);
    }
};

class People_3 : public QGraphicsItem{
public :
    People_3(QGraphicsItem *parent = nullptr) : QGraphicsItem(parent) {}

    QRectF boundingRect() const override {
        return QRectF(-150, 70, 250, 150); // Прямоугольник, описывающий границы объекта
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
        painter->drawEllipse(-100,167, 30, 30); // Голова (круг)

        // Рисуем туловище
        painter->drawLine(-68, 182, 60, 182); // Тело

        // Рисуем руки
        painter->drawLine(-35, 182, -27, 200); // Левая рука
        painter->drawLine(-35, 182, -40, 200); // Правая рука

        // Рисуем ноги
        painter->drawLine(60, 182, 65, 200); // Левая нога
        painter->drawLine(60, 182, 55, 200); // Правая нога
    }
};

class Dialog_2_2_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_2_2_1(int h,QWidget *parent = nullptr);
    ~Dialog_2_2_1();

private:
    Ui::Dialog_2_2_1 *ui;
    QGraphicsScene * scene;
    Led_3 *led;
    Led_3 * voda;
    People_3 * people;
};

#endif // DIALOG_2_2_1_H
