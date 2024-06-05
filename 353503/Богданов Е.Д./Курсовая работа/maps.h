#ifndef MAPS_H
#define MAPS_H

#include <QGraphicsObject>
#include <QPainter>



class Maps : public QGraphicsObject {
  Q_OBJECT
 public:
  Maps();
  Maps(QPointF point, QString file, int wight, int height);

 protected:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;

 private:
  QString file;
  QPointF point;
  int wight, height;
};

#endif  // MAPS_H
