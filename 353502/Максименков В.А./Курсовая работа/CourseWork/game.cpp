#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) : QDialog(parent), ui(new Ui::Game)
{
    ui->setupUi(this);
    setFixedSize(geometry().size());

    scene = new QGraphicsScene(0, 0, 2*RADIUS + HEIGHT_OF_ARROW, 2*RADIUS);
    sceneForKeys = new QGraphicsScene(0, 0, 2*RADIUS + HEIGHT_OF_ARROW, RADIUS/3);
    sceneForCar = new QGraphicsScene(0, 0, 2*RADIUS + HEIGHT_OF_ARROW, 1.5*RADIUS/2);
    sceneForLetters = new QGraphicsScene(0, 0, 1058, 235);
    sceneForMenu = new QGraphicsScene(0, 0, 295, 235);
    sceneForGame = new QGraphicsScene(0, 0, 1345, 565);
    sceneForPrizes = new QGraphicsScene(0, 0, 965, 545);
    baraban = new Baraban();
    backgroundForLetters = new Background(2);
    backgroundForMenu = new Background(3);
    backgroundForGame = new Background(4);
    arrow = new Arrow();
    key1 = new Key();
    key2 = new Key();
    key3 = new Key();
    letteres = new Letters();
    car = new Car();
    prize = new Prize();
    key1->setPos(80, 10);
    key2->setPos(140, 10);
    key3->setPos(200, 10);
    car->setPos(LENGTH_OF_CAR/2, WIDTH_OF_CAR/2);
    sceneForKeys->addItem(key1);
    sceneForKeys->addItem(key2);
    sceneForKeys->addItem(key3);
    sceneForCar->addItem(car);
    sceneForLetters->addItem(backgroundForLetters);
    sceneForMenu->addItem(backgroundForMenu);
    sceneForGame->addItem(backgroundForGame);
    timer = new QTimer();
    timerForSupergame = new QTimer();
    ui->baraban->setScene(scene);
    ui->keys->setScene(sceneForKeys);
    ui->car->setScene(sceneForCar);
    ui->backgroundForLetters->setScene(sceneForLetters);
    ui->backgroundforMenu->setScene(sceneForMenu);
    ui->backgroundForGame->setScene(sceneForGame);
    ui->keys->hide();
    ui->car->hide();
    arrow->setPos(0, RADIUS);
    baraban->setPos(WIDTH_OF_ARROW + RADIUS, RADIUS);
    scene->addItem(baraban);
    scene->addItem(arrow);

    music->setMedia(QUrl::fromLocalFile(MUSIC_FOR_BEGINING));
    music->setVolume(MEDIUM_VOLUME);
    music->play();
    connect(music, &QMediaPlayer::stateChanged, this, &Game::processMusicChange);

    connect(ui->barabanButton, &QPushButton::clicked, this, &Game::rotateBaraban);
    connect(ui->claimTheLetterButton, &QPushButton::clicked, this, &Game::processClaimedLetter);
    connect(ui->openChosenLetterButton, &QPushButton::clicked, this, &Game::openChosenLetter);
    connect(ui->choosingPlayButton, &QPushButton::clicked, this, &Game::choosePlay);
    connect(ui->choosingPrizeButton, &QPushButton::clicked, this, &Game::choosePrize);
    connect(ui->prizeButton, &QPushButton::clicked, this, &Game::traidingWithPrize);
    connect(ui->moneyButton, &QPushButton::clicked, this, &Game::getMoney);
    connect(ui->answerTheWordButton, &QPushButton::clicked, this,  &Game::answerTheWord);
    connect(ui->claimTheWordButton, &QPushButton::clicked, this,  &Game::claimTheWord);
    connect(ui->rejectAnswerTheWordButton, &QPushButton::clicked, this, &Game::rejectAnswerTheWord);
    connect(ui->giveupButton, &QPushButton::clicked, this, &Game::giveUPandShowMenu);

    connect(timer, &QTimer::timeout, this, &Game::onTimeout);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);

    ui->player1Browser->setText(QString::number(0));
    ui->player2Browser->setText(QString::number(0));
    ui->playerBrowser->setText(QString::number(0));
    ui->choosingLetterSpinBox->hide();
    ui->openChosenLetterButton->hide();
    ui->choosingPrizeButton->hide();
    ui->choosingPlayButton->hide();
    ui->prizeButton->hide();
    ui->moneyButton->hide();
    ui->claimTheWordEdit->hide();
    ui->claimTheWordButton->hide();
    ui->rejectAnswerTheWordButton->hide();
    ui->answerTheWordButton->setEnabled(false);
    ui->barabanButton->setEnabled(false);
    ui->answerTheWordButton->setStyleSheet(DISABLED_COLOR_MODE);
    ui->barabanButton->setStyleSheet(DISABLED_COLOR_MODE);
    ui->claimTheLetterButton->setEnabled(false);

    letters.push_back(ui->taskBrowser);
    letters.push_back(ui->letter1);
    letters.push_back(ui->letter2);
    letters.push_back(ui->letter3);
    letters.push_back(ui->letter4);
    letters.push_back(ui->letter5);
    letters.push_back(ui->letter6);
    letters.push_back(ui->letter7);
    letters.push_back(ui->letter8);
    letters.push_back(ui->letter9);
    letters.push_back(ui->letter10);
    letters.push_back(ui->letter11);
    letters.push_back(ui->letter12);

    buttons.push_back(ui->claimTheLetterButton);
    buttons.push_back(ui->let1);
    buttons.push_back(ui->let2);
    buttons.push_back(ui->let3);
    buttons.push_back(ui->let4);
    buttons.push_back(ui->let5);
    buttons.push_back(ui->let6);
    buttons.push_back(ui->let7);
    buttons.push_back(ui->let8);
    buttons.push_back(ui->let9);
    buttons.push_back(ui->let10);
    buttons.push_back(ui->let11);
    buttons.push_back(ui->let12);
    buttons.push_back(ui->let13);
    buttons.push_back(ui->let14);
    buttons.push_back(ui->let15);
    buttons.push_back(ui->let16);
    buttons.push_back(ui->let17);
    buttons.push_back(ui->let18);
    buttons.push_back(ui->let19);
    buttons.push_back(ui->let20);
    buttons.push_back(ui->let21);
    buttons.push_back(ui->let22);
    buttons.push_back(ui->let23);
    buttons.push_back(ui->let24);
    buttons.push_back(ui->let25);
    buttons.push_back(ui->let26);
    buttons.push_back(ui->let27);
    buttons.push_back(ui->let28);
    buttons.push_back(ui->let29);
    buttons.push_back(ui->let30);
    buttons.push_back(ui->let31);
    buttons.push_back(ui->let32);
    buttons.push_back(ui->let33);

    keyButtons.push_back(ui->key1Button);
    keyButtons.push_back(ui->key2Button);
    keyButtons.push_back(ui->key3Button);

    for (int i = 0; i < keyButtons.size(); ++i)
    {
        keyButtons[i]->hide();
    }

    for (int i = 0; i < ALPHABET.size(); ++i)
    {
        russianLetters.push_back(QString(ALPHABET[i]));
    }

    for (int i = 1; i < buttons.size(); ++i)
    {
        connect(buttons[i], &QPushButton::pressed, this, &Game::processLetterPress);
    }

    for (int i = 0; i < keyButtons.size(); ++i)
    {
        connect(keyButtons[i], &QPushButton::pressed, this, &Game::selectKey);
    }

