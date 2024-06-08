#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "deck.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->pauseMenu->hide();
    ui->doubleUp->hide();
    ui->repeatButton->hide();
    ui->doubleButton->hide();
    ui->hitButton->hide();
    ui->splitButton->hide();
    ui->standButton->hide();
    ui->splitHit->hide();
    ui->splitStand->hide();
    //connect(&_game, &Game::indexChanged, this, &MainWindow::whoIsNow);
    connect(&_game, &Game::cardDealt, this, &MainWindow::playerTakesCard);
    connect(&_game, &Game::splitCardDealt, this, &MainWindow::playerTakesSplitCard);
    connect(&_game, &Game::gameEnded, this, &MainWindow::startNewTurn);
    connect(&_game, &Game::getPlayerScore, this, &MainWindow::showPlayerScore);
    connect(&_game, &Game::getPlayerSplitScore, this, &MainWindow::showPlayerSplitScore);
    connect(&_game, &Game::getPlayerChips, this, &MainWindow::showPlayerChips);
    connect(&_game, &Game::gameStarted, this, &MainWindow::switchToPlayButtons);
    connect(&_game, &Game::splitEnded, this, &MainWindow::switchToPlayButtons);
    connect(&_game, &Game::amountHasChanged, this, &MainWindow::changeAmount);
    connect(&_game, &Game::dealersTurn, this, &MainWindow::hideButtons);
    connect(&_game, &Game::splited, this, &MainWindow::switchToSplitButtons);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quitGame()
{
    for (int i = 0; i < _amount_of_players; ++i) {
        for (int j = 0; j < _card_labels[i].size(); ++j) {
            _card_labels[i][j]->clear();
            delete _card_labels[i][j];
        }
        _card_labels[i].clear();
        _score[i]->clear();
        delete _score[i];
    }

    for (int i = 0; i < _amount_of_players; ++i) {
        for (int j = 0; j < _split_card_labels[i].size(); ++j) {
            _split_card_labels[i][j]->clear();
            delete _split_card_labels[i][j];
        }
        _split_card_labels[i].clear();
        _split_card_count[i] = 0;
        _split_score[i]->clear();
        _split_score[i]->hide();
    }

    for (int i = 0; i < _amount_of_players - 1; ++i) {
        _chips[i]->clear();
        delete _chips[i];
    }

    _split_card_labels.clear();
    _split_score.clear();
    _card_labels.clear();
    _card_count.clear();
    _score.clear();
    _chips.clear();
    switchToBetButtons();
}

void MainWindow::on_pushButton_2_clicked()
{
    qApp->exit(0);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_backFromLevelMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_easyDiff_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    _amount_of_players = 2;
    _game.addPlayer(_amount_of_players);
    initializeMoveOnSplit();
    initializeCardLabels();
    initializeCardSplitLabels();
    initializePlayerChips();
    initializePlayerScore();
    initializePlayerSplitScore();
    for (int i = 0; i < _amount_of_players - 1; ++i) {
        positionOfScoreAndChips(i);
        _chips[i]->setText("50000");
        _chips[i]->show();
        _chips[i]->move(_xPosition, _yPosition);
    }
}


void MainWindow::on_mediumDiff_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    _amount_of_players = 3;
    _game.addPlayer(_amount_of_players);
    initializeMoveOnSplit();
    initializeCardLabels();
    initializeCardSplitLabels();
    initializePlayerChips();
    initializePlayerScore();
    initializePlayerSplitScore();
    for (int i = 0; i < _amount_of_players - 1; ++i) {
        positionOfScoreAndChips(i);
        _chips[i]->setText("50000");
        _chips[i]->show();
        _chips[i]->move(_xPosition, _yPosition);
    }
}


void MainWindow::on_hardDiff_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    _amount_of_players = 4;
    _game.addPlayer(_amount_of_players);
    initializeMoveOnSplit();
    initializeCardLabels();
    initializeCardSplitLabels();
    initializePlayerChips();
    initializePlayerScore();
    initializePlayerSplitScore();
    for (int i = 0; i < _amount_of_players - 1; ++i) {
        positionOfScoreAndChips(i);
        _chips[i]->setText("50000");
        _chips[i]->show();
        _chips[i]->move(_xPosition, _yPosition);
    }
}


