#ifndef PAINTEREFFECTS_H
#define PAINTEREFFECTS_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include "figures.h"

class PainterEffects : public QGraphicsScene
{
    Q_OBJECT

    Q_PROPERTY(int actual_figure_type READ actual_figure_type WRITE set_actual_figure_type NOTIFY SignalOfChangingType)

public:
    explicit PainterEffects();
    ~PainterEffects();

    QPointF start_point;
    QPointF end_point;
    QPointF scene_start_point;
    int actual_figure_type();
    void set_actual_figure_type(const int type);
    void set_create(bool c);
    figures *get_actual_figure();
    bool is_ctrl_pressed = false;

    double calculateAngle(double dx, double dy);

    enum FigureTypes {
        TriangleT,
        RectT,
        RhombusT,
        CircleT,
        star5,
        star6,
        star7,
        star8
    };

signals:
    void SignalOfChangingType();
    void signal_of_changin_smf();

private:
    int actual_type;
    figures* actual_figure = 0;
    bool create;
    QPointF c;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


};

#endif // PAINTEREFFECTS_H
