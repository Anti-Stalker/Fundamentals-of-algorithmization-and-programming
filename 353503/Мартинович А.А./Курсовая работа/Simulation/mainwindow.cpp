#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./ui_mainwindow.h"
#include "vectorfileio.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int width = ui->drawer->width();
    int height = ui->drawer->height();

    field = new Field(width/CELL_SIZE,height/CELL_SIZE);
    ui->drawer->SetGrid(field->getField());

    graphic = new Graphic(this);
    ui->graphicsView->setScene(graphic);
    setFixedSize(WIDNOW_WIDTH, WINDOW_HEIGHT);

    connect(field, &Field::signalChangeField, ui->drawer, &DrawerGL::draw);
    connect(field, &Field::signalTimeLive, graphic, &Graphic::addValue);
    connect(field, &Field::signalSaveGenoms, ui->listGenoms, &GenomsListWidget::setGenoms);

    //slider
    connect(ui->speedSlider, &QSlider::valueChanged, field, &Field::changeSpeedTimer);

    //buttons
    connect(ui->pauseButton, &QPushButton::clicked, field, &Field::pause);
    connect(ui->worldSettingsMenu, &QPushButton::clicked, this, &MainWindow::showMenu);
    connect(ui->activateDrawButton, &QPushButton::clicked, ui->drawer, &DrawerGL::activate);
    connect(ui->saveGenomsButton, &QPushButton::clicked, this, &MainWindow::saveGenomsButtonClick);
    connect(ui->loadGenomsButton, &QPushButton::clicked, this, &MainWindow::loadGenomsButtonClick);
    connect(ui->newPopulationSettingsButton, &QPushButton::clicked, this, &MainWindow::showPopulationMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newWorldSettings()
{
    graphic->clearGraphic();
    ui->listGenoms->clearList();
    field->newField();
}

void MainWindow::newPopulationSettings()
{
    graphic->clearGraphic();
    ui->listGenoms->clearList();
    field->newPopulation();
}

void MainWindow::showMenu()
{
    field->stop();
    SettingsMenu *menu = new SettingsMenu(this);
    connect(menu, &SettingsMenu::accepted, menu, &SettingsMenu::UpdateSettings);
    connect(menu, &SettingsMenu::accepted, this, &MainWindow::newWorldSettings);
    connect(menu, &QDialog::finished, menu, &QObject::deleteLater);
    menu->exec();
    field->start();
}

void MainWindow::showPopulationMenu()
{
    field->stop();
    CreatePopulationMenu *menu = new CreatePopulationMenu(this);
    connect(menu, &CreatePopulationMenu::accepted, menu, &CreatePopulationMenu::UpdateSettings);
    connect(menu, &CreatePopulationMenu::accepted, this, &MainWindow::newPopulationSettings);
    connect(menu, &QDialog::finished, menu, &QObject::deleteLater);
    menu->exec();
    field->start();
}

void MainWindow::saveGenomsButtonClick()
{
    field->stop();
    QString fileName = QFileDialog::getSaveFileName(nullptr, tr("Save genoms"), "", tr("(*.genoms)"));
    fileName+=".genoms";
    if (fileName.isEmpty()) {
    } else {
        VectorFileIO::writeToFile(field->getSavedGenoms(), fileName);
    }
    field->start();

}

void MainWindow::loadGenomsButtonClick()
{
    field->stop();
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("Open saved genoms"), "/home", tr("genoms files (*.genoms)"));
    if (fileName.isEmpty()) {
    } else {
        QVector<QVector<int>> g;
        VectorFileIO::readFromFile(g, fileName);
        field->setSavedGenoms(g);
    }
    graphic->clearGraphic();
    ui->listGenoms->clearList();
    field->bornPopulation();
    field->start();
}


