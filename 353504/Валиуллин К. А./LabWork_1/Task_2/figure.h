#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsObject>

#include "dialogsetxy.h"

struct CoordinatesXY {
    int x,y;
};

class Figure : public QGraphicsObject {

public:
    Figure();
    virtual float findSquare();
    virtual float findPerimeter();
    // virtual void findCenterOfMass();
    void setPosition();
    CoordinatesXY showPosition();

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    void upScale();
    void downScale();

    float getScale();

    // void rotateLeft();
    // void rotateRight();

    // virtual void setPoints(QMouseEvent *);
    // void mouseMovePressing(QMouseEvent *);
    // void mouseMoveMoving(QMouseEvent *);
    // void mouseMovePressing(QMouseEvent *);
    // void mouseMoveMoving(QMouseEvent *);
    QRectF boundingRect() const override;

    void rotateRight();
    void rotateLeft();
    bool movable;

public slots:
    void receiveValues(valuesNewXY &XY);

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int xCoord, yCoord;
    float scale = 1.0;
};

#endif // FIGURE_H
