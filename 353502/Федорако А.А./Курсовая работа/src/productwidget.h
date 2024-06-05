#ifndef PRODUCTWIDGET_H
#define PRODUCTWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include <QFont>
#include "stringprocessing.h"

namespace Ui {
class ProductWidget;
}

class ProductWidget : public QWidget
{
    Q_OBJECT
protected:

public:
    explicit ProductWidget(QWidget *parent = nullptr);
    ~ProductWidget();
    void add(Product* product);
private:
    void setAppearance();
    QVector<QLabel*> arrPrice;
    void setPrice(int number, double price);
    void setBestPrice(int number, double price);
    QVector<QLabel*> arrLabelPriceShop;
    QVector<QLabel*> arrLabelShop;
    int const MOVING_WIDGET_X_CENTRE = 200;
    int const MOVING_WIDGET_Y_CENTRE = 100;
    Ui::ProductWidget *ui;
};

#endif // PRODUCTWIDGET_H
