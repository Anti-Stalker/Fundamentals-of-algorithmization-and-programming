#ifndef FIGURES_H
#define FIGURES_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsView>

class figures : public QObject, public QGraphicsItem
{

Q_OBJECT

Q_PROPERTY(QPointF startPoint READ startPoint WRITE setStartPoint NOTIFY point_changed)
Q_PROPERTY(QPointF endPoint READ endPoint WRITE setEndPoint NOTIFY point_changed)

public:
    explicit figures(QPointF point, QObject* parent = 0);
    ~figures();

    QRectF boundingRect() const;

    QPointF startPoint() const;
    QPointF endPoint() const;

    void  setStartPoint(const QPointF point);
    void  setEndPoint(const QPointF point);
    //void  set_centre(const QPointF point);

    double perimetr();
    double square();
    QPointF centre();

    int rotation_angle = 0;

signals:
    void point_changed();

private:
    QPointF m_startpoint;
    QPointF m_endpoint;


public slots:
    void updeteRect();

protected:
    double m_perimetr;
    double m_square;
    QPointF m_centre;

    virtual void set_perimetr() = 0;
    virtual void set_square() = 0;
    void  set_centre();
};

#endif // FIGURES_H
