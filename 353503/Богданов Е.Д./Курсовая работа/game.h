#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>

#include "constant.h"
#include "framegame.h"
#include "gamescene.h"

namespace Ui {
class Game;
}

class Game : public QWidget {
  Q_OBJECT

 public:
  explicit Game(QWidget* parent = nullptr);
  ~Game() override;

 private:
  Ui::Game* ui;
  gameScene* gamescene;
  QVector<bool> firstButtons{true, true, true};
  QVector<bool> secondButtons{true, true, true};
  QVector<bool> treeButtons{true, true, true};

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void AltAction(QString info);

  void HideButton();

  void on_pushButton_4_clicked();

  void Association(int power);

  void HideAssociations();

  void NewProject();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_9_clicked();

  void on_pushButton_10_clicked();

  void on_pushButton_11_clicked();

  void on_pushButton_12_clicked();

  void on_pushButton_14_clicked();

  void on_pushButton_15_clicked();

  void on_pushButton_16_clicked();

  void on_pushButton_17_clicked();

  void on_pushButton_19_clicked();

  void on_pushButton_18_clicked();

  void on_pushButton_20_clicked();

  void on_pushButton_21_clicked();

  void on_pushButton_22_clicked();

  void End(int score);

signals:
  void UpdateInfo(QString);
  void StartGame();
  void EndMenu(int score);
};

#endif  // GAME_H