/**********************************************************************************************/
    prizeButtons.push_back(ui->choosePrizesButton);
    prizeButtons.push_back(ui->prize1);
    prizeButtons.push_back(ui->prize2);
    prizeButtons.push_back(ui->prize3);
    prizeButtons.push_back(ui->prize4);
    prizeButtons.push_back(ui->prize5);
    prizeButtons.push_back(ui->prize6);
    prizeButtons.push_back(ui->prize7);
    prizeButtons.push_back(ui->prize8);

    priceLabels.push_back(ui->pointsLabel);
    priceLabels.push_back(ui->price1);
    priceLabels.push_back(ui->price2);
    priceLabels.push_back(ui->price3);
    priceLabels.push_back(ui->price4);
    priceLabels.push_back(ui->price5);
    priceLabels.push_back(ui->price6);
    priceLabels.push_back(ui->price7);
    priceLabels.push_back(ui->price8);

    ui->prizes->setScene(sceneForPrizes);

    for (int i = 1; i < prizeButtons.size(); ++i)
    {
        connect(prizeButtons[i], &QPushButton::pressed, this, &Game::processClaimedPrize);
    }

    ui->supergameButton->hide();
    ui->rejectPlaySupergameButton->hide();
    for (int i = 0; i < prizeButtons.size(); ++i)
    {
        prizeButtons[i]->hide();
    }
    for (int i = 0; i < priceLabels.size(); ++i)
    {
        priceLabels[i]->hide();
    }
    ui->prizes->hide();
    ui->pointsBrowser->hide();
    ui->openChosenLettersButton->hide();
    ui->giveAnswerButton->hide();
    ui->timeBrowser->hide();
    ui->timeLabel->hide();

    connect(ui->choosePrizesButton, &QPushButton::clicked, this, &Game::choosePrizes);
    connect(ui->supergameButton, &QPushButton::clicked, this, &Game::startSupergame);
    connect(ui->rejectPlaySupergameButton, &QPushButton::clicked, this, &Game::rejectSupergame);
    connect(ui->openChosenLettersButton, &QPushButton::clicked, this, &Game::openChosenLettersInSupergame);
    connect(ui->giveAnswerButton, &QPushButton::clicked, this, &Game::checkAnswerInSupergame);
    connect(timerForSupergame, &QTimer::timeout, this, &Game::changeTimeValue);

    ui->testPrizeButton->hide();
    connect(ui->testPrizeButton, &QPushButton::clicked, this, &Game::showPrizes);
}


Game::~Game()
{
    delete ui;
}


void Game::setUserName(const QString &newUserName)
{
    userName = newUserName;
    ui->nameForPlayerLabel->setText(userName + ":");
}


void Game::setAnswer(const QString &newAnswer)
{
    answer = newAnswer;
    answerLength = answer.size();
    answer.remove(answerLength-1, 1);
    answerLength--;
    hideExtraBrowsers();
    player1 = new Player(answer, level);
    player2 = new Player(answer, level);
    ui->choosingLetterSpinBox->setMinimum(1);
    ui->choosingLetterSpinBox->setMaximum(answerLength);
}


void Game::setQuestion(const QString &newQuestion)
{
    question = newQuestion;
    ui->taskBrowser->setText(question);
}

void Game::onTimeout() // срабатывание таймера
{
    ++microRotations;
    baraban->rotationFunction();
    scene->update();

    if (state == 2)
    {
        timer->stop();
        return;
    }


    if (microRotations == NUMBER_OF_MICROROTATIONS)
    {
        timer->stop();
        scene->update();
        scene->update();
        microRotations = 0;
        music->stop();
        processCurrentSector(baraban->evaluateCurrentSector());
    }
}


void Game::setLevel(int newLevel)
{
    level = newLevel;
}


void Game::stopTime(int sec)
{
    if (state == 2)
    {
        return;
    }

    QTime dieTime= QTime::currentTime().addSecs(sec);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}


void Game::hideExtraBrowsers()
{
    for(int i = answerLength + 1; i <= MAX_NUMBER_OF_LETTERS; ++i)
    {
        letters[i]->hide();
    }
}


