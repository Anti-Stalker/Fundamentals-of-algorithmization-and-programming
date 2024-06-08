#ifndef LAB6TASK1_WIDGET_H
#define LAB6TASK1_WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QValidator>

#include "Motorbike.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

private slots:

    void on_evaluateButton_clicked();

    void setSpace();

private:
    Ui::Widget *ui;

    QRegExpValidator *validator;

    void print(QString list[]);
};


#endif //LAB6TASK1_WIDGET_H
