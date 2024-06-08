#include "mainwindow.h"
#include "game.h"

Game::Game(){
    deck = new Deck(6);
    deck->shuffle();
    connect(this, &Game::dealersTurn, this, &Game::dealerPlay);
}

Player& Game::getCurrentPlayer() {
    return *currentPlayer;
}

void Game::nextPlayer() {
    if(_index != players.size()){
        qDebug() << "before next player: "  << _index;
        ++_index;
        qDebug() << "after next player: "  << _index;
        emit indexChanged(_index);
    }
    if(_index == players.size() - 1){
        qDebug("dealers turn emited");
        ended = false;
        QTimer::singleShot(0, this, &Game::dealersTurn);
    }
    else if (_index == players.size() and !ended) {
        QTimer::singleShot(2500, this, &Game::endGame);
    }
    // Переместите итератор на следующего игрока
    // Если это был последний игрок, вернитесь к первому игроку
}

void Game::addPlayer(int amount) {
    for(int i = 0; i < amount; ++i){
        players.insert(players.cbegin(), Player());
    }
}

void Game::startGame() {
    // Раздать карты игрокам
    for (int i = 0; i < players.size(); ++i) {
        if(i == players.size() - 1){
            dealCard(players[i]);
            continue;
        }
        dealCard(players[i]);
        dealCard(players[i]);
        ++_index;
    }
    _index = 0;
}

void Game::dealCard(Player &player) {
    Card card = deck->takeCardFromDeck();
    player.addCard(card);

    QPixmap pixmap = getCardImage();
    emit cardDealt(pixmap, getIndex());
    qDebug("card dealt emited");
    int score = player.getScore();
    int index = _index;
    emit getPlayerScore(score, index);
}

void Game::dealSplitCard(Player &player)
{
    Card card = deck->takeCardFromDeck();
    player.addCardToSplit(card);

    QPixmap pixmap = getCardImage();
    emit splitCardDealt(pixmap, getIndex());
    qDebug("split card dealt emited");
    int score = player.getSplitScore();
    int index = _index;
    emit getPlayerSplitScore(score, index);
}

QPixmap Game::getCardImage()
{
    return QPixmap::fromImage(deck->takeCardImageFromDeck());
}

void Game::playerPlaceBet(int bet)
{
    if(bet < 500){
        bet = 500;
    }
    if (bet > players[_index].getChips()){
        bet = players[_index].getChips();
    }
    players[_index].placeBet(bet);
    ++_index;
    if(_index == players.size() - 1){
        _index = 0;
        startGame();
        emit gameStarted();
    }
}

void Game::playerRepeatBet()
{
    if(players[_index].getChips() < players[_index].getBet()){
        players[_index].placeBet(players[_index].getChips());
    }
    else players[_index].placeBet(players[_index].getBet());
    int chips = players[_index].getChips();
    int index = _index;
    emit getPlayerChips(chips, index);
    ++_index;
    if(_index == players.size() - 1){
        _index = 0;
        startGame();
        emit gameStarted();
    }
}

void Game::playerDoubleBet()
{
    if(players[_index].getChips() < players[_index].getBet() * 2){
        players[_index].placeBet(players[_index].getChips());
    }
    else players[_index].placeBet(players[_index].getBet() * 2);
    int chips = players[_index].getChips();
    int index = _index;
    emit getPlayerChips(chips, index);
    ++_index;
    if(_index == players.size() - 1){
        _index = 0;
        startGame();
        emit gameStarted();
    }
}

void Game::playerHit() {
    dealCard(players[_index]);
    if (players[_index].getScore() >= 21) {
        nextPlayer();
    }
    if(_index == players.size() - 1){
        emit dealersTurn();
    }
}

void Game::playerStand() {
    nextPlayer();
}

void Game::playerDouble() {
    if(players[_index].getChips() < players[_index].getBet() * 2){
        return;
    }
    players[_index].doubleBet();
    dealCard(players[_index]);
    nextPlayer();
}

