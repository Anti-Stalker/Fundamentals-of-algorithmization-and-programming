#ifndef EDGE_H
#define EDGE_H

#include <QTextDocument>
#include <QGraphicsTextItem>
#include "vertex.h"
#include <QGraphicsPathItem>
#include <QGraphicsScene>
#include <QObject>

class Vertex;

class Edge : public QObject, public QGraphicsPathItem
{
    Q_OBJECT
public:
    Edge(Vertex *startVertex, Vertex *endVertex, bool isDirect, QGraphicsItem *parent = 0);
    Vertex *startVertex() const;
    Vertex *endVertex() const;
    bool directed;
    bool isDirected() const { return directed; }
    int getStart();
    int getEnd();
    qreal m_weight;
    void setWeight(qreal number);
    void setHighlighted(bool highlighted);
private:

    Vertex *start, *end;

    QPolygonF arrowHead;
    QGraphicsTextItem *textItem;
    void centerText();
private slots:


protected:

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
public slots:
    void updatePosition();
    void updateSize();
    void updateWeight();

};

#endif // EDGE_H

