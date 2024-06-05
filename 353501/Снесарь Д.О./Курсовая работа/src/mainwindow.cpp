#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    gameWidget = new GameWidget(false, this);
    solveWidget = new GameWidget(true, this);
    infoWidget = new Info;

    menuWidget = new Menu(this);
    stackedWidget->addWidget(gameWidget);
    stackedWidget->addWidget(solveWidget);
    stackedWidget->addWidget(menuWidget);
    stackedWidget->addWidget(infoWidget);
    stackedWidget->setCurrentWidget(menuWidget);


    connect(menuWidget, &Menu::openPlay, this, [this]() {
        stackedWidget->setCurrentWidget(gameWidget);
        gameWidget->setPaletteW(menuWidget->getPaletteW());
    });
    connect(menuWidget, &Menu::openSolve, this, [this]() {
        stackedWidget->setCurrentWidget(solveWidget);
        solveWidget->setPaletteW(menuWidget->getPaletteW());
    });
    connect(gameWidget, &GameWidget::backToMenu, this, [this]() {
        stackedWidget->setCurrentWidget(menuWidget);
    });
    connect(solveWidget, &GameWidget::backToMenu, this, [this]() {
        stackedWidget->setCurrentWidget(menuWidget);
    });

    connect(infoWidget, &Info::backMenu, this, [this]() {
        stackedWidget->setCurrentWidget(menuWidget);
    });

    connect(menuWidget, &Menu::openInfo, this, [this]() {
        stackedWidget->setCurrentWidget(infoWidget);
        infoWidget->setPaletteW(menuWidget->getPaletteW());
    });



}

void MainWindow::switchToGameWidget() {
    stackedWidget->setCurrentWidget(gameWidget);
}



MainWindow::~MainWindow()
{
    delete ui;
}

