#ifndef MOVING_ELLIPSE_H
#define MOVING_ELLIPSE_H
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
#include<QtWidgets>
class Moving_ellipse : public QWidget
{
protected :
    int x=50;
    int h,w=50;
    void paintEvent(QPaintEvent *event) override ;
public:
    void moveEllipse();
};

#endif // MOVING_ELLIPSE_H
