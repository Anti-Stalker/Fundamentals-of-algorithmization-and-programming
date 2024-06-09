#include "dialog_1_1.h"
#include "ui_dialog_1_1.h"

dialog_1_1::dialog_1_1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialog_1_1)
{
    ui->setupUi(this);
    connect(ui->comboBoxForTip_1_1,SIGNAL(currentTextChanged(QString &)),this,SLOT(on_comboBoxForTip_1_1_currentTextChanged(QString &)));
    connect(ui->comboBoxForMarka_1_1,SIGNAL(currentTextChanged(QString &)),this,SLOT(on_comboBoxForMarka_1_1_currentTextChanged(QString &)));
    connect(ui->comboBoxForModel_1_1,SIGNAL(currentTextChanged(QString &)),this,SLOT(on_comboBoxForModel_1_1_currentTextChanged(QString &)));
    razmer = ui->spinBoxFor_1_1->value();
    tolst = ui->doubleSpinBoxTolst_1_1->value();
    rost = ui->spinBoxForRost_1_1->value();
    compressionStrength = ice.getCompressionStrength(tolst);
    massa = ui->spinBoxMassa_1_1->value();
    g = 9.8;
    this->setStyleSheet("background-color: #E6FAE6;");
    ui->comboBoxForTip_1_1->setStyleSheet("background-color: #E6F7FF;");
    ui->comboBoxForMarka_1_1->setStyleSheet("background-color: #E6F7FF;");
    ui->comboBoxForModel_1_1->setStyleSheet("background-color: #E6F7FF;");

}

dialog_1_1::~dialog_1_1()
{
    delete ui;
}

void dialog_1_1::on_close_1_1_clicked()
{
    close();
}

void dialog_1_1::on_comboBoxForTip_1_1_currentTextChanged(const QString &tip)
{
    ui->comboBoxForMarka_1_1->clear();

    if (tip == "Крассовки")
    {
        ui->comboBoxForMarka_1_1->addItem("");
        ui->comboBoxForMarka_1_1->addItem("Nike");
        ui->comboBoxForMarka_1_1->addItem("Adidas");
        ui->comboBoxForMarka_1_1->addItem("Puma");
    }
    else if (tip == "Лыжи")
    {
        ui->comboBoxForMarka_1_1->addItem(" ");
        ui->comboBoxForMarka_1_1->addItem("Atomic");
        ui->comboBoxForMarka_1_1->addItem("Salomon");
        ui->comboBoxForMarka_1_1->addItem("Rossignol");
    }
    else if (tip == "Коньки")
    {
        ui->comboBoxForMarka_1_1->addItem(" ");
        ui->comboBoxForMarka_1_1->addItem("Bauer");
        ui->comboBoxForMarka_1_1->addItem("CCM");
        ui->comboBoxForMarka_1_1->addItem("Reebok");
    }
}



