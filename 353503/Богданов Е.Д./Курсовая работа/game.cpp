#include "game.h"

#include "ui_game.h"

Game::Game(QWidget* parent) : QWidget(parent), ui(new Ui::Game) {
  FrameGame* frame = new FrameGame(this);

  frame->setGeometry(0, 0, wight_window, height_window);

  frame->setStyleSheet(
      "QWidget { background-image: url(:/img/img/Table4.jpeg); "
      "background-repeat: no-repeat; background-position: center;} ");

  ui->setupUi(this);
  ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
  ui->graphicsView->setStyleSheet(frame->styleSheet());
  ui->pushButton_3->hide();
  ui->pushButton_4->hide();
  ui->pushButton_5->hide();
  ui->pushButton_6->hide();
  ui->pushButton_7->hide();
  ui->pushButton_8->hide();
  ui->pushButton_9->hide();
  ui->pushButton_10->hide();
  ui->pushButton_11->hide();
  ui->pushButton_12->hide();
  ui->pushButton_13->hide();
  ui->pushButton_14->hide();
  ui->pushButton_15->hide();
  ui->pushButton_16->hide();
  ui->pushButton_17->hide();
  ui->pushButton_18->hide();
  ui->pushButton_19->hide();
  ui->pushButton_20->hide();
  ui->pushButton_21->hide();
  ui->pushButton_22->hide();
  ui->pushButton_3->adjustSize();
}

Game::~Game() { delete ui; }

void Game::on_pushButton_clicked() { emit UpdateInfo("Меню"); }

void Game::on_pushButton_2_clicked() {
  gamescene = new gameScene();
  ui->graphicsView->setScene(gamescene);
  connect(gamescene, SIGNAL(ButtonSignal(QString)), this,
          SLOT(AltAction(QString)));
  connect(gamescene, SIGNAL(HideButton()), this, SLOT(HideButton()));
  connect(gamescene, SIGNAL(Associations(int)), this, SLOT(Association(int)));
  connect(gamescene, SIGNAL(HideAssociations()), this,
          SLOT(HideAssociations()));
  connect(gamescene, SIGNAL(NewProject()), this, SLOT(NewProject()));
  connect(gamescene, SIGNAL(End(int)), this, SLOT(End(int)));
  gamescene->Start();
  ui->pushButton_2->setText("Начать сначала");
}

void Game::on_pushButton_3_clicked() {
  gamescene->AltAction(ui->pushButton_3->text());
  ui->pushButton_3->hide();
  gamescene->ProjectsOff();
}

void Game::AltAction(QString info) {
  ui->pushButton_3->setText(info);
  ui->pushButton_3->show();
}

void Game::HideButton() { ui->pushButton_3->hide(); }

void Game::on_pushButton_4_clicked() {
  gamescene->Association(2);
  gamescene->ProjectsOff();
}

void Game::Association(int power) {
  if (power >= 2) {
    ui->pushButton_4->show();
  }
  if (power >= 3) {
    ui->pushButton_5->show();
    ui->pushButton_6->show();
    ui->pushButton_7->show();
    ui->pushButton_8->show();
    ui->pushButton_9->show();
  }
  if (power >= 4) {
    ui->pushButton_10->show();
    ui->pushButton_11->show();
    ui->pushButton_12->show();
  }
  if (power >= (5 - gamescene->IsVeterenar())) {
    ui->pushButton_13->show();
    if (gamescene->HowManyProjects() >= 1) {
      if (firstButtons[0]) {
        ui->pushButton_14->show();
      }
      if (firstButtons[1]) {
        ui->pushButton_15->show();
      }
      if (firstButtons[2]) {
        ui->pushButton_16->show();
      }
    }
    if(gamescene->HowManyProjects()>=2){
      if(secondButtons[0]){
        ui->pushButton_17->show();
      }
      if(secondButtons[1]){
        ui->pushButton_18->show();
      }
      if(secondButtons[2]){
        ui->pushButton_19->show();
      }
    }
    if(gamescene->HowManyProjects()==3){
      if(treeButtons[0]){
        ui->pushButton_20->show();
      }
      if(treeButtons[1]){
        ui->pushButton_21->show();
      }
      if(treeButtons[2]){
        ui->pushButton_22->show();
      }
    }
  }
  gamescene->ProjectsOff();
}

