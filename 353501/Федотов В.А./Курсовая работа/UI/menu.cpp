#include "menu.h"
#include "ui_menu.h"

#include <QDialog>

#include <qcoreapplication.h>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qtmetamacros.h>
#include <qwidget.h>

Menu::Menu(QWidget *parent) : QWidget(parent), ui(new Ui::Menu){
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    
    ui->setupUi(this);
    ui->rulesFrame->hide();

    ui->w_SpinBox->setValue(size_x);
    ui->h_SpinBox->setValue(size_y);

    connect(ui->startButton, &QPushButton::clicked, this, &Menu::handleStartGame);
    connect(ui->rulesButton, &QPushButton::pressed, this, &Menu::showRulesBox);
    connect(ui->exitButton, &QPushButton::clicked, this, &QCoreApplication::quit);
}

Menu::~Menu() {}

void Menu::handleStartGame() {
    size_x = ui->w_SpinBox->value();
    size_y = ui->h_SpinBox->value();
    emit startGame(size_x, size_y, ui->hardmodeCcheckBox->isChecked());
}

void Menu::showRulesBox() {
    QDialog* dialog = new QDialog(this); 
    dialog->setLayout(new QVBoxLayout());
    dialog->layout()->addWidget(ui->rulesFrame);
    ui->rulesFrame->show();
    dialog->exec(); // Show the dialog box as modal

}