void dialog_1_1::on_comboBoxForMarka_1_1_currentTextChanged(const QString &brand)
{
    ui->comboBoxForModel_1_1->clear();

    if (brand == "Nike")
    {
        ui->comboBoxForModel_1_1->addItem("");
        ui->comboBoxForModel_1_1->addItem("Air Max");
        ui->comboBoxForModel_1_1->addItem("Air Force");
        ui->comboBoxForModel_1_1->addItem("Blazer");
    }
    else if (brand == "Adidas")
    {
        ui->comboBoxForModel_1_1->addItem("");
        ui->comboBoxForModel_1_1->addItem("Superstar");
        ui->comboBoxForModel_1_1->addItem("Yeezy Boost");
        ui->comboBoxForModel_1_1->addItem("Gazelle");
    }
    else if (brand == "Puma")
    {
        ui->comboBoxForModel_1_1->addItem("");
        ui->comboBoxForModel_1_1->addItem("Suede");
        ui->comboBoxForModel_1_1->addItem("Clyde");
        ui->comboBoxForModel_1_1->addItem("Basket");
    }

    if (brand == "Atomic")
    {
        ui->comboBoxForModel_1_1->addItem("");
        ui->comboBoxForModel_1_1->addItem("Redster X9");
        ui->comboBoxForModel_1_1->addItem("Vantage X");
        ui->comboBoxForModel_1_1->addItem("Bent Chetler");
    }
    else if (brand == "Salomon")
    {
        ui->comboBoxForModel_1_1->addItem("");
        ui->comboBoxForModel_1_1->addItem("S/Max");
        ui->comboBoxForModel_1_1->addItem("QST");
        ui->comboBoxForModel_1_1->addItem("Stance");
    }
    else if (brand == "Rossignol")
    {
        ui->comboBoxForModel_1_1->addItem("");
        ui->comboBoxForModel_1_1->addItem("Experience");
        ui->comboBoxForModel_1_1->addItem("Black Ops");
        ui->comboBoxForModel_1_1->addItem("Hero");
    }

    if (brand == "Bauer")
    {
        ui->comboBoxForModel_1_1->addItem("");
        ui->comboBoxForModel_1_1->addItem("Vapor X2.9");
        ui->comboBoxForModel_1_1->addItem("Supreme 2S Pro");
        ui->comboBoxForModel_1_1->addItem("Nexus 2N Pro");
    }
    else if (brand == "CCM")
    {
        ui->comboBoxForModel_1_1->addItem("");
        ui->comboBoxForModel_1_1->addItem("Jetspeed FT2");
        ui->comboBoxForModel_1_1->addItem("Super Tacks AS3 Pro");
        ui->comboBoxForModel_1_1->addItem("Ribcor 100K");
    }
    else if (brand == "Reebok ")
    {
        ui->comboBoxForModel_1_1->addItem("");
        ui->comboBoxForModel_1_1->addItem("Ribcor 70K");
        ui->comboBoxForModel_1_1->addItem("Jetspeed FT485");
        ui->comboBoxForModel_1_1->addItem("Super Tacks 9370");
    }
}


