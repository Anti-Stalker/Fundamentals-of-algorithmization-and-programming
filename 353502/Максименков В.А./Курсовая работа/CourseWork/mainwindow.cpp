#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(geometry().size());

    scene = new QGraphicsScene(0, 0, 1100, 600);
    background = new Background(1);
    ui->background->setScene(scene);
    scene->addItem(background);
    timer = new QTimer();
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::exitGame);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimeout);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::startGame()
{
    QString username = ui->nameTextEdit->toPlainText();

    if (username.isEmpty())
    {
        QMessageBox::information(this, INFORMATION_HEADER, INFORMATION_TEXT);
    }
    else if (username.size() > 10)
    {
        QMessageBox::information(this, INFORMATION_HEADER, INFORMATION_LONG_NAME);
    }
    else
    {
        hide();
        game = new Game();
        connect(game, &Game::giveup, this, &MainWindow::showMenu);
        game->setUserName(username);
        game->setLevel(level);
        srand(time(0));
        int index = (rand() % NUMBER_OF_TASKS) + 1;


        QFile file(FILE_WITH_TASKS);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) qDebug() << SUCCESSFUL_FILE_OPENING;
        else qDebug() << ERROR_FILE_OPENING;

        int counter = 1;
        while(true)
        {
            if (counter == 2 * index - 1)
            {
                game->setQuestion(file.readLine());
                game->setAnswer(file.readLine());
                break;
            }

            file.readLine();
            file.readLine();
            counter += 2;
        }

        file.close();

        game->exec();
    }
}


void MainWindow::exitGame()
{
    QApplication::quit();
}


void MainWindow::showMenu()
{
    timer->start(FREQUENCY_OF_TIMER);
}


void MainWindow::onTimeout()
{
    ++sec;
    if (sec == TIME_FOR_STOP_TIMER)
    {
        sec = 0;
        timer->stop();
        game->reject();
        show();
    }
}


void MainWindow::on_comboBox_activated(int index)
{
    switch (index) {
    case 0:
        level = EASY_LEVEL;
        break;
    case 1:
        level = MEDIUM_LEVEL;
        break;
    case 2:
        level = HARD_LEVEL;
        break;
    default:
        break;
    }
}

