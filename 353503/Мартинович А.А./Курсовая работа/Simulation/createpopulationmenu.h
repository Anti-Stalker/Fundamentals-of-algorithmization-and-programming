#ifndef CREATEPOPULATIONMENU_H
#define CREATEPOPULATIONMENU_H

#include <QDialog>
#include "settings.h"

namespace Ui {
class CreatePopulationMenu;
}

class CreatePopulationMenu : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePopulationMenu(QWidget *parent = nullptr);
    ~CreatePopulationMenu();
    void UpdateSettings();

private:
    Ui::CreatePopulationMenu *ui;
};

#endif // CREATEPOPULATIONMENU_H
