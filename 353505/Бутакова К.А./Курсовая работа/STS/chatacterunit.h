#ifndef ROLEUNIT_H
#define ROLEUNIT_H

#include "characterstatus.h"
#include <QGraphicsObject>


class CharacterUnit : public QGraphicsObject{
    Q_OBJECT
private:
    double m_dWidth;
    double m_dHeight;
    QRect m_Fill;
    QPixmap *pixmap;

    RoleUnitData m_data;

    int m_CoorX;
    int m_CoorY;

    bool m_bMoved;
    bool m_bAttacked;

public:
    CharacterUnit(characterStatus::dataPack dp, double width, double height);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void printPos(){ printf("(%d, %d)\n", static_cast<int>(x()), static_cast<int>(y())); }

    int getCoorX(){ return m_CoorX; }
    int getCoorY(){ return m_CoorY; }
    void setOnMap(QPointF pos, int index_x, int index_y);
    void MoveTo(MapCell *block);

    QString getTeam(){ return QString::fromStdString((m_data.getTeam())); }
    QString getClass(){ return QString::fromStdString(m_data.getClass()); }
    int getMaxHP(){ return m_data.getMaxHP(); }
    int getHP(){ return m_data.getHP(); }
    int getATK(){ return m_data.getAttackDamage(); }
    int getAtkRange(){ return m_data.AttackRange(); }
    int getMoveRange(){ return m_data.MoveRange(); }
    int getDistance(CharacterUnit* role);

    bool isMoved(){ return m_bMoved; }
    bool isAttacked(){ return m_bAttacked; }
    void setMoved(bool t){ m_bMoved = t; update();}
    void setAttacked(bool t){ m_bAttacked = t; update(); }

    void damaged(int attackDamage);
    bool checkIfDead();

    void Attack(CharacterUnit* target);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void RoleIsSelected(CharacterUnit*);
    void statusGifRequest(CharacterUnit*, QString);
    void stopGif(CharacterUnit*);
    void KillRole(CharacterUnit*);

public slots:
    void Iced();
    void TurnStartInit();
    void PngUpdate(CharacterUnit* role, QString pic);
    void GifUpdate(CharacterUnit* role, QPixmap pic);

    friend class CombatZone;
};


#endif
