#ifndef DIALOG_2_1_2_H
#define DIALOG_2_1_2_H

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
class Dialog_2_1_2;
}

class Led_2 : public QGraphicsRectItem{
public:
    Led_2(int h){
        setRect(-700, 200,1400, h);
        setBrush(Qt::blue);
    }

    Led_2(){
        setRect(-700, 210,1400,140);
        setBrush(Qt::blue);
    }
};

class People_2 : public QGraphicsItem{
public :
    People_2(QGraphicsItem *parent = nullptr) : QGraphicsItem(parent) {}

    QRectF boundingRect() const override {
        return QRectF(-25, 70, 50, 130); // Прямоугольник, описывающий границы объекта
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

class Dialog_2_1_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_2_1_2(int h,QWidget *parent = nullptr);
    ~Dialog_2_1_2();

private:
    Ui::Dialog_2_1_2 *ui;
    QGraphicsScene * scene;
    Led_2 *led;
    Led_2 * voda;
    People_2 * people;
};

#endif // DIALOG_2_1_2_H
