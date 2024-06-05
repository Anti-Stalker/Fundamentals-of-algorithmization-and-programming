#include "linadetails.h"
#include "ui_linadetails.h"

LinaDetails::LinaDetails(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LinaDetails)
{
    ui->setupUi(this);

    QMovie *lina = new QMovie("../../Resources/images/Heroes/Lina/Lina.gif");
    ui->LinaGif->setScaledContents(true);
    ui->LinaGif->setMovie(lina);
    lina->start();

    QPixmap ab_1("../../Resources/images/Heroes/Lina/lina_dragon_slave.png");
    ui->Ab_1_img->setPixmap(ab_1);

    QPixmap ab_2("../../Resources/images/Heroes/Lina/lina_light_strike.png");
    ui->Ab_2_img->setPixmap(ab_2);

    QPixmap ab_3("../../Resources/images/Heroes/Lina/lina_laguna_blade.png");
    ui->Ab_3_img->setPixmap(ab_3);
}

LinaDetails::~LinaDetails()
{
    delete ui;
}

void LinaDetails::on_Ab_1_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Dragon Slave");

    QPixmap pixmap("../../Resources/images/Heroes/Lina/lina_dragon_slave.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 75\nСтоимость: 50 маны\nПерезарядка: 0 раундов");

    details.exec();
}


void LinaDetails::on_Ab_2_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Light Strike");

    QPixmap pixmap("../../Resources/images/Heroes/Lina/lina_light_strike.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 50\nСтоимость: 100 маны\nПерезарядка: 2 раунда\nОглушает врага на 1 раунд");

    details.exec();
}


void LinaDetails::on_Ab_3_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Laguna Blade");

    QPixmap pixmap("../../Resources/images/Heroes/Lina/lina_laguna_blade.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 300\nСтоимость: 200 маны\nПерезарядка: 4 раунда");

    details.exec();
}


void LinaDetails::on_close_button_clicked()
{
    this->close();
}

