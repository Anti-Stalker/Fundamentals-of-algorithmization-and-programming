#ifndef CARDS_H
#define CARDS_H

#include "constant.h"
#include "maps.h"

class Cards : public Maps {
 public:
  Cards(QPointF point, QString file);
  Cards(QPointF point, QString file, QString skill, int power);
  Cards(QPointF point, QString file, QString skill, int power, QString race, int money, int size, int popylaru);
  void SetActiv(bool new_status);
  bool GetActiv();
  QString GetFile();
  QString GetSkill();
  void SetSkill(QString new_skill);
  int GetPower();
  void UpPower();
  void PowerDown();
  QString GetRace();
  int GetMoney();
  int GetSize();
  int GetPopylaru();

 protected:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;

 private:
  int power, money, size, popylaru;
  QPointF point;
  QString file, skill, race;
  bool isActivited;
};

#endif  // CARDS_H
