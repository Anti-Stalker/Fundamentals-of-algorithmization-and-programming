#include "cards.h"

Cards::Cards(QPointF point, QString file)
    : point(point),
      file(std::move(file)),
      isActivited(false),
      skill("-"),
      power(0),
      race("-"),
      money(0),
      size(0),
      popylaru(0) {}

Cards::Cards(QPointF point, QString file, QString skill, int power)
    : point(point),
      file(std::move(file)),
      skill(skill),
      power(power),
      race("-"),
      money(0),
      size(0),
      popylaru(0),
      isActivited(false) {}

Cards::Cards(QPointF point, QString file, QString skill, int power,
             QString race, int money, int size, int popylaru)
    : point(point),
      file(std::move(file)),
      skill(skill),
      power(power),
      race(race),
      money(money),
      size(size),
      popylaru(popylaru),
      isActivited(false) {}

QRectF Cards::boundingRect() const {
  return {point.x(), point.y(), CONSTANT_H::wight, CONSTANT_H::height};
}

void Cards::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget) {
  Q_UNUSED(*option)
  Q_UNUSED(*widget)

  QPixmap card(file);

  painter->drawPixmap(point, card);
}

void Cards::SetActiv(bool new_status) { isActivited = new_status; }

bool Cards::GetActiv() { return isActivited; }

QString Cards::GetFile() { return file; }

QString Cards::GetSkill() { return skill; }

void Cards::SetSkill(QString new_skill) { skill = new_skill; }

int Cards::GetPower() { return power; }

void Cards::UpPower() { ++power; }

void Cards::PowerDown() { power = 1; }

QString Cards::GetRace() { return race; }

int Cards::GetMoney() { return money; }

int Cards::GetSize() { return size; }

int Cards::GetPopylaru() { return popylaru; }
