#ifndef DIALOGRECTANGLE_H
#define DIALOGRECTANGLE_H

#include <QDialog>

namespace Ui {
class DialogRectangle;
}

struct sidesValues {
    int side1, side2;
};

class DialogRectangle : public QDialog
{
    Q_OBJECT

public:
    DialogRectangle(QWidget *parent = nullptr);
    ~DialogRectangle();

signals:
    void transmitValues(sidesValues &sides);

private slots:   
    void on_buttonBox_accepted();

private:
    Ui::DialogRectangle *ui;

};

#endif // DIALOGRECTANGLE_H
