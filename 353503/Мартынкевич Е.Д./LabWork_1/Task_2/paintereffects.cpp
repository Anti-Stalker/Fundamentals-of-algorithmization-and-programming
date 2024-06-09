#include "paintereffects.h"
#include "circle.h"
#include "rhombus.h"
#include "rect.h"
#include "triangle.h"
#include <QtMath>
#include "star.h"

PainterEffects::PainterEffects() {}

PainterEffects::~PainterEffects()
{
    delete actual_figure;
}

int PainterEffects::actual_figure_type()
{
    return actual_type;
}

void PainterEffects::set_actual_figure_type(const int type)
{
    actual_type = type;
}

void PainterEffects::set_create(bool c)
{
    create = c;
}

figures *PainterEffects::get_actual_figure()
{
    return actual_figure;
}

void PainterEffects::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(create) {
    switch(actual_type) {
    case TriangleT: {
        figures *item = new triangle(event->scenePos());
        item->setPos(event->pos());
        actual_figure = item;
        break;
    }
    case RectT: {
        rect *item = new rect(event->scenePos());
        item->setPos(event->pos());
        actual_figure = item;
        break;
    }
    case RhombusT:
    {
        rhombus *item = new rhombus(event->scenePos());
        item->setPos(event->pos());
        actual_figure = item;
        break;
    }
    case star5:
    {
        star *item = new star(5, event->scenePos());
        item->setPos(event->pos());
        actual_figure = item;
        break;
    }
    case star6:
    {
        star *item = new star(6, event->scenePos());
        item->setPos(event->pos());
        actual_figure = item;
        break;
    }
    case CircleT:
    {
        circle *item = new circle(event->scenePos());
        item->setPos(event->pos());
        actual_figure = item;
        break;
    }
    case star7:
    {
        star *item = new star(7, event->scenePos());
        item->setPos(event->pos());
        actual_figure = item;
        break;
    }
    case star8:
    {
        star *item = new star(8, event->scenePos());
        item->setPos(event->pos());
        actual_figure = item;
        break;
    }
    default:
        break;
    }

    this->addItem(actual_figure);

    }
    else {

        QGraphicsItem* it = this->itemAt(event->scenePos(), QTransform());
        if(it) {
            actual_figure = dynamic_cast<figures*>(it);

            scene_start_point.setX(actual_figure->x() - event->scenePos().x());
            scene_start_point.setY(actual_figure->y() - event->scenePos().y());

            //start_point.setX(actual_figure->mapToScene(actual_figure->startPoint()).x() - event->scenePos().x());
            //start_point.setY(actual_figure->mapToScene(actual_figure->startPoint()).y() - event->scenePos().y());

            //end_point.setX(actual_figure->mapToScene(actual_figure->endPoint()).x() - event->scenePos().x());
            //end_point.setY(actual_figure->mapToScene(actual_figure->endPoint()).y() - event->scenePos().y());

            QPointF center = actual_figure->boundingRect().center();
            QPointF centerSceneCord = actual_figure->mapToScene(center);

            double cx = centerSceneCord.x();
            double cy = centerSceneCord.y();
            double dx = cx - event->scenePos().x();
            double dy = cy - event->scenePos().y();

            actual_figure->rotation_angle = fmod(calculateAngle(dx, -dy) - actual_figure->rotation(), 360);
            //c = actual_figure->centre();
        }
        else {
            actual_figure = nullptr;
        }
    }

    emit signal_of_changin_smf();
}

void PainterEffects::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (create) {
        actual_figure->setEndPoint(event->scenePos());
        this->update(QRectF(0, 0, this->width(), this->height()));
    }
    else {
        if(actual_figure) {

            if(is_ctrl_pressed) {
                QPointF center = actual_figure->boundingRect().center();
                QPointF centerSceneCord = actual_figure->mapToScene(center);

                double cx = centerSceneCord.x();
                double cy = centerSceneCord.y();
                double dx = cx - event->scenePos().x();
                double dy = cy - event->scenePos().y();

                actual_figure->setTransformOriginPoint(center);
                actual_figure->setRotation(calculateAngle(dx, -dy) - actual_figure->rotation_angle);
            }
            else{
                actual_figure->setPos(scene_start_point + event->scenePos());

                //actual_figure->setStartPoint(start_point + event->scenePos());
                //actual_figure->setEndPoint(end_point + event->scenePos());
            }

            this->update(QRectF(0, 0, this->width(), this->height()));
        }
    }

    this->update();
    emit signal_of_changin_smf();
}

void PainterEffects::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

double PainterEffects::calculateAngle(const double dx, const double dy) {
    double angleInRadians = atan2(dx, dy);

    // Преобразуем угол в градусы
    double angleInDegrees = (angleInRadians * 180.0) / M_PI;

    return angleInDegrees;
}
