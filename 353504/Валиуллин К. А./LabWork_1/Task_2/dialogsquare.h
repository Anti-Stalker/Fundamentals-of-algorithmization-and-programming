#ifndef DIALOGSQUARE_H
#define DIALOGSQUARE_H

#include <QDialog>

namespace Ui {
class DialogSquare;
}

class DialogSquare : public QDialog
{
    Q_OBJECT

public:
    DialogSquare(QWidget *parent = nullptr);
    ~DialogSquare();

signals:
    void transmitValue(int side);

private slots:   
    void on_buttonBox_accepted();

private:
    Ui::DialogSquare *ui;

};

#endif // DIALOGSQUARE_H
