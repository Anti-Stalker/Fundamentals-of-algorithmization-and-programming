//
// Created by u on 03.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"

void main_window::generate()
{
    if (generating)
        return;
    generating = true;

    std::string text = ui->textField->toPlainText().toStdString();
    predict(n, text, ui->predictNum->value(), ui->kolNum->value());

    std::string newText;
    std::ifstream fin(OUTPUT);
    while (!fin.eof())
    {
        std::string s;
        getline(fin, s);
        newText += s;
        newText += "\n";
    }

    for (int i = (int)text.size(); i < newText.size() - 1; i++)
    {
        QCoreApplication::processEvents();
        if (newText[i] == ' ')
        {
            ui->textField->setPlainText(QString::fromStdString(newText.substr(0, i + 1)));
            usleep(20000);
            continue;
        }
        i++;
        ui->textField->setPlainText(QString::fromStdString(newText.substr(0, i + 1)));
        usleep(20000);
    }

    generating = false;
}

void main_window::showSettings()
{
    ui->label->setVisible(!ui->label->isVisible());
    ui->label_2->setVisible(!ui->label_2->isVisible());
    ui->predictNum->setVisible(!ui->predictNum->isVisible());
    ui->kolNum->setVisible(!ui->kolNum->isVisible());
}

void main_window::fullScreen()
{
    if (isFullScreen)
        main_window::setWindowState(Qt::WindowMaximized);
    else
        main_window::setWindowState(Qt::WindowFullScreen);
    isFullScreen = !isFullScreen;
}

main_window::main_window(QWidget *parent) : QWidget(parent), ui(new Ui::main_window)
{
    ui->setupUi(this);
    ui->predictNum->setVisible(false);
    ui->kolNum->setVisible(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);

    connect(ui->generateButton, SIGNAL(clicked(bool)), this, SLOT(generate()));
    connect(ui->settingsButton, SIGNAL(clicked(bool)), this, SLOT(showSettings()));
    connect(ui->bread, SIGNAL(clicked(bool)), this, SLOT(fullScreen()));
}

main_window::~main_window()
{
    delete ui;
}
