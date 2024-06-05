#ifndef DRAGONKNIGHTDETAILS_H
#define DRAGONKNIGHTDETAILS_H

#include <QDialog>
#include <QMovie>
#include <QMessageBox>

namespace Ui {
class DragonKnightDetails;
}

class DragonKnightDetails : public QDialog
{
    Q_OBJECT

public:
    explicit DragonKnightDetails(QWidget *parent = nullptr);
    ~DragonKnightDetails();

public slots:
    void on_Ab_1_clicked();

    void on_Ab_2_clicked();

    void on_Ab_3_clicked();

    void on_close_button_clicked();

private:
    Ui::DragonKnightDetails *ui;
};

#endif // DRAGONKNIGHTDETAILS_H
