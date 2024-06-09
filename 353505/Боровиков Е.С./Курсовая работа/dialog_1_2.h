#ifndef DIALOG_1_2_H
#define DIALOG_1_2_H
#include"icedata.h"
#include <QDialog>
#include"dialog_2_2_1.h"
#include"dialog_2_2_2.h"
#include<QDebug>
namespace Ui {
class dialog_1_2;
}

class dialog_1_2 : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_1_2(QWidget *parent = nullptr);
    ~dialog_1_2();
    IceData ice;
    int razmer, g = 9.8;
    int massa;
    int rost;
    double tolst;
    int compressionStrength;
    double P,pi = 3.1415926535;
    void rezult();

private slots:
    void on_rezult_clicked();

    void on_pushButton_clicked();

private:
    Ui::dialog_1_2 *ui;
};

#endif // DIALOG_1_2_H
