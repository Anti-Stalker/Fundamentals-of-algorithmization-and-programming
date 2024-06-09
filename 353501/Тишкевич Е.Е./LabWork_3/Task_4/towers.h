#ifndef TOWERS_H
#define TOWERS_H
#include<QPainter>
#include<QGraphicsObject>
class towers : public QGraphicsObject
{
public:
    bool isChanging = true;
    int n = 1;
      bool stop = false;
    void setN(int num);
    towers();
    bool finished = false;
    int lastEmptyPositionA = 230;
    int lastEmptyPositionB = 230;
    int lastEmptyPositionC = 230;

    int posN[10] = {180, 160, 140, 120, 100, 80, 60, 40, 20, 0};

    void changeNumberOfRings(int arg);
    void animate(int num,char from,char to);
protected:

    int posMinN[10] = {-180, -160, -140, -120, -100, -80, -60, -40, -20, 0};
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const;
    int diskWidth[10] = {240, 220, 200, 180, 160, 140, 120, 100, 80, 60};
    int diskHeight = 20;
    QPointF diskPos[10];
    int towerX[3] = {-300, 0, 300};
    bool onY[10]{};
    bool onX[10]{};
    bool diskUnused[10] = {true,true,true,true,true,true,true,true,true,true};

};

#endif // TOWERS_H
