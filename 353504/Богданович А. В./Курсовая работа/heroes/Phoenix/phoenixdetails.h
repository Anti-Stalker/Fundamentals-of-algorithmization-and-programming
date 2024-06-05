#ifndef PHOENIXDETAILS_H
#define PHOENIXDETAILS_H

#include <QDialog>
#include <QMovie>
#include <QMessageBox>

namespace Ui {
class PhoenixDetails;
}

class PhoenixDetails : public QDialog
{
    Q_OBJECT

public:
    explicit PhoenixDetails(QWidget *parent = nullptr);
    ~PhoenixDetails();

public slots:
    void on_close_button_clicked();

    void on_Ab_1_clicked();

    void on_Ab_2_clicked();

    void on_Ab_3_clicked();

private:
    Ui::PhoenixDetails *ui;
};

#endif // PHOENIXDETAILS_H