void dialog_1_1::on_comboBoxForModel_1_1_currentTextChanged(const QString &model)
{
    if (model == "Vapor X2.9" ||
        model == "Supreme 2S Pro" ||
        model == "Nexus 2N Pro" ||
        model == "Jetspeed FT2" ||
        model == "Super Tacks AS3 Pro" ||
        model == "Ribcor 100K" ||
        model == "Ribcor 70K" ||
        model == "Jetspeed FT485" ||
        model == "Super Tacks 9370") {
        if (razmer == 33) {
            S = 0.0009;
        } else if (razmer == 34) {
            S = 0.0010;
        } else if (razmer == 35) {
            S = 0.0010;
        } else if (razmer == 36) {
            S = 0.0010;
        } else if (razmer == 37) {
            S = 0.0010;
        } else if (razmer == 38) {
            S = 0.0010;
        } else if (razmer == 39) {
            S = 0.0010;
        } else if (razmer == 40) {
            S = 0.0010;
        } else if (razmer == 41) {
            S = 0.0011;
        } else if (razmer == 42) {
            S = 0.0011;
        } else if (razmer == 43) {
            S = 0.0011;
        } else if (razmer == 44) {
            S = 0.0011;
        } else if (razmer == 45) {
            S = 0.0011;
        }
    }


    if (model == "QST"||model == "Black Ops") {
        if (rost >= 150 && rost < 160) {
            S = 0.0095;
        } else if (rost >= 160 && rost < 170) {
            S = 0.0098;
        } else if (rost >= 170 && rost < 180) {
            S = 0.0101;
        } else if (rost >= 180 && rost < 190) {
            S = 0.0104;
        } else if (rost >= 190 && rost < 200) {
            S = 0.0107;
        }
    }


    if (model == "S/Max"||model == "Hero") {
        if (rost >= 150 && rost < 160) {
            S = 0.0098;
        } else if (rost >= 160 && rost < 170) {
            S = 0.0102;
        } else if (rost >= 170 && rost < 180) {
            S = 0.0106;
        } else if (rost >= 180 && rost < 190) {
            S = 0.011;
        } else if (rost >= 190 && rost <= 200) {
            S = 0.0114;
        }
    }


    if (model == "Bent Chetler"||model == "Experience") {
        if (rost >= 150 && rost < 160) {
            S = 0.0101;
        } else if (rost >= 160 && rost < 170) {
            S = 0.0105;
        } else if (rost >= 170 && rost < 180) {
            S = 0.0109;
        } else if (rost >= 180 && rost < 190) {
            S = 0.0113;
        } else if (rost >= 190 && rost <= 200) {
            S = 0.0117;
        }
    }


    if (model == "Redster X9"||model == "Stance") {
        if (rost >= 150 && rost < 160) {
            S = 0.010725;
        } else if (rost >= 160 && rost < 170) {
            S = 0.01105;
        } else if (rost >= 170 && rost < 180) {
            S = 0.011375;
        } else if (rost >= 180 && rost < 190) {
            S = 0.0117;
        } else if (rost >= 190 && rost <= 200) {
            S = 0.012025;
        }
    }

    if (model == "Vantage X"||model == "Black Ops") {
        if (rost >= 150 && rost < 160) {
            S = 0.0106;
        } else if (rost >= 160 && rost < 170) {
            S = 0.011;
        } else if (rost >= 170 && rost < 180) {
            S = 0.0114;
        } else if (rost >= 180 && rost < 190) {
            S = 0.0118;
        } else if (rost >= 190 && rost <= 200) {
            S = 0.0122;
        }
    }

    if (model == "Suede"||model == "Basket") {
        if (razmer == 33) {
            S = 0.0031;
        } else if (razmer == 34) {
            S = 0.0032;
        } else if (razmer == 35) {
            S = 0.0033;
        } else if (razmer == 36) {
            S = 0.0034;
        } else if (razmer == 37) {
            S = 0.0035;
        } else if (razmer == 38) {
            S = 0.0036;
        } else if (razmer == 39) {
            S = 0.0037;
        } else if (razmer == 40) {
            S = 0.0038;
        } else if (razmer == 41) {
            S = 0.0039;
        } else if (razmer == 42) {
            S = 0.0040;
        } else if (razmer == 43) {
            S = 0.0041;
        } else if (razmer == 44) {
            S = 0.0042;
        } else if (razmer == 45) {
            S = 0.0043;
        }
    }

    if (model == "Gazelle") {
        if (razmer == 33) {
            S = 0.0032;
        } else if (razmer == 34) {
            S = 0.0033;
        } else if (razmer == 35) {
            S = 0.0034;
        } else if (razmer == 36) {
            S = 0.0035;
        } else if (razmer == 37) {
            S = 0.0036;
        } else if (razmer == 38) {
            S = 0.0037;
        } else if (razmer == 39) {
            S = 0.0038;
        } else if (razmer == 40) {
            S = 0.0039;
        } else if (razmer == 41) {
            S = 0.0040;
        } else if (razmer == 42) {
            S = 0.0041;
        } else if (razmer == 43) {
            S = 0.0042;
        } else if (razmer == 44) {
            S = 0.0043;
        } else if (razmer == 45) {
            S = 0.0044;
        }
    }

    if (model == "Yeezy Boost") {
        if (razmer == 33) {
            S = 0.0031;
        } else if (razmer == 34) {
            S = 0.0032;
        } else if (razmer == 35) {
            S = 0.0033;
        } else if (razmer == 36) {
            S = 0.0034;
        } else if (razmer == 37) {
            S = 0.0035;
        } else if (razmer == 38) {
            S = 0.0036;
        } else if (razmer == 39) {
            S = 0.0037;
        } else if (razmer == 40) {
            S = 0.0038;
        } else if (razmer == 41) {
            S = 0.0039;
        } else if (razmer == 42) {
            S = 0.0040;
        } else if (razmer == 43) {
            S = 0.0041;
        } else if (razmer == 44) {
            S = 0.0042;
        } else if (razmer == 45) {
            S = 0.0043;
        }
    }

    if (model == "Clyde"||model == "Air Max") {
        if (razmer == 33) {
            S = 0.00315;
        } else if (razmer == 34) {
            S = 0.003282;
        } else if (razmer == 35) {
            S = 0.00342;
        } else if (razmer == 36) {
            S = 0.003564;
        } else if (razmer == 37) {
            S = 0.003711;
        } else if (razmer == 38) {
            S = 0.003864;
        } else if (razmer == 39) {
            S = 0.004023;
        } else if (razmer == 40) {
            S = 0.004188;
        } else if (razmer == 41) {
            S = 0.004359;
        } else if (razmer == 42) {
            S = 0.004536;
        } else if (razmer == 43) {
            S = 0.004719;
        } else if (razmer == 44) {
            S = 0.004908;
        } else if (razmer == 45) {
            S = 0.005103;
        }
    }

    if (model == "Air Force") {
        if (razmer == 33) {
            S = 0.00309;
        } else if (razmer == 34) {
            S = 0.003222;
        } else if (razmer == 35) {
            S = 0.00336;
        } else if (razmer == 36) {
            S = 0.003504;
        } else if (razmer == 37) {
            S = 0.003651;
        } else if (razmer == 38) {
            S = 0.003804;
        } else if (razmer == 39) {
            S = 0.003963;
        } else if (razmer == 40) {
            S = 0.004128;
        } else if (razmer == 41) {
            S = 0.004299;
        } else if (razmer == 42) {
            S = 0.004476;
        } else if (razmer == 43) {
            S = 0.004659;
        } else if (razmer == 44) {
            S = 0.004848;
        } else if (razmer == 45) {
            S = 0.005043;
        }
    }

    if (model == "Air Force") {
        if (razmer == 33) {
            S = 0.00309;
        } else if (razmer == 34) {
            S = 0.003222;
        } else if (razmer == 35) {
            S = 0.00336;
        } else if (razmer == 36) {
            S = 0.003504;
        } else if (razmer == 37) {
            S = 0.003651;
        } else if (razmer == 38) {
            S = 0.003804;
        } else if (razmer == 39) {
            S = 0.003963;
        } else if (razmer == 40) {
            S = 0.004128;
        } else if (razmer == 41) {
            S = 0.004299;
        } else if (razmer == 42) {
            S = 0.004476;
        } else if (razmer == 43) {
            S = 0.004659;
        } else if (razmer == 44) {
            S = 0.004848;
        } else if (razmer == 45) {
            S = 0.005043;
        }
    }

    if (model == "Superstar") {
        if (razmer == 33) {
            S = 0.003;
        } else if (razmer == 34) {
            S = 0.003;
        } else if (razmer == 35) {
            S = 0.003;
        } else if (razmer == 36) {
            S = 0.0035;
        } else if (razmer == 37) {
            S = 0.0035;
        } else if (razmer == 38) {
            S = 0.0035;
        } else if (razmer == 39) {
            S = 0.004;
        } else if (razmer == 40) {
            S = 0.004;
        } else if (razmer == 41) {
            S = 0.004;
        } else if (razmer == 42) {
            S = 0.004;
        } else if (razmer == 43) {
            S = 0.0045;
        } else if (razmer == 44) {
            S = 0.0045;
        } else if (razmer == 45) {
            S = 0.0045;
        }
    }
}

void dialog_1_1::rezult()
{
    int height = 0;
    if(tolst<0.15){
        height = tolst*1000;
    }else{
        height = 150;
    }

    double P = (massa*g)/(2*S);
    qDebug()<<compressionStrength;
    qDebug()<<P;
    qDebug()<<S;
    if(P<compressionStrength){
        Dialog_2_1 okno_1_1(height,this);
        okno_1_1.showFullScreen();
        okno_1_1.exec();
    }else if(P>=compressionStrength){
        Dialog_2_1_2 okno_1_2(height,this);
        okno_1_2.showFullScreen();
        okno_1_2.exec();
    }

}


void dialog_1_1::on_pushButton_clicked()
{
    rost = ui->spinBoxForRost_1_1->value();
    tolst = ui->doubleSpinBoxTolst_1_1->value();
    compressionStrength = ice.getCompressionStrength(tolst);
    razmer = ui->spinBoxFor_1_1->value();
    massa = ui->spinBoxMassa_1_1->value();
    QString model = ui->comboBoxForModel_1_1->currentText();
    if(model==""){
        QMessageBox::information(this, "Информация", "Вы не ввели данные!");

    }else{
    on_comboBoxForModel_1_1_currentTextChanged(model);
    rezult();
    }
}


