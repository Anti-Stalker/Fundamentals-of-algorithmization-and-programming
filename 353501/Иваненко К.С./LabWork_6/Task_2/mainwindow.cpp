#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "choosedialog.h"
#include "paragraphoption.h"
#include "arrayoption.h"
#include "structoption.h"
#include "binstructoption.h"
#include "paragraphtextoption.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  on_options_clicked();
}

MainWindow::~MainWindow()
{
  if (option)
  {
    delete option;
  }
  delete ui;
}

void MainWindow::on_options_clicked()
{
  if (option != nullptr) {
    delete option;
  }

  bool ok = true;
  int optionNumber = 1;
  ChooseDialog chooseOption(MAINMENU, 5, this);

  if (chooseOption.exec() == QDialog::Accepted)
  {
    optionNumber = chooseOption.getOption();
  }
  else
  {
    ok = false;
  }

  switch (optionNumber)
  {
  case 1:
  {
    option = new ParagraphOption(ui->inputData, ui->outputData, ui->instructions, this);
  }
    break;
  case 2:
  {
    option = new ArrayOption(ui->inputData, ui->outputData, ui->instructions, this);
  }
    break;
  case 3:
  {
    ChooseDialog chooseOption(INOROUT, 2, this);
    int io = 1;
    if (chooseOption.exec() == QDialog::Accepted)
    {
      io = chooseOption.getOption();
      option = new StructOption(ui->inputData, ui->outputData, ui->instructions, this, (OptionType)io);
    }
  }
  break;
  case 4:
  {
    ChooseDialog chooseOption(INOROUT, 2, this);
    int io = 1;
    if (chooseOption.exec() == QDialog::Accepted)
    {
      io = chooseOption.getOption();
      option = new BinStructOption(ui->inputData, ui->outputData, ui->instructions, this, (OptionType)io);
    }
  }
  break;
  case 5:
  {
    ChooseDialog chooseOption(INOROUT, 2, this);
    int io = 1;
    if (chooseOption.exec() == QDialog::Accepted)
    {
      io = chooseOption.getOption();
      option = new ParagraphTextOption(ui->inputData, ui->outputData, ui->instructions, this, (OptionType)io);
    }
  }
  break;
  }
  
  if (ok)
    option->init();
}