void MainWindow::on_pauseButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->pauseMenu->show();
}


void MainWindow::on_resume_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->pauseMenu->hide();
}


void MainWindow::on_quitGame_clicked()
{
    ui->pauseMenu->hide();
    ui->stackedWidget->setCurrentIndex(2);
    quitGame();
    _game.quitGame();
}

void MainWindow::on_doubleUp_clicked()
{
    _game.playerDoubleBet();
}

void MainWindow::on_oneKButton_clicked()
{
    _game.playerPlaceBet(1000);
}


void MainWindow::on_fiveKButton_clicked()
{
    _game.playerPlaceBet(5000);
}


void MainWindow::on_tenKButton_clicked()
{
    _game.playerPlaceBet(10000);
}


void MainWindow::on_repeatButton_clicked()
{
    _game.playerRepeatBet();
}


void MainWindow::on_betButton_clicked()
{
    QString input = ui->lineEdit->text();
    int betSize = input.toInt();
    ui->lineEdit->clear();
    _game.playerPlaceBet(betSize);
}


void MainWindow::on_hitButton_clicked()
{
    _game.playerHit();
}


void MainWindow::on_standButton_clicked()
{
    _game.playerStand();
}


void MainWindow::on_splitButton_clicked()
{
    _game.playerSplit();
}

void MainWindow::switchToPlayButtons()
{
    ui->oneKButton->hide();
    ui->fiveKButton->hide();
    ui->tenKButton->hide();
    ui->betButton->hide();
    ui->lineEdit->hide();
    ui->doubleUp->hide();
    ui->repeatButton->hide();
    ui->splitHit->hide();
    ui->splitStand->hide();
    ui->doubleButton->show();
    ui->hitButton->show();
    ui->splitButton->show();
    ui->standButton->show();
}

void MainWindow::switchToSplitButtons(int index)
{
    ui->doubleButton->hide();
    ui->hitButton->hide();
    ui->splitButton->hide();
    ui->standButton->hide();
    ui->splitHit->show();
    ui->splitHit->move(850, 920);
    ui->splitStand->show();
    ui->splitStand->move(1000, 920);
    positionOfCards(index);
    _card_labels[index][0]->move(_xPosition - 4 * cardSpacing, _yPosition);
    QLabel *label = new QLabel(ui->page_3);
    label = _card_labels[index].takeLast();
    _split_card_labels[index].push_back(label);
    _split_card_labels[index][0]->move(_xPosition + 4 * cardSpacing, _yPosition);
    ++_split_card_count[index];
    --_card_count[index];
    QString number = _score[index]->text();
    int num = number.toInt() / 2;
    _move_on_split[index] = splitmove;
    _score[index]->setText(QString::number(num));
    showPlayerSplitScore(num, index);
}

void MainWindow::switchToBetButtons()
{
    ui->oneKButton->show();
    ui->fiveKButton->show();
    ui->tenKButton->show();
    ui->betButton->show();
    ui->lineEdit->show();
    ui->doubleUp->show();
    ui->repeatButton->show();
    ui->doubleButton->hide();
    ui->hitButton->hide();
    ui->splitButton->hide();
    ui->standButton->hide();
}

void MainWindow::hideButtons()
{
    ui->oneKButton->hide();
    ui->fiveKButton->hide();
    ui->tenKButton->hide();
    ui->betButton->hide();
    ui->lineEdit->hide();
    ui->doubleUp->hide();
    ui->repeatButton->hide();
    ui->doubleButton->hide();
    ui->hitButton->hide();
    ui->splitButton->hide();
    ui->standButton->hide();
}

void MainWindow::initializeMoveOnSplit()
{
    _move_on_split.resize(_amount_of_players - 1);
    _move_on_split.fill(0);
}

