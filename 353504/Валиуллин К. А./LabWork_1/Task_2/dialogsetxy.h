#ifndef DIALOGSETXY_H
#define DIALOGSETXY_H

#include <QDialog>

namespace Ui {
class DialogSetXY;
}

struct valuesNewXY {
    int x,y;
};

class DialogSetXY : public QDialog
{
    Q_OBJECT

public:
    DialogSetXY(QWidget *parent = nullptr);
    ~DialogSetXY();

signals:
    void transmitValue(valuesNewXY &XY);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogSetXY *ui;

};

#endif // DIALOGSETXY_H