void Game::processLetterPress()
{
    if (state == 1 || state == 2)
    {
        return;
    }

    if (state == 3)
    {
        int numberOfChosenLetter = findPressedLetter();

        if (buttons[numberOfChosenLetter]->styleSheet() == PURPLE_COLOUR_MODE)
        {
            letteres->removeLetter();
            buttons[numberOfChosenLetter]->setStyleSheet(DEFAULT_COLOUR_MODE);
        }
        else if (letteres->addLetter())
        {
            buttons[numberOfChosenLetter]->setStyleSheet(PURPLE_COLOUR_MODE);
        }

        if (letteres->getCurrentNumber() == 7)
        {
            ui->openChosenLettersButton->setEnabled(true);
        }
        else
        {
            ui->openChosenLettersButton->setEnabled(false);
        }

        return;
    }

    int numberOfChosenLetter = findPressedLetter();
    deactivateChosenMode(currentChosenLetter);
    currentChosenLetter = russianLetters[numberOfChosenLetter];
    numberOfCurrentChosenLetter = numberOfChosenLetter;
    buttons[numberOfChosenLetter]->setStyleSheet(PURPLE_COLOUR_MODE);
}


void Game::deactivateChosenMode(const QString &letter)
{
    if (letter == "")
    {
        return;
    }

    buttons[numberOfCurrentChosenLetter]->setStyleSheet(DEFAULT_COLOUR_MODE);
}


int Game::findPressedLetter()
{
    for (int i = 1; i < buttons.size(); ++i)
    {
        if (buttons[i]->isDown())
        {
            return i;
        }
    }

    return 0;
}


int Game::findPressedKey()
{
    for (int i = 0; i < keyButtons.size(); ++i)
    {
        if (keyButtons[i]->isDown())
        {
            return i + 1;
        }
    }

    return 0;
}


void Game::playMusic(QString musicNow)
{
    if (state == 2)
    {
        return;
    }

    music->setVolume(MEDIUM_VOLUME);
    music->setMedia(QUrl::fromLocalFile(musicNow));
    music->play();
}


void Game::processMusicChange(QMediaPlayer::State newState)
{
    if (newState == QMediaPlayer::StoppedState && music->media() == QUrl::fromLocalFile(MUSIC_FOR_BEGINING))
    {
        ui->Leonid_Label->setText(TEXT_FOR_BARABAN);
        playMusic(SOUND_FOR_BARABAN);
        ui->answerTheWordButton->setEnabled(true);
        ui->barabanButton->setEnabled(true);
        ui->answerTheWordButton->setStyleSheet(ENABLED_COLOR_MODE);
        ui->barabanButton->setStyleSheet(ENABLED_COLOR_MODE);
    }
    else if (newState == QMediaPlayer::StoppedState && music->media() == QUrl::fromLocalFile(SOUND_FOR_SUPERGAME))
    {
        ui->Leonid_Label->setText("Можете открыть любые 7 букв.\nВыбирайте!");
        stopTime();

        for (int i = 1; i < buttons.size(); ++i)
        {
            buttons[i]->show();
        }

        ui->openChosenLettersButton->show();
        ui->openChosenLettersButton->setEnabled(false);
    }
}


void Game::rotateBaraban()
{
    if (state == 2)
    {
        return;
    }

    state = 1;
    ui->answerTheWordButton->setEnabled(false);
    ui->barabanButton->setEnabled(false);
    ui->answerTheWordButton->setStyleSheet(DISABLED_COLOR_MODE);
    ui->barabanButton->setStyleSheet(DISABLED_COLOR_MODE);
    ui->claimTheLetterButton->setEnabled(false);
    ui->Leonid_Label->setText("");
    playMusic(MUSIC_FOR_BARABAN);
    microRotations = 100 * (4 + rand() % RANGE_OF_NUMBER_OF_ROTATIONS);
    timer->start(FREQUENCY_OF_TIMER);
}


bool Game::isExists(const QString &letter)
{
    QString tempLetter = "";

    for (int i = 0; i < answerLength; ++i)
    {
        tempLetter = "";
        tempLetter.push_back(answer[i]);
        if (tempLetter == letter)
        {
            return true;
        }
    }

    return false;
}


void Game::openingLettersFunction(const QString &letter)
{
    playMusic(SOUND_FOR_RIGHT_LETTER);
    QString tempLetter = "";
    for (int i = 0; i < answerLength; ++i)
    {
        tempLetter = "";
        tempLetter.push_back(answer[i]);

        if (tempLetter == letter)
        {
            openLetter(i+1, letter);
        }
    }

    stopTime();
}


void Game::openLetter(int number, const QString& letter)
{
    letters[number]->setText(letter);
}


void Game::processClaimedLetter()
{   
    if (currentChosenLetter == "")
    {
        return;
    }

    isPlus = false;

    ui->answerTheWordButton->setEnabled(false);
    ui->answerTheWordButton->setStyleSheet(DISABLED_COLOR_MODE);
    ui->claimTheLetterButton->setEnabled(false);

    ui->Leonid_Label->setText("");

    if (isExists(currentChosenLetter))
    {
        state = 1;
        ui->Leonid_Label->setText(OPEN);
        playMusic(OPEN_THE_LETTERS);
        stopTime(2);
        ui->player1Label->setText("");
        ui->player2Label->setText("");
        ui->Leonid_Label->setText("");
        openingLettersFunction(currentChosenLetter);
        buttons[numberOfCurrentChosenLetter]->setStyleSheet(GREEN_COLOUR_MODE);
        player1->removeRightLetter(currentChosenLetter);
        player2->removeRightLetter(currentChosenLetter);
        addPoints();
    }
    else
    {
        state = 1;
        playMusic(NO);
        ui->Leonid_Label->setText("Нет");
        stopTime();
        ui->player1Label->setText("");
        ui->player2Label->setText("");
        ui->Leonid_Label->setText("");
        playMusic(SOUND_FOR_WRONG_LETTER);
        buttons[numberOfCurrentChosenLetter]->setStyleSheet(RED_COLOUR_MODE);
        player1->removeFakeLetter(currentChosenLetter);
        player2->removeFakeLetter(currentChosenLetter);

        if (currentPlayer == PLAYER)
        {
            currentPlayer = COMPUTER_1;
        }
        else if (currentPlayer == COMPUTER_1)
        {
            currentPlayer = COMPUTER_2;
        }
        else
        {
            currentPlayer = PLAYER;
        }
    }

    buttons[numberOfCurrentChosenLetter]->setEnabled(false);

    stopTime(2);
    currentChosenLetter = "";
    numberOfCurrentChosenLetter = 0;

    playAI();
}


