// mainwindow.cpp
#include <QPixmap>
#include <QMovie>
#include <QPalette>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QEasingCurve>
#include "mainwindow.h"
#include "hoverbutton.h"
#include "ui_mainwindow.h"
#include <memory> // для std::unique_ptr

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , rng(std::max({wealth, power, intelligence, decency}), dialogStep)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0); // Загрузочный экран

    this->setFixedSize(1280, 760);
    QCursor::setPos(640, 360);

    // Создаем кнопки как дочерние виджеты
    acceptButton = new HoverButton(ui->page_2);
    declineButton = new HoverButton(ui->page_2);
    characterButton = new QPushButton(ui->page_2);
    restartButton = new HoverButton(ui->page_3);
    exitButton = new HoverButton(ui->page_3);
    graphButton = new HoverButton(ui->page_3);

    // Устанавливаем кнопкам прозрачный фон
    QString transparentStyle = "background-color: rgba(255, 255, 255, 0);";
    acceptButton->setStyleSheet(transparentStyle);
    declineButton->setStyleSheet(transparentStyle);
    characterButton->setStyleSheet(transparentStyle);
    restartButton->setStyleSheet(transparentStyle);
    exitButton->setStyleSheet(transparentStyle);
    graphButton->setStyleSheet(transparentStyle);

    // Устанавливаем расположение и размер кнопок
    acceptButton->setGeometry(QRect(850,0,430,720));
    declineButton->setGeometry(QRect(0,0,430,720));
    characterButton->setGeometry(QRect(430,0,420,720));
    restartButton->setGeometry(QRect(0,503,1280,50));
    exitButton->setGeometry(QRect(0,553,1280,50));
    graphButton->setGeometry(QRect(46,620,80,80));

    // Создаею StatsBars с page_2 в качестве родителя
    statsBars = new StatsBars(ui->page_2);
    statsBars->setGeometry(490, 95, 300, 90);

    // Создаю StatsGraph с page_3 в качестве родителя
    statsGraph = new StatsGraph(ui->page_3);
    statsGraph->setGeometry(230, 60, 820, 400);

    // Создаю VerticalBars с page_2 в качестве родителя
    greenBar = new ClickerGame(ui->page_4);
    greenBar->setGeometry(100, 150, 90, 420);
    redBar = new ClickerGame(ui->page_4);
    redBar->setGeometry(1090, 150, 90, 420);

    // Заполняю шкалы сразу при запуске
    greenBar->updateVerticalBars(100, 0);
    redBar->updateVerticalBars(0, 100);

    // Создаю SkillCheckBar с page_5 в качестве родителя
    skillCheckBar = new SkillCheck(ui->page_5);
    skillCheckBar->setGeometry(100, 150, 90, 420);
    skillCheckBar->updateVerticalBar(100);

    // Создаю QTimer и подключаю его к слоту updateRedBar
    greenBarTimer = new QTimer(this);
    connect(greenBarTimer, &QTimer::timeout, this, &MainWindow::updateGreenBar);

    // Инициализация таймера
    skillCheckTimer = new QTimer(this);
    connect(skillCheckTimer, &QTimer::timeout, this, &MainWindow::updateSkillCheckBar);
    skillCheckGameStarted = false;

    // Связываем сигналы и слоты
    connect(acceptButton, &QPushButton::clicked, this, &MainWindow::on_acceptButton_clicked);
    connect(declineButton, &QPushButton::clicked, this, &MainWindow::on_declineButton_clicked);
    connect(characterButton, &QPushButton::clicked, this, &MainWindow::on_characterButton_clicked);
    connect(restartButton, &QPushButton::clicked, this, &MainWindow::on_restartButton_clicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::on_exitButton_clicked);
    connect(acceptButton, &HoverButton::hovered, this, &MainWindow::on_acceptButton_hovered);
    connect(declineButton, &HoverButton::hovered, this, &MainWindow::on_declineButton_hovered);
    connect(restartButton, &HoverButton::hovered, this, &MainWindow::on_restartButton_hovered);
    connect(exitButton, &HoverButton::hovered, this, &MainWindow::on_exitButton_hovered);
    connect(acceptButton, &HoverButton::unhovered, this, &MainWindow::on_optionButtons_unhovered);
    connect(declineButton, &HoverButton::unhovered, this, &MainWindow::on_optionButtons_unhovered);
    connect(exitButton, &HoverButton::unhovered, this, &MainWindow::on_endGameButtons_unhovered);
    connect(restartButton, &HoverButton::unhovered, this, &MainWindow::on_endGameButtons_unhovered);
    connect(ui->startGameButton, &QPushButton::clicked, this, &MainWindow::on_startGameButton_clicked);
    connect(graphButton, &HoverButton::hovered, this, &MainWindow::on_graphButton_hovered);
    connect(graphButton, &HoverButton::unhovered, this, &MainWindow::on_graphButton_unhovered);

    QPixmap stat_1 ("D:/COURSE WORK/pictures/wealth.png");
    ui->stat_1->setPixmap(stat_1);

    QPixmap stat_2 ("D:/COURSE WORK/pictures/power.png");
    ui->stat_2->setPixmap(stat_2);

    QPixmap stat_3 ("D:/COURSE WORK/pictures/intelligence.png");
    ui->stat_3->setPixmap(stat_3);

    QPixmap stat_4 ("D:/COURSE WORK/pictures/decency.png");
    ui->stat_4->setPixmap(stat_4);

    QPixmap statsGraph_background ("D:/COURSE WORK/pictures/graphic.png");
    ui->statsGraph_background->setPixmap(statsGraph_background);

    QPixmap show_graph ("D:/COURSE WORK/pictures/graph_negate.png");
    ui->show_graph->setPixmap(show_graph);

    QPixmap dazzle_icon ("D:/COURSE WORK/pictures/dazzle_icon.png");
    ui->dazzle_icon->setPixmap(dazzle_icon);

    QPixmap earthshaker_icon ("D:/COURSE WORK/pictures/earthshaker_icon.png");
    ui->earthshaker_icon->setPixmap(earthshaker_icon);

    QPixmap axe_icon("D:/COURSE WORK/pictures/axe_icon.png");
    ui->axe_icon->setPixmap(axe_icon);

    QPixmap earthshaker_icon_2 ("D:/COURSE WORK/pictures/earthshaker_icon.png");
    ui->earthshaker_icon_2->setPixmap(earthshaker_icon_2);

    QPixmap sf_icon ("D:/COURSE WORK/pictures/sf_icon.png");
    ui->sf_icon->setPixmap(sf_icon);

    QPixmap sven_icon ("D:/COURSE WORK/pictures/sven_icon.png");
    ui->sven_icon->setPixmap(sven_icon);

    QPixmap bounty_hunter ("D:/COURSE WORK/pictures/bounty_hunter_icon.png");
    ui->bounty_hunter->setPixmap(bounty_hunter);

    QPixmap card_background("D:/COURSE WORK/pictures/card_background_2.png");
    ui->card_background->setPixmap(card_background);

    QPixmap decline_label("D:/COURSE WORK/pictures/red_transparent.png");
    ui->decline_label->setPixmap(decline_label);

    QPixmap accept_label("D:/COURSE WORK/pictures/green_transparent.png");
    ui->accept_label->setPixmap(accept_label);

    QPixmap skillcheckArea("D:/COURSE WORK/pictures/red_transparent.png");
    ui->skillcheckArea->setPixmap(skillcheckArea);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::stopAllMovies() {
    if (characterMovie && characterMovie->state() == QMovie::Running) {
        characterMovie->stop();
    }
    if (menu_background && menu_background->state() == QMovie::Running) {
        menu_background->stop();
    }
    if (game_background && game_background->state() == QMovie::Running) {
        game_background->stop();
    }
    if (end_backgorund && end_backgorund->state() == QMovie::Running) {
        end_backgorund->stop();
    }
    if (endgame_background && endgame_background->state() == QMovie::Running) {
        endgame_background->stop();
    }
    if (skillcheck_background && skillcheck_background->state() == QMovie::Running) {
        skillcheck_background->stop();
    }
    if (endgame_label && endgame_label->state() == QMovie::Running) {
        endgame_label->stop();
    }
    if (skillcheck_label && skillcheck_label->state() == QMovie::Running) {
        skillcheck_label->stop();
    }
    if (skillcheck_text && skillcheck_text->state() == QMovie::Running) {
        skillcheck_text->stop();
    }
    if (restart_label && restart_label->state() == QMovie::Running) {
        restart_label->stop();
    }
    if (exit_label && exit_label->state() == QMovie::Running) {
        exit_label->stop();
    }
    if (clicker_label && clicker_label->state() == QMovie::Running) {
        clicker_label->stop();
    }
    if (shaker_fight_background && shaker_fight_background->state() == QMovie::Running) {
        shaker_fight_background->stop();
    }
    if (shaker_fight_label && shaker_fight_label->state() == QMovie::Running) {
        shaker_fight_label->stop();
    }
}

