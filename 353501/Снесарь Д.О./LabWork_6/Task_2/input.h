#ifndef INPUT_H
#define INPUT_H

#include <QWidget>
#include "animal.h"
namespace Ui {
class input;
}

class input : public QWidget
{
    Q_OBJECT

public:
    explicit input(QWidget *parent = nullptr);
    ~input();
    void createByUser();
    Animal a;
    QString b;
    Animal getAnimal(){return a;}
    QString getStrAnimal(){return b;}
private:
    Ui::input *ui;
signals:
    void enter(QString b, Animal a);
private slots:
    void on_pushButton_clicked();
};

#endif // INPUT_H
