#include "mainwindow.h"
#include<QPainter>
#include"circle.h"
#include <QApplication>
#include<QPushButton>
#include<QWidget>
#include <QVBoxLayout>
#include<QLabel>
#include<QTimer>
#include<QTime>
#include<QSpinBox>
#include"rectangle.h"
#include"hexagon.h"
#include"rhombus.h"
#include"square.h"
#include"star_5.h"
#include"star_6.h"
#include"star_8.h"
#include"triangle.h"
int main(int argc, char *argv[])
{
    bool b1=1,b2=1,b3=1,b4=1,b5=1,b6=1,b7=1,b8=1,b9=1;
    qreal p=1;
    QApplication a(argc, argv);
    QMainWindow window;
    QWidget w;
    QPushButton circle_click("create circle");
    QPushButton circle_destroy("destroy circle");
    QPushButton triangle_click("create triangle");
    QPushButton triangle_destroy("destroy triangle");
    QPushButton square_click("create square");
    QPushButton square_destroy("destroy square");
    QPushButton rectangle_click("create rectangle");
    QPushButton rectangle_destroy("destroy rectangle");
    QPushButton rhombus_click("create rhombus");
    QPushButton rhombus_destroy("destroy rhombus");
    QPushButton hexagon_click("create hexagon");
    QPushButton hexagon_destroy("destroy hexagon");
    QPushButton st5_click("create star(5)");
    QPushButton st5_destroy("destroy star(5)");
    QPushButton* st6_click=new QPushButton("create star(6)");
    QPushButton st6_destroy("destroy star(6)");
    QPushButton st8_click("create star(8)");
    QPushButton st8_destroy("destroy star(8)");
    QPushButton moveRight("move_right");
    QPushButton Rotate("rotate");
    QPushButton moveLeft("move_left");
    QPushButton moveUp("move_up");
    QPushButton moveDown("move_down");
    QPushButton mah("up_scale");
    QPushButton mah1("release_scale");
    QGraphicsScene *scene=new QGraphicsScene;
    QGraphicsView view(scene);
    window.setCentralWidget(&w);
    QGridLayout *layout=new QGridLayout(&w);
    QLabel l1;
    QLabel l2;
    QLabel l3;
    QLabel x;
    QLabel y;
    QLabel area;
    QLabel perimetr;
    l1.setText("Coordinates of x and y ");
    l2.setText("Perimetr");
    l3.setText("Area");
    Circle circle;
    triangle tr;
    Square square;
    Rectangle rectangle;
    Rhombus rhombus;
    hexagon hh;
    star_5 st5;
    star_6 st6;
    star_8 st8;




    w.setFixedSize(1500,1000);
    layout->addWidget(&circle_click,10,0);
    layout->addWidget(&circle_destroy,11,0);
    layout->addWidget(&triangle_click,10,1);
    layout->addWidget(&triangle_destroy,11,1);
    layout->addWidget(&square_click,10,2);
    layout->addWidget(&square_destroy,11,2);
    layout->addWidget(&rectangle_click,8,3);
    layout->addWidget(&rectangle_destroy,9,3);
    layout->addWidget(&rhombus_click,8,4);
    layout->addWidget(&rhombus_destroy,9,4);
    layout->addWidget(&mah,10,4);
    layout->addWidget(&mah1,11,4);
    layout->addWidget(&hexagon_click,8,2);
    layout->addWidget(&hexagon_destroy,9,2);
    layout->addWidget(&st5_click,8,0);
    layout->addWidget(&st5_destroy,9,0);
    layout->addWidget(st6_click,10,3);
    layout->addWidget(&st6_destroy,11,3);
    layout->addWidget(&st8_click,8,1);
    layout->addWidget(&st8_destroy,9,1);
    layout->addWidget(&view,1,1);
    layout->addWidget(&Rotate,8,6);
    layout->addWidget(&l1,8,7);
    layout->addWidget(&l2,9,7);
    layout->addWidget(&l3,10,7);
    layout->addWidget(&x,8,8);
    layout->addWidget(&y,8,10);
    layout->addWidget(&perimetr,9,8);
    layout->addWidget(&area,10,8);
    layout->addWidget(&moveRight,8,5);
    layout->addWidget(&moveLeft,9,5);
    layout->addWidget(&moveUp,10,5);
    layout->addWidget(&moveDown,11,5);
    double x1;
    double y1;
    double areap;
    double perimetrp;
    QTimer timer1;
    int intervl=5;
    timer1.setInterval(intervl);
    QTimer timer2;
    timer2.setInterval(intervl);
    QTimer timer3;
    timer3.setInterval(intervl);
    QTimer timer4;
    timer4.setInterval(intervl);
    QTimer timer5;
    timer5.setInterval(intervl);
    QTimer timer6;
    timer6.setInterval(intervl);
    QTimer timer7;
    timer7.setInterval(intervl);
    QObject::connect(&circle_click, &QPushButton::clicked, [&]() {
         scene->addItem(&circle);
        circle.create();
         x1 = circle.centrFindX();
         y1=circle.centrFindY();
         areap=circle.areaFind();
         perimetrp=circle.perFind();
         x.setText(QString::number(x1));
         y.setText(QString::number(y1));
         area.setText(QString::number((areap)));
         perimetr.setText(QString::number(perimetrp));
         scene->update();
         if(b1){
         QObject::connect(&moveRight, &QPushButton::pressed, [&]() {
             timer1.stop();
             timer1.start();
             QObject::connect(&timer1, &QTimer::timeout, [&]() {
                 circle.move_right();
                 x1 = circle.centrFindX();
                 x.setText(QString::number(x1));
                 scene->update();
             });
         });
         QObject::connect(&moveRight, &QPushButton::released, [&]() {
             timer1.stop();
         });
         QObject::connect(&moveLeft, &QPushButton::pressed, [&]() {
             timer2.stop();
             timer2.start();
             QObject::connect(&timer2, &QTimer::timeout, [&]() {
                 x1 = circle.centrFindX();
                 x.setText(QString::number(x1));
                 circle.move_left();
                 scene->update();
             });
             timer2.start();
         });
         QObject::connect(&moveLeft, &QPushButton::released, [&]() {
             timer2.stop();
         });
         QObject::connect(&moveUp, &QPushButton::pressed, [&]() {
             timer3.stop();
             timer3.start();
             QObject::connect(&timer3, &QTimer::timeout, [&]() {
                 y1 = circle.centrFindY();
                 y.setText(QString::number(y1));
                 circle.move_up();
                 scene->update();
             });
         });
         QObject::connect(&moveUp, &QPushButton::released, [&]() {
             timer3.stop();
             scene->update();
         });
         QObject::connect(&moveDown, &QPushButton::pressed, [&]() {
             timer4.start();
             QObject::connect(&timer4, &QTimer::timeout, [&]() {
                 y1 = circle.centrFindY();
                 y.setText(QString::number(y1));
                 circle.move_down();
                 scene->update();
             });
         });
         QObject::connect(&moveDown, &QPushButton::released, [&]() {
             timer4.stop();
             scene->update();
}        );
         QObject::connect(&mah, &QPushButton::pressed, [&]() {
             timer5.start();
             QObject::connect(&timer5, &QTimer::timeout, [&]() {
                 circle.mashUp(&circle);
                 y1 =circle.centrFindY();
                 y.setText(QString::number(y1));
                 x1 = circle.centrFindX();
                 x.setText(QString::number(x1));
                 areap = circle.areaFind();
                 area.setText(QString::number(areap));
                 perimetrp = circle.perFind();
                 perimetr.setText(QString::number(perimetrp));
                 scene->update();
             });
         });
         QObject::connect(&mah, &QPushButton::released, [&]() {
             timer5.stop();
         });
         QObject::connect(&mah1, &QPushButton::pressed, [&]() {
             timer6.start();
             QObject::connect(&timer6, &QTimer::timeout, [&]() {
                 circle.mashDown(&circle);
                 y1 =circle.centrFindY();
                 y.setText(QString::number(y1));
                 x1 = circle.centrFindX();
                 x.setText(QString::number(x1));
                 areap = circle.areaFind();
                 area.setText(QString::number(areap));
                 perimetrp = circle.perFind();
                 perimetr.setText(QString::number(perimetrp));
                 scene->update();
             });
         });
         QObject::connect(&mah1, &QPushButton::released, [&]() {
             timer6.stop();
         });
         b1=0;
         QObject::connect(&Rotate, &QPushButton::pressed, [&]() {
             timer7.start();
             QObject::connect(&timer7, &QTimer::timeout, [&]() {
                 circle.setRotation(p);
                 scene->update();
                 p+=0.1;
             });
         });
         QObject::connect(&Rotate, &QPushButton::released, [&]() {
             timer7.stop();
             p=0;
         });
         }
    });
    QObject::connect(&circle_destroy, &QPushButton::clicked, [&]() {
        circle.destroy();
         scene->removeItem(&circle);
     scene->update();
    });
    QObject::connect(&triangle_destroy, &QPushButton::clicked, [&]() {
        tr.destroy_triangle();
        scene->removeItem(&tr);
        scene->update();
    });
    QObject::connect(&triangle_click, &QPushButton::clicked, [&]() {
        scene->addItem(&tr);
        tr.create_triangle();
        x1 = tr.centrFindX();
        y1=tr.centrFindY();
        areap=tr.areaFind();
        perimetrp=tr.perFind();
        x.setText(QString::number(x1));
        y.setText(QString::number(y1));
        area.setText(QString::number((areap)));
        perimetr.setText(QString::number(perimetrp));
        scene->update();
        if(b2){
            QObject::connect(&moveRight, &QPushButton::pressed, [&]() {
                timer1.stop();
                timer1.start();
                QObject::connect(&timer1, &QTimer::timeout, [&]() {
                    tr.move_right();
                    x1 = tr.centrFindX();
                    x.setText(QString::number(x1));
                    scene->update();
                });
            });
            QObject::connect(&moveRight, &QPushButton::released, [&]() {
                timer1.stop();
            });
            QObject::connect(&moveLeft, &QPushButton::pressed, [&]() {
                timer2.stop();
                timer2.start();
                QObject::connect(&timer2, &QTimer::timeout, [&]() {
                    x1 = tr.centrFindX();
                    x.setText(QString::number(x1));
                    tr.move_left();
                    scene->update();
                });
                timer2.start();
            });
            QObject::connect(&moveLeft, &QPushButton::released, [&]() {
                timer2.stop();
            });
            QObject::connect(&moveDown, &QPushButton::pressed, [&]() {
                timer3.stop();
                timer3.start();
                QObject::connect(&timer3, &QTimer::timeout, [&]() {
                    y1 = tr.centrFindY();
                    y.setText(QString::number(y1));
                    tr.move_up();
                    scene->update();
                });
            });
            QObject::connect(&moveDown, &QPushButton::released, [&]() {
                timer3.stop();
                scene->update();
            });
            QObject::connect(&moveUp, &QPushButton::pressed, [&]() {
                timer4.start();
                QObject::connect(&timer4, &QTimer::timeout, [&]() {
                    y1 = tr.centrFindY();
                    y.setText(QString::number(y1));
                    tr.move_down();
                    scene->update();
                });
            });
            QObject::connect(&moveUp, &QPushButton::released, [&]() {
                timer4.stop();
                scene->update();
            }        );
            QObject::connect(&mah, &QPushButton::pressed, [&]() {
                timer5.start();
                QObject::connect(&timer5, &QTimer::timeout, [&]() {
                    tr.mashUp(&tr);
                    y1 =tr.centrFindY();
                    y.setText(QString::number(y1));
                    x1 = tr.centrFindX();
                    x.setText(QString::number(x1));
                    areap = tr.areaFind();
                    area.setText(QString::number(areap));
                    perimetrp = tr.perFind();
                    perimetr.setText(QString::number(perimetrp));
                    scene->update();
                });
            });
            QObject::connect(&mah, &QPushButton::released, [&]() {
                timer5.stop();
            });
            QObject::connect(&mah1, &QPushButton::pressed, [&]() {
                timer6.start();
                QObject::connect(&timer6, &QTimer::timeout, [&]() {
                    tr.mashDown(&tr);
                    y1 =tr.centrFindY();
                    y.setText(QString::number(y1));
                    x1 = tr.centrFindX();
                    x.setText(QString::number(x1));
                    areap = tr.areaFind();
                    area.setText(QString::number(areap));
                    perimetrp = tr.perFind();
                    perimetr.setText(QString::number(perimetrp));
                    scene->update();
                });
            });
            QObject::connect(&mah1, &QPushButton::released, [&]() {
                timer6.stop();
            });
            b2=0;
            QObject::connect(&Rotate, &QPushButton::pressed, [&]() {
                timer7.start();
                QObject::connect(&timer7, &QTimer::timeout, [&]() {
                    tr.setRotation(p);
                    scene->update();
                    p+=0.1;
                });
            });
            QObject::connect(&Rotate, &QPushButton::released, [&]() {
                timer7.stop();
                p=0;
            });
        }
    });
    QObject::connect(&square_click, &QPushButton::clicked, [&]() {
        scene->addItem(&square);
        square.create_square();
        x1 = square.centrFindX();
        y1=square.centrFindY();
        areap=square.areaFind();
        perimetrp=square.perFind();
        x.setText(QString::number(x1));
        y.setText(QString::number(y1));
        area.setText(QString::number((areap)));
        perimetr.setText(QString::number(perimetrp));
        scene->update();
        if(b3){
        QObject::connect(&moveRight, &QPushButton::pressed, [&]() {
            timer1.stop();
            timer1.start();
            QObject::connect(&timer1, &QTimer::timeout, [&]() {
                square.move_right();
                x1 = square.centrFindX();
                x.setText(QString::number(x1));
                scene->update();
            });
        });
        QObject::connect(&moveRight, &QPushButton::released, [&]() {
        timer1.stop();
        });
        QObject::connect(&moveLeft, &QPushButton::pressed, [&]() {
            timer2.stop();
            timer2.start();
            QObject::connect(&timer2, &QTimer::timeout, [&]() {
                x1 = square.centrFindX();
                x.setText(QString::number(x1));
                square.move_left();
                scene->update();
            });
            timer2.start();
        });
        QObject::connect(&moveLeft, &QPushButton::released, [&]() {
            timer2.stop();
        });
        QObject::connect(&moveUp, &QPushButton::pressed, [&]() {
            timer3.stop();
            timer3.start();
            QObject::connect(&timer3, &QTimer::timeout, [&]() {
                y1 = square.centrFindY();
                y.setText(QString::number(y1));
                square.move_up();
                scene->update();
            });
        });
        QObject::connect(&moveUp, &QPushButton::released, [&]() {
            timer3.stop();
            scene->update();
        });
        QObject::connect(&moveDown, &QPushButton::pressed, [&]() {
            timer4.start();
            QObject::connect(&timer4, &QTimer::timeout, [&]() {
                y1 = square.centrFindY();
                y.setText(QString::number(y1));
                square.move_down();
                scene->update();
            });
        });
        QObject::connect(&moveDown, &QPushButton::released, [&]() {
            timer4.stop();
            scene->update();
        });
        b3=0;
        QObject::connect(&mah, &QPushButton::pressed, [&]() {
            timer5.start();
            QObject::connect(&timer5, &QTimer::timeout, [&]() {
                square.mashUp(&square);
                y1 =square.centrFindY();
                y.setText(QString::number(y1));
                x1 = square.centrFindX();
                x.setText(QString::number(x1));
                areap = square.areaFind();
                area.setText(QString::number(areap));
                perimetrp = square.perFind();
                perimetr.setText(QString::number(perimetrp));
                scene->update();
            });
        });
        QObject::connect(&mah, &QPushButton::released, [&]() {
            timer5.stop();
        });
        QObject::connect(&mah1, &QPushButton::pressed, [&]() {
            timer6.start();
            QObject::connect(&timer6, &QTimer::timeout, [&]() {
                square.mashDown(&square);
                y1 =square.centrFindY();
                y.setText(QString::number(y1));
                x1 = square.centrFindX();
                x.setText(QString::number(x1));
                areap = square.areaFind();
                area.setText(QString::number(areap));
                perimetrp = square.perFind();
                perimetr.setText(QString::number(perimetrp));
                scene->update();
            });
        });
        QObject::connect(&mah1, &QPushButton::released, [&]() {
            timer6.stop();
        });
        QObject::connect(&Rotate, &QPushButton::pressed, [&]() {
            timer7.start();
            QObject::connect(&timer7, &QTimer::timeout, [&]() {
                square.setRotation(p);
                scene->update();
                p+=0.1;
            });
        });
        QObject::connect(&Rotate, &QPushButton::released, [&]() {
            timer7.stop();
            p=0;
        });
        }
    });
    QObject::connect(&square_destroy, &QPushButton::clicked, [&]() {
        square.destroy_square();
        scene->removeItem(&square);
        scene->update();
    });
    QObject::connect(&rectangle_click, &QPushButton::clicked, [&]() {
         scene->addItem(&rectangle);
        rectangle.create_rectangle();
         x1 = rectangle.centrFindX();
         y1=rectangle.centrFindY();
         areap=rectangle.areaFind();
         perimetrp=rectangle.perFind();
         x.setText(QString::number(x1));
         y.setText(QString::number(y1));
         area.setText(QString::number((areap)));
         perimetr.setText(QString::number(perimetrp));
         if(b4){
         QObject::connect(&moveRight, &QPushButton::pressed, [&]() {
             timer1.stop();
             timer1.start();
             QObject::connect(&timer1, &QTimer::timeout, [&]() {
                 rectangle.move_right();
                 x1 =  rectangle.centrFindX();
                 x.setText(QString::number(x1));
                 scene->update();
             });
         });
         QObject::connect(&moveRight, &QPushButton::released, [&]() {
             timer1.stop();
         });
         QObject::connect(&moveLeft, &QPushButton::pressed, [&]() {
             timer2.stop();
             timer2.start();
             QObject::connect(&timer2, &QTimer::timeout, [&]() {
                 x1 =  rectangle.centrFindX();
                 x.setText(QString::number(x1));
                  rectangle.move_left();
                 scene->update();
             });
             timer2.start();
         });
         QObject::connect(&moveLeft, &QPushButton::released, [&]() {
             timer2.stop();
         });
         QObject::connect(&moveUp, &QPushButton::pressed, [&]() {
             timer3.stop();
             timer3.start();
             QObject::connect(&timer3, &QTimer::timeout, [&]() {
                 y1 =  rectangle.centrFindY();
                 y.setText(QString::number(y1));
                  rectangle.move_up();
                 scene->update();
             });
         });
         QObject::connect(&moveUp, &QPushButton::released, [&]() {
             timer3.stop();
             scene->update();
         });
         QObject::connect(&moveDown, &QPushButton::pressed, [&]() {
             timer4.start();
             QObject::connect(&timer4, &QTimer::timeout, [&]() {
                 y1 =rectangle.centrFindY();
                 y.setText(QString::number(y1));
                 rectangle.move_down();
                 scene->update();
             });
         });
         QObject::connect(&moveDown, &QPushButton::released, [&]() {
             timer4.stop();
             scene->update();
         }        );
         b4=0;
         QObject::connect(&mah, &QPushButton::pressed, [&]() {
             timer5.start();
             QObject::connect(&timer5, &QTimer::timeout, [&]() {
                 rectangle.mashUp(&rectangle);
                 y1 =rectangle.centrFindY();
                 y.setText(QString::number(y1));
                 x1 =rectangle.centrFindX();
                 x.setText(QString::number(x1));
                 areap = rectangle.areaFind();
                 area.setText(QString::number(areap));
                 perimetrp = rectangle.perFind();
                 perimetr.setText(QString::number(perimetrp));
                 scene->update();
             });

         });
         QObject::connect(&mah, &QPushButton::released, [&]() {
             timer5.stop();
         });
         QObject::connect(&mah1, &QPushButton::pressed, [&]() {
             timer6.start();
             QObject::connect(&timer6, &QTimer::timeout, [&]() {
                 rectangle.mashDown(&rectangle);
                 y1 =rectangle.centrFindY();
                 y.setText(QString::number(y1));
                 x1 = rectangle.centrFindX();
                 x.setText(QString::number(x1));
                 areap = rectangle.areaFind();
                 area.setText(QString::number(areap));
                 perimetrp = rectangle.perFind();
                 perimetr.setText(QString::number(perimetrp));
                 scene->update();
             });
         });
         QObject::connect(&mah1, &QPushButton::released, [&]() {
             timer6.stop();
         });
         QObject::connect(&Rotate, &QPushButton::pressed, [&]() {
             timer7.start();
             QObject::connect(&timer7, &QTimer::timeout, [&]() {
                 rectangle.setRotation(p);
                 scene->update();
                 p+=0.1;
             });
         });
         QObject::connect(&Rotate, &QPushButton::released, [&]() {
             timer7.stop();
             p=0;
         });
         }
    });
    QObject::connect(&rectangle_destroy, &QPushButton::clicked, [&]() {
        rectangle.destroy_rectangle();
        scene->removeItem(&rectangle);
        scene->update();
    });
    QObject::connect(&rhombus_click, &QPushButton::clicked, [&]() {
         scene->addItem(&rhombus);
        rhombus.create_rhombus();
         x1 = rhombus.centrFindX();
         y1=rhombus.centrFindY();
         areap=rhombus.areaFind();
         perimetrp=rhombus.perFind();
         x.setText(QString::number(x1));
         y.setText(QString::number(y1));
         area.setText(QString::number((areap)));
         perimetr.setText(QString::number(perimetrp));
         scene->update();
         if(b5)
         {
             QObject::connect(&moveRight, &QPushButton::pressed, [&]() {
                 timer1.stop();
                 timer1.start();
                 QObject::connect(&timer1, &QTimer::timeout, [&]() {
                     rhombus.move_right();
                     x1 =  rhombus.centrFindX();
                     x.setText(QString::number(x1));
                     scene->update();
                 });
             });
             QObject::connect(&moveRight, &QPushButton::released, [&]() {
                 timer1.stop();
             });
             QObject::connect(&moveLeft, &QPushButton::pressed, [&]() {
                 timer2.stop();
                 timer2.start();
                 QObject::connect(&timer2, &QTimer::timeout, [&]() {
                     x1 = rhombus.centrFindX();
                     x.setText(QString::number(x1));
                     rhombus.move_left();
                     scene->update();
                 });
                 timer2.start();
             });
             QObject::connect(&moveLeft, &QPushButton::released, [&]() {
                 timer2.stop();
             });
             QObject::connect(&moveDown, &QPushButton::pressed, [&]() {
                 timer3.stop();
                 timer3.start();
                 QObject::connect(&timer3, &QTimer::timeout, [&]() {
                     y1 = rhombus.centrFindY();
                     y.setText(QString::number(y1));
                     rhombus.move_down();
                     scene->update();
                 });
             });
             QObject::connect(&moveDown, &QPushButton::released, [&]() {
                 timer3.stop();
                 scene->update();
             });
             QObject::connect(&moveUp, &QPushButton::pressed, [&]() {
                 timer4.start();
                 QObject::connect(&timer4, &QTimer::timeout, [&]() {
                     y1 =rhombus.centrFindY();
                     y.setText(QString::number(y1));
                     rhombus.move_up();
                     scene->update();
                 });
             });
             QObject::connect(&moveUp, &QPushButton::released, [&]() {
                 timer4.stop();
                 scene->update();
             }        );
             b5=0;
             QObject::connect(&mah, &QPushButton::pressed, [&]() {
                 timer5.start();
                 QObject::connect(&timer5, &QTimer::timeout, [&]() {
                     rhombus.mashUp(&rhombus);
                     y1 =rhombus.centrFindY();
                     y.setText(QString::number(y1));
                     x1 = rhombus.centrFindX();
                     x.setText(QString::number(x1));
                     areap = rhombus.areaFind();
                     area.setText(QString::number(areap));
                     perimetrp = rhombus.perFind();
                     perimetr.setText(QString::number(perimetrp));
                     scene->update();
                 });
             });
             QObject::connect(&mah, &QPushButton::released, [&]() {
                 timer5.stop();
             });
             QObject::connect(&mah1, &QPushButton::pressed, [&]() {
                 timer6.start();
                 QObject::connect(&timer6, &QTimer::timeout, [&]() {
                     rhombus.mashDown(&rhombus);
                     y1 =rhombus.centrFindY();
                     y.setText(QString::number(y1));
                     x1 = rhombus.centrFindX();
                     x.setText(QString::number(x1));
                     areap = rhombus.areaFind();
                     area.setText(QString::number(areap));
                     perimetrp = rhombus.perFind();
                     perimetr.setText(QString::number(perimetrp));
                     scene->update();
                 });
             });
             QObject::connect(&mah1, &QPushButton::released, [&]() {
                 timer6.stop();
             });
             QObject::connect(&Rotate, &QPushButton::pressed, [&]() {
                 timer7.start();
                 QObject::connect(&timer7, &QTimer::timeout, [&]() {
                     rhombus.setRotation(p);
                     scene->update();
                     p+=0.1;
                 });
             });
             QObject::connect(&Rotate, &QPushButton::released, [&]() {
                 timer7.stop();
                 p=0;
             });
         }
    });
    QObject::connect(&rhombus_destroy, &QPushButton::clicked, [&]() {
        rhombus.destroy_rhombus();
        scene->removeItem(&rhombus);
        scene->update();
    });
    QObject::connect(&hexagon_click, &QPushButton::clicked, [&]() {
         scene->addItem(&hh);
        hh.create_hexagon();
         x1 = hh.centrFindX();
         y1=hh.centrFindY();
         areap=hh.areaFind();
         perimetrp=hh.perFind();
         x.setText(QString::number(x1));
         y.setText(QString::number(y1));
         area.setText(QString::number((areap)));
         perimetr.setText(QString::number(perimetrp));
         scene->update();
         if(b6)
         {
             QObject::connect(&moveRight, &QPushButton::pressed, [&]() {
                 timer1.stop();
                 timer1.start();
                 QObject::connect(&timer1, &QTimer::timeout, [&]() {
                     hh.move_right();
                     x1 =  hh.centrFindX();
                     x.setText(QString::number(x1));
                     scene->update();
                 });
             });
             QObject::connect(&moveRight, &QPushButton::released, [&]() {
                 timer1.stop();
             });
             QObject::connect(&moveLeft, &QPushButton::pressed, [&]() {
                 timer2.stop();
                 timer2.start();
                 QObject::connect(&timer2, &QTimer::timeout, [&]() {
                     x1 = hh.centrFindX();
                     x.setText(QString::number(x1));
                     hh.move_left();
                     scene->update();
                 });
                 timer2.start();
             });
             QObject::connect(&moveLeft, &QPushButton::released, [&]() {
                 timer2.stop();
             });
             QObject::connect(&moveUp, &QPushButton::pressed, [&]() {
                 timer3.stop();
                 timer3.start();
                 QObject::connect(&timer3, &QTimer::timeout, [&]() {
                     y1 = hh.centrFindY();
                     y.setText(QString::number(y1));
                     hh.move_up();
                     scene->update();
                 });
             });
             QObject::connect(&moveUp, &QPushButton::released, [&]() {
                 timer3.stop();
                 scene->update();
             });
             QObject::connect(&moveDown, &QPushButton::pressed, [&]() {
                 timer4.start();
                 QObject::connect(&timer4, &QTimer::timeout, [&]() {
                     y1 =hh.centrFindY();
                     y.setText(QString::number(y1));
                     hh.move_down();
                     scene->update();
                 });
             });
             QObject::connect(&moveDown, &QPushButton::released, [&]() {
                 timer4.stop();
                 scene->update();
             }        );
             QObject::connect(&mah, &QPushButton::pressed, [&]() {
                 timer5.start();
                 QObject::connect(&timer5, &QTimer::timeout, [&]() {
                     hh.mashUp(&hh);
                     y1 =hh.centrFindY();
                     y.setText(QString::number(y1));
                     x1 = hh.centrFindX();
                     x.setText(QString::number(x1));
                     areap = hh.areaFind();
                     area.setText(QString::number(areap));
                     perimetrp = hh.perFind();
                     perimetr.setText(QString::number(perimetrp));
                     scene->update();
                 });
             });
             QObject::connect(&mah, &QPushButton::released, [&]() {
                 timer5.stop();
             });
             QObject::connect(&mah1, &QPushButton::pressed, [&]() {
                 timer6.start();
                 QObject::connect(&timer6, &QTimer::timeout, [&]() {
                     hh.mashDown(&hh);
                     y1 =hh.centrFindY();
                     y.setText(QString::number(y1));
                     x1 = hh.centrFindX();
                     x.setText(QString::number(x1));
                     areap = hh.areaFind();
                     area.setText(QString::number(areap));
                     perimetrp = hh.perFind();
                     perimetr.setText(QString::number(perimetrp));
                     scene->update();
                 });
             });
             QObject::connect(&mah1, &QPushButton::released, [&]() {
                 timer6.stop();
             });
             b6=0;
             QObject::connect(&Rotate, &QPushButton::pressed, [&]() {
                 timer7.start();
                 QObject::connect(&timer7, &QTimer::timeout, [&]() {
                     hh.setRotation(p);
                     scene->update();
                     p+=0.1;
                 });
             });
             QObject::connect(&Rotate, &QPushButton::released, [&]() {
                 timer7.stop();
                 p=0;
             });
         }
    });
    QObject::connect(&hexagon_destroy, &QPushButton::clicked, [&]() {
        hh.destroy_hexagon();
        scene->removeItem(&hh);
        scene->update();
    });
    QObject::connect(&st5_click, &QPushButton::clicked, [&]() {

            scene->addItem(&st5);
        st5.create_st5();
            x1 = st5.centrFindX();
            y1=st5.centrFindY();
            areap=st5.areaFind();
            perimetrp=st5.perFind();
            x.setText(QString::number(x1));
            y.setText(QString::number(y1));
            area.setText(QString::number((areap)));
            perimetr.setText(QString::number(perimetrp));
            scene->update();
        if(b7)
        {
            QObject::connect(&moveRight, &QPushButton::pressed, [&]() {
                timer1.stop();
                timer1.start();
                QObject::connect(&timer1, &QTimer::timeout, [&]() {
                    st5.move_right();
                    x1 =  st5.centrFindX();
                    x.setText(QString::number(x1));
                    scene->update();
                });
            });
            QObject::connect(&moveRight, &QPushButton::released, [&]() {
                timer1.stop();
            });
            QObject::connect(&moveLeft, &QPushButton::pressed, [&]() {
                timer2.stop();
                timer2.start();
                QObject::connect(&timer2, &QTimer::timeout, [&]() {
                    x1 = st5.centrFindX();
                    x.setText(QString::number(x1));
                    st5.move_left();
                    scene->update();
                });
                timer2.start();
            });
            QObject::connect(&moveLeft, &QPushButton::released, [&]() {
                timer2.stop();
            });
            QObject::connect(&moveUp, &QPushButton::pressed, [&]() {
                timer3.stop();
                timer3.start();
                QObject::connect(&timer3, &QTimer::timeout, [&]() {
                    y1 = st5.centrFindY();
                    y.setText(QString::number(y1));
                    st5.move_up();
                    scene->update();
                });
            });
            QObject::connect(&moveUp, &QPushButton::released, [&]() {
                timer3.stop();
                scene->update();
            });
            QObject::connect(&moveDown, &QPushButton::pressed, [&]() {
                timer4.start();
                QObject::connect(&timer4, &QTimer::timeout, [&]() {
                    y1 =st5.centrFindY();
                    y.setText(QString::number(y1));
                    st5.move_down();
                    scene->update();
                });
            });
            QObject::connect(&moveDown, &QPushButton::released, [&]() {
                timer4.stop();
                scene->update();
            }        );
            b7=0;
            QObject::connect(&mah, &QPushButton::pressed, [&]() {
                timer5.start();
                QObject::connect(&timer5, &QTimer::timeout, [&]() {
                    st5.mashUp(&st5);
                    y1 =st5.centrFindY();
                    y.setText(QString::number(y1));
                    x1 = st5.centrFindX();
                    x.setText(QString::number(x1));
                    areap = st5.areaFind();
                    area.setText(QString::number(areap));
                    perimetrp = st5.perFind();
                    perimetr.setText(QString::number(perimetrp));
                    scene->update();
                });
            });
            QObject::connect(&mah, &QPushButton::released, [&]() {
                timer5.stop();
            });
            QObject::connect(&mah1, &QPushButton::pressed, [&]() {
                timer6.start();
                QObject::connect(&timer6, &QTimer::timeout, [&]() {
                    st5.mashDown(&st5);
                    y1 =st5.centrFindY();
                    y.setText(QString::number(y1));
                    x1 = st5.centrFindX();
                    x.setText(QString::number(x1));
                    areap = st5.areaFind();
                    area.setText(QString::number(areap));
                    perimetrp = st5.perFind();
                    perimetr.setText(QString::number(perimetrp));
                    scene->update();
                });
            });
            QObject::connect(&mah1, &QPushButton::released, [&]() {
                timer6.stop();
            });
            QObject::connect(&Rotate, &QPushButton::pressed, [&]() {
                timer7.start();
                QObject::connect(&timer7, &QTimer::timeout, [&]() {
                    st5.setRotation(p);
                    scene->update();
                    p+=0.1;
                });
            });
            QObject::connect(&Rotate, &QPushButton::released, [&]() {
                timer7.stop();
                p=0;
            });
        }

    });
    QObject::connect(&st5_destroy, &QPushButton::clicked, [&]() {
        st5.destroy_st5();
        scene->removeItem(&st5);
        scene->update();
    });
    QObject::connect(st6_click, &QPushButton::clicked, [&]() {
        scene->addItem(&st6);
        st6.create_st6();
        x1 = st6.centrFindX();
        y1=st6.centrFindY();
        areap=st6.areaFind();
        perimetrp=st6.perFind();
        x.setText(QString::number(x1));
        y.setText(QString::number(y1));
        area.setText(QString::number((areap)));
        perimetr.setText(QString::number(perimetrp));
        scene->update();
        if(b8)
        {
            QObject::connect(&moveRight, &QPushButton::pressed, [&]() {
                timer1.stop();
                timer1.start();
                QObject::connect(&timer1, &QTimer::timeout, [&]() {
                    st6.move_right();
                    x1 =  st6.centrFindX();
                    x.setText(QString::number(x1));
                    scene->update();
                });
            });
            QObject::connect(&moveRight, &QPushButton::released, [&]() {
                timer1.stop();
            });
            QObject::connect(&moveLeft, &QPushButton::pressed, [&]() {
                timer2.stop();
                timer2.start();
                QObject::connect(&timer2, &QTimer::timeout, [&]() {
                    x1 = st6.centrFindX();
                    x.setText(QString::number(x1));
                    st6.move_left();
                    scene->update();
                });
                timer2.start();
            });
            QObject::connect(&moveLeft, &QPushButton::released, [&]() {
                timer2.stop();
            });
            QObject::connect(&moveUp, &QPushButton::pressed, [&]() {
                timer3.stop();
                timer3.start();
                QObject::connect(&timer3, &QTimer::timeout, [&]() {
                    y1 = st6.centrFindY();
                    y.setText(QString::number(y1));
                    st6.move_up();
                    scene->update();
                });
            });
            QObject::connect(&moveUp, &QPushButton::released, [&]() {
                timer3.stop();
                scene->update();
            });
            QObject::connect(&moveDown, &QPushButton::pressed, [&]() {
                timer4.start();
                QObject::connect(&timer4, &QTimer::timeout, [&]() {
                    y1 =st6.centrFindY();
                    y.setText(QString::number(y1));
                    st6.move_down();
                    scene->update();
                });
            });
            QObject::connect(&moveDown, &QPushButton::released, [&]() {
                timer4.stop();
                scene->update();
            }        );
            b8=0;
            QObject::connect(&mah, &QPushButton::pressed, [&]() {
                timer5.start();
                QObject::connect(&timer5, &QTimer::timeout, [&]() {
                    st6.mashUp(&st6);
                    y1 =st6.centrFindY();
                    y.setText(QString::number(y1));
                    x1 = st6.centrFindX();
                    x.setText(QString::number(x1));
                    areap = st6.areaFind();
                    area.setText(QString::number(areap));
                    perimetrp = st6.perFind();
                    perimetr.setText(QString::number(perimetrp));
                    scene->update();
                });
            });
            QObject::connect(&mah, &QPushButton::released, [&]() {
                timer5.stop();
            });
            QObject::connect(&mah1, &QPushButton::pressed, [&]() {
                timer6.start();
                QObject::connect(&timer6, &QTimer::timeout, [&]() {
                    st6.mashDown(&st6);
                    y1 =st6.centrFindY();
                    y.setText(QString::number(y1));
                    x1 = st6.centrFindX();
                    x.setText(QString::number(x1));
                    areap = st6.areaFind();
                    area.setText(QString::number(areap));
                    perimetrp = st6.perFind();
                    perimetr.setText(QString::number(perimetrp));
                    scene->update();
                });
            });
            QObject::connect(&mah1, &QPushButton::released, [&]() {
                timer6.stop();
            });
            QObject::connect(&Rotate, &QPushButton::pressed, [&]() {
                timer7.start();
                QObject::connect(&timer7, &QTimer::timeout, [&]() {
                    st6.setRotation(p);
                    scene->update();
                    p+=0.1;
                });
            });
            QObject::connect(&Rotate, &QPushButton::released, [&]() {
                timer7.stop();
                p=0;
            });
        }
    });
    QObject::connect(&st6_destroy, &QPushButton::clicked, [&]() {
        st6.destroy_st6();
        scene->removeItem(&st6);
        scene->update();
    });
    QObject::connect(&st8_click, &QPushButton::clicked, [&]() {
          scene->addItem(&st8);
        st8.create_st8();
          x1 = st8.centrFindX();
          y1=st8.centrFindY();
          areap=st8.areaFind();
          perimetrp=st8.perFind();
          x.setText(QString::number(x1));
          y.setText(QString::number(y1));
          area.setText(QString::number((areap)));
          perimetr.setText(QString::number(perimetrp));
          scene->update();
        if(b9)
        {
            QObject::connect(&moveRight, &QPushButton::pressed, [&]() {
                timer1.stop();
                timer1.start();
                QObject::connect(&timer1, &QTimer::timeout, [&]() {
                    st8.move_right();
                    x1 =  st8.centrFindX();
                    x.setText(QString::number(x1));
                    scene->update();
                });
            });
            QObject::connect(&moveRight, &QPushButton::released, [&]() {
                timer1.stop();
            });
            QObject::connect(&moveLeft, &QPushButton::pressed, [&]() {
                timer2.stop();
                timer2.start();
                QObject::connect(&timer2, &QTimer::timeout, [&]() {
                    x1 = st8.centrFindX();
                    x.setText(QString::number(x1));
                    st8.move_left();
                    scene->update();
                });
                timer2.start();
            });
            QObject::connect(&moveLeft, &QPushButton::released, [&]() {
                timer2.stop();
            });
            QObject::connect(&moveUp, &QPushButton::pressed, [&]() {
                timer3.stop();
                timer3.start();
                QObject::connect(&timer3, &QTimer::timeout, [&]() {
                    y1 = st8.centrFindY();
                    y.setText(QString::number(y1));
                    st8.move_up();
                    scene->update();
                });
            });
            QObject::connect(&moveUp, &QPushButton::released, [&]() {
                timer3.stop();
                scene->update();
            });
            QObject::connect(&moveDown, &QPushButton::pressed, [&]() {
                timer4.start();
                QObject::connect(&timer4, &QTimer::timeout, [&]() {
                    y1 =st8.centrFindY();
                    y.setText(QString::number(y1));
                    st8.move_down();
                    scene->update();
                });
            });
            QObject::connect(&moveDown, &QPushButton::released, [&]() {
                timer4.stop();
                scene->update();
            }        );
            b9=0;
            QObject::connect(&mah, &QPushButton::pressed, [&]() {
                timer5.start();
                QObject::connect(&timer5, &QTimer::timeout, [&]() {
                    st8.mashUp(&st8);
                    y1 =st8.centrFindY();
                    y.setText(QString::number(y1));
                    x1 = st8.centrFindX();
                    x.setText(QString::number(x1));
                    areap = st8.areaFind();
                    area.setText(QString::number(areap));
                    perimetrp = st8.perFind();
                    perimetr.setText(QString::number(perimetrp));
                    scene->update();
                });
            });
            QObject::connect(&mah, &QPushButton::released, [&]() {
                timer5.stop();
            });
            QObject::connect(&mah1, &QPushButton::pressed, [&]() {
                timer6.start();
                QObject::connect(&timer6, &QTimer::timeout, [&]() {
                    st8.mashDown(&st8);
                    y1 =st8.centrFindY();
                    y.setText(QString::number(y1));
                    x1 = st8.centrFindX();
                    x.setText(QString::number(x1));
                    areap = st8.areaFind();
                    area.setText(QString::number(areap));
                    perimetrp = st8.perFind();
                    perimetr.setText(QString::number(perimetrp));
                    scene->update();
                });
            });
            QObject::connect(&mah1, &QPushButton::released, [&]() {
                timer6.stop();
            });
            QObject::connect(&Rotate, &QPushButton::pressed, [&]() {
                timer7.start();
                QObject::connect(&timer7, &QTimer::timeout, [&]() {
                    st8.setRotation(p);
                    scene->update();
                    p+=0.1;
                });
            });
            QObject::connect(&Rotate, &QPushButton::released, [&]() {
                timer7.stop();
                p=0;
            });
        }
    });
    QObject::connect(&st8_destroy, &QPushButton::clicked, [&]() {
        st8.destroy_st8();

        scene->update();
    });
    window.show();
    return a.exec();
}
