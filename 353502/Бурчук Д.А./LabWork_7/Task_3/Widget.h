#ifndef LAB7TASK3_WIDGET_H
#define LAB7TASK3_WIDGET_H

#include <QWidget>


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


#endif //LAB7TASK3_WIDGET_H
