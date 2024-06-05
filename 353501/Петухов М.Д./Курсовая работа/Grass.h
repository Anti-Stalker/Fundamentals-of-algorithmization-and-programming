#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsObject>

class Grass : public QGraphicsObject
{
public:

    Grass(QGraphicsItem* parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

public:
    int amount = 2;

    QPixmap m_image;
    qreal m_height = 100;
    qreal m_width = 100;
};