void Game::processSelectedKey(int number)
{
    if (state == 2)
    {
        return;
    }

    switch (number) {
    case 1:
        key1->selectKey();
        break;
    case 2:
        key2->selectKey();
        break;
    case 3:
        key3->selectKey();
        break;
    default:
        throw 0;
        break;
    }

    stopTime(2);
    srand(time(0));
    int temp = 1 + rand() % 100;

    if (temp >= 70)
    {
        playMusic(MUSIC_FOR_THE_RIGHT_KEY);
        ui->car->show();
        ui->Leonid_Label->setText("Вы выиграли автомобиль!");
        stopTime(24);
    }
    else
    {
        ui->Leonid_Label->setText("Увы, повезёт в следующий раз.");
        stopTime(2);
    }

    ui->car->hide();
    ui->keys->hide();

    key1->returnDefaultState();
    key2->returnDefaultState();
    key3->returnDefaultState();

    processPointSector();
}


void Game::playAI()
{
    if (state == 2)
    {
        return;
    }

    ui->Leonid_Label->setText("");

    if (currentPlayer == COMPUTER_1)
    {
        if (currentRemovedPlayer == COMPUTER_1)
        {
            currentPlayer = COMPUTER_2;
        }

        state = 1;
        checkIfEnd();
        ui->Leonid_Label->setText(TEXT_FOR_BARABAN);
        playMusic(SOUND_FOR_BARABAN);
        stopTime(2);
        rotateBaraban();
    }
    else if (currentPlayer == COMPUTER_2)
    {
        if (currentRemovedPlayer == COMPUTER_2)
        {
            currentPlayer = PLAYER;
            checkIfEnd();
            ui->Leonid_Label->setText(TEXT_FOR_BARABAN);
            playMusic(SOUND_FOR_BARABAN);
            ui->answerTheWordButton->setEnabled(true);
            ui->barabanButton->setEnabled(true);
            ui->answerTheWordButton->setStyleSheet(ENABLED_COLOR_MODE);
            ui->barabanButton->setStyleSheet(ENABLED_COLOR_MODE);
            ui->claimTheLetterButton->setEnabled(true);
            stopTime(2);
            state = 0;
            return;
        }

        state = 1;
        checkIfEnd();
        ui->Leonid_Label->setText(TEXT_FOR_BARABAN);
        playMusic(SOUND_FOR_BARABAN);
        stopTime(2);
        rotateBaraban();
    }
    else
    {
        checkIfEnd();
        ui->Leonid_Label->setText(TEXT_FOR_BARABAN);
        playMusic(SOUND_FOR_BARABAN);
        ui->answerTheWordButton->setEnabled(true);
        ui->barabanButton->setEnabled(true);
        ui->answerTheWordButton->setStyleSheet(ENABLED_COLOR_MODE);
        ui->barabanButton->setStyleSheet(ENABLED_COLOR_MODE);
        stopTime(2);
        return;
    }
}


void Game::processCurrentSector(int sector)
{
    if (state == 2)
    {
        return;
    }

    switch (sector) {
    case 1:
        processSectorPlus();
        break;
    case 4:
        processSectorBankrot();
        break;
    case 5:
        processSectorKey();
        break;
    case 7:
        processSectorPrize();
        break;
    default:
        processPointSector();
        break;
    }
}


void Game::processSectorPlus()
{
    isSectorPlus = true;
    ui->Leonid_Label->setText(TEXT_FOR_SECTOR_PLUS);
    playMusic(SOUND_FOR_SECTOR_PLUS);
    stopTime(2);

    if (currentPlayer == PLAYER)
    {
        ui->choosingLetterSpinBox->show();
        ui->openChosenLetterButton->show();
    }
    else
    {
        openChosenLetter();
    }
}


void Game::processSectorBankrot()
{
    ui->Leonid_Label->setText(TEXT_FOR_SECTOR_BANKROT);
    playMusic(SOUND_FOR_BANKROT);
    stopTime(3);

    if (currentPlayer == COMPUTER_1)
    {
        player1->setNumberOfPoints(0);
        ui->player1Browser->setText(QString::number(0));
        currentPlayer = COMPUTER_2;
    }
    else if (currentPlayer == COMPUTER_2)
    {
        player2->setNumberOfPoints(0);
        ui->player2Browser->setText(QString::number(0));
        currentPlayer = PLAYER;
    }
    else
    {
        playerPoints = 0;
        ui->playerBrowser->setText(QString::number(0));
        currentPlayer = COMPUTER_1;
    }

    playAI();
}


void Game::processSectorKey()
{
    if (state == 2)
    {
        return;
    }

    playMusic(SOUND_FOR_SECTOR_KEY);
    stopTime(3);
    ui->Leonid_Label->setText(TEXT_FOR_SECTOR_KEY);
    stopTime();
    ui->keys->show();

    if (currentPlayer == PLAYER)
    {
        for (int i = 0; i < keyButtons.size(); ++i)
        {
            keyButtons[i]->show();
        }
    }
    else
    {
        selectKey();
    }
}


