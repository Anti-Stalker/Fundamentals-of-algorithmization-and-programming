#include "menuinterface.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>

MenuUi::MenuUi(QMainWindow *parent) : QMainWindow(parent)
{
    scene = new QGraphicsScene(20, 20, 580, 380);
    view = new QGraphicsView(scene);

    setCentralWidget(view);

    LabelFont = new QFont("Bahnschrift Light", 36);
    ButtonFont = new QFont("Calibri Regular", 18);

    WelcomeLabel = new QLabel("STS GAME");
    WelcomeLabel->setAlignment(Qt::AlignCenter);
    WelcomeLabel->setFont(QFont("Audiowide", 36));
    WelcomeLabel->setMinimumSize(300, 120);

    btnStartGame = new QPushButton("START");
    btnTutorial = new QPushButton("TUTORIAL");
    btnExit = new QPushButton("EXIT");
    btnStartGame->setFont(*ButtonFont);
    btnTutorial->setFont(*ButtonFont);
    btnExit->setFont(*ButtonFont);
    btnStartGame->setMinimumSize(250, 60);
    btnTutorial->setMinimumSize(250, 60);
    btnExit->setMinimumSize(250, 60);


    layout = new QVBoxLayout;
    layout->addWidget(WelcomeLabel);
    layout->addSpacing(30);
    layout->addWidget(btnStartGame);
    layout->addWidget(btnTutorial);
    layout->addWidget(btnExit);
    layout->setSpacing(10);

    view->setLayout(layout);

    connect(btnStartGame, &QPushButton::clicked, [=](){ emit SelectLevel(); });
    connect(btnTutorial, &QPushButton::clicked, [=](){ emit Tutorial(); });
    connect(btnExit, &QPushButton::clicked, this, &MenuUi::close);
}

void MenuUi::backToMenu()
{
    this->show();
}
