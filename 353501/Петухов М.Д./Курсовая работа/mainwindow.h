#pragma once
#include <QMainWindow>
#include "CustomGraphicsScene.h"
#include <QMessageBox>
#include "Egg.h"
#include "Animal.h"
#include <QElapsedTimer>
#include <QPropertyAnimation>
#include <QTime>
#include "dialog.h"
#include "Bear.h"
#include "factory.h"
#include "product.h"
#include "winDialog.h"
#include "widget.h"
#include "xorshiftplus.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  MainWindow(QWidget *parent = nullptr);
  Widget* _parentPtr;
  WinDialog* winDialog = nullptr;
private:
  QTimer* updateTimer;

  CustomGraphicsScene* scene;
  int moneyToBuyWater = 19;
  int collectedProducts = 0;
  int buyedHens = 0;
  QTimer* timerForRandomEvent;
  int remainingTime = 20000;
  short amountOfbears = 2;
  int timeForCreatingBears[2];
  Factory* factory;

  const int amountOfEggsToCollect = 6;
  const int amountOfProductsToCollect = 2;
  const int hensToBuy = 3;
  QTimer* timerToCheckWinCondition;

private:
  QString formatTime(int seconds);

  XORShiftPlusPlus* rng;

public:
  int collectedBears = 0;
  int money = 390;
  int collectedEggs = 0;
  QTimer* timerForSellingEggs;
  QElapsedTimer* elapsedTimer;
  QVector<Egg* > eggVec;

public:
  void on_addHen_clicked();

protected:
  Ui::MainWindow *ui;

protected:
  void closeEvent(QCloseEvent *event) override;
private slots:
  void on_buyWater_clicked();
  void on_openEggDialogButton_clicked();
  void startSellingEggs(QPushButton* sellEggsButton, int eggsForSale);
  void updateCollectedEggsSlotAndIncrement();
  void updateCollectedEggsSlot();
  void deleteHen(Animal* henToDelete);
  void addBear(); 
  void makeProductSlot();
  void collectedProductsIncrement();
  void on_createFactoryButton_clicked();
  void checkWinConditionSlot();
  void increaseAmountOfCollectedBears();
  void startSellingBears(QPushButton* sellBearsButton, int bearsForSale);
  void getTimeForBears();
public slots:
  void closedSlot();
signals:
    void closed();
};