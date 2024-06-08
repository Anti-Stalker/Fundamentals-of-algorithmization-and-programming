#ifndef LAB8TASK1_WIDGET_H
#define LAB8TASK1_WIDGET_H

#include <QWidget>
#include <QDebug>

#include "BinarySearchTree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

private:
    Ui::Widget *ui;
};


#endif //LAB8TASK1_WIDGET_H
