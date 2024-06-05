#include "createpopulationmenu.h"
#include "ui_createpopulationmenu.h"

CreatePopulationMenu::CreatePopulationMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePopulationMenu)
{
    ui->setupUi(this);
}

CreatePopulationMenu::~CreatePopulationMenu()
{
    delete ui;
}

void CreatePopulationMenu::UpdateSettings()
{
    Settings::GENOME_SIZE = ui->genome_size_box->value();
    Settings::MIN_POPULATIONS_SIZE = ui->min_population_size_box->value();
}
