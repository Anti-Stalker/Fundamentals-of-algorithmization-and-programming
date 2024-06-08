#include "createorderwindow.h"
#include "QtQml/qqmlcontext.h"
#include "ui_createorderwindow.h"
#include <QDateTime>
#include <QDir>
#include <iostream>
#include <volume.h>
#include <sstream>

CreateOrderWindow::CreateOrderWindow(QWidget *parent, QQmlApplicationEngine *eng, Orders *ords)
    : QMainWindow(parent)
    , ui(new Ui::CreateOrderWindow)
{
    ui->setupUi(this);
    engine = eng;
    orders = ords;

    std::stringstream ss;
    ss << std::setw(6) << std::setfill('0') << orders->d.size()+1;
    std::string s = ss.str();

    ui->orderIdLabel->setText(QString::fromStdString(s));

    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd-MM-yyyy");
    ui->createdAtLabel->setText(formattedTime);


    materialList = new QList<Material>();
    materialList->append(Material("Gold 985", 1.5));
    materialList->append(Material("Silver 925", 0.3));
    materialList->append(Material("Gold 585", 1.2));
    materialList->append(Material("Silver 725", 0.26));
    materialList->append(Material("Gold VIP", 2));

    int i = 0;
    foreach(Material m, *materialList) {
        ui->materialComboBox->addItem(m.name, i);
        i++;
    }

    modelList = new QList<Model>();
    QDir directory("/Users/daryastasiuk/Documents/BSUIR/Rings");
    i = 0;
    QStringList models = directory.entryList(QStringList() << "*.stl" << "*.obj",QDir::Files);
    foreach(QString filename, models) {
        Model m(filename, (directory.absolutePath()+"/"+filename), i);
        modelList->append(m);
        ui->modelComboBox->addItem(modelList->at(i).name, i);
        i++;
    }
}

CreateOrderWindow::~CreateOrderWindow()
{
    delete ui;
}



void CreateOrderWindow::on_materialComboBox_textActivated(const QString &arg1)
{
    QString f_path = modelList->at(ui->modelComboBox->currentIndex()).path;
    float volume = getVolumeStl(f_path.toStdString());

    ui->volumeLabel->setText(QString::number(volume));

    Material mat = materialList->at(ui->materialComboBox->currentIndex());

    float price = volume * mat.pricePerPice;

    ui->priceLabel->setText(QString::number(price));
}


void CreateOrderWindow::on_modelComboBox_textActivated(const QString &arg1)
{
    QString f_path = modelList->at(ui->modelComboBox->currentIndex()).path;
    this->engine->rootContext()->setContextProperty("modelUrl", QUrl::fromLocalFile(f_path));
    float volume = getVolumeStl(f_path.toStdString());

    ui->volumeLabel->setText(QString::number(volume));

    Material mat = materialList->at(ui->materialComboBox->currentIndex());

    float price = volume * mat.pricePerPice;

    ui->priceLabel->setText(QString::number(price));
}


void CreateOrderWindow::on_pushButton_clicked()
{
    Order o {
        ui->orderIdLabel->text().toStdString(),
        ui->customerLineEdit->text().toStdString(),
        modelList->at(ui->modelComboBox->currentIndex()).path.toStdString(),
        materialList->at(ui->materialComboBox->currentIndex()).name.toStdString(),
        std::stof(ui->priceLabel->text().toStdString()),
        std::stof(ui->volumeLabel->text().toStdString()),
        QDate::fromString(ui->createdAtLabel->text(), "dd-MM-yyyy"),
    };
    orders->d.push_back(o);
    orders->save_to_file("/Users/daryastasiuk/Documents/BSUIR/Courses\ work/d.txt");
    this->close();
}

