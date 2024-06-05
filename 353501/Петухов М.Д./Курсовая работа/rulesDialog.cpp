#include "rulesDialog.h"
#include "ui_rulesDialog.h"

RulesDialog::RulesDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RulesDialog)
{
    ui->setupUi(this);
    
    QPixmap backgroundImage("../resources/backEggDialog.png");  
    QPalette palette;
    QSize newSize(400, 400); 
    backgroundImage = backgroundImage.scaled(newSize, Qt::KeepAspectRatio);
    palette.setBrush(QPalette::Window, backgroundImage);
    setPalette(palette);
    setFixedSize(newSize);

    ui->textBrowser->setAttribute(Qt::WA_TranslucentBackground); 
    ui->textBrowser->setStyleSheet("background-color: transparent; font-family: Comic Sans MS; font-size: 14pt;");
    QString a = ("Задачей игры является собрать определенное количество ресурсов за минимальное время\n"
             "Ресурсы, которые нужно собрать, располагаются в нижней правой части экрана\n"
             "Курицу можно купить за 100 монет, кнопка располагается в верхней правой части экрана\n"
             "Чтобы купить траву, нужно щелкнуть мышкой по колодцу\n"
             "Чтобы собрать яйцо, нужно кликнуть по нему 2 раза\n"
             "Яйца можно использовать при производстве яичного порошка");
    ui->textBrowser->setText(a);
}

RulesDialog::~RulesDialog()
{
    delete ui;
}

