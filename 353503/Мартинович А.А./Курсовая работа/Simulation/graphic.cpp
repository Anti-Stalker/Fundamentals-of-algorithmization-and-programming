#include "graphic.h"

Graphic::Graphic(QObject *parent)
    : QGraphicsScene{parent}
{
    this->setSceneRect(QRect(0, 0, GRAPH_SCENE_WIDTH, GRAPH_SCENE_HEIGHT));
    pathItem = new QGraphicsPathItem(_graph);
    //pathItem->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));

    asix_x_text = new QGraphicsTextItem();
    asix_x_text->setPos(0, -20);
    addItem(asix_x_text);

    asix_y_text = new QGraphicsTextItem();
    asix_y_text->setPos(width()-10, height());
    addItem(asix_y_text);

    createAsix();

    addItem(pathItem);
    updateGraphic();
}

void Graphic::updateGraphic()
{
    _graph.clear();

    _graph.moveTo(0, GRAPH_SCENE_HEIGHT);

    if (_max_value) {
        for (int i = 0; i < _values.size(); i++) {
            _graph.lineTo(i*this->width()/_values.size(), GRAPH_SCENE_HEIGHT-_values[i]*GRAPH_SCENE_HEIGHT/_max_value);
        }
    }
    pathItem->setPath(_graph);
}

void Graphic::addValue(int value)
{
    _temp_values.append(value);

    if (_temp_values.size() == _max_points) {
        for (int i = 0; i < _max_points-1; i++) {
            value += _temp_values[i];
        }
        value = value / _max_points;
        asix_x_text->setPlainText(QString::number(_max_value));
        asix_y_text->setPlainText(QString::number(_values.size()*_max_points));
        _temp_values.clear();

        if (value > _max_value) {
            _max_value = value;
        }
        _values.append(value);
        updateGraphic();

        if (_values.size() % GRAPH_SMOOTH == 0 && _values.size() != 0) {
            //_max_points++;
        }

    }
}

void Graphic::createAsix()
{
    QGraphicsPathItem *asix = new QGraphicsPathItem();
    QPainterPath asix_path;
    asix_path.lineTo(-2, 15);
    asix_path.lineTo(2, 15);
    asix_path.lineTo(0, 0);
    asix_path.lineTo(0, height());
    asix_path.lineTo(width(), height());
    asix_path.lineTo(width()-15, height()-2);
    asix_path.lineTo(width()-15, height()+2);
    asix_path.lineTo(width(), height());
    asix->setPath(asix_path);
    addItem(asix);
}

void Graphic::clearGraphic()
{
    _values.clear();
    _temp_values.clear();
    _graph.clear();
    _max_points = GRAPH_SMOOTH;
    _max_value = 0;
    asix_x_text->setPlainText("");
    asix_y_text->setPlainText("");
    updateGraphic();
    update();
}

