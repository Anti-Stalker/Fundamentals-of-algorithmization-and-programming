#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->pushButton->hide();

  Menu *menu = new Menu();
  Game *game = new Game();

  windows = new QStackedWidget;
  windows->addWidget(menu);
  windows->addWidget(game);

  this->setCentralWidget(windows);

  windows->setCurrentIndex(0);

  Menu* _menu = dynamic_cast<Menu*>(windows->widget(0));

  connect(_menu, SIGNAL(UpdateInfo(QString)), this, SLOT(UpdateWindow(QString)));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::UpdateWindow(QString name_new_window) {
  if (name_new_window == "Играть") {
    Game *game = dynamic_cast<Game*>(windows->widget(1));

    connect(game, SIGNAL(UpdateInfo(QString)), this,
            SLOT(UpdateWindow(QString)));
    connect(game, SIGNAL(EndMenu(int)), this, SLOT(EndMenu(int)));

    windows->setCurrentIndex(1);

  } else if (name_new_window == "Правила игры") {
  } else if (name_new_window == "Рейтинг") {
  } else if (name_new_window == "Меню") {

    windows->setCurrentIndex(0);

    Menu *menu = dynamic_cast<Menu*>(windows->currentWidget());

    connect(menu, SIGNAL(UpdateInfo(QString)), this,
            SLOT(UpdateWindow(QString)));

  } else {
    exit(error);
  }
}

void MainWindow::EndMenu(int score)
{
  ui->pushButton->show();
  delete this->centralWidget();
  FrameGame* frame = new FrameGame(this);

  frame->setGeometry(0, 0, wight_window, height_window);

  frame->setStyleSheet(
      "QWidget { background-image: url(:/img/img/congratulations.jpg); "
      "background-repeat: no-repeat; background-position: center;} ");

  QPainter painter;
  painter.drawText(this->width()/2, this->height()/2, "Ваш результат: " +QString::number(score)+ " очка");

}

void MainWindow::on_pushButton_clicked()
{
  exit(0);
}

