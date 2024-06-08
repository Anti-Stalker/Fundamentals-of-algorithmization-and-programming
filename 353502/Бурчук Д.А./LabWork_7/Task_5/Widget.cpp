#include "Widget.h"
#include "ui_Widget.h"


Widget::Widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    deque = new Deque();
}

Widget::~Widget() {
    delete ui;
    delete deque;
}