void Game::processSectorPrize()
{
    ui->Leonid_Label->setText(TEXT_FOR_SECTOR_PRIZE);
    playMusic(SOUND_FOR_SECTOR_PRIZE);
    stopTime(2);

    if (currentPlayer == PLAYER)
    {
        ui->choosingPrizeButton->show();
        ui->choosingPlayButton->show();
    }
    else
    {
        if (player1->wantToGetPrize())
        {
            (currentPlayer == COMPUTER_1) ? ui->player1Label->setText(WANT_PRIZE) : ui->player2Label->setText(WANT_PRIZE);
            stopTime(2);
            choosePrize();
        }
        else
        {
            (currentPlayer == COMPUTER_1) ? ui->player1Label->setText(WANT_PLAY) : ui->player2Label->setText(WANT_PLAY);
            stopTime(2);
            choosePlay();
        }
    }
}


void Game::processPointSector()
{
    int points = 0;
    checkIfEnd();

    switch (baraban->evaluateCurrentSector()) {
    case 1:
        points = 500;
        break;
    case 2:
        points = 600;
        break;
    case 3:
        points = 1000;
        break;
    case 4:
        points = 0;
        break;
    case 5:
        points = 500;
        break;
    case 6:
        points = 500;
        break;
    case 7:
        points = 1000;
        break;
    case 8:
        points = 800;
        break;
    case 9:
        points = 700;
        break;
    default:
        break;
    }

    if (state == 2)
    {
        return;
    }

    QString temp = QString::number(points);
    QString LeonidPhraze = (temp + " очков. Буква...");
    ui->Leonid_Label->setText(LeonidPhraze);

    if (currentPlayer != PLAYER)
    {
        stopTime();
        currentChosenLetter = player1->claimTheLetter();
        if (currentPlayer == COMPUTER_1)
        {
            ui->player1Label->setText("Буква " + currentChosenLetter);
        }
        else
        {
            ui->player2Label->setText("Буква " + currentChosenLetter);
        }

        for (int i = 1; i <= russianLetters.size(); ++i)
        {
            if (russianLetters[i] == currentChosenLetter)
            {
                numberOfCurrentChosenLetter = i;
                break;
            }
        }

        stopTime();
        processClaimedLetter();
    }
    else
    {
        ui->claimTheLetterButton->setEnabled(true);
        state = 0;
        return;
    }
}


void Game::addPoints()
{
    int points = 0;

    switch (baraban->evaluateCurrentSector()) {
    case 1:
        points = 500;
        break;
    case 2:
        points = 600;
        break;
    case 3:
        points = 1000;
        break;
    case 4:
        points = 1000;
        break;
    case 5:
        points = 900;
        break;
    case 6:
        points = 500;
        break;
    case 7:
        points = 1000;
        break;
    case 8:
        points = 800;
        break;
    case 9:
        points = 700;
        break;
    default:
        break;
    }

    if (currentPlayer == COMPUTER_1)
    {
        player1->addPointsToComputer(points);
        ui->player1Browser->setText(QString::number(player1->getNumberOfPoints()));
    }
    else if (currentPlayer == COMPUTER_2)
    {
        player2->addPointsToComputer(points);
        ui->player2Browser->setText(QString::number(player2->getNumberOfPoints()));
    }
    else
    {
        playerPoints += points;
        ui->playerBrowser->setText(QString::number(playerPoints));
    }
}


void Game::selectKey()
{
    if (state == 2)
    {
        return;
    }

    int numberOfKey = 0;

    if (currentPlayer == PLAYER)
    {
        numberOfKey = findPressedKey();

        for (int i = 0; i < keyButtons.size(); ++i)
        {
            keyButtons[i]->hide();
        }
    }
    else
    {
        numberOfKey = player1->chooseKey();
        (currentPlayer == COMPUTER_1 ? ui->player1Label->setText("Ключ номер " + QString::number(numberOfKey)) : ui->player2Label->setText("Ключ номер " + QString::number(numberOfKey)));
        stopTime(2);
    }

    processSelectedKey(numberOfKey);
}


void Game::openChosenLetter()
{
    int number = 0;

    if (currentPlayer == PLAYER)
    {
        int temp = ui->choosingLetterSpinBox->value();
        QString potentialLetter = "";
        potentialLetter.push_back(answer[temp - 1]);

        if (player1->isExistsInRightLetters(potentialLetter))
        {
            number = ui->choosingLetterSpinBox->value();
            currentChosenLetter = answer[number-1];
        }
        else
        {
            QMessageBox::information(this, "ОШИБКА", "Эта буква уже открыта.");
            return;
        }
    }
    else
    {
        currentChosenLetter = player1->claimTheRightLetter();
    }

    for (int i = 1; i <= russianLetters.size(); ++i)
    {
        if (russianLetters[i] == currentChosenLetter)
        {
            numberOfCurrentChosenLetter = i;
            break;
        }
    }

    ui->choosingLetterSpinBox->hide();
    ui->openChosenLetterButton->hide();

    openingLettersFunction(currentChosenLetter);
    buttons[numberOfCurrentChosenLetter]->setStyleSheet(GREEN_COLOUR_MODE);
    player1->removeRightLetter(currentChosenLetter);
    player2->removeRightLetter(currentChosenLetter);
    buttons[numberOfCurrentChosenLetter]->setEnabled(false);
    addPoints();
    stopTime(2);

    if (currentPlayer == PLAYER)
    {
        ui->answerTheWordButton->setEnabled(true);
        ui->answerTheWordButton->setStyleSheet(ENABLED_COLOR_MODE);
    }

    currentChosenLetter = "";
    numberOfCurrentChosenLetter = 0;
    processPointSector();
}


