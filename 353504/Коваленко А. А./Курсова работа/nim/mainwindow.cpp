#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Const.h"
#include <QRandomGenerator>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/Pict/msg268862666-114708.000001.jpg");
    int w1=ui->label_3->width();
    int h1=ui->label_3->height();
    ui->label_3->setPixmap(pix.scaled(w1,h1,Qt::KeepAspectRatio));
    QPixmap pax(":/Pict/maxresdef.jpg");
    int w2=ui->label_4->width();
    int h2=ui->label_4->height();
    ui->label_4->setPixmap(pax.scaled(w2,h2,Qt::KeepAspectRatio));
    // Изначально показываем меню
    ui->stackedWidget->setCurrentIndex(1);
    ui->pile4Label->setVisible(false);
    ui->label_11->setVisible(false);    // Скрыть 4-ую кучу по умолчанию
    srand(static_cast<unsigned>(time(nullptr)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}

void MainWindow::on_startGameButton_clicked()
{
    // Переход на экран настроек игры
    ui->stackedWidget->setCurrentIndex(2);
    ui->humanFirstRadioButton->setChecked(true);
}

void MainWindow::on_infoButton_clicked()
{
    // Показать информацию о игре (например, можно сделать диалоговое окно с информацией)
    QMessageBox::information(this, "Информация", "Ним — игра, в которой два игрока по очереди берут предметы, разложенные на несколько кучек. За один ход может быть взято любое количество предметов (больше нуля) из одной кучки. Выигрывает игрок, взявший последний предмет. В классическом варианте игры число кучек равняется трём."
                                                 "В данной игры вы можете выбрать количество кучек(3-4), а также выбрать соперника: играть против искусственного интелекта или другого игрока сидящий рядом с вами. Также если вы выбрали искусственный интелект вы можете выбрать: с какой сложностью выбрать ИИ, а также первыми будете ходить вы или ИИ."
                                                 "Классическая игра Ним имеет фундаментальное значение для теоремы Шпрага — Гранди. Эта теорема утверждает, что обычная игра, являющаяся суммой беспристрастных игр, эквивалентна обычной игре в Ним. При этом каждой беспристрастной игре-слагаемому соответствует кучка Ним, число предметов в которой равно значению функции Шпрага — Гранди для игровой позиции данной игры.");
}

void MainWindow::on_exitButton_clicked()
{
    // Закрыть приложение
    close();
}

void MainWindow::on_startGamePlayButton_clicked()
{
    int numPiles = ui->numPilesSpinBox->value();
    int initialPiles[numPiles];
    int max=10;
    for (int i = 0; i < numPiles; ++i) {
        initialPiles[i] = QRandomGenerator::global()->bounded(max); // Случайное количество предметов в каждой куче
    }

    game = new NimGame(this, numPiles);
    ui->pile4Label->setVisible(numPiles == 4);
    game->setInitialPiles(initialPiles);

    // Обновить метки кучек
    ui->pile1Label->setText(QString::number(initialPiles[0])+ " Камней");
    ui->pile2Label->setText(QString::number(initialPiles[1])+ " Камней");
    ui->pile3Label->setText(QString::number(initialPiles[2])+ " Камней");
    ui->pile4Label->setVisible(numPiles == 4);
    if (numPiles == 4) {
        ui->label_11->setVisible(true);
        ui->pile4Label->setText(QString::number(initialPiles[3])+ " Камней");
    }
    ui->pileSpinBox->setRange(1, numPiles);
    isTwoPlayerMode = ui->twoPlayerModeRadioButton->isChecked();
    maxTake = ui->difficultyComboBox->currentText().toInt();

    ui->stackedWidget->setCurrentIndex(0);
    ui->numItemsSpinBox->setRange(1, initialPiles[0]);
}

void MainWindow::handleGameEnd(QString message)
{
    if(ui->twoPlayerModeRadioButton->isChecked())
    {
        QMessageBox::information(this, "Конец игры", "Игра Окончена!");
    }else {
    QMessageBox::information(this, "Конец игры", message);
    }
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_humanMoveButton_clicked()
{

    int pile = ui->pileSpinBox->value() - 1;
    int numItems = ui->numItemsSpinBox->value();
    if (game->humanMove(pile, numItems))
    {
    updateGameState();

    if (!isTwoPlayerMode && !game->checkEmpty()) {
        game->aiMove(maxTake);
        updateGameState();
    }
    }
    int numPiles = ui->numPilesSpinBox->value();
    if(numPiles==3)
    {
        ui->pileSpinBox->setValue((pile+1)%3+1);
    }
    if(numPiles==4)
    {
        ui->pileSpinBox->setValue((pile+1)%4+1);
    }

}

void MainWindow::showGameSettings()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::showGame()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::updateGameState()
{
    int numPiles = game->getNumPiles();
    ui->pile1Label->setText("Куча 1: " + QString::number(game->getPile(0)));
    ui->pile2Label->setText("Куча 2: " + QString::number(game->getPile(1)));
    ui->pile3Label->setText("Куча 3: " + QString::number(game->getPile(2)));
    if (numPiles == 4) {
        ui->pile4Label->setText("Куча 4: " + QString::number(game->getPile(3)));
    }

    if (game->checkEmpty()) {
        handleGameEnd(game->getWinner());
    }
}
void MainWindow::on_pileSpinBox_valueChanged(int value)
{
    int pileIndex = value - 1;
    if (pileIndex >= 0 && pileIndex < game->getNumPiles()) {
        ui->numItemsSpinBox->setRange(1, game->getPile(pileIndex));
    }
}

