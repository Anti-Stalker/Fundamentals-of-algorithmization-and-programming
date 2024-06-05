#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsObject>
#include <QTimer>
#include <QPushButton>

class Factory : public QGraphicsObject
{
    Q_OBJECT
public:

    Factory(int* collectedEggs, QGraphicsItem* parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
private:
    QPixmap m_image;

    QTimer* timerToMakeProduct;
    int timeToMakeProduct = 16000;
    int progress = 0;
    int* _collectedEggs;
    bool isFactoryWorking = false;
private:
    void hoverEnterEvent(QGraphicsSceneHoverEvent*) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *aEvent) override;

    void updateMakingProduct();
signals:
    void updateCollectedEggsLabelSignal();
    void makeProduct();
};