void Game::choosePlay()
{
    ui->choosingPrizeButton->hide();
    ui->choosingPlayButton->hide();
    stopTime();
    processPointSector();
}


void Game::choosePrize()
{
    ui->choosingPrizeButton->hide();
    ui->choosingPlayButton->hide();
    traidingWithPrize();
}


void Game::traidingWithPrize()
{
    ++prizeCounter;

    QString quantityOfMoney = "";

    switch (prizeCounter) {
    case 1:
        quantityOfMoney = "10000";
        break;
    case 2:
        quantityOfMoney = "20000";
        break;
    case 3:
        quantityOfMoney = "30000";
        break;
    default:
        prizeCounter = 0;
        ui->Leonid_Label->setText("Поздравляю! Вы выиграли приз!");
        stopTime(2);
        removeThePlayer();
        return;
        break;
    }

    ui->Leonid_Label->setText("Я могу вам предложить " + quantityOfMoney + " - \nи вы отказываетесь от приза");
    stopTime(2);

    if (currentPlayer == PLAYER)
    {
        ui->prizeButton->show();
        ui->moneyButton->show();
    }
    else
    {
        if (player1->wantToGetPrize())
        {
            (currentPlayer == COMPUTER_1) ? ui->player1Label->setText(PRIZE) : ui->player2Label->setText(PRIZE);
            stopTime(2);
            traidingWithPrize();
        }
        else
        {
            (currentPlayer == COMPUTER_1) ? ui->player1Label->setText(WANT_MONEY) : ui->player2Label->setText(WANT_MONEY);
            stopTime(2);
            prizeCounter = 0;
            ui->Leonid_Label->setText("Поздравляю! Вы получаете ваши \n" + quantityOfMoney + " рублей!");
            stopTime(2);
            removeThePlayer();
        }
    }
}


void Game::removeThePlayer()/****************************************************************************************/
{
    ui->Leonid_Label->setText("");
    prizeCounter = 0;

    if (currentPlayer == COMPUTER_1)
    {
        ui->nameForPlayer1Label->hide();
        ui->player1Label->hide();
        ui->player1Browser->hide();

        if (currentRemovedPlayer == COMPUTER_2)
        {
            QMessageBox::information(this, GAME_OVER, "Поздравляем! Вы выиграли.");
            showPrizes();
            return;
        }

        currentRemovedPlayer = COMPUTER_1;
        playAI();
    }
    else if (currentPlayer == COMPUTER_2)
    {
        ui->nameForPlayer2Label->hide();
        ui->player2Label->hide();
        ui->player2Browser->hide();

        if (currentRemovedPlayer == COMPUTER_1)
        {
            QMessageBox::information(this, GAME_OVER, "Поздравляем! Вы выиграли.");
            showPrizes();
            return;
        }

        currentRemovedPlayer = COMPUTER_2;
        playAI();
    }
    else
    {
        QMessageBox::information(this, GAME_OVER, "Поздравляем! Вы выиграли приз.");
        int numberofPrize = 0;
        srand(time(nullptr));
        numberofPrize = 1 + (rand() % 7);

        ui->prizes->show();
        prizeImage = new PrizeImage(numberofPrize);
        prizeImage->setPos(200, 200);
        sceneForPrizes->addItem(prizeImage);
        stopTime(2);

        giveUPandShowMenu();
    }
}


void Game::getMoney()/**************************************************************************************************///деньги
{
    prizeCounter = 0;
    QMessageBox::information(this, GAME_OVER, "Поздравляем! Вы выиграли деньги.");

    ui->prizes->show();
    prizeImage = new PrizeImage(0);
    prizeImage->setPos(200, 200);
    sceneForPrizes->addItem(prizeImage);
    stopTime(2);

    giveUPandShowMenu();
}


void Game::answerTheWord()
{
    if (ui->claimTheLetterButton->isEnabled())
    {
        isPlus = true;
    }

    ui->barabanButton->setEnabled(false);
    ui->barabanButton->setStyleSheet(DISABLED_COLOR_MODE);
    ui->claimTheLetterButton->setEnabled(false);
    ui->claimTheWordEdit->show();
    ui->claimTheWordButton->show();
    ui->rejectAnswerTheWordButton->show();
}


void Game::claimTheWord()/***************************************************************************************/
{
    QString potentialAnswer = "";
    potentialAnswer = ui->claimTheWordEdit->text();
    potentialAnswer = potentialAnswer.toUpper();

    if (potentialAnswer == answer)
    {
        QMessageBox::information(this, "ПОБЕДА", "Поздравлем, вы выиграли!");
        showPrizes();
    }
    else
    {
        QMessageBox::information(this, "ПОРАЖЕНИЕ", "Увы, к сожалению, вы проирграли.");
        giveUPandShowMenu();
    }
}


void Game::rejectAnswerTheWord()
{
    if (isSectorPlus && isPlus)
    {
        ui->barabanButton->setEnabled(false);
        ui->barabanButton->setStyleSheet(DISABLED_COLOR_MODE);
        ui->claimTheLetterButton->setEnabled(true);
    }
    else
    {
        ui->barabanButton->setEnabled(true);
        ui->barabanButton->setStyleSheet(ENABLED_COLOR_MODE);
    }


    ui->claimTheWordEdit->hide();
    ui->claimTheWordEdit->setText("");
    ui->claimTheWordButton->hide();
    ui->rejectAnswerTheWordButton->hide();
}


void Game::giveUPandShowMenu()////////////////////////////////////////////////////////////////////////////////////
{
    state = 2;
    ui->giveupButton->hide();
    ui->barabanButton->hide();
    ui->answerTheWordButton->hide();
    ui->claimTheLetterButton->hide();
    ui->claimTheLetterButton->hide();
    ui->claimTheWordEdit->hide();
    ui->claimTheWordButton->hide();
    ui->rejectAnswerTheWordButton->hide();
    music->stop();
    emit giveup();
}


