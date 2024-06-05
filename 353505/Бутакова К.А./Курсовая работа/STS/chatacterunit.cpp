#include "chatacterunit.h"
#include "datahub.h"
#include "mapcell.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <QGraphicsEffect>

#include <QEventLoop>
#include <QTimer>

extern void waiter(int time = 1000);


CharacterUnit::CharacterUnit(characterStatus::dataPack dp, double width, double height) : m_data(dp), m_dWidth(width), m_dHeight(height)
{
    m_Fill = QRect(-((m_dWidth)/2), -((m_dHeight)/2), (m_dWidth), (m_dHeight));
    pixmap = new QPixmap(width, height);
    pixmap->load(dp.picSource);
    pixmap->rect();
}

QRectF CharacterUnit::boundingRect() const
{
    qreal adjust = 1;
    return QRectF(-(m_dWidth/2) - adjust, -(m_dHeight/2) - adjust, m_dWidth + adjust, m_dHeight + adjust);
}

void CharacterUnit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(m_Fill, *pixmap);
    if(m_bAttacked && m_bMoved)
    {
        painter->setBrush(QColor(0, 0, 0, 100));
        painter->drawRect(m_Fill);
    }
}

void CharacterUnit::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit(RoleIsSelected(this));
    event->accept();
}

void CharacterUnit::setOnMap(QPointF pos, int index_x, int index_y)
{
    setPos(pos);
    m_CoorX = index_x;
    m_CoorY = index_y;
}

void CharacterUnit::MoveTo(MapCell *block)
{
    QPropertyAnimation *moving = new QPropertyAnimation(this, "pos");
    moving->setStartValue(this->pos());
    moving->setEndValue(block->pos());
    moving->setDuration(animation::TIME_PRE_BLOCK * (abs(m_CoorX - block->getCoorX()) + abs(m_CoorY - block->getCoorY())) );
    connect(moving, &QPropertyAnimation::finished, [=](){ delete moving; } );
    moving->start();
    m_CoorX = block->getCoorX();
    m_CoorY = block->getCoorY();
}

void CharacterUnit::damaged(int attackDamage)
{
    int x = pos().x(), y = pos().y();

    QPropertyAnimation *shock = new QPropertyAnimation(this, "opacity");
    shock->setKeyValueAt(0, 1);

    shock->setKeyValueAt(0.1, 1);
    shock->setKeyValueAt(0.11, 0);
    shock->setKeyValueAt(0.24, 0);
    shock->setKeyValueAt(0.25, 1);

    shock->setKeyValueAt(0.4, 1);
    shock->setKeyValueAt(0.41, 0);
    shock->setKeyValueAt(0.54, 0);
    shock->setKeyValueAt(0.55, 1);

    shock->setKeyValueAt(0.7, 1);
    shock->setKeyValueAt(0.71, 0);
    shock->setKeyValueAt(0.84, 0);
    shock->setKeyValueAt(0.85, 1);

    shock->setKeyValueAt(1, 1);
    shock->setDuration(animation::DAMAGED_DELAY);
    shock->start();
    connect(shock, &QPropertyAnimation::finished, [=](){ delete shock; } );
    m_data.damaged(attackDamage);

}

bool CharacterUnit::checkIfDead()
{
    if(m_data.isDead())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int CharacterUnit::getDistance(CharacterUnit* role)
{
    return (abs(m_CoorX - role->getCoorX()) + abs(m_CoorY - role->getCoorY()));
}

void CharacterUnit::Attack(CharacterUnit* target)
{

    emit statusGifRequest(this, "ATTACK");
    waiter(animation::ATTACK_DELAY);
    setAttacked(true);
    printf("attack!");

    target->damaged(this->m_data.getAttackDamage());
    waiter(animation::DAMAGED_DELAY);


    if(target->checkIfDead())
    {
        emit KillRole(target);
    }

}

void CharacterUnit::TurnStartInit()
{
    m_bMoved = false;
    m_bAttacked = false;
}

void CharacterUnit::Iced()
{
    m_bMoved = true;
    m_bAttacked = true;
}

void CharacterUnit::PngUpdate(CharacterUnit* role, QString pic)
{
    if(role == this)
    {
        pixmap->load(pic);
        this->update();
    }
}

void CharacterUnit::GifUpdate(CharacterUnit* role, QPixmap pic)
{
    if(role == this)
    {
        pixmap = new QPixmap(pic);
        this->update();
    }
}
