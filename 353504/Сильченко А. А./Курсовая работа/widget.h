    #ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

#include <fish.h>
#include <fishes.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();
     void fishes(Fishes *it);
     bool eat(Fishes *it);

     void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
     void on_exitButton_clicked();
 private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    int N=1;
    QTimer *timer;
    Fishes *it = new Fishes();
    Fish *item = new Fish();
};

#endif // WIDGET_H