void Game::checkIfEnd()/**************************************************************************************/
{
    if (player1->getNumberOfCurrentRightLetters() == 0)
    {
        if (currentPlayer == COMPUTER_1)
        {
            QMessageBox::information(this, GAME_OVER, "Компьютер 1 выиграл.");
            giveUPandShowMenu();
        }
        else if (currentPlayer == COMPUTER_2)
        {
            QMessageBox::information(this, GAME_OVER, "Компьютер 2 выиграл.");
            giveUPandShowMenu();
        }
        else
        {
            QMessageBox::information(this, "ПОБЕДА", "Поздравлем, вы выиграли!");
            showPrizes();
        }
    }
}


void Game::showPrizes()
{
    // показываем ответ
    QString letter = "";
    QString temp = "";

    for (int i = 0; i < answer.size(); ++i)
    {
        letter = "";
        letter.push_back(answer[i]);

        for (int j = 1; j < russianLetters.size(); ++j)
        {
            temp = "";
            temp.push_back(russianLetters[j]);
            if (temp == letter)
            {
                openLetter(i+1, letter);
            }
        }
    }

    playMusic(SOUND_FOR_PRIZES);
    stopTime(3);

    // всё прячем
    ui->baraban->hide();
    ui->barabanButton->hide();
    ui->answerTheWordButton->hide();
    ui->claimTheLetterButton->hide();
    ui->nameForPlayer1Label->hide();
    ui->nameForPlayer2Label->hide();
    ui->nameForPlayerLabel->hide();
    ui->player1Label->hide();
    ui->player2Label->hide();
    ui->playerLabel->hide();
    ui->player1Browser->hide();
    ui->player2Browser->hide();
    ui->playerBrowser->hide();
    ui->claimTheWordButton->hide();
    ui->claimTheWordEdit->hide();
    ui->rejectAnswerTheWordButton->hide();

    for (int i = 1; i <= 33; ++i)
    {
        buttons[i]->hide();
    }
    // всё показываем

    for (int i = 0; i < prizeButtons.size(); ++i)
    {
        prizeButtons[i]->show();
    }
    for (int i = 0; i < priceLabels.size(); ++i)
    {
        priceLabels[i]->show();
    }
    ui->pointsBrowser->show();

    prize->setPoints(playerPoints);
    ui->pointsBrowser->setText(QString::number(playerPoints));
}


void Game::processClaimedPrize()
{
    int currentClaimedPrize = findClaimedPrize();
    QString nameOfClaimedPrize = "";

    switch (currentClaimedPrize) {
    case 1:
        nameOfClaimedPrize = "Кофемолка";
        break;
    case 2:
        nameOfClaimedPrize = "Утюг";
        break;
    case 3:
        nameOfClaimedPrize = "Мультиварка";
        break;
    case 4:
        nameOfClaimedPrize = "Микроволновая печь";
        break;
    case 5:
        nameOfClaimedPrize = "Телевизор";
        break;
    case 6:
        nameOfClaimedPrize = "Стиральная машина";
        break;
    case 7:
        nameOfClaimedPrize = "Компьютер";
        break;
    case 8:
        nameOfClaimedPrize = "Автомобиль";
        break;
    default:
        break;
    }

    if (prizeButtons[currentClaimedPrize]->styleSheet() == GREEN_COLOUR_MODE)
    {
        prizeButtons[currentClaimedPrize]->setStyleSheet(DEFAULT_COLOUR_MODE);
        prize->removePrize(nameOfClaimedPrize);
        playerPoints = prize->getPoints();
        ui->pointsBrowser->setText(QString::number(playerPoints));
    }
    else if (prizeButtons[currentClaimedPrize]->styleSheet() == DEFAULT_COLOUR_MODE && prize->addPrize(nameOfClaimedPrize))
    {
        prizeButtons[currentClaimedPrize]->setStyleSheet(GREEN_COLOUR_MODE);
        playerPoints = prize->getPoints();
        ui->pointsBrowser->setText(QString::number(playerPoints));
    }
}


int Game::findClaimedPrize()
{
    for (int i = 1; i < prizeButtons.size(); ++i)
    {
        if (prizeButtons[i]->isDown())
        {
            return i;
        }
    }

    return 0;
}


void Game::choosePrizes()
{
    for (int i = 1; i < prizeButtons.size(); ++i)
    {
        prizeButtons[i]->setEnabled(false);
    }

    ui->Leonid_Label->setText("Желаете сыграть в СУПЕРИГРУ\nи выиграть суперприз?");
    ui->supergameButton->show();
    ui->rejectPlaySupergameButton->show();
}


void Game::startSupergame()
{
    state = 3;
    // прячем всё лишнее
    ui->supergameButton->hide();
    ui->rejectPlaySupergameButton->hide();
    for (int i = 0; i < prizeButtons.size(); ++i)
    {
        prizeButtons[i]->hide();
    }
    for (int i = 0; i < priceLabels.size(); ++i)
    {
        priceLabels[i]->hide();
    }
    ui->pointsBrowser->hide();
    ui->pointsLabel->hide();

    ui->Leonid_Label->setText("СУПЕР ИГРА!!!");
    playMusic(SOUND_FOR_SUPERGAME);

    // подчищаем клавиатуру с буквами
    for (int i = 1; i < buttons.size(); ++i)
    {
        buttons[i]->setStyleSheet(DEFAULT_COLOUR_MODE);
        buttons[i]->setEnabled(true);
    }

    // генерируем задание
    int index = 0;
    QString questionForSupergame = "", answerForSupergame = "";

    srand(time(nullptr));

    do
    {
        index = 1 + rand() % NUMBER_OF_TASKS;
        questionForSupergame = readSupergameTaskFromFile(index).first;
        answerForSupergame = readSupergameTaskFromFile(index).second;
    }
    while(answerForSupergame == answer);

    question = questionForSupergame;
    answer = answerForSupergame;
    answerLength = answer.size();

    ui->taskBrowser->setText(question);
    hideExtraBrowsers();

    // подчищаем ответ с предыдущего раунда
    for (int i = 1; i <= MAX_NUMBER_OF_LETTERS; ++i)
    {
        letters[i]->setText("");
        letters[i]->show();
    }

    hideExtraBrowsers();
}


