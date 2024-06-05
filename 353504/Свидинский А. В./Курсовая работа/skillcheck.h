#ifndef SKILLCHECK_H
#define SKILLCHECK_H

#include <QWidget>
#include <QPaintEvent>

class SkillCheck: public QWidget
{
    Q_OBJECT
public:
    SkillCheck(QWidget *parent = nullptr);
    void updateVerticalBar(int greenValue);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    int greenValue;
};

#endif // SKILLCHECK_H