void MainWindow::on_stackedWidget_currentChanged(int arg1)
{
    stopAllMovies();

    switch(arg1) {
    case 0: // Загрузочный экран
        if (!menu_background) {
            menu_background = std::make_unique<QMovie>("D:/COURSE WORK/pictures/dota2_reigns_loading_screen.gif");
            ui->menu_background->setMovie(menu_background.get());
        }
        menu_background->start();
        break;
    case 1: // Кликер
        if (!clicker_label) {
            clicker_label = std::make_unique<QMovie>("D:/COURSE WORK/pictures/clicker_label.gif");
            ui->clicker_label->setMovie(clicker_label.get());
        }
        clicker_label->start();

        if (!shaker_fight_background) {
            shaker_fight_background = std::make_unique<QMovie>("D:/COURSE WORK/pictures/dota_landscape.gif");
            ui->shaker_fight_background->setMovie(shaker_fight_background.get());
        }
        shaker_fight_background->start();

        if (!shaker_fight_label) {
            shaker_fight_label = std::make_unique<QMovie>("D:/COURSE WORK/pictures/earthshaker_fight.gif");
            ui->shaker_fight_label->setMovie(shaker_fight_label.get());
        }
        shaker_fight_label->start();
        break;
    case 2: // Скиллчек
        if (!skillcheck_label) {
            skillcheck_label = std::make_unique<QMovie>("D:/COURSE WORK/pictures/axe_fight.gif");
            ui->skillcheck_label->setMovie(skillcheck_label.get());
        }
        skillcheck_label->start();

        if (!skillcheck_text) {
            skillcheck_text = std::make_unique<QMovie>("D:/COURSE WORK/pictures/skillcheck_text.gif");
            ui->skillcheck_text->setMovie(skillcheck_text.get());
        }
        skillcheck_text->start();

        if (!skillcheck_background) {
            skillcheck_background = std::make_unique<QMovie>("D:/COURSE WORK/pictures/dota_landscape.gif");
            ui->skillcheck_background->setMovie(skillcheck_background.get());
        }
        skillcheck_background->start();
        break;
    case 3: // Концовка
        if (!endgame_label) {
            endgame_label = std::make_unique<QMovie>("D:/COURSE WORK/pictures/npc_dota_hero_gg.gif");
            ui->endgame_label->setMovie(endgame_label.get());
        }
        endgame_label->start();

        if (!endgame_background) {
            endgame_background = std::make_unique<QMovie>("D:/COURSE WORK/pictures/dota_landscape.gif");
            ui->endgame_background->setMovie(endgame_background.get());
        }
        endgame_background->start();
        break;
    case 4: // Игровая сцена
        if (!game_background) {
            game_background = std::make_unique<QMovie>("D:/COURSE WORK/pictures/dota_landscape.gif");
            ui->game_background->setMovie(game_background.get());
        }
        game_background->start();

        if (!characterMovie) {
            characterMovie = std::make_unique<QMovie>("D:/COURSE WORK/pictures/npc_dota_hero_wisp.gif");
            ui->character->setMovie(characterMovie.get());
        }
        characterMovie->start();
        break;
    case 5: // Конечный экран
        ui->statsGraph_background->setVisible(false);
        statsGraph->setVisible(false);
        if (!end_backgorund) {
            end_backgorund = std::make_unique<QMovie>("D:/COURSE WORK/pictures/dota_2_end_screen.gif");
            ui->end_backgorund->setMovie(end_backgorund.get());
        }
        end_backgorund->start();

        if (!restart_label) {
            restart_label = std::make_unique<QMovie>("D:/COURSE WORK/pictures/dota_2_end_screen_restart_button_v2.gif");
            ui->restart_label->setMovie(restart_label.get());
        }
        restart_label->start();

        if (!exit_label) {
            exit_label = std::make_unique<QMovie>("D:/COURSE WORK/pictures/dota_2_end_screen_exit_button_v2.gif");
            ui->exit_label->setMovie(exit_label.get());
        }
        exit_label->start();
        break;
    default:
        break;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (ui->stackedWidget->currentIndex() == 0) {
        on_startGameButton_clicked();
    }
    QMainWindow::keyPressEvent(event);
}

void MainWindow::on_startGameButton_clicked()
{
    QCursor::setPos(640, 360);
    ui->stackedWidget->setCurrentIndex(4); // Переключиться на игровую сцену
}

void MainWindow::on_exitButton_clicked()
{
    statsGraph->clearStatsHistory(); // Очищаю историю статистик
    this->close();
}

void MainWindow::on_restartButton_clicked()
{
    statsGraph->clearStatsHistory(); // Очищаю историю статистик
    QCursor::setPos(640, 360);
    resetGame();
}

void MainWindow::resetGame() {
    // Сбросить все параметры к их начальным значениям
    actionapproved = true;
    isquestion = true;
    wealth = 50;
    power = 50;
    intelligence = 50;
    decency = 50;
    dialogStep = 1; // Начальный шаг сюжета
    game_plot();
    // Обновляю статистику и интерфейс
    updateStats();
    ui->stackedWidget->setCurrentIndex(0); // переключиться на начальную сцену
}

void MainWindow::on_graphButton_hovered() {
    statsGraph->setVisible(true);
    ui->statsGraph_background->setVisible(true);
}

void MainWindow::on_graphButton_unhovered() {
    statsGraph->setVisible(false);
    ui->statsGraph_background->setVisible(false);
}

void MainWindow::on_exitButton_hovered()
{
    ui->exit_label->move(0, ui->exit_label->y());
}

void MainWindow::on_restartButton_hovered()
{
    ui->restart_label->move(0, ui->restart_label->y());
}

void MainWindow::on_endGameButtons_unhovered()
{
    ui->exit_label->move(-1280, ui->exit_label->y());
    ui->restart_label->move(-1280, ui->exit_label->y());
}

void MainWindow::on_acceptButton_hovered()
{
    // Создаю анимацию для перемещения character вправо
    QPropertyAnimation *animation = new QPropertyAnimation(ui->character, "geometry");
    animation->setDuration(700); // Продолжительность анимации в миллисекундах
    animation->setStartValue(ui->character->geometry());
    animation->setEndValue(QRect(630, ui->character->y(), ui->character->width(), ui->character->height()));
    animation->setEasingCurve(QEasingCurve::OutCubic); // Тип анимации, имитирующий свайп
    animation->start(QAbstractAnimation::DeleteWhenStopped); // Начать анимацию и удалить объект после завершения

    // Создаю анимацию затухания для accept_label
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect();
    ui->accept_label->setGraphicsEffect(opacityEffect);
    QPropertyAnimation *blinkAnimation = new QPropertyAnimation(opacityEffect, "opacity");
    blinkAnimation->setDuration(500);
    blinkAnimation->setStartValue(0);
    blinkAnimation->setEndValue(1);
    blinkAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    if(isquestion==true){
        // Создаю анимацию для перемещения accept_label с 1280 до 850
        QPropertyAnimation *acceptAnimation = new QPropertyAnimation(ui->accept_label, "geometry");
        acceptAnimation->setDuration(700);
        acceptAnimation->setStartValue(ui->accept_label->geometry());
        acceptAnimation->setEndValue(QRect(960, ui->accept_label->y(), ui->accept_label->width(), ui->accept_label->height()));
        acceptAnimation->setEasingCurve(QEasingCurve::OutCubic);
        acceptAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    }

   if(rhetorical==true){
        ui->accept_label->setGraphicsEffect(opacityEffect);
        QPropertyAnimation *animationBlink = new QPropertyAnimation(opacityEffect, "opacity");
        animationBlink->setDuration(1000); // Продолжительность анимации
        animationBlink->setStartValue(1);
        animationBlink->setKeyValueAt(0.1, 0);
        animationBlink->setKeyValueAt(0.2, 1);
        animationBlink->setKeyValueAt(0.3, 0);
        animationBlink->setKeyValueAt(0.4, 1);
        animationBlink->setKeyValueAt(0.5, 0);
        animationBlink->setKeyValueAt(0.6, 1);
        animationBlink->setKeyValueAt(0.7, 0);
        animationBlink->setKeyValueAt(0.8, 1);
        animationBlink->setKeyValueAt(0.9, 0);
        animationBlink->setEndValue(1);
        animationBlink->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void MainWindow::on_declineButton_hovered()
{
    // Создаю анимацию для перемещения character влево
    QPropertyAnimation *animation = new QPropertyAnimation(ui->character, "geometry");
    animation->setDuration(700); // Продолжительность анимации в миллисекундах
    animation->setStartValue(ui->character->geometry());
    animation->setEndValue(QRect(330, ui->character->y(), ui->character->width(), ui->character->height()));
    animation->setEasingCurve(QEasingCurve::OutCubic); // Тип анимации, имитирующий свайп
    animation->start(QAbstractAnimation::DeleteWhenStopped); // Начать анимацию и удалить объект после завершения

    // Создаю анимацию затухания для decline_label
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect();
    ui->decline_label->setGraphicsEffect(opacityEffect);
    QPropertyAnimation *blinkAnimation = new QPropertyAnimation(opacityEffect, "opacity");
    blinkAnimation->setDuration(500);
    blinkAnimation->setStartValue(0);
    blinkAnimation->setEndValue(1);
    blinkAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    if(isquestion==true){
        // Создаю анимацию для перемещения decline_label вправо на координату 0
        QPropertyAnimation *declineAnimation = new QPropertyAnimation(ui->decline_label, "geometry");
        declineAnimation->setDuration(700);
        declineAnimation->setStartValue(ui->decline_label->geometry());
        declineAnimation->setEndValue(QRect(0, ui->decline_label->y(), ui->decline_label->width(), ui->decline_label->height()));
        declineAnimation->setEasingCurve(QEasingCurve::OutCubic);
        declineAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    }

    if(rhetorical==true){
        ui->decline_label->setGraphicsEffect(opacityEffect);
        QPropertyAnimation *animationBlink = new QPropertyAnimation(opacityEffect, "opacity");
        animationBlink->setDuration(1000); // Продолжительность анимации
        animationBlink->setStartValue(1);
        animationBlink->setKeyValueAt(0.1, 0);
        animationBlink->setKeyValueAt(0.2, 1);
        animationBlink->setKeyValueAt(0.3, 0);
        animationBlink->setKeyValueAt(0.4, 1);
        animationBlink->setKeyValueAt(0.5, 0);
        animationBlink->setKeyValueAt(0.6, 1);
        animationBlink->setKeyValueAt(0.7, 0);
        animationBlink->setKeyValueAt(0.8, 1);
        animationBlink->setKeyValueAt(0.9, 0);
        animationBlink->setEndValue(1);
        animationBlink->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void MainWindow::on_optionButtons_unhovered() {
    // Создаю анимацию для возврата qlabel в начальное положение
    QPropertyAnimation *animation = new QPropertyAnimation(ui->character, "geometry");
    animation->setDuration(700); // Продолжительность анимации в миллисекундах
    animation->setStartValue(ui->character->geometry());
    animation->setEndValue(QRect(476, ui->character->y(), ui->character->width(), ui->character->height()));
    animation->setEasingCurve(QEasingCurve::OutCubic); // Тип анимации, имитирующий свайп
    animation->start(QAbstractAnimation::DeleteWhenStopped); // Начать анимацию и удалить объект после завершения


    // Создаю анимацию для перемещения accept_label обратно на 12 0
    QPropertyAnimation *acceptAnimation = new QPropertyAnimation(ui->accept_label, "geometry");
    acceptAnimation->setDuration(700);
    acceptAnimation->setStartValue(ui->accept_label->geometry());
    acceptAnimation->setEndValue(QRect(1280, ui->accept_label->y(), ui->accept_label->width(), ui->accept_label->height()));
    acceptAnimation->setEasingCurve(QEasingCurve::OutCubic);
    acceptAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    // Создаю анимацию для перемещения decline_label обратно на -320
    QPropertyAnimation *declineAnimation = new QPropertyAnimation(ui->decline_label, "geometry");
    declineAnimation->setDuration(700);
    declineAnimation->setStartValue(ui->decline_label->geometry());
    declineAnimation->setEndValue(QRect(-320, ui->decline_label->y(), ui->decline_label->width(), ui->decline_label->height()));
    declineAnimation->setEasingCurve(QEasingCurve::OutCubic);
    declineAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::fadeAnimation(QGraphicsEffect *opacityEffect, QWidget *widget)
{
    widget->setGraphicsEffect(opacityEffect);
    QPropertyAnimation *blinkAnimation = new QPropertyAnimation(opacityEffect, "opacity");
    blinkAnimation->setDuration(700);
    blinkAnimation->setStartValue(1);
    blinkAnimation->setKeyValueAt(0.5, 0);
    blinkAnimation->setEndValue(1);
    blinkAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::on_acceptButton_clicked()
{
    QCursor::setPos(640, 360);
    if (isquestion == true) {
        actionapproved = true;
    }
    game_plot();
    // Создаю анимацию затухания
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect();
    fadeAnimation(opacityEffect, ui->character);
}


void MainWindow::on_declineButton_clicked()
{
    QCursor::setPos(640, 360);
    if (isquestion == true) {
        actionapproved = false;
    }
    game_plot();
    // Создаю анимацию затухания
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect();
    fadeAnimation(opacityEffect, ui->character);
}

void MainWindow::on_characterButton_clicked(){
    if(isquestion==false){
        QCursor::setPos(640, 360);
        game_plot();
        // Создаю анимацию затухания
        QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect();
        fadeAnimation(opacityEffect, ui->character);
    }
}

void MainWindow::updateStats() {
    // Максимальный стат
    maxStat = wealth;
    if (power > maxStat) maxStat = power;
    if (intelligence > maxStat) maxStat = intelligence;
    if (decency > maxStat) maxStat = decency;

    // Проверка границ значений
    if (wealth < 0) wealth = 0;
    if (power < 0) power = 0;
    if (intelligence < 0) intelligence = 0;
    if (decency < 0) decency = 0;
    if (wealth > 100) wealth = 100;
    if (power > 100) power = 100;
    if (intelligence > 100) intelligence = 100;
    if (decency > 100) decency = 100;

    // Обновляю график статистики
    statsGraph->updateStatsGraph(wealth, power, intelligence, decency);

    if (wealth == 0 || power == 0 || intelligence == 0 || decency == 0) {
        ui->stackedWidget->setCurrentIndex(5); // Переключение на page_3
        QCursor::setPos(640, 360);
    }
    statsBars->updateStatsBars(wealth, power, intelligence, decency);
}

void MainWindow::setCharacterGif(QString character, QString borderColor) {
    if (!characterMovie) {
        characterMovie = std::make_unique<QMovie>("D:/COURSE WORK/pictures/npc_dota_hero_" + character + ".gif");
        ui->character->setMovie(characterMovie.get());
    }
    // Задаем цвет обводки
    ui->character->setStyleSheet("border: 4px solid " + borderColor + "; border-radius: 4px;");
    characterMovie->start();
}

void MainWindow::game_plot()
{
    QPixmap accept_label;
    QPixmap decline_label;
    characterMovie = nullptr;
    updateStats();
    switch (dialogStep) {
    case 0:
        setWispGif();
        isquestion = false;
        if (actionapproved == true) {
            ui->dialog_text->setText("Хорошо, удачи!");
            updateStats();
        } else {
            ui->dialog_text->setText("...");
            updateStats();
        }
        break;
    case 1:
        setElderTitanGif();
        isquestion = true;
        ui->dialog_text->setText("Give me ward, hey! Hello give me ward fast! I dont speak russian man! Give me ward in hard lane!");
        break;
    case 2:
        isquestion = false;
        if (actionapproved == true) {
            setElderTitanGif();
            ui->dialog_text->setText("Okey thank you...");
            decency+=10;
            wealth-=10;
            updateStats();
        } else {
            setWispGif();
            ui->dialog_text->setText("После спора с Элдер Титаном вы в конечном счете дали ему вард, но он замутил комманду.");
            decency-=10;
            power-=10;
            wealth+=20;
            updateStats();
        }
        break;
    case 3:
        setInvokerGif();
        isquestion = true;
        ui->dialog_text->setText("Танго дай быстро!");
        break;
    case 4:
        setInvokerGif();
        isquestion = false;
        if (actionapproved == true) {
            ui->dialog_text->setText("Хех.");
            dialogStep = dialogStep + 1;
            wealth-=10;
            decency-=10;
            intelligence+=10;
            updateStats();
        } else {
            ui->dialog_text->setText("Ну окей, я тебя понял.");
            decency-=30;
            updateStats();
        }
        break;
    case 5:
        setWispGif();
        isquestion = false;
        ui->dialog_text->setText("Инвокер ушел фидить.");
        break;
    case 6:
        setDazzleGif();
        isquestion = false;
        ui->dialog_text->setText("Вы решили сходить на легкую линию и встретили там антимага.");
        break;
    case 7:
        setAntimageGif();
        isquestion = true;
        ui->dialog_text->setText("Заговорить с антимагом?");
        break;
    case 8:
        isquestion = false;
        if (actionapproved == true) {
            setAxeGif();
            ui->dialog_text->setText("Он не слышит, он вообще никого не слышит. Ты его ник видел? <<ВыВсеВМуте>>! Кстати, рад представиться, я второй саппорт, Аксевич! Для друзей лесник, хе-хе.");
            intelligence-=10;
            updateStats();
        } else {
            setAntimageGif();
            ui->dialog_text->setText("Чего уставился? Ты в муте чел...");
            decency-=10;
            updateStats();
        }
        break;
    case 9:
        setWispGif();
        if (actionapproved == true) {
            isquestion = true;
            ui->dialog_text->setText("Опять лесник... Выйти из игры?");
        }
        else {
            isquestion = false;
            ui->dialog_text->setText("Вы решили долго не задерживаться и ушли с линии в сторону леса.");
            dialogStep = dialogStep + 1;
        }
        break;
    case 10:
        isquestion = false;
        if (actionapproved == true) {
            setWispGif();
            decency=0;
            power=0;
            wealth=0;
            intelligence=0;
            updateStats();
        } else {
            setAxeGif();
            power-=10;
            wealth-=10;
            intelligence+=10;
            decency += rng.generate(-10, 10);
            updateStats();
            setAxeGif();
            ui->dialog_text->setText("Чего ты встал как вкопанный?");
            dialogStep = dialogStep + 1;
        }
        break;
    case 11:
        setAxeGif();
        ui->dialog_text->setText("В лесу вы встретили ваш pos5. Это лесной акс..");
        break;
    case 12:
        setWispGif();
        ui->dialog_text->setText("Посмотрев на его экономику, вы задумались о том, когда же он купить блинк.");
        break;
    case 13:
        setAxeGif();
        isquestion = true;
        ui->dialog_text->setText("Спросить у акса, когда он собирается купить блинк?");
        break;
    case 14:
        setAxeGif();
        isquestion = false;
        if (actionapproved == true) {
            ui->dialog_text->setText("Вообще-то я сначало соберу мидас.");
            decency-=10;
            power-=10;
            wealth-=10;
            intelligence-=10;
            updateStats();
        } else {
            ui->dialog_text->setText("Вы решили избежать разговор с Аксом во избежении каких-либо проблем, но в вашем сердце начались появлятся сомнения об исходе вашей игры..");
            power-=10;
            intelligence+=20;
            updateStats();
            dialogStep = dialogStep + 2;
        }
        break;
    case 15:
        setWispGif();
        isquestion = true;
        ui->dialog_text->setText("Желаете ли вы отказаться от продолжения игры, или же вы попробуете переубедить Акса?");
        break;
    case 16:
        isquestion = false;
        if (actionapproved == false) {
            setWispGif();
            decency=0;
            power-=0;
            wealth-=0;
            intelligence=0;
            updateStats();
        } else {
            setAxeGif();
            ui->dialog_text->setText("Я соберусь так, как я желаю, и вообще, хватить делить со мной экспу");
            power-=10;
            decency-=10;
            updateStats();
        }
        break;
    case 17:
        setDazzleGif();
        ui->dialog_text->setText("Фармящий Антимаг, фидящий мидер, лесник.. Да это же нереально выйграть! Нет, с меня хватит...");
        break;
    case 18:
        rhetorical = true;
        isquestion = true;
        setWispGif();
        ui->dialog_text->setText("Продолжить игру?");
        accept_label.load("D:/COURSE WORK/pictures/red_transparent.png");
        ui->accept_label->setPixmap(accept_label);
        break;
    case 19:
        setGabenGif();
        rhetorical = false;
        isquestion = false;
        decency=1;
        power=1;
        wealth=1;
        intelligence=1;
        updateStats();
        ui->dialog_text->setText("Привет, это Габен. Ну или как ты меня обычно называешь в пабликах, жирный ***, который не фиксит свою игру.");
        accept_label.load("D:/COURSE WORK/pictures/green_transparent.png");
        ui->accept_label->setPixmap(accept_label);
        break;
    case 20:
        setGabenGif();
        wealth=100;
        updateStats();
        ui->dialog_text->setText("Слушай, друг. Ты нам нехило так надоел со своими капризами, может уже закончим с этим? Просто посcапорти, окей? Ты будешь удивлен насколько безнадежные игры можно вытаскивать.");
        break;
    case 21:
        setDazzleGif();
        power = 100;
        updateStats();
        ui->dialog_text->setText("Если мы когда-нибудь встретимся в одной игре, то я возьму лесника! Покажу тебе страту через фаст мидасик, и вот тогда... Просто поссапорти, окей?");
        break;
    case 22:
        setGabenGif();
        ui->dialog_text->setText("Неужели у тебя никогда не было игр, когда ты думал, что вы уже проиграли? Но в итоге вы каким-то чудом побеждаете. ");
        break;
    case 23:
        setGabenGif();
        intelligence = 100;
        updateStats();
        ui->dialog_text->setText("То что ты не понимаешь как тут можно выйграть, не значит что это невозможно. Просто играй до конца и ты будешь удивлен, я обещаю.");
        break;
    case 24:
        setWispGif();
        decency=100;
        updateStats();
        isquestion = true;
        ui->dialog_text->setText("Попробовать еще раз?");
        break;
    case 25:
        isquestion = false;
        if(actionapproved == true){
            setDazzleGif();
            ui->dialog_text->setText("Окей, запускай! Я сыграю на максимум! И после этого ты расскажешь почему я проиграл!");
        }
        else {
            setWispGif();
            decency=0;
            power=0;
            wealth=0;
            intelligence=0;
            updateStats();
        }
        break;
    case 26:
        setTryhardGif();
        decency=50;
        power=50;
        wealth=50;
        intelligence=50;
        updateStats();
        ui->dialog_text->setText("Сейчас я вам покажу трайхард!");
        break;
    case 27:
        setWispGif();
        ui->dialog_text->setText("После разговора с Габенов вы решили приложить все усилия к победе. Все что было раньше вы прошли без колебаний. Теперь вы отправляетесь на свою линию.");
        break;
    case 28:
        setEarthShakerGif();
        isquestion = true;
        ui->dialog_text->setText("Может на экспу сыграем?");
        break;
    case 29:
        setDazzleGif();
        isquestion = false;
        if (actionapproved == false) {
            ui->dialog_text->setText("Да давай рули отсюда, тут антимаг фармит.");
            decency+=10;
            power+=10;
        }
        else{
            ui->dialog_text->setText("Ну... давай.");
            wealth+=10;
            decency-=20;
        }
        updateStats();
        break;
    case 30:
        isquestion = false;
        if (actionapproved == false) {
            setEarthShakerGif();
            ui->dialog_text->setText("Ну мне экспа нужна.");
            decency-=10;
        }
        else{
            setWispGif();
            ui->dialog_text->setText("Earthshaker помимо фарма своих крипов, начал денаить ваших.");
            wealth-=10;
        }
        updateStats();
        break;
    case 31:
        isquestion = false;
        setDazzleGif();
        if (actionapproved == false){
            ui->dialog_text->setText("Я сказал сваливай!");
        }
        else{
            ui->dialog_text->setText("Дальше так не может быть...");
        }
        break;
    case 32:
        isquestion = true;
        rhetorical = true;
        if (actionapproved == false) {
            setEarthShakerGif();
            ui->dialog_text->setText("Earthshaker инициализирует битву, принять бой?");
        }
        else{
            setDazzleGif();
            ui->dialog_text->setText("Инициализировать битву с Earthshaker?");
        }
        decline_label.load("D:/COURSE WORK/pictures/green_transparent.png");
        ui->decline_label->setPixmap(decline_label);
        break;
    case 33:
        setWispGif();
        isquestion = false;
        rhetorical = false;
        ui->stackedWidget->setCurrentIndex(1); // Переключение на page_4
        QCursor::setPos(640, 360);
        break;
    case 34:
        if (clickerGameVictory == true){
            setDazzleGif();
            ui->dialog_text->setText("Вы решили раздать пятюни с пацанами.");
        }
        else {
            setDazzleTpGif();
            ui->dialog_text->setText("Вы нажимаете тп обратно.");
        }
        break;
    case 35:
        if (clickerGameVictory == true){
            setHighFiveGif();
            ui->dialog_text->setText("Вы стакнулись для пятюнь, вследствии чего шейкер нажал в вас ульту.");
        }
        else {
            setAntimageDyingGif();
            ui->dialog_text->setText("Вашего керри убили.");
        }
        break;
    case 36:
        setWispGif();
        decency=1;
        power=1;
        wealth=1;
        intelligence=1;
        updateStats();
        ui->dialog_text->setText("Вы проиграли игру.");
        break;
    case 37:
        setGabenGif();
        if (clickerGameVictory == true){
            ui->dialog_text->setText("Пятюну парни против шейкера? Ты можешь с ними не разговаривать? Просто побегай за ними и все.");
        }
        else {
            ui->dialog_text->setText("Я просто не могу понять, как можно было 17 раз умереть. От тебя никто не требует, чтобы ты затаскивал игру. Таких тупых чуваков как ты у нас никогда не было.");
        }
        break;
    case 38:
        setGabenGif();
        if (clickerGameVictory == true){
            ui->dialog_text->setText("<<Этот *** уже утомил, отправляйте его до тех пор, пока он не выйграет.>>");
        }
        else {
            ui->dialog_text->setText("Тебя говорят просто поссапорти и все. Если дота и умерает, то от таких как ты. (неразборчиво)<<Этот *** уже утомил, отправляйте его до тех пор, пока он не выйграет.>>");
        }
        break;
    case 39:
        setDazzleGif();
        isquestion = true;
        rhetorical = true;
        ui->dialog_text->setText("Продолжить игру?");
        break;
    case 40:
        setConvincingAxeGif();
        decency=100;
        power=100;
        wealth=100;
        intelligence=100;
        updateStats();
        isquestion = false;
        rhetorical = false;
        decline_label.load("D:/COURSE WORK/pictures/red_transparent.png");
        ui->decline_label->setPixmap(decline_label);
        ui->dialog_text->setText("Axe: Окей, сейчас самый важный файт. Они нас пушат, Antimage сплитит топ. Надо их подзадержать. Dazzle: Давай братан! Видишь момент прыгай! Дам грэйв не ссы! Работаем, окей? Только не подведи. Axe: Я тебя не подведу братан... Окей, я пошел!");
        greenBarValue = 100;
        break;
    case 41:
        setWispGif();
        ui->stackedWidget->setCurrentIndex(2);
        QCursor::setPos(640, 360);
        break;
    case 42:
        setAxeGif();
        ui->dialog_text->setText("Axe: ******* (звучит оскорбительно)");
        break;
    case 43:
        setDazzleJustifiedGif();
        ui->dialog_text->setText("Анимация у скилла есть, вкурсе о таком? Ты вообще лесника взял, придурок!");
        break;
    case 44:
        setWispGif();
        decency=1;
        power=1;
        wealth=1;
        intelligence=1;
        updateStats();
        ui->dialog_text->setText("...");
        break;
    case 45:
        setDazzleGif();
        ui->dialog_text->setText("Я бездарность?");
        break;
    case 46:
        setWispGif();
        ui->dialog_text->setText("Пф... Эх... Ну вообще ты очень долго думаешь над этим тестом.");
        break;
    case 47:
        setDazzleGif();
        ui->dialog_text->setText("Ответь мне прямо.");
        break;
    case 48:
        setWispGif();
        ui->dialog_text->setText("Ну да, ты худший.");
        break;
    case 49:
        setDazzleGif();
        ui->dialog_text->setText("Да пошла ты!");
        break;
    case 50:
        setGabenGif();
        ui->dialog_text->setText("Нервничаешь что-то... Правда глаза режет? Да? Мне просто интересно, почему же ты в каждой катке говоришь что-то про саппортов, а сам не можешь отыграть?");
        break;
    case 51:
        setDazzleGif();
        ui->dialog_text->setText("Я могу, просто впадлу стараться. Что, может поспорим? Если я сейчас выйгрываю, то ты мне 6000 рейтинга на аккаунт делаешь.");
        break;
    case 52:
        setGabenGif();
        ui->dialog_text->setText("Но ты же мне в ответ ничего не можешь предложить?");
        break;
    case 53:
        setDazzleGif();
        ui->dialog_text->setText("Нет... не могу. Но разве что ты мне заблокируешь аккаунт и сделаешь мне доступ в игру... только за деньги.");
        break;
    case 54:
        setGabenGif();
        ui->dialog_text->setText("(неразборчиво)<<Да. Платный доступ только для тех, у кого много репортов. Напиши там, типо, на вас поступало много жалоб в последнее время - плати косарь или иди ***. Типо такого короче сделай.>>");
        break;
    case 55:
        setWispGif();
        isquestion = true;
        ui->dialog_text->setText("Слушай, нам пора начинать.");
        break;
    case 56:
        setDazzleGif();
        isquestion = false;
        if (actionapproved == true) {
            ui->dialog_text->setText("Запускайте.");
            dialogStep+=2;
        }
        else {
            ui->dialog_text->setText("А что если я не хочу? Может уже самое время закончить?");
        }
        break;
    case 57:
        setWispGif();
        ui->dialog_text->setText("...");
        break;
    case 58:
        setDazzleGif();
        ui->dialog_text->setText("Запускайте.");
        break;
    case 59:
        setWispGif();
        ui->dialog_text->setText("Если проиграешь и на этот раз, то уже не сможешь играть в доту...");
        break;
    case 60:
        setWispGif();
        ui->stackedWidget->setCurrentIndex(3); // Переключение на page_6 (конечная заставка)
        QCursor::setPos(640, 360);
        QTimer::singleShot(40500, this, SLOT(game_plot())); // Вызов game_plot() через 40,5 секунд
        break;
    case 61:
        setWispGif();
        ui->stackedWidget->setCurrentIndex(5); // Переключение на page_3
        QCursor::setPos(640, 360);
        break;
    }
    dialogStep++; // Переход к следующему шагу диалога
}

void MainWindow::on_clickerButton_clicked()
{
    if (clickerGameEnded) {
        return; // Если игра завершена, ничего не делаю
    }

    if (redBarValue > 0) {
        redBarValue--;
    }
    redBar->updateVerticalBars(0, redBarValue);

    ui->clicker_label->hide();

    if (!greenBarTimer->isActive()) {
        greenBarTimer->start(150);
    }
}

void MainWindow::updateGreenBar()
{
    if (clickerGameEnded) {
        return; // Если игра завершена, ничего не делаю
    }

    if (greenBarValue > 0) {
        greenBarValue--;
    }
    greenBar->updateVerticalBars(greenBarValue, 0);

    if (greenBarValue <= 0 || redBarValue <= 0) {
        clickerGameEnded = true; // Игра завершена
        greenBarTimer->stop();

        QMovie *clicker_label;
        if (greenBarValue <= 0) {
            clicker_label = new QMovie("D:/COURSE WORK/pictures/clicker_label_lost.gif");
            clickerGameVictory = false;
        } else {
            clicker_label = new QMovie("D:/COURSE WORK/pictures/clicker_label_victory.gif");
            clickerGameVictory = true;
        }

        // Обновляю текст в зависимости от результата игры
        if (clickerGameVictory == true) {
            QTimer::singleShot(350, this, SLOT(setClickerVictoryGif()));
            ui->dialog_text->setText("Вы выйграли Earthshaker. Вам уже нетерпиться отпраздновать это с тиммейтами.");
        } else {
            QTimer::singleShot(350, this, SLOT(setClickerLostGif()));
            ui->dialog_text->setText("Вы почти выйграли, но из-за затяжной битвы вас забрал Bounty Hunter из инвиза. Вы отправляетесь в таверну");
        }

        ui->clicker_label->setMovie(clicker_label);
        clicker_label->start();
        ui->clicker_label->show();
        QTimer::singleShot(5000, this, SLOT(switchToGameScene()));
    }
}

void MainWindow::switchToGameScene()
{
    QCursor::setPos(640, 360);
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_skillcheckButton_clicked()
{
    clickCount++;

    if (clickCount == 2) {
        // Запускаем анимацию только после второго клика
        QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect();
        ui->skillcheckArea->setGraphicsEffect(opacityEffect);
        QPropertyAnimation *animationBlink = new QPropertyAnimation(opacityEffect, "opacity");
        animationBlink->setDuration(1000); // Продолжительность анимации
        animationBlink->setStartValue(1);
        animationBlink->setKeyValueAt(0.1, 0);
        animationBlink->setKeyValueAt(0.2, 1);
        animationBlink->setKeyValueAt(0.3, 0);
        animationBlink->setKeyValueAt(0.4, 1);
        animationBlink->setKeyValueAt(0.5, 0);
        animationBlink->setKeyValueAt(0.6, 1);
        animationBlink->setKeyValueAt(0.7, 0);
        animationBlink->setKeyValueAt(0.8, 1);
        animationBlink->setKeyValueAt(0.9, 0);
        animationBlink->setEndValue(1);
        animationBlink->start(QAbstractAnimation::DeleteWhenStopped);
    }

    if (skillcheckGameEnded) {
        return; // Если игра завершена, ничего не делаю
    }

    if (clickCount > 2) {
        return; // Если было сделано больше двух кликов, не делаем ничего
    }

    ui->skillcheck_text->hide();

    if (!skillCheckGameStarted) {
        // Если игра еще не началась, начинаю ее
        skillCheckGameStarted = true;
        rng_skillcheck += rng.generate(-10,5);
        skillCheckTimer->start(20 + rng_skillcheck); // Обновляю каждую секунду
    } else {
         // Если игра уже началась, проверяю, находится ли greenValue в нужном диапазоне
        if (greenBarValue > 10 && greenBarValue < 20) {
            skillcheck_text = std::make_unique<QMovie>("D:/COURSE WORK/pictures/clicker_label_victory.gif");
            ui->skillcheck_text->setMovie(skillcheck_text.get());
            skillcheck_text->start();
            ui->skillcheck_text->show();
            skillcheckGameVictory = true;
            ui->dialog_text->setText("Вы успешно дали грэйв в тайминг, но не учли время каста и Axe погиб.");
        } else {
            skillcheck_text = std::make_unique<QMovie>("D:/COURSE WORK/pictures/clicker_label_lost.gif");
            ui->skillcheck_text->setMovie(skillcheck_text.get());
            skillcheck_text->start();
            ui->skillcheck_text->show();
            skillcheckGameVictory = false;
            ui->dialog_text->setText("Вы не успели дать грэйв. Axe погиб.");
        }
    skillcheckEndGame();
    }
}

void MainWindow::updateSkillCheckBar()
{
    if (skillcheckGameEnded) {
        return; // Если игра завершена, ничего не делаем
    }

    if (greenBarValue > 0) {
        greenBarValue--;
    }
    skillCheckBar->updateVerticalBar(greenBarValue);

    if (greenBarValue <= 0) {
        skillcheck_text = std::make_unique<QMovie>("D:/COURSE WORK/pictures/clicker_label_lost.gif");
        ui->skillcheck_text->setMovie(skillcheck_text.get());
        skillcheck_text->start();
        ui->skillcheck_text->show();
        skillcheckGameVictory = false;
        ui->dialog_text->setText("Вы не успели дать грэйв. Axe погиб.");
        skillcheckEndGame(); // Вызываем функцию завершения игры
    }
}

void MainWindow::skillcheckEndGame()
{
    skillcheckGameEnded = true; // Игра завершена
    skillCheckTimer->stop();
    QTimer::singleShot(5000, this, SLOT(switchToGameScene()));
}

