#ifndef LAB7TASK2_WIDGET_H
#define LAB7TASK2_WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTreeWidgetItem>

#include "AVLTree.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

    AVLTree *tree;

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

private:
    Ui::Widget *ui;

    QTreeWidgetItem *updateTree(AVLTree *tree);

    void update(AVLTree *tree);

    void printTree(AVLTree *tree);

private slots:

    void on_insertButton_clicked();

    void on_containsButton_clicked();

    void on_removeButton_clicked();

    void on_doTaskButton_clicked();

    void setSpaces();
};


#endif //LAB7TASK2_WIDGET_H
