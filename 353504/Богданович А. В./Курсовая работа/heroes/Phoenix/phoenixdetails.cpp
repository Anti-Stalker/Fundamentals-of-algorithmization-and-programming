#include "phoenixdetails.h"
#include "ui_phoenixdetails.h"



PhoenixDetails::PhoenixDetails(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PhoenixDetails)
{
    ui->setupUi(this);

    QMovie *phoenix = new QMovie("../../Resources/images/Heroes/Phoenix/Phoenix.gif");
    ui->PhoenixGif->setScaledContents(true);
    ui->PhoenixGif->setMovie(phoenix);
    phoenix->start();

    QPixmap ab_1("../../Resources/images/Heroes/Phoenix/phoenix_icarus_dive.png");
    ui->Ab_1_img->setPixmap(ab_1);

    QPixmap ab_2("../../Resources/images/Heroes/Phoenix/phoenix_fire_spirits.png");
    ui->Ab_2_img->setPixmap(ab_2);

    QPixmap ab_3("../../Resources/images/Heroes/Phoenix/phoenix_supernova.png");
    ui->Ab_3_img->setPixmap(ab_3);
}

PhoenixDetails::~PhoenixDetails()
{
    delete ui;
}

void PhoenixDetails::on_close_button_clicked()
{
    this->close();
}


void PhoenixDetails::on_Ab_1_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Icarus Dive");

    QPixmap pixmap("../../Resources/images/Heroes/Phoenix/phoenix_icarus_dive.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 40\nСтоимость: 20 маны\nПерезарядка: 0 раундов");

    details.exec();
}


void PhoenixDetails::on_Ab_2_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Fire Spirits");

    QPixmap pixmap("../../Resources/images/Heroes/Phoenix/phoenix_fire_spirits.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 50\nСтоимость: 80 маны\nПерезарядка: 3 раунда\nПереодический урон: 10 в течении 3ёх раундов");

    details.exec();
}


void PhoenixDetails::on_Ab_3_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Supernova");

    QPixmap pixmap("../../Resources/images/Heroes/Phoenix/phoenix_supernova.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 150\nСтоимость: 200 маны\nПерезарядка: 3 раунда\nПереодический урон: 15 в течении 2ух раундов\nОглушает на 1 раунд");

    details.exec();
}

