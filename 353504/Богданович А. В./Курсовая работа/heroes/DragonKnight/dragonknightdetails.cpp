#include "dragonknightdetails.h"
#include "ui_dragonknightdetails.h"

DragonKnightDetails::DragonKnightDetails(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DragonKnightDetails)
{
    ui->setupUi(this);

    QMovie *dragonKnight = new QMovie("../../Resources/images/Heroes/DragonKnight/DragonKnight.gif");
    ui->DragonKnightGif->setScaledContents(true);
    ui->DragonKnightGif->setMovie(dragonKnight);
    dragonKnight->start();

    QPixmap ab_1("../../Resources/images/Heroes/DragonKnight/dragon_knight_breathe_fire.png");
    ui->Ab_1_img->setPixmap(ab_1);

    QPixmap ab_2("../../Resources/images/Heroes/DragonKnight/dragon_knight_dragon_tail.png");
    ui->Ab_2_img->setPixmap(ab_2);

    QPixmap ab_3("../../Resources/images/Heroes/DragonKnight/dragon_knight_elder_dragon_form.png");
    ui->Ab_3_img->setPixmap(ab_3);
}

DragonKnightDetails::~DragonKnightDetails()
{
    delete ui;
}

void DragonKnightDetails::on_Ab_1_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Breathe Fire");

    QPixmap pixmap("../../Resources/images/Heroes/DragonKnight/dragon_knight_breathe_fire.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 70\nСтоимость: 50 маны\nПерезарядка: 0 раундов");

    details.exec();
}


void DragonKnightDetails::on_Ab_2_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Dragon Tail");

    QPixmap pixmap("../../Resources/images/Heroes/DragonKnight/dragon_knight_dragon_tail.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 50\nСтоимость: 50 маны\nПерезарядка: 2 раунда\nОглушает противника на 1 раунд");

    details.exec();
}


void DragonKnightDetails::on_Ab_3_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Elder Dragon Form");

    QPixmap pixmap("../../Resources/images/Heroes/DragonKnight/dragon_knight_elder_dragon_form.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 75\nСтоимость: 150 маны\nПерезарядка: 2 раунда\nОглушает противника на 1 раунд\nПериодический урон: 25 в течении 3ёх раундов");

    details.exec();
}


void DragonKnightDetails::on_close_button_clicked()
{
    this->close();
}

