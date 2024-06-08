#pragma once

#include <QMainWindow>
#include "choosedialog.h"
#include "parentoption.h"

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

  const QString MAINMENU = "1 - Абзац\n"
                           "2 - Массив\n"
                           "3 - Структура\n"
                           "4 - Бинарная структура\n"
                           "5 - Текст";

  const QString INOROUT = "1 - Ввод\n"
                          "2 - Вывод";

private slots:
  void on_options_clicked();

private:
  Ui::MainWindow *ui;
  ParentOption *option = nullptr;
};
