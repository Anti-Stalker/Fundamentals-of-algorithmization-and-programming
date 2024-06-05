#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <QDialog>
#include "settings.h"

namespace Ui {
class SettingsMenu;
}

class SettingsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsMenu(QWidget *parent = nullptr);
    ~SettingsMenu();
    void UpdateSettings();

private:
    Ui::SettingsMenu *ui;

};

#endif // SETTINGSMENU_H
