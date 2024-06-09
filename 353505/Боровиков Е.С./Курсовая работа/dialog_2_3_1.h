#ifndef DIALOG_2_3_1_H
#define DIALOG_2_3_1_H

#include <QDialog>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include <QTimer>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include<QDebug>

namespace Ui {
class Dialog_2_3_1;
}

class HealthBar : public QGraphicsRectItem {
public:
    HealthBar(int fallHeight, QGraphicsItem *parent = nullptr) : QGraphicsRectItem(parent), fallHeight(fallHeight) {
        // Определение высоты здоровья в зависимости от высоты падения
        setRect(-300, -340, 300, 20); // Прямоугольник здоровья
        setBrush(Qt::green); // Зеленый цвет
        setPen(QPen(Qt::black)); // Черная оконтовка
    }

    void updateHealth(int newFallHeight) {
        // Обновление ширины здоровья при изменении высоты падения
        int healthWidth = newFallHeight * 3; // Примерная зависимость ширины здоровья от высоты падения
        setRect(-300, -340, 300 - healthWidth , 20); // Обновление размеров прямоугольника здоровья
    }

private:
    int fallHeight; // Высота падения человека
};

class FiveFloorBuilding : public QGraphicsItem
{
public:
    FiveFloorBuilding(QGraphicsItem *parent = nullptr) : QGraphicsItem(parent) {
        setFlag(QGraphicsItem::ItemIsSelectable, false);
        setFlag(QGraphicsItem::ItemIsMovable, false);
    }

    QRectF boundingRect() const override {
        return QRectF(-50, -150, 100, 300); // Прямоугольник, описывающий границы объекта
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        Q_UNUSED(option);
        Q_UNUSED(widget);

        // Устанавливаем толщину пера
        QPen pen;
        pen.setWidth(2);
        painter->setPen(pen);

        // Рисуем корпус дома
        painter->setBrush(QColor("#F5DEB3")); // Бежевый цвет
        painter->drawRect(85, -282,160,480); // Основание дома

        // Рисуем окна на каждом этаже
        for (int floor = 0; floor < 5; ++floor) {
            for (int window = 0; window < 3; ++window) {
                int x = 110 + window * 40; // X координата окна
                int y = 20 - floor * 70; // Y координата окна
                painter->setBrush(Qt::white);
                painter->drawRect(x, y, 30,60 ); // Окно
            }
        }

        // Рисуем дверь
        painter->setBrush(QColor("#8B4513")); // Коричневый цвет
        painter->drawRect(140, 98, 50, 100); // Дверь
    }
};

class Led_5 : public QGraphicsRectItem{
public:
    Led_5(int h){
        setRect(-700, 200,1400, h);
        setBrush(Qt::blue);
    }

    Led_5(){
        setRect(-700, 210,1400,140);
        setBrush(Qt::blue);
    }
};

class People_5 : public QGraphicsItem{
public :
    People_5(QGraphicsItem *parent = nullptr) : QGraphicsItem(parent) {}

    QRectF boundingRect() const override {
        return QRectF(-6, 38, 14, 53); // Прямоугольник, описывающий границы объекта
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        Q_UNUSED(option);
        Q_UNUSED(widget);

        // Устанавливаем толщину пера
        QPen pen;
        pen.setWidth(2);
        painter->setPen(pen);

        // Рисуем голову
        painter->setBrush(Qt::black);
        painter->drawEllipse(-5, 40, 10, 10); // Голова (круг)

        // Рисуем туловище
        painter->drawLine(0, 48, 0, 72); // Тело

        // Рисуем руки
        painter->drawLine(0, 48, -6, 60); // Левая рука
        painter->drawLine(0, 48, 6, 60); // Правая рука

        // Рисуем ноги
        painter->drawLine(0, 72, -5, 90); // Левая нога
        painter->drawLine(0, 72, 5, 90); // Правая нога
    }

};

class Dialog_2_3_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_2_3_1(int tol,int h, QWidget *parent = nullptr);
    ~Dialog_2_3_1();

private:
    Ui::Dialog_2_3_1 *ui;
    QGraphicsScene * scene;
    Led_5 *led;
    Led_5 * voda;
    People_5 * people;
    FiveFloorBuilding * dom;

    HealthBar * healthBar;
};

#endif // DIALOG_2_3_1_H
