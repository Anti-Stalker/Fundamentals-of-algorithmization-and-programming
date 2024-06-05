#ifndef DIALOGOVAL_H
#define DIALOGOVAL_H

#include <QDialog>

namespace Ui {
class DialogOval;
}

struct valuesOfOval {
    int r1, r2;
};

class DialogOval : public QDialog
{
    Q_OBJECT

public:
    DialogOval(QWidget *parent = nullptr);
    ~DialogOval();

signals:
    void transmitValues(valuesOfOval &values);

private slots:   
    void on_buttonBox_accepted();

private:
    Ui::DialogOval *ui;

};

#endif // DIALOGOVAL_H
