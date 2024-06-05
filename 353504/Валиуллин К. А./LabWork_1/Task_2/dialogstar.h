#ifndef DIALOGSTAR_H
#define DIALOGSTAR_H

#include <QDialog>

namespace Ui {
class DialogStar;
}

struct valuesOfStar {
    int tip, side;
};

class DialogStar : public QDialog
{
    Q_OBJECT

public:
    DialogStar(QWidget *parent = nullptr);
    ~DialogStar();

signals:
    void transmitValues(valuesOfStar &values);

private slots:    
    void on_buttonBox_accepted();

private:
    Ui::DialogStar *ui;

};

#endif // DIALOGSTAR_H
