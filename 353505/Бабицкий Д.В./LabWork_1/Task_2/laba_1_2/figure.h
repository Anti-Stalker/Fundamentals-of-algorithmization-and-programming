#ifndef FIGURE_H
#define FIGURE_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QApplication>
#include <QMainWindow>
#include <QDockWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsEllipseItem>
#include<QWidget>
#include<QPainterPath>
#include<QMouseEvent>
#include<QGraphicsSceneMouseEvent>
#include<QTimer>
class Figure :public QGraphicsItem
{

public:
    Figure();
};

#endif // FIGURE_H
