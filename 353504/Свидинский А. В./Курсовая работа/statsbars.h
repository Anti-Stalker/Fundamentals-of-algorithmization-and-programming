// statsbars.h
#ifndef STATSBARS_H
#define STATSBARS_H

#include <QWidget>
#include <QPaintEvent>

class StatsBars: public QWidget
{
    Q_OBJECT
public:
    StatsBars(QWidget *parent = nullptr);
    void updateStatsBars(int wealth, int power, int intelligence, int decency);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    int wealth;
    int power;
    int intelligence;
    int decency;
};

#endif // STATSBARS_H
