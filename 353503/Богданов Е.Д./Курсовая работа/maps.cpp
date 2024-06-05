#include "maps.h"

Maps::Maps() = default;

Maps::Maps(QPointF point, QString file, int wight, int height) : point(point), file(file), wight(wight), height(height) {}

QRectF Maps::boundingRect() const
{
  return {point.x(), point.y(), wight, height};
}

void Maps::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  Q_UNUSED(*option)
  Q_UNUSED(*widget)

  QPixmap card(file);

  painter->drawPixmap(point, card);
}
