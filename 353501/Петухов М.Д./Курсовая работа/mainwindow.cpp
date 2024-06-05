#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QRegularExpressionValidator>
#include <QPixmap>
#include <QObject>
#include <QTimer>
#include "globals.h"
#include <QElapsedTimer>

bool isMouseOnEgg = false;
bool isMouseOnBear = false;
bool isMouseOnProduct = false;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
                                         ui(new Ui::MainWindow) {

                                          
  _parentPtr = dynamic_cast<Widget* >(parent);

  rng = new XORShiftPlusPlus(XORShiftPlusPlus::Rand(), XORShiftPlusPlus::Rand(), XORShiftPlusPlus::Rand());

  this->setFixedSize(1280, 855); 
  this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  ui->setupUi(this);

  scene = new CustomGraphicsScene();

  ui->graphicsView->setRenderHint(QPainter::Antialiasing);

  ui->graphicsView->setCacheMode(QGraphicsView::CacheNone);

  ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  ui->graphicsView->setWindowTitle("QGraphicsView example");

  ui->graphicsView->setFrameStyle(0);
  ui->graphicsView->setSceneRect(0,0,1280, 855);
  ui->graphicsView->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
  ui->graphicsView->setFixedSize(1280, 855);

  ui->buyWater->setStyleSheet("background-color: rgba(255, 255, 255, 0);\n"
  "border: none;");
  ui->openEggDialogButton->setStyleSheet("background-color: rgba(255, 255, 255, 0);\n"
  "border: none;");
  ui->winLabel->hide();

  QString imageMoneyPath = "../resources/MoneyPicture.png";
  QPixmap imageMoney(imageMoneyPath);
  ui->labeMoneyPicture->setScaledContents(true);
  ui->labeMoneyPicture->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->labeMoneyPicture->setPixmap(imageMoney);

  QString imageEggPath = "../resources/egg.png";
  QPixmap imageEgg(imageEggPath);
  ui->eggsLabelPicture->setScaledContents(true);
  ui->eggsLabelPicture->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->eggsLabelPicture->setPixmap(imageEgg);

  QString imageClockPath = "../resources/clock.png";
  QPixmap imageClock(imageClockPath);
  ui->clockPictureLabel->setScaledContents(false);
  ui->clockPictureLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->clockPictureLabel->setPixmap(imageClock);

  QString imageProductPath = "../resources/product.png";
  QPixmap imageProduct(imageProductPath);
  ui->labelProductPicture->setScaledContents(true);
  ui->labelProductPicture->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->labelProductPicture->setPixmap(imageProduct);

  QString imageBackWinLabelPath = "../resources/backEggDialog.png";
  QPixmap imageWinLabel(imageBackWinLabelPath);
  ui->winLabel->setScaledContents(true);
  ui->winLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->winLabel->setPixmap(imageWinLabel);
  QFont font("Noto Sans", 36);
  font.setWeight(QFont::Bold);
  ui->winLabel->setFont(font);
  ui->winLabel->setText("You won");

  QString imageHenLabelPath = "../resources/Hen-removebg-preview.png";
  QPixmap imageHenLabel(imageHenLabelPath);
  ui->labelBuyedHens->setScaledContents(true);
  ui->labelBuyedHens->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  ui->labelBuyedHens->setPixmap(imageHenLabel);

  QString imageHenPath = "../resources/Hen-removebg-preview.png";
  QPixmap imageHen(imageHenPath);
  ui->addHen->setIcon(QIcon(imageHen));
  ui->addHen->setStyleSheet("background-color: transparent; border: none;");

  ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

  scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    QPixmap backImage("../resources/fieldFinal.jpeg");

  QSize newSize(1280, 855); 
  backImage = backImage.scaled(newSize, Qt::KeepAspectRatio);

    if (backImage.isNull()) {
      qDebug() << "no image";
  }
  QBrush backgroundBrush(backImage);

  ui->graphicsView->setBackgroundBrush(backImage);

  ui->graphicsView->setScene(scene);

  ui->moneyAmountLabel->setText(QString::number(money));
  ui->collectedEggsLabel->setText(QString::number(collectedEggs) + " / " + QString::number(amountOfEggsToCollect));
  ui->collectedProductsLabel->setText(QString::number(collectedProducts) + " / " + QString::number(amountOfProductsToCollect));
  ui->amountOfBuyedHens->setText(QString::number(buyedHens) + " / " + QString::number(hensToBuy));

  ui->clockPictureLabel->show();
//////////////////
  QString buttonStyle = "QPushButton {"
                    "    background-color: #000080;" 
                    "    color: #FFFFFF;"
                    "}";
  QString pressedStyle = "QPushButton:pressed {"
                      "    background-color: #009ACD;"
                      "}";
  ui->createFactoryButton->setStyleSheet(buttonStyle + pressedStyle);
  ui->createFactoryButton->setIcon(QIcon("../resources/MoneyPicture.png"));
////////////////
  connect(ui->addHen, &QPushButton::clicked, this, &MainWindow::on_addHen_clicked);

  elapsedTimer = new QElapsedTimer();
  elapsedTimer->start();

  updateTimer = new QTimer(); 
  updateTimer->start(1000);

  for(auto i = 0; i < amountOfbears; i++){
    timeForCreatingBears[i] = rng->getRandomValue(10000, 120000);
  }

  connect(updateTimer, &QTimer::timeout, this, &MainWindow::getTimeForBears);

  timerToCheckWinCondition = new QTimer();
  connect(timerToCheckWinCondition, &QTimer::timeout, this, &MainWindow::checkWinConditionSlot);
  timerToCheckWinCondition->start(100);

  on_addHen_clicked();
  on_addHen_clicked();
}