void Game::rejectSupergame()
{
    ui->supergameButton->hide();
    ui->rejectPlaySupergameButton->hide();
    for (int i = 0; i < prizeButtons.size(); ++i)
    {
        prizeButtons[i]->hide();
    }
    for (int i = 0; i < priceLabels.size(); ++i)
    {
        priceLabels[i]->hide();
    }
    ui->pointsBrowser->hide();
    ui->pointsLabel->hide();

    showAllPrizes(false);
}


void Game::showAllPrizes(bool isSuperprize)
{
    ui->prizes->show();

    QVector<int> chosenPrizes;

    if (playerPoints != 0)
    {
        chosenPrizes.push_back(0);
    }

    for (int i = 1; i < prizeButtons.size(); ++i)
    {
        if (prizeButtons[i]->styleSheet() == GREEN_COLOUR_MODE)
        {
            chosenPrizes.push_back(i);
        }
    }

    int x = 50, y = 200;

    for (int i = 0; i < chosenPrizes.size(); ++i, x += 120)
    {
        prizeImage = new PrizeImage(chosenPrizes[i]);
        prizeImage->setPos(x, y);
        sceneForPrizes->addItem(prizeImage);
    }

    if (isSuperprize)
    {
        prizeImage = new PrizeImage(9);
        prizeImage->setPos(x, y);
        sceneForPrizes->addItem(prizeImage);
    }
}


QPair<QString, QString> Game::readSupergameTaskFromFile(int index)
{
    QString questionForSupeergame = "", answerForSupergame = "";
    QFile file(FILE_WITH_TASKS);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) qDebug() << SUCCESSFUL_FILE_OPENING;
    else qDebug() << ERROR_FILE_OPENING;

    int counter = 1;
    while(true)
    {
        if (counter == 2 * index - 1)
        {
            questionForSupeergame = file.readLine();
            answerForSupergame = file.readLine();
            break;
        }

        file.readLine();
        file.readLine();
        counter += 2;
    }

    file.close();

    answerForSupergame.remove(answerForSupergame.size()-1, 1);
    return QPair<QString, QString> (questionForSupeergame, answerForSupergame);
}


void Game::openChosenLettersInSupergame()
{
    state = 1; // блокируем кнопки с буквами
    ui->openChosenLettersButton->hide();

    int isOk = 0;

    for (int i = 1; i < buttons.size(); ++i)
    {
        if (buttons[i]->styleSheet() == PURPLE_COLOUR_MODE)
        {
            if (processLetterInSupergame(i))
            {
                ++isOk;
            }
        }
    }

    if (isOk > 0)
    {
        playMusic(SOUND_FOR_RIGHT_LETTER);
    }
    else
    {
        playMusic(SOUND_FOR_WRONG_LETTER);
    }

    ui->Leonid_Label->setText("У Вас ровно минута, чтобы дать ответ.\nУдачи!!!");
    ui->timeBrowser->setText("01:00");
    ui->timeLabel->show();
    ui->timeBrowser->show();
    stopTime(2);

    ui->claimTheWordEdit->setText("");
    ui->claimTheWordEdit->show();
    ui->giveAnswerButton->show();
    playMusic(MUSIC_FOR_SUPERGAME);
    timerForSupergame->start(1000);
}


bool Game::processLetterInSupergame(int numberOfLetter)
{
    QString letter = "";
    bool isOk = false;

    letter.push_back(russianLetters[numberOfLetter]);

    for (int i = 0; i < answer.size(); ++i)
    {
        if (answer[i] == letter)
        {
            openLetter(i+1, letter);
            buttons[numberOfLetter]->setStyleSheet(GREEN_COLOUR_MODE);
            isOk = true;
        }
    }

    if (isOk)
    {
        return true;
    }
    else
    {
        buttons[numberOfLetter]->setStyleSheet(RED_COLOUR_MODE);
        return false;
    }

}


void Game::checkAnswerInSupergame()
{
    music->stop();
    timerForSupergame->stop();
    ui->giveAnswerButton->hide();
    ui->timeLabel->hide();
    ui->timeBrowser->hide();

    QString potentialAnswer = ui->claimTheWordEdit->text();
    potentialAnswer = potentialAnswer.toUpper();

    qDebug() << potentialAnswer << " " << answer;

    if (potentialAnswer == answer)
    {
        playMusic(SOUND_FOR_RIGHT_WORD);
        ui->Leonid_Label->setText("Конечно!\nВы выиграли ДЕЛЬТАПЛАН!!!");
        stopTime(3);
        showAllPrizes(true);
    }
    else
    {
        playMusic(SOUND_FOR_WRONG_WORD);
        ui->Leonid_Label->setText("Увы, это неверно.\nВы теряете выигранные деньги.");
        playerPoints = 0;
        stopTime(3);
        showAllPrizes(false);
    }
}


void Game::changeTimeValue()
{
    --currentTime;
    QString seconds = QString::number(currentTime);

    if (seconds.size() == 1)
    {
        seconds = "0" + seconds;
        ui->timeBrowser->setStyleSheet("color: rgb(200, 0, 0)");
    }

    ui->timeBrowser->setText("00:" + seconds);

    if (currentTime == -1)
    {
        timerForSupergame->stop();
        ui->giveAnswerButton->hide();
        checkAnswerInSupergame();
    }
}

























