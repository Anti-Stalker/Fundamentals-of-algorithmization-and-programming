#include "Widget.h"
#include "ui_Widget.h"


Widget::Widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    ArrayBH bh;

    bh.add(2);

    bh.add(3);

    bh.add(5);

    bh.add(67);

    bh.add(24);

    bh.add(32);

    bh.add(55);

    bh.add(7);

    bh.print();
}

Widget::~Widget() {
    delete ui;
}
