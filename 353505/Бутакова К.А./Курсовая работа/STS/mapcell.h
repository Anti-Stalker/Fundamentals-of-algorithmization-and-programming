#ifndef MAPCELL_H
#define MAPCELL_H

#include <QGraphicsObject>

class MapCell : public QGraphicsObject {
    Q_OBJECT
public:
    MapCell();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setColor(QColor brust, QColor pen);
    QColor getBrust(){ return brushColor; }
    QColor getPen(){ return penColor; }

    void setCoor(int x, int y){ m_CoorX = x; m_CoorY = y;}
    int getCoorX(){ return m_CoorX;}
    int getCoorY(){ return m_CoorY;}
    std::string getCoorInfo();

    bool isObstacle(){ return Obstacle; }
    void setObstacle(bool t){ Obstacle = t; }

private:

    QColor brushColor;
    QColor penColor;
    double m_dSide;
    int m_CoorX;
    int m_CoorY;
    bool Obstacle;

protected:
    //
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void GroundIsSelected(MapCell*);
};

#endif
