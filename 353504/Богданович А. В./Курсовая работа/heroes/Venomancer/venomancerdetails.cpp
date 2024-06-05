#include "venomancerdetails.h"
#include "ui_venomancerdetails.h"

VenomancerDetails::VenomancerDetails(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VenomancerDetails)
{
    ui->setupUi(this);

    QMovie *venomancer = new QMovie("../../Resources/images/Heroes/Venomancer/Venomancer.gif");
    ui->VenomancerGif->setScaledContents(true);
    ui->VenomancerGif->setMovie(venomancer);
    venomancer->start();

    QPixmap ab_1("../../Resources/images/Heroes/Venomancer/venomancer_venomous_gale.png");
    ui->Ab_1_img->setPixmap(ab_1);

    QPixmap ab_2("../../Resources/images/Heroes/Venomancer/venomancer_poison_sting.png");
    ui->Ab_2_img->setPixmap(ab_2);

    QPixmap ab_3("../../Resources/images/Heroes/Venomancer/venomancer_noxious_plague.png");
    ui->Ab_3_img->setPixmap(ab_3);
}

VenomancerDetails::~VenomancerDetails()
{
    delete ui;
}

void VenomancerDetails::on_Ab_1_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Venomous Gale");

    QPixmap pixmap("../../Resources/images/Heroes/Venomancer/venomancer_venomous_gale.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 80\nСтоимость: 50 маны\nПерезарядка: 1 раунд\nПериодический урон: 10 в течении 2ух раундов");

    details.exec();
}


void VenomancerDetails::on_Ab_2_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Poison Sting");

    QPixmap pixmap("../../Resources/images/Heroes/Venomancer/venomancer_poison_sting.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 20\nСтоимость: 15 маны\nПерезарядка: 0 раундов\nПериодический урон: 5 в течении 4ёх раундов");

    details.exec();
}


void VenomancerDetails::on_Ab_3_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Noxious Plague");

    QPixmap pixmap("../../Resources/images/Heroes/Venomancer/venomancer_noxious_plague.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 175\nСтоимость: 150 маны\nПерезарядка: 4 раунда\nПериодический урон: 25 в течении 2ух раундов");

    details.exec();
}


void VenomancerDetails::on_close_button_clicked()
{
    this->close();
}

