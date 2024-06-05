#ifndef DIALOGCIRCLE_H
#define DIALOGCIRCLE_H

#include <QDialog>

namespace Ui {
class DialogCircle;
}

class DialogCircle : public QDialog
{
    Q_OBJECT

public:
    DialogCircle(QWidget *parent = nullptr);
    ~DialogCircle();
    void Show();

signals:
    void circleValue(int Radius);
    void transmitRotation(bool isChecked);

private slots:
    void on_buttonBox_accepted();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::DialogCircle *ui;

};

#endif // DIALOGCIRCLE_H