void Game::playerSplit() {
    if(players[_index].canSplit()){
        players[_index].splitHand();
        emit splited(_index);
    }
}

void Game::playerBust(Player &player) {

    nextPlayer();
    // Игрок превысил 21 очко
}

void Game::playerSplitHit()
{
    if(players[_index].getScore() <= 21 and !standing){
        dealCard(players[_index]);
    }

    if (players[_index].getScore() > 21 and !standing){
        playerSplitStand();
    }

    if(players[_index].getSplitScore() <= 21 and standing){
        dealSplitCard(players[_index]);
    }

    if(players[_index].getSplitScore() > 21 and standing){
        playerSplitStand();
    }
}

void Game::playerSplitStand()
{
    if(count == 0){
        ++count;
        standing = true;
    }
    else{
        count = 0;
        standing = false;
        emit splitEnded();
        nextPlayer();
    }
}

void Game::dealerPlay() {
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this, timer]{
        if(players.back().getScore() > 21){
            playerBust(players.back());
            timer->stop();
            timer->deleteLater();
        }
        if(players.back().getScore() < 17) {
            playerHit();
            timer->stop();
            timer->deleteLater();
        }
        if(players.back().getScore() <= 21 and players.back().getScore() >= 17){
            playerStand();
            timer->stop();
            timer->deleteLater();
        }
    });
    timer->start(1500);
}

void Game::endGameForSplit(Player &player, int i)
{
    if(player.getSplitScore() == 21 and player.getHandSize() == 2 and players.back().getScore() != 21){
        player.blackJack();
        int chips = player.getChips();
        int index = i;
        emit getPlayerChips(chips, index);
    }
    if (player.getSplitScore() > players.back().getScore() and player.getSplitScore() <= 21 or players.back().getScore() > 21 and player.getSplitScore() <= 21) {
        player.winChips();
        int chips = player.getChips();
        int index = i;
        emit getPlayerChips(chips, index);
    }
    else if(player.getSplitScore() == players.back().getScore()){
    }
    else{
        players[i].loseChips();
        int chips = players[i].getChips();
        int index = i;
        emit getPlayerChips(chips, index);
    }
    player.clearSplitHand();
    player.resetSplitScore();
    player.resetSplitAces();
    qDebug() << "Split Player " << i << " was cleared";
}

void Game::endGame() {
    if(ended){
        return;
    }
    _index = 0;
    qDebug("index = 0");
    for(int i = 0; i < players.size() - 1; ++i){
        if(players[i].getSpliting()){
            endGameForSplit(players[i], i);
        }
        if(players[i].getScore() == 21 and players[i].getHandSize() == 2 and players.back().getScore() != 21){
            players[i].blackJack();
            int chips = players[i].getChips();
            int index = i;
            emit getPlayerChips(chips, index);
        }
        if (players[i].getScore() > players.back().getScore() and players[i].getScore() <= 21 or players.back().getScore() > 21 and players[i].getScore() <= 21) {
            players[i].winChips();
            int chips = players[i].getChips();
            int index = i;
            emit getPlayerChips(chips, index);
        }
        else if(players[i].getScore() == players.back().getScore()){
        }
        else{
            players[i].loseChips();
            int chips = players[i].getChips();
            int index = i;
            emit getPlayerChips(chips, index);
        }
        players[i].clearHand();
        players[i].resetScore();
        players[i].resetAces();
        qDebug() << "Player " << i << " was cleared";
    }

    players.back().clearHand();
    players.back().resetScore();
    players.back().resetAces();
    if(!ended){
        QTimer::singleShot(500, this, &Game::gameEnded);
        ended = true;
    }
}

void Game::kickNahuy()
{
    for(int i = 0; i < players.size() - 1; ++i){
        if(players[i].getChips() <= 0){
            players.erase(players.begin() + i);
            emit amountHasChanged(i);
            --i;
        }
    }
    _index = 0;
}

void Game::quitGame() {
    players.clear();
    _index = 0;
    delete deck;
    deck = new Deck(6);
}

int Game::getIndex()
{
    return _index;
}

