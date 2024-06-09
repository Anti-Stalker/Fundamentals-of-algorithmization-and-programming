#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QtWidgets>
#include "dialog_1_1.h"
#include"dialog_1_2.h"
#include"dialog_1_3.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class FirstWindow;
}
QT_END_NAMESPACE

class FirstWindow : public QWidget
{
    Q_OBJECT

public:
    FirstWindow(QWidget *parent = nullptr);
    ~FirstWindow();

    QMap<double, double> ProchIce;


private slots:

    void on_dialog_1_2_Btn_clicked();

    void on_dialog_1_1_Btn_clicked();

    void on_dailog_1_3_Btn_clicked();

    void on_pushButton_clicked();

private:
    Ui::FirstWindow *ui;
    void initializeProchIce();
};
#endif // FIRSTWINDOW_H
