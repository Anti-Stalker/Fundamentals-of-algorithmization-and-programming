#ifndef VENOMANCERDETAILS_H
#define VENOMANCERDETAILS_H

#include <QDialog>
#include <QMovie>
#include <QMessageBox>

namespace Ui {
class VenomancerDetails;
}

class VenomancerDetails : public QDialog
{
    Q_OBJECT

public:
    explicit VenomancerDetails(QWidget *parent = nullptr);
    ~VenomancerDetails();

public slots:
    void on_Ab_1_clicked();

    void on_Ab_2_clicked();

    void on_Ab_3_clicked();

    void on_close_button_clicked();

private:
    Ui::VenomancerDetails *ui;
};

#endif // VENOMANCERDETAILS_H
