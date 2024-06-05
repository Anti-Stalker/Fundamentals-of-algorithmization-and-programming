#include "settingsmenu.h"
#include "ui_settingsmenu.h"

SettingsMenu::SettingsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsMenu)
{
    ui->setupUi(this);
}



SettingsMenu::~SettingsMenu()
{
    delete ui;
}

void SettingsMenu::UpdateSettings()
{
    Settings::MAX_HP = ui->max_hp_box->value();
    Settings::FOOD_HEAL = ui->food_heal_box->value();
    Settings::MAX_FOOD = (double)ui->ratio_box->value() / ui->ratio_box->maximum() * ui->max_food_poison_box->value();
    Settings::MAX_POISON = ui->max_food_poison_box->value() - Settings::MAX_FOOD;
    Settings::COUNT_WALLS = ui->count_walls_box->value();
    Settings::MIN_WALL_SIZE = ui->min_wall_size->value();
    Settings::MAX_WALL_SIZE = ui->max_wall_size->value();

}
