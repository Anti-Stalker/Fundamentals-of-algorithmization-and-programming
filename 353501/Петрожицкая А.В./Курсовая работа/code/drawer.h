#ifndef DRAWER_H
#define DRAWER_H
#include <QImage>
#include <QPainter>
#include<QColor>
#include<QWidget>

class Drawer
{
private:
    QImage image;
    QPainter painter;
    int x;
    int y;
    int blockSpacing = 20;
    int blockWidth = 100;
    int blockHeight = 50;

public:
    Drawer();
    void drawStart();
    void drawInput();
    void drawProcess();
    void drawDecision();
    void drawLoop();
    void drawOutput();
    void drawEnd();
    void drawLine();
    QImage returnImage();
};

#endif // DRAWER_H
