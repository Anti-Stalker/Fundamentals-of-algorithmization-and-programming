#include "menu.h"

#include "ui_menu.h"

Menu::Menu(QWidget* parent) : QWidget(parent), ui(new Ui::Menu) {
  FrameMenu* frame = new FrameMenu(this);

  frame->setGeometry(0, 0, wight_window, height_window);

  frame->setStyleSheet(
      "QWidget { background-image: url(:/img/img/ARK_NOVA.jpg); "
      "background-repeat: no-repeat; background-position: center;} ");

  ui->setupUi(this);
}

Menu::~Menu() { delete ui; }

void Menu::on_pushButton_6_clicked() { exit(0); }
void Menu::on_pushButton_4_clicked() { emit UpdateInfo("Правила игры"); }
void Menu::on_pushButton_2_clicked() { emit UpdateInfo("Играть"); }
void Menu::on_pushButton_5_clicked() { emit UpdateInfo("Рейтинг"); }