void MainWindow::initializeCardLabels()
{
    for (int i = 0; i < _amount_of_players; ++i) {
        QVector<QLabel*> cardLabels;
        _card_labels.push_back(cardLabels);
    }

    _card_count.resize(_amount_of_players);
    _card_count.fill(0);
}

void MainWindow::initializeCardSplitLabels()
{
    for (int i = 0; i < _amount_of_players; ++i) {
        QVector<QLabel*> cardLabels;
        _split_card_labels.push_back(cardLabels);
    }

    _split_card_count.resize(_amount_of_players);
    _split_card_count.fill(0);
}

void MainWindow::initializePlayerScore()
{
    for (int i = 0; i < _amount_of_players; ++i) {
        QLabel *label = new QLabel(ui->page_3);
        label->setAttribute(Qt::WA_TranslucentBackground);
        label->setFixedSize(100,20);
        label->setAlignment(Qt::AlignCenter);
        _score.push_back(label);
    }
}

void MainWindow::initializePlayerSplitScore()
{
    for (int i = 0; i < _amount_of_players; ++i) {
        QLabel *label = new QLabel(ui->page_3);
        label->setAttribute(Qt::WA_TranslucentBackground);
        label->setFixedSize(100,20);
        label->setAlignment(Qt::AlignCenter);
        _split_score.push_back(label);
    }
}

void MainWindow::initializePlayerChips()
{
    for (int i = 0; i < _amount_of_players - 1; ++i) {
        QLabel *label = new QLabel(ui->page_3);
        label->setAttribute(Qt::WA_TranslucentBackground);
        label->setFixedSize(100,20);
        label->setAlignment(Qt::AlignCenter);
        _chips.push_back(label);
    }
}

void MainWindow::changeAmount(int index)
{
    _score[index]->clear();
    _score.erase(_score.begin()+index);
    _chips[index]->clear();
    _chips.erase(_chips.begin()+index);
    --_amount_of_players;
    for (int i = 0; i < _amount_of_players - 1; ++i) {
        positionOfScoreAndChips(i);
        _chips[i]->move(_xPosition, _yPosition);
    }
}

void MainWindow::whoIsNow(int index)
{
    for (int i = 0; i < _chips.size(); ++i) {
        if(i == index){
            _chips[index]->setStyleSheet("QLabel { color : rgb(64, 224, 208); }");
        }
        else{
            _chips[i]->setStyleSheet("QLabel { color : rgb(255, 255, 255); }");
        }
    }
}

void MainWindow::playerTakesCard(const QPixmap& pixmap, int index)
{
    QLabel *label = new QLabel(ui->page_3);
    label->setAttribute(Qt::WA_TranslucentBackground);
    label->setFixedSize(250, 350); // Размер карты
    _card_labels[index].push_back(label);
    _card_labels[index][_card_count[index]]->setPixmap(pixmap.scaled(250, 350));
    positionOfCards(index);
    _card_labels[index][_card_count[index]]->show();
    _card_labels[index][_card_count[index]]->move(_xPosition, _yPosition);
    ++_card_count[index];
}

void MainWindow::playerTakesSplitCard(const QPixmap &pixmap, int index)
{
    QLabel *label = new QLabel(ui->page_3);
    label->setAttribute(Qt::WA_TranslucentBackground);
    label->setFixedSize(250, 350); // Размер карты
    _split_card_labels[index].push_back(label);
    _split_card_labels[index][_split_card_count[index]]->setPixmap(pixmap.scaled(250, 350));

    positionOfSplitCards(index);

    _split_card_labels[index][_split_card_count[index]]->show();
    _split_card_labels[index][_split_card_count[index]]->move(_xPosition, _yPosition);
    ++_split_card_count[index];
}

