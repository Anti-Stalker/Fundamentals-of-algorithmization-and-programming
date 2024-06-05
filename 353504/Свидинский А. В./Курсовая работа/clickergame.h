#ifndef CLICKERGAME_H
#define CLICKERGAME_H

#include <QWidget>
#include <QPaintEvent>

class ClickerGame: public QWidget
{
    Q_OBJECT
public:
    ClickerGame(QWidget *parent = nullptr);
    void updateVerticalBars(int greenValue, int redValue);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    int greenValue;
    int redValue;
};

#endif // CLICKERGAME_H
