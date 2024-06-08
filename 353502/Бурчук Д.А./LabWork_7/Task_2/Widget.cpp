#include "Widget.h"
#include "ui_Widget.h"


Widget::Widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    tree = new AVLTree();
    tree->insert(20);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(25);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(23);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(24);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(12);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(13);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(3);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(0);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(4);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(6);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(34);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(55);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(29);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(17);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    tree->insert(18);


    while (tree->Parent() != nullptr) tree = tree->Parent();
    printTree(tree);
    update(tree);
}

Widget::~Widget() {
    delete ui;
}

void Widget::on_insertButton_clicked() {
    bool ok;
    int value = ui->keyEdit->text().toInt(&ok);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    if (ok)
        tree->insert(value);
    update(tree);
}


void Widget::on_containsButton_clicked() {
    bool ok;
    int value = ui->keyEdit->text().toInt(&ok);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    if (ok)
        if (tree->contains(value)) {
            ui->keyEdit->setText("contains");
            QTimer::singleShot(600, this, SLOT(setSpaces()));
        } else {
            ui->keyEdit->setText("not contains");
            QTimer::singleShot(600, this, SLOT(setSpaces()));
        }
}


void Widget::on_removeButton_clicked() {
    bool ok;
    int value = ui->keyEdit->text().toInt(&ok);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    if (ok)
        tree->remove(value);
    update(tree);
}


void Widget::on_doTaskButton_clicked() {
    bool ok;
    int value = ui->keyEdit->text().toInt(&ok);
    while (tree->Parent() != nullptr) tree = tree->Parent();
    if (ok)
        tree->remove(value);
    update(tree);

}

void Widget::setSpaces() {
    ui->keyEdit->setText("");
}

QTreeWidgetItem *Widget::updateTree(AVLTree *tree) {
    QTreeWidgetItem *parent = new QTreeWidgetItem();
    parent->setText(0, QString::number(tree->get()));
    if (tree->Right() != nullptr) {
        parent->addChild(updateTree(tree->Right()));
    }
    if (tree->Left() != nullptr) {
        parent->addChild(updateTree(tree->Left()));
    }
    return parent;
}

void Widget::update(AVLTree *tree) {
    while (tree->Parent() != nullptr) tree = tree->Parent();
    QTreeWidgetItem *parent = updateTree(tree);
    ui->treeWidget->setColumnCount(ui->treeWidget->columnCount() + 1);
    ui->treeWidget->addTopLevelItem(parent);
}

void Widget::printTree(AVLTree *tree) {
    std::cout << tree->get() << ' ';
    if (tree->Right() != nullptr)
        printTree(tree->Right());
    if (tree->Left() != nullptr)
        printTree(tree->Left());
}
