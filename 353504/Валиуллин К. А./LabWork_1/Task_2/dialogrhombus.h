#ifndef DIALOGRHOMBUS_H
#define DIALOGRHOMBUS_H

#include <QDialog>

namespace Ui {
class DialogRhombus;
}

struct sideAndAngleCoordinates {
    int side1, side2;
};

class DialogRhombus : public QDialog
{
    Q_OBJECT

public:
    DialogRhombus(QWidget *parent = nullptr);
    ~DialogRhombus();

signals:
    void rhombusValues(sideAndAngleCoordinates &coordinates);

private slots:    
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogRhombus *ui;
    bool rejectPushed = false;
};

#endif // DIALOGRHOMBUS_H
