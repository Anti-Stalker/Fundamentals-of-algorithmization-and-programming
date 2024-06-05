#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "game.h"
#include "menu.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;

 private:
  bool firstTry = true;

 public slots:
  void UpdateWindow(QString name_new_window);

  void EndMenu(int score);

private slots:
  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;
  QStackedWidget *windows;
};
#endif  // MAINWINDOW_H
