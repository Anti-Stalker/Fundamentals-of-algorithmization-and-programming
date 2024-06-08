#ifndef LAB7TASK5_WIDGET_H
#define LAB7TASK5_WIDGET_H

#include <QWidget>

#include "Deque.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

    Deque *deque;

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

private:
    Ui::Widget *ui;
};


#endif //LAB7TASK5_WIDGET_H
