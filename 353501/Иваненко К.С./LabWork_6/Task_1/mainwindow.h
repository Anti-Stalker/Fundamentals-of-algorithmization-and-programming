#pragma once

#include <QMainWindow>
#include "town.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
  class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();
  ~MainWindow();

private:
  void fillUiFromStruct();

private slots:
  void on_printButton_clicked();

private:
  Ui::MainWindow *ui;
  Town *town;
};