void Game::HideAssociations() {
  ui->pushButton_4->hide();
  ui->pushButton_5->hide();
  ui->pushButton_6->hide();
  ui->pushButton_7->hide();
  ui->pushButton_8->hide();
  ui->pushButton_9->hide();
  ui->pushButton_10->hide();
  ui->pushButton_11->hide();
  ui->pushButton_12->hide();
  ui->pushButton_13->hide();
  ui->pushButton_14->hide();
  ui->pushButton_15->hide();
  ui->pushButton_16->hide();
  ui->pushButton_17->hide();
  ui->pushButton_18->hide();
  ui->pushButton_19->hide();
  ui->pushButton_20->hide();
  ui->pushButton_21->hide();
  ui->pushButton_22->hide();
}

void Game::NewProject()
{
  QVector<bool> newButtons{true, true, true};

  treeButtons = secondButtons;
  secondButtons = firstButtons;
  firstButtons = newButtons;
}

void Game::on_pushButton_5_clicked() {
  gamescene->AssociationCountry("Амр");
  gamescene->ProjectsOff();
}

void Game::on_pushButton_6_clicked() {
  gamescene->AssociationCountry("Афр");
  gamescene->ProjectsOff();
}

void Game::on_pushButton_7_clicked() {
  gamescene->AssociationCountry("Авс");
  gamescene->ProjectsOff();
}

void Game::on_pushButton_8_clicked() {
  gamescene->AssociationCountry("Азя");
  gamescene->ProjectsOff();
}

void Game::on_pushButton_9_clicked() {
  gamescene->AssociationCountry("Евр");
  gamescene->ProjectsOff();
}

void Game::on_pushButton_10_clicked() {
  gamescene->AssociationInstitutes("Верх");
  gamescene->ProjectsOff();
}

void Game::on_pushButton_11_clicked() {
  gamescene->AssociationInstitutes("Лево");
  gamescene->ProjectsOff();
}

void Game::on_pushButton_12_clicked() {
  gamescene->AssociationInstitutes("Право");
  gamescene->ProjectsOff();
}

void Game::on_pushButton_14_clicked() {
  gamescene->ProjestAction(3);
  firstButtons[0] = false;
  gamescene->ProjectsOff();
}

void Game::on_pushButton_15_clicked()
{
  gamescene->ProjestAction(2);
  firstButtons[1] = false;
  gamescene->ProjectsOff();
}


void Game::on_pushButton_16_clicked()
{
  gamescene->ProjestAction(1);
  firstButtons[2] = false;
  gamescene->ProjectsOff();
}


void Game::on_pushButton_17_clicked()
{
  gamescene->ProjestAction(6);
  secondButtons[0] = false;
  gamescene->ProjectsOff();
}


void Game::on_pushButton_19_clicked()
{
  gamescene->ProjestAction(5);
  secondButtons[1] = false;
  gamescene->ProjectsOff();
}


void Game::on_pushButton_18_clicked()
{
  gamescene->ProjestAction(4);
  secondButtons[2] = false;
  gamescene->ProjectsOff();
}


void Game::on_pushButton_20_clicked()
{
  gamescene->ProjestAction(9);
  treeButtons[0] = false;
  gamescene->ProjectsOff();
}


void Game::on_pushButton_21_clicked()
{
  gamescene->ProjestAction(8);
  treeButtons[1] = false;
  gamescene->ProjectsOff();
}


void Game::on_pushButton_22_clicked()
{
  gamescene->ProjestAction(7);
  treeButtons[2] = false;
  gamescene->ProjectsOff();
}

void Game::End(int score)
{
  emit EndMenu(score);
}