void MainWindow::getTimeForBears(){
    int elapsedTime = elapsedTimer->elapsed() / 1000; 
    ui->pastTimeLabel->setText(formatTime(elapsedTime));
    for(auto i = 0; i < this->amountOfbears; i++){
      if(this->timeForCreatingBears[i] / 1000 == elapsedTimer->elapsed() / 1000){
        addBear();
      };
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    closedSlot();
    QMainWindow::closeEvent(event);
}

void MainWindow::increaseAmountOfCollectedBears(){
  collectedBears++;
}

void MainWindow::checkWinConditionSlot(){
  if(collectedEggs >= amountOfEggsToCollect 
      && collectedProducts >= amountOfProductsToCollect 
        && buyedHens >= hensToBuy){
          winDialog = new WinDialog(this);
          winDialog->exec();
          timerToCheckWinCondition->stop();
          delete timerToCheckWinCondition;
      }
}

void MainWindow::closedSlot(){
  _parentPtr->show();
  if(winDialog != nullptr){ 
    winDialog->close();
  }
  close();
}

void MainWindow::on_createFactoryButton_clicked(){
  if(money >= 150){
    ui->createFactoryButton->hide();
    money-=150;
    ui->moneyAmountLabel->setText(QString::number(money));
    factory = new Factory(&collectedEggs);
    scene->addItem(factory);
    factory->setPos(115, 160);

    connect(factory, &Factory::updateCollectedEggsLabelSignal, this, &MainWindow::updateCollectedEggsSlot);
    connect(factory, &Factory::makeProduct, this, &MainWindow::makeProductSlot);
  }
}

void MainWindow::makeProductSlot(){
  Product* product = new Product();
  scene->addItem(product);
  product->setPos(115 + 180, 160 + 180);
  product->setZValue(1.9);
  connect(product, &Product::productWasCollected, this, &MainWindow::collectedProductsIncrement);
}

void MainWindow::collectedProductsIncrement(){
  collectedProducts++;
  ui->collectedProductsLabel->setText(QString::number(collectedProducts) + " / " + QString::number(amountOfProductsToCollect));
}

void MainWindow::addBear(){
  Bear* bear = new Bear(scene);
  scene->addItem(bear);
  int x = rng->getRandomXPos();
  int y = rng->getRandomYPos();
  bear->setPos(x, y);
  bear->setZValue(2.0);
  connect(bear, &Bear::bearWasRemoved, this, &MainWindow::increaseAmountOfCollectedBears);
}

QString MainWindow::formatTime(int seconds) {
    const int minutes = seconds / 60;
    const int remainingSeconds = seconds % 60;
    return QString("%1:%2")
        .arg(minutes, 2, 10, QChar('0'))
        .arg(remainingSeconds, 2, 10, QChar('0'));
}

void MainWindow::on_addHen_clicked(){
  if(money >= 100){
    money -= 100;
    ui->moneyAmountLabel->setText(QString::number(money));
    Animal* hen = new Animal(scene, &eggVec);
    buyedHens++;
    ui->amountOfBuyedHens->setText(QString::number(buyedHens) + " / " + QString::number(hensToBuy));
    scene->addItem(hen);
    hen->setZValue(1.0);
    int x = rng->getRandomXPos();
    int y = rng->getRandomYPos();
    hen->setPos(x, y);
    connect(hen, &Animal::updateCollectedEggsLabelSignal, this, &MainWindow::updateCollectedEggsSlotAndIncrement);
    connect(hen, &Animal::deleteHenSignal, this, &MainWindow::deleteHen);
  }
}

void MainWindow::deleteHen(Animal* henToDelete){
  delete henToDelete;
}

void MainWindow::updateCollectedEggsSlotAndIncrement(){
  collectedEggs++;
  ui->collectedEggsLabel->setText(QString::number(collectedEggs) + " / " + QString::number(amountOfEggsToCollect));
}

void MainWindow::on_buyWater_clicked(){
  if(scene->waterToGrowGrass < 1 && money - moneyToBuyWater > 0){
    scene->waterToGrowGrass = 7;
    money -= moneyToBuyWater;
    scene->drawWaterInWell();
    ui->moneyAmountLabel->setText(QString::number(money));
  }
}

void MainWindow::startSellingEggs(QPushButton* sellEggsButton, int eggsForSale){
      sellEggsButton->setEnabled(false);
      QTimer* timerForSellingEggs = new QTimer();
      connect(timerForSellingEggs, &QTimer::timeout, this, [this, sellEggsButton, eggsForSale](){
        this->remainingTime -= 100;  

        QString timeText = QString::number(this->remainingTime + 1) + " мс";
        ui->labelForRemainedTime->setText(QString::number(this->remainingTime/1000));
        if (this->remainingTime <= 0) {
            QTimer* timer = qobject_cast<QTimer*>(sender());
            if (timer) {
                timer->stop(); 
                delete timer; 
            }
            sellEggsButton->setEnabled(true);
            this->remainingTime = 20000;
            money+=eggsForSale*10;
            ui->moneyAmountLabel->setText(QString::number(money));
        }
      });
      timerForSellingEggs->start(100);
}

void MainWindow::startSellingBears(QPushButton* sellBearsButton, int bearsForSelling){
      sellBearsButton->setEnabled(false);
      QTimer* timerForSellingBears = new QTimer();
      connect(timerForSellingBears, &QTimer::timeout, this, [this, sellBearsButton, bearsForSelling](){
        this->remainingTime -= 100;  

        QString timeText = QString::number(this->remainingTime + 1) + " мс";
        ui->labelForRemainedTime->setText(QString::number(this->remainingTime/1000));
        if (this->remainingTime <= 0) {
            QTimer* timer = qobject_cast<QTimer*>(sender());
            if (timer) {
                timer->stop(); 
                delete timer; 
            }
            sellBearsButton->setEnabled(true);
            this->remainingTime = 20000;
            money+=bearsForSelling*60;
            ui->moneyAmountLabel->setText(QString::number(money));
        }
      });
      timerForSellingBears->start(100);
}

void MainWindow::on_openEggDialogButton_clicked(){
    Dialog* dialog = new Dialog(this);
    QLabel* tempMoneyLabel = ui->moneyAmountLabel;
    QLabel* tempEggsLabel = ui->collectedEggsLabel;
    int remainingTime = 5000;
    connect(dialog, &Dialog::selledEggs, this, &MainWindow::startSellingEggs);
    connect(dialog, &Dialog::updateCollectedEggsLabelSignal, this, &MainWindow::updateCollectedEggsSlot);
    connect(dialog, &Dialog::selledBears, this, &MainWindow::startSellingBears);
      dialog->exec();
}

void MainWindow::updateCollectedEggsSlot(){
    ui->collectedEggsLabel->setText(QString::number(collectedEggs) + " / " + QString::number(amountOfEggsToCollect));
}