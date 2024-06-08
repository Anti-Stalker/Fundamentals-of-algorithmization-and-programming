#include "character.h"
#include "const.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsItem>
#include <QTimer>
#include <QMap>
#include <QColor>

QMap<TileType, QColor> tileColorMap = {
    {TileType::Empty, Qt::white},
    {TileType::Wall, Qt::black},
    {TileType::Character, Qt::gray},
    {TileType::Goal, Qt::darkGreen}
};

Character::Character(LevelGenerator *levelGenerator, QGraphicsScene *scene, QWidget *parent)
    : QWidget(parent), m_level(levelGenerator), m_coinsCollected(START_COINS), m_health(START_HEALTH), m_x(START_X), m_y(START_Y) {

    m_graphicsItem = new QGraphicsRectItem();
    scene->addItem(m_graphicsItem);

    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    m_timer.start();
}

void Character::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(QBrush(tileColorMap[TileType::Character]));
    painter.drawRect(m_x * SQUARE_SIZE, m_y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
}

void Character::move(int dx, int dy) {

    qDebug() << "Move method called with dx:" << dx << "dy:" << dy;

    int newX = m_x;
    int newY = m_y;

    while (true) {
        newX += dx;
        newY += dy;

        TileType tileType = m_level->getTileType(newX, newY);
        if (tileType == TileType::Wall) {
            qDebug() << "Wall encountered, character cannot move";
            break;
        }

        qDebug() << "Moving character";

        TileType tileTypeFor = m_level->getTileType(newX, newY);
        if (tileTypeFor == TileType::Enemy) {
            qDebug() << "Enemy";
            m_health--;
            setHealth(m_health--);
        }
        else if (tileTypeFor == TileType::Coin){
            m_level->setTileType(newX, newY, TileType::Empty);
            qDebug() << "Coin";
            m_coinsCollected++;
            setCoinsCollected(m_coinsCollected++);
        }
        else if (tileTypeFor == TileType::BonusShield){
            qDebug() << "BonusShield";
            m_level->setTileType(newX, newY, TileType::Empty);
            m_health++;
        }
        else if (tileTypeFor == TileType::BonusCoin){
            qDebug() << "BonusCoin";
            m_level->setTileType(newX, newY, TileType::Empty);
            m_coinsCollected *= 2;
            setCoinsCollected(m_coinsCollected *= 2);
        }
        else if (tileTypeFor == TileType::BonusFreeze){
            qDebug() << "BonusFreeze";
            m_level->setTileType(newX, newY, TileType::Empty);
            m_health += 2;
            setHealth(m_health += 2);
        }

        if(m_health <= 0) {
            die();
        }

        m_level->setTileType(m_x, m_y, TileType::Empty);

        m_level->setTileType(newX, newY, TileType::Character);

        m_x = newX;
        m_y = newY;


        emit moved();

        checkGoal();
    }
}

void Character::setX(int x) {
    m_x = x;
}

void Character::setY(int y) {
    m_y = y;
}

void Character::setLevel(LevelGenerator *level) {
    m_level = level;
}

int Character::getCoinsCollected() const {
    return m_coinsCollected;
}

void Character::setCoinsCollected(int newCoins)
{
    m_coinsCollected = newCoins;
}

int Character::getHealth() const {
    return m_health;
}

void Character::setHealth(int health) {
    m_health = health;
}

int Character::getX() const {
    return m_x;
}

int Character::getY() const {
    return m_y;
}

void Character::keyPressEvent(QKeyEvent *event) {
    qDebug() << "keyPressEvent";
    if (event->key() == Qt::Key_W) {
        move(0, -1);
    } else if (event->key() == Qt::Key_S) {
        move(0, 1);
    } else if (event->key() == Qt::Key_A) {
        move(-1, 0);
    } else if (event->key() == Qt::Key_D) {
        move(1, 0);
    }  else if (event->key() == Qt::Key_Escape)   {
        m_mainWindow->close();
    } else {
        QWidget::keyPressEvent(event);
    }
}

void Character::checkGoal() {
    qDebug() << "CheckGoal";
    qDebug() << m_x << " " << m_y;
    if (m_x == GLOBAL_WIDTH - 2 && m_y == GLOBAL_HEIGHT - 2) {

        qDebug() << "Goal is check";
        m_points = m_coinsCollected * 150 + 1000 * m_coinsCollected / (m_timer.elapsed() / 100);

        QMessageBox messageBox;
        messageBox.setText("Goal reached!");
        qint64 elapsedTime = m_timer.elapsed();
        QString infoText = QString("Elapsed time: %1 milliseconds\nReceived coins: %2\nYour points: %3")
                               .arg(elapsedTime)
                               .arg(m_coinsCollected)
                               .arg(m_points);
        messageBox.setInformativeText(infoText);
        messageBox.exec();
        m_timer.invalidate();

        m_mainWindow->close();

    }
}


void Character::die() {
    QMessageBox messageBox;
    messageBox.setText("Game Over!");
    qint64 elapsedTime = m_timer.elapsed();
    QString infoTextForDeath = QString("Elapsed time before death: %1 milliseconds\n"
                                       "Received coins before death: %2\n")
                                   .arg(elapsedTime)
                                   .arg(m_coinsCollected);
    messageBox.setInformativeText(infoTextForDeath);
    messageBox.exec();
    m_timer.invalidate();
    m_mainWindow->close();
}
void Character::setMainWindow(MainWindow* mainWindow) {
    m_mainWindow = mainWindow;
}
