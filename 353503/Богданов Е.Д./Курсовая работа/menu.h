#ifndef MENU_H
#define MENU_H

#include <QPainter>
#include <QWidget>

#include "constant.h"
#include "framemenu.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget {
  Q_OBJECT

 public:
  explicit Menu(QWidget *parent = nullptr);
  ~Menu() override;

 private slots:
  void on_pushButton_6_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_5_clicked();

 private:
  Ui::Menu *ui;

 signals:
  void UpdateInfo(QString name_new_window);
};

#endif  // MENU_H
