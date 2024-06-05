#include "game.h"
#include "ui_game.h"

#include <qcoreapplication.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qtmetamacros.h>
#include <qwidget.h>

Game::Game(bool hardmode, QWidget *parent) : QWidget(parent), ui(new Ui::Game), hardmode(hardmode){
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFocusPolicy(Qt::StrongFocus);

    ui->setupUi(this);

    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setLayout(new QVBoxLayout());
    ui->graphicsView->layout()->addWidget(ui->scoreFrame);
    ui->graphicsView->layout()->addWidget(ui->pauseFrame);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scoreFrame->setStyleSheet("color: black;");
    ui->powerupsFrame->hide();
    ui->pauseFrame->hide();

    connect(ui->resumeButton, &QPushButton::pressed, this, &Game::handlePause);
    connect(ui->toMenuButton, &QPushButton::pressed, this, &Game::exitToMenu);
    this->installEventFilter(this);
}

Game::~Game() {
    if (maze != nullptr) {
        delete maze;
        maze = nullptr;
        qDebug() << "Game deleted";
    }
}

void Game::setMaze(int w, int h, int cellSize){
    if (maze != nullptr) {
        delete maze;
        maze = nullptr;
    }

    Cell::size = cellSize;

    this->w = w;
    this->h = h;

    size_x = w * 20;
    size_y = h * 20;

    Cell::image = new QPixmap("../Sprites/coin.png");
    Player::defaultFace = new QPixmap("../Sprites/smirk.png");
    Player::invisibleFace = new QPixmap("../Sprites/invisible.png");
    Enemy::image = new QPixmap("../Sprites/ghost.png");
    Powerup::imageTeleport = new QPixmap("../Sprites/teleport.png");
    Powerup::imageInvisibility = new QPixmap("../Sprites/invisibility.png");

    maze = new Maze(w, h, scene);
    player = Player::getInstance();
    ui->graphicsView->setFixedSize(size_x + 20, size_y + 20 );
    ui->graphicsView->setFocus();
    // connect(maze, &Maze::pause, this, &Game::handlePause);
    connect(maze, &Maze::scoreUpdated, this, &Game::updateScore);
    connect(maze, &Maze::levelComplete, this, &Game::exitToMenu);
    connect(player, &Player::powerupAdded, this, &Game::handlePowerupAdded);
    connect(player, &Player::powerupUsed, this, &Game::handlePowerupUsed);

    if (hardmode) {
        shiftToCenter();
        ui->graphicsView->setFixedSize(420, 420);
        connect(player, &Player::playerMoved, this, &Game::shift);
    }
}

void Game::handlePause() {
    paused ^= true;
    if (paused)
        ui->pauseFrame->show();
    else
        ui->pauseFrame->hide();

    // emit pause(paused);
}

void Game::handlePowerupAdded(Powerup *powerup) {
    ui->powerupsFrame->show();

    QLabel *label = new QLabel(ui->powerupsFrame);
    label->setFixedSize(64, 64);
    label->setAlignment(Qt::AlignCenter);

    QPixmap pixmap = *(powerup->getImage());
    QPixmap scaledPixmap = pixmap.scaled(QSize(32, 32), Qt::KeepAspectRatio);

    label->setPixmap(scaledPixmap);
    label->show();

    ui->powerupsFrame->layout()->addWidget(label);

    powerupLabels.append(label);
}

void Game::handlePowerupUsed(int index) {
    if (index < 0 || index >= powerupLabels.size()) {
        return;
    }

    QLabel *label = powerupLabels.at(index);
    powerupLabels.removeAt(index);
    label->deleteLater();

    if (powerupLabels.empty()) {
        ui->powerupsFrame->hide();
        this->parentWidget()->adjustSize();
    }
}

void Game::updateScore(int score) {
    ui->scoreLabel->setText(QString::number(score));
}

void Game::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Escape) {
        handlePause();
        return;
    }

    bool moved = false;
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        moved = maze->movePlayer(Up);

    } else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        moved = maze->movePlayer(Down);

    } else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        moved = maze->movePlayer(Left);

    } else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        moved = maze->movePlayer(Right);
    }

    if (event->key() == Qt::Key_1) {
        player->usePowerup(0);
    } else if (event->key() == Qt::Key_2) {
        player->usePowerup(1);
    }

}

bool Game::eventFilter(QObject* object, QEvent* event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        keyPressEvent(keyEvent);
        return true;
    }
    
    return QObject::eventFilter(object, event);
}

void Game::shiftToCenter() {
    int dx = 20 * Cell::size / 4 + Cell::size / 2;
    int dy = 20 * Cell::size / 4 + Cell::size / 2;

    QPointF shiftAmount(dx, dy);

    QList<QGraphicsItem*> items = scene->items();
    for (QGraphicsItem* item : items) {
        QPointF newPos = item->pos() + shiftAmount;
        item->setPos(newPos);
    }
}

void Game::shift(QPointF offset) {
    QList<QGraphicsItem*> items = scene->items();
    for (QGraphicsItem* item : items) {
        QPointF newPos = item->pos() - offset;
        item->setPos(newPos);
    }
}