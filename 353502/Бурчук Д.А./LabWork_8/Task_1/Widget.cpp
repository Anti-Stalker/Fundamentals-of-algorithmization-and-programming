#include "Widget.h"
#include "ui_Widget.h"

#include "BinarySearchTree.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    BinarySearchTree<QString> tree;

    tree.add("e", 2);

    tree.add("k", 1);

    tree.add("d", 4);

    tree.add("g", 5);

    std::vector<QString> v = tree.inorderTraversal();

    for (const QString& s : v) {
        qDebug() << s;
    }

}

Widget::~Widget() {
    delete ui;
}
