#include"moving_ellipse.h"
#ifndef FACE_H
#define FACE_H

class face :public Moving_ellipse
{
protected:
     void paintEvent(QPaintEvent *event) override;
    int x=100;
     int h=10;
    int w=35;
     int x1=100;
public:
     void move_eyes_right();
    void move_eyes_left();
     void close_mouth();
    void open_mouth();
};

#endif // FACE_H
