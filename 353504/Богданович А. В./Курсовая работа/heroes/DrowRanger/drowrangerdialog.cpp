#include "drowrangerdialog.h"
#include "ui_drowrangerdialog.h"

DrowRangerDialog::DrowRangerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DrowRangerDialog)
{
    ui->setupUi(this);

    QMovie *drowRanger = new QMovie("../../Resources/images/Heroes/DrowRanger/DrowRanger.gif");
    ui->DrowRangerGif->setScaledContents(true);
    ui->DrowRangerGif->setMovie(drowRanger);
    drowRanger->start();

    QPixmap ab_1("../../Resources/images/Heroes/DrowRanger/drow_ranger_wave_of_silence.png");
    ui->Ab_1_img->setPixmap(ab_1);

    QPixmap ab_2("../../Resources/images/Heroes/DrowRanger/drow_ranger_multishot.png");
    ui->Ab_2_img->setPixmap(ab_2);

    QPixmap ab_3("../../Resources/images/Heroes/DrowRanger/drow_ranger_marksmanship.png");
    ui->Ab_3_img->setPixmap(ab_3);
}

DrowRangerDialog::~DrowRangerDialog()
{
    delete ui;
}

void DrowRangerDialog::on_Ab_1_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Gust");

    QPixmap pixmap("../../Resources/images/Heroes/DrowRanger/drow_ranger_wave_of_silence.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 30\nСтоимость: 50 маны\nПерезарядка: 2 раунда\nНакладывает безмолвие на 1 раунд");

    details.exec();
}


void DrowRangerDialog::on_Ab_2_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Multishot");

    QPixmap pixmap("../../Resources/images/Heroes/DrowRanger/drow_ranger_multishot.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 100\nСтоимость: 75 маны\nПерезарядка: 1 раунд");

    details.exec();
}


void DrowRangerDialog::on_Ab_3_clicked()
{
    QMessageBox details;

    details.setWindowTitle("Marksmanship");

    QPixmap pixmap("../../Resources/images/Heroes/DrowRanger/drow_ranger_marksmanship.png");
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText("Урон: 120\nСтоимость: 100 маны\nПерезарядка: 0 раундов");

    details.exec();
}


void DrowRangerDialog::on_close_button_clicked()
{
    this->close();
}