void MainWindow::positionOfCards(int i)
{
    if(i == _amount_of_players - 1){
        qDebug("dealer takes");
        _xPosition = this->width() / 2 - 150 + _card_count[i] * cardSpacing;
        _yPosition = 150;
    }

    else if (_amount_of_players == 2){
        _xPosition = this->width() / 2 - 150 - _move_on_split[i] + _card_count[i] * cardSpacing;
        _yPosition = 550;
    }

    else if (_amount_of_players == 3){
        playerSpacing = 980;
        _xPosition = 450 + playerSpacing * i - 150 - _move_on_split[i] + _card_count[i] * cardSpacing;
        _yPosition = 550;
    }

    else{
        playerSpacing = 760;
        _xPosition = 200 + playerSpacing * i - 150 - _move_on_split[i] + _card_count[i] * cardSpacing;
        _yPosition = 550;
    }
}

void MainWindow::positionOfSplitCards(int i)
{
    cardSpacing = 50;
    if (_amount_of_players == 2){
        _xPosition = this->width() / 2  + 150 + _split_card_count[i] * cardSpacing;
        _yPosition = 550;
    }

    else if (_amount_of_players == 3){
        playerSpacing = 980;
        _xPosition = 450 + playerSpacing * i + 150  + _split_card_count[i] * cardSpacing;
        _yPosition = 550;
    }

    else{
        playerSpacing = 760;
        _xPosition = 200 + playerSpacing * i + 150 + _split_card_count[i] * cardSpacing;
        _yPosition = 550;
    }
}

void MainWindow::positionOfScoreAndChips(int i)
{
    qDebug("show time");
    if (_amount_of_players == 2){
        _xPosition = this->width() / 2 - 50;
        _yPosition = 902;
    }

    else if (_amount_of_players == 3){
        playerSpacing = 980;
        _xPosition = 450 + playerSpacing * i - 50;
        _yPosition = 902;
    }

    else{
        playerSpacing = 760;
        _xPosition = 200 + playerSpacing * i - 50;
        _yPosition = 902;
    }
}

void MainWindow::startNewTurn()
{
    qDebug("new deal");
    for (int i = 0; i < _amount_of_players; ++i) {
        for (int j = 0; j < _card_labels[i].size(); ++j) {
            _card_labels[i][j]->clear();
            delete _card_labels[i][j];
        }
        _card_labels[i].clear();
        _card_count[i] = 0;
        _score[i]->clear();
        _score[i]->hide();
    }

    for (int i = 0; i < _amount_of_players; ++i) {
        for (int j = 0; j < _split_card_labels[i].size(); ++j) {
            _split_card_labels[i][j]->clear();
            delete _split_card_labels[i][j];
        }
        _split_card_labels[i].clear();
        _split_card_count[i] = 0;
        _split_score[i]->clear();
        _split_score[i]->hide();
    }

    _card_labels.clear();
    _card_count.clear();
    _split_card_labels.clear();
    _split_card_count.clear();
    _move_on_split.fill(0);

    _game.kickNahuy();

    // Инициализация векторов для новой раздачи
    initializeCardLabels();
    initializeCardSplitLabels();
    initializePlayerChips();
    initializePlayerScore();
    initializePlayerSplitScore();
    switchToBetButtons();
}

void MainWindow::showPlayerScore(int score, int index)
{
    QString scoree = QString::number(score);
    _score[index]->setText(scoree);
    _score[index]->show();
    _score[index]->move(_xPosition, (_yPosition - 50));
}

void MainWindow::showPlayerSplitScore(int score, int index)
{
    QString scoree = QString::number(score);
    _split_score[index]->setText(scoree);
    _split_score[index]->show();
    _split_score[index]->move(_xPosition + 100, (_yPosition - 50));
}

void MainWindow::showPlayerChips(int chips, int index)
{
    QString chiips = QString::number(chips);
    _chips[index]->setText(chiips);

    positionOfScoreAndChips(index);

    _chips[index]->show();
    _chips[index]->move(_xPosition, _yPosition);
}

void MainWindow::on_doubleButton_clicked()
{
    _game.playerDouble();
}


void MainWindow::on_splitStand_clicked()
{
    _game.playerSplitStand();
}


void MainWindow::on_splitHit_clicked()
{
    _game.playerSplitHit();
}

