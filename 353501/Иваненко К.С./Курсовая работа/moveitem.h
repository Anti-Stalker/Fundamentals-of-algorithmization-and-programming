#pragma once

#ifndef MOVEITEM_H
#define MOVEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

#include "note.h"

class MoveItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    enum ItemType
    {
        noteType,
        tagType
    };
    explicit MoveItem(ItemType type, QObject *parent = 0);
    ~MoveItem();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

signals:
    void itemDoubleClicked(const int id, const QString &name);

public:
    void setupMoveItemNote(const Note &note);
    void setupMoveItemTag(const QString tag);
    QPointF getPosition() const;
    QString title;
    QString tags;
    int id;
    ItemType itemType;
    QGraphicsTextItem *titleText;
};

#endif // MOVEITEM_H