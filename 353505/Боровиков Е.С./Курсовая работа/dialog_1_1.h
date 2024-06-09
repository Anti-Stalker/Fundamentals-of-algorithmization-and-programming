#ifndef DIALOG_1_1_H
#define DIALOG_1_1_H
#include"icedata.h"
#include <QDialog>
#include "dialog_2_1_1.h"
#include"dialog_2_1_2.h"

namespace Ui {
class dialog_1_1;
}

class dialog_1_1 : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_1_1(QWidget *parent = nullptr);
    ~dialog_1_1();
    IceData ice;
    void Label_1_1();
    int compressionStrength;
    double S = 0;
    int razmer;
    int rost;
    double tolst;
    int massa;
    double on_doubleSpinBoxTolst_1_1_valueChanged(double value);
    double g;
    void rezult();


private slots:
    void on_close_1_1_clicked();

    void on_comboBoxForMarka_1_1_currentTextChanged(const QString &brand);

    void on_comboBoxForModel_1_1_currentTextChanged(const QString &model);

    void on_comboBoxForTip_1_1_currentTextChanged(const QString &tip);

    void on_pushButton_clicked();

private:
    Ui::dialog_1_1 *ui;
};

#endif // DIALOG_1_1_H
