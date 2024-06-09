#ifndef DIALOG_1_3_H
#define DIALOG_1_3_H
#include"icedata.h"
#include <QDialog>
#include"dialog_2_3_1.h"
#include"dialog_2_3_2.h"
namespace Ui {
class dialog_1_3;
}

class dialog_1_3 : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_1_3(QWidget *parent = nullptr);
    ~dialog_1_3();
    IceData ice;
    void Label_1_3();
    int compressionStrength;
    double S = 0;
    int razmer;
    int rost;
    double tolst;
    int massa;
    double on_doubleSpinBoxTolst_1_3_valueChanged(double value);
    double g,t = 0.64;
    int h;
    void rezult();


private slots:
    void on_close_1_3_clicked();

    void on_comboBoxForMarka_1_3_currentTextChanged(const QString &brand);

    void on_comboBoxForModel_1_3_currentTextChanged(const QString &model);

    void on_comboBoxForTip_1_3_currentTextChanged(const QString &tip);

    //void on_spinBoxFor_1_1_valueChanged(int razmer);

    void on_pushButton_clicked();

private:
    Ui::dialog_1_3 *ui;
};

#endif
