#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QLabel>
#include <QObject>
#include <QPropertyAnimation>
#include <QRandomGenerator>

#include "cards.h"
#include "constant.h"

class gameScene : public QGraphicsScene {
  Q_OBJECT
 public:
  explicit gameScene(QObject* parent = nullptr);
  void Start();
  void AltAction(QString info);
  void Association(int power);
  void AssociationCountry(QString country);
  void AssociationInstitutes(QString institution);
  bool IsVeterenar();
  void ProjestAction(int buttonNumber);
  int HowManyProjects();
  void ProjectsOff();

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
  void wheelEvent(QGraphicsSceneWheelEvent* event);
  void SortCardsZooInHand();
  void ShopEvent();
  void PopylaruEvent();
  void ReburthEvent();
  void Lunch();
  void AnimalsSkills(QString skill);
  void SposorsSkills(QString file);
  QVector<QGraphicsPolygonItem*> Pavilions(int size);

 private:
  int money = 25, howManyUsingCards = 0, howManyCardsCanBuy = 0,
      deleteCards = 4, predators = 0, herbivores = 0, primates = 0,
      reptiles = 0, birds = 0, Africa = 0, America = 0, Australia = 0,
      Europe = 0, Asua = 0, lunchcheck = 0, rotation = 90, howManyCanBuild = 0,
      nowPavSize = 0, howManyKiosks = 1, popylaru = 0, reburth = 0,
      research = 0, howManyFreePavs = 1, howManyCanZacelenie = 0, income,
      incomeFromPopylaru = 5, incomeFromKiosks = 3, equivalentForPopylaru = 112,
      howManyPersonsFree = 3, howManyActiveProjects = 0;
  bool oneOfCardsActive = false, buildNow = false, move = false,
       zacelenie1 = false, zacelenie2 = false, isZagar = false, isUmnui = false,
       isSponsors = false, isZacelenie = false, isVeterenar = false,
       isPrimatolog = false, isOrintolog = false, isTravoad = false,
       isHisniki = false, firstAssociationFree = true,
       secondAssociationFree = true, treeAssociationFree = true,
       institutionForLunch = false, projects = false;
  QVector<QVector<QGraphicsPolygonItem*>> PavsOnBlocks;
  QVector<QGraphicsPolygonItem*> nowPav;
  QVector<QGraphicsPolygonItem*> pav1;
  QVector<QGraphicsPolygonItem*> pav2;
  QVector<QGraphicsPolygonItem*> pav3;
  QVector<QGraphicsPolygonItem*> pav4;
  QVector<QGraphicsPolygonItem*> pav5;
  QVector<QGraphicsPolygonItem*> pavKiosk;
  QVector<QGraphicsPolygonItem*> voler;
  QVector<QGraphicsPolygonItem*> pavForZacelenie;
  QPointF firstPointPav;
  QPointF firstPersonPoint;
  QPointF secondPersonPoint;
  QPointF treePersonPoint;
  QVector<QGraphicsPolygonItem*> blocks;
  QGraphicsItem* item;
  QGraphicsTextItem* deleteCardsText;
  QGraphicsTextItem* moneyText;
  QGraphicsTextItem* incomeText;
  QGraphicsTextItem* popylaruText;
  QGraphicsTextItem* reburthText;
  QGraphicsTextItem* researchText;
  QGraphicsRectItem* lunchchecker;
  QGraphicsRectItem* firstPerson;
  QGraphicsRectItem* secondPerson;
  QGraphicsRectItem* treePerson;
  Cards* ActiveCard;
  Cards* finalGoal;
  Cards* zacelenieAnimalsa;
  Maps* soviet;
  Maps* lunch;
  Maps* firstPartOfSkrol;
  Maps* secondPartOfSkrol;
  Maps* build;
  QBrush* brush;
  QVector<Cards*> doingCards;
  QVector<Cards*> cardsOfZooInHand;
  QVector<Cards*> cardsOnShop;
  QVector<Cards*> ActiveProjects;
  QVector<QString> cardsOfZooName;
  QVector<QString> cardsOfZooSkill;
  QVector<QString> projectsName;
  QVector<QString> sponsorsName;
  QVector<QString> animalsName;
  QVector<QString> animalsSkill;
  QVector<QString> animalsRace;
  QVector<int> animalsMoney;
  QVector<int> animalsSize;
  QVector<int> animalsPopylaru;

 signals:
  void ButtonSignal(QString info);
  void HideButton();
  void Associations(int power);
  void HideAssociations();
  void NewProject();
  void End(int score);
};

#endif  // GAMESCENE_H
