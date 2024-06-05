#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QGraphicsScene>
#include "QPainterPath"
#include "QGraphicsPathItem"
#include "QGraphicsLineItem"
#include "QGraphicsTextItem"
#include "Consts.h"

class Graphic : public QGraphicsScene
{
public:
    explicit Graphic(QObject *parent = nullptr);
    void updateGraphic();
    void addValue(int value);
    void createAsix();
    void clearGraphic();

private:
    QGraphicsPathItem *pathItem;
    QVector<int> _values;
    QVector<int> _temp_values;
    QPainterPath _graph;
    QGraphicsTextItem *asix_x_text;
    QGraphicsTextItem *asix_y_text;
    int _max_points = GRAPH_SMOOTH;
    int _max_value{};
};

#endif // GRAPHIC_H
