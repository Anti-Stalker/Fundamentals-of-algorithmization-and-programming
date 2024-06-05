#include "gamescene.h"

constexpr int displacementForPrety = 50;
constexpr int sideLength = 50;
constexpr int rows = 5;
constexpr int cols = 10;
constexpr int hex = 6;
constexpr int Pi_6 = 60;
constexpr int Pi_2 = 180;
constexpr int size_blocks = 100;

gameScene::gameScene(QObject *parent) : QGraphicsScene{parent} {
  this->setSceneRect(0, 0, wight, CONSTANT_H::height);

  projectsName.push_back(":/cards/cards/Птицы.png");
  projectsName.push_back(":/cards/cards/Травоядные");
  projectsName.push_back(":/cards/cards/Хищники");
  projectsName.push_back(":/cards/cards/Приматы.png");
  projectsName.push_back(":/cards/cards/Исследования.png");
  projectsName.push_back(":/cards/cards/Австралия.png");
  projectsName.push_back(":/cards/cards/Азия.png");
  projectsName.push_back(":/cards/cards/Америка.png");
  projectsName.push_back(":/cards/cards/Африка.png");
  projectsName.push_back(":/cards/cards/Европа.png");
  sponsorsName.push_back(":/cards/cards/Ветеринар.png");
  sponsorsName.push_back(":/cards/cards/Приматолог.png");
  sponsorsName.push_back(":/cards/cards/Орнитолог.png");
  sponsorsName.push_back(":/cards/cards/Федеральные гранты.png");
  sponsorsName.push_back(":/cards/cards/Эксперт по травоядным.png");
  sponsorsName.push_back(":/cards/cards/Эксперт по хищникам.png");

  for (int y = 0; 16 > y; y++) {
    animalsSkill.push_back("-");
    animalsRace.push_back("-");
    animalsMoney.push_back(0);
    animalsPopylaru.push_back(0);
    animalsSize.push_back(0);
  }

  animalsName.push_back(":/cards/cards/Австралийский динго.png");
  animalsSkill.push_back("Стая");
  animalsRace.push_back("ХищАвс");
  animalsMoney.push_back(13);
  animalsPopylaru.push_back(3);
  animalsSize.push_back(2);
  animalsName.push_back(":/cards/cards/Альпийский козерог.png");
  animalsSkill.push_back("Прыжок2");
  animalsRace.push_back("ТрвЕвр");
  animalsMoney.push_back(10);
  animalsPopylaru.push_back(5);
  animalsSize.push_back(2);
  animalsName.push_back(":/cards/cards/Американский аллигатор.png");
  animalsSkill.push_back("Щелчок1");
  animalsRace.push_back("РепАмр");
  animalsMoney.push_back(18);
  animalsPopylaru.push_back(7);
  animalsSize.push_back(4);
  animalsName.push_back(":/cards/cards/Африканская черепаха.png");
  animalsSkill.push_back("Загар3");
  animalsRace.push_back("РепАфр");
  animalsMoney.push_back(22);
  animalsPopylaru.push_back(6);
  animalsSize.push_back(3);
  animalsName.push_back(":/cards/cards/Большая рея.png");
  animalsSkill.push_back("Быстрый1");
  animalsRace.push_back("ПтцАмр");
  animalsMoney.push_back(12);
  animalsPopylaru.push_back(5);
  animalsSize.push_back(2);
  animalsName.push_back(":/cards/cards/Волк.png");
  animalsSkill.push_back("Стая");
  animalsRace.push_back("ХищЕвр");
  animalsMoney.push_back(12);
  animalsPopylaru.push_back(4);
  animalsSize.push_back(4);
  animalsName.push_back(":/cards/cards/Гепард.png");
  animalsSkill.push_back("Быстрый3");
  animalsRace.push_back("ХищАфр");
  animalsMoney.push_back(17);
  animalsPopylaru.push_back(6);
  animalsSize.push_back(5);
  animalsName.push_back(":/cards/cards/Золотой львиный тамарин.png");
  animalsSkill.push_back("Умный");
  animalsRace.push_back("ПрмАмр");
  animalsMoney.push_back(10);
  animalsPopylaru.push_back(4);
  animalsSize.push_back(1);
  animalsName.push_back(":/cards/cards/Кольцехвостый лемур.png");
  animalsSkill.push_back("Загар3");
  animalsRace.push_back("ПрмАфр");
  animalsMoney.push_back(12);
  animalsPopylaru.push_back(6);
  animalsSize.push_back(3);
  animalsName.push_back(":/cards/cards/Лиса.png");
  animalsSkill.push_back("Умный");
  animalsRace.push_back("ХищАфр");
  animalsMoney.push_back(8);
  animalsPopylaru.push_back(3);
  animalsSize.push_back(1);
  animalsName.push_back(":/cards/cards/Мантовая гереса.png");
  animalsSkill.push_back("Умный");
  animalsRace.push_back("ПрмАфр");
  animalsMoney.push_back(13);
  animalsPopylaru.push_back(6);
  animalsSize.push_back(3);
  animalsName.push_back(":/cards/cards/Новозеландский морской лев.png");
  animalsSkill.push_back("Стая");
  animalsRace.push_back("ХищАвс");
  animalsMoney.push_back(17);
  animalsPopylaru.push_back(6);
  animalsSize.push_back(3);
  animalsName.push_back(":/cards/cards/Очковый лангур.png");
  animalsSkill.push_back("Умный");
  animalsRace.push_back("ПрмАзя");
  animalsMoney.push_back(12);
  animalsPopylaru.push_back(5);
  animalsSize.push_back(2);
  animalsName.push_back(":/cards/cards/Пума.png");
  animalsSkill.push_back("Прыжок3");
  animalsRace.push_back("ХищАмр");
  animalsMoney.push_back(10);
  animalsPopylaru.push_back(5);
  animalsSize.push_back(3);
  animalsName.push_back(":/cards/cards/Серый лангур северных равнин.png");
  animalsSkill.push_back("Прыжок3");
  animalsRace.push_back("ПрмАзя");
  animalsMoney.push_back(13);
  animalsPopylaru.push_back(6);
  animalsSize.push_back(3);
  animalsName.push_back(":/cards/cards/Скальный варан.png");
  animalsSkill.push_back("Загар3");
  animalsRace.push_back("РепАфр");
  animalsMoney.push_back(12);
  animalsPopylaru.push_back(5);
  animalsSize.push_back(2);
  animalsName.push_back(":/cards/cards/Широконосый кайман.png");
  animalsSkill.push_back("Щелчок1");
  animalsRace.push_back("РепАмр");
  animalsMoney.push_back(16);
  animalsPopylaru.push_back(6);
  animalsSize.push_back(4);
  animalsName.push_back(":/cards/cards/Эквадорская белечья обезьяна.png");
  animalsSkill.push_back("Умный");
  animalsRace.push_back("ПрмАмр");
  animalsMoney.push_back(12);
  animalsPopylaru.push_back(5);
  animalsSize.push_back(2);

  cardsOfZooName.append(projectsName);
  cardsOfZooName.append(sponsorsName);
  cardsOfZooName.append(animalsName);
}

void gameScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  QList<QGraphicsItem *> foundItems = this->items(
      QPolygonF()
      << QPointF(event->scenePos().x() + 10, event->scenePos().y() + 10)
      << QPointF(event->scenePos().x() + 10, event->scenePos().y() - 10)
      << QPointF(event->scenePos().x() - 10, event->scenePos().y() + 10)
      << QPointF(event->scenePos().x() - 10, event->scenePos().y() - 10));

  if (!foundItems.isEmpty()) {
    if (!isZagar) emit HideButton();
    item = foundItems[0];
    if (event->button() == Qt::MouseButton::RightButton) {
      this->update();
      return;
    }

    bool isCard = false;

    Cards *card_item = dynamic_cast<Cards *>(item);

    if (card_item == doingCards[0] or card_item == doingCards[1] or
        card_item == doingCards[2] or card_item == doingCards[3] or
        card_item == doingCards[4]) {
      isCard = true;
    }

    if (projects and cardsOfZooInHand.indexOf(card_item) != -1 and
        projectsName.indexOf(card_item->GetFile()) != -1) {
      if (cardsOfZooInHand.indexOf(card_item) <= 4) {
        int size1 =
            cardsOfZooInHand.size() - 1 < 4 ? cardsOfZooInHand.size() - 1 : 4;

        for (int y = cardsOfZooInHand.indexOf(card_item) + 1; size1 >= y; y++) {
          Cards *card = cardsOfZooInHand[y];
          card->moveBy(-150, 0);
        }

        if (cardsOfZooInHand.size() > 5) {
          Cards *card = cardsOfZooInHand[5];
          card->moveBy(600, -240);
        }
      }

      int size2 = cardsOfZooInHand.indexOf(card_item) > 6
                      ? cardsOfZooInHand.indexOf(card_item)
                      : 6;
      for (int y = size2; cardsOfZooInHand.size() > y; y++) {
        Cards *card = cardsOfZooInHand[y];
        card->moveBy(-150, 0);
      }

      cardsOfZooInHand.remove(cardsOfZooInHand.indexOf(card_item));
      howManyUsingCards--;

      if (howManyActiveProjects <= 3) {
        Cards *newProject =
            new Cards(QPointF(500 + 150 * howManyActiveProjects, -125),
                      card_item->GetFile());
        this->addItem(newProject);
        ActiveProjects.push_back(newProject);
        howManyActiveProjects++;
      } else {
        Cards *lastProject = ActiveProjects.last();
        ActiveProjects.remove(2);
        delete lastProject;
        foreach (Cards *proj, ActiveProjects) {
          proj->moveBy(150, 0);
        }

        Cards *newProject = new Cards(QPointF(500, -125), card_item->GetFile());
        this->addItem(newProject);
        ActiveProjects.push_back(newProject);
        emit NewProject();
      }
      delete card_item;
      projects = false;
      SortCardsZooInHand();
      emit HideAssociations();
    }

    if (!zacelenie1 and deleteCards != 0 and !cardsOfZooInHand.isEmpty() and
        howManyCardsCanBuy == 0) {
      if (cardsOfZooInHand.indexOf(card_item) != -1) {
        if (cardsOfZooInHand.indexOf(card_item) <= 4) {
          int size1 =
              cardsOfZooInHand.size() - 1 < 4 ? cardsOfZooInHand.size() - 1 : 4;

          for (int y = cardsOfZooInHand.indexOf(card_item) + 1; size1 >= y;
               y++) {
            Cards *card = cardsOfZooInHand[y];
            card->moveBy(-150, 0);
          }

          if (cardsOfZooInHand.size() > 5) {
            Cards *card = cardsOfZooInHand[5];
            card->moveBy(600, -240);
          }
        }

        int size2 = cardsOfZooInHand.indexOf(card_item) > 6
                        ? cardsOfZooInHand.indexOf(card_item)
                        : 6;
        for (int y = size2; cardsOfZooInHand.size() > y; y++) {
          Cards *card = cardsOfZooInHand[y];
          card->moveBy(-150, 0);
        }

        QString race = card_item->GetRace();

        QString race1 = race;
        QString race2 = race.remove(0, 3);
        race1 = race1.remove(3, 3);

        if (race1 == "Хищ")
          --predators;
        else if (race1 == "Трв")
          --herbivores;
        else if (race1 == "Прм")
          --primates;
        else if (race1 == "Реп")
          --reptiles;
        else if (race1 == "Птц")
          --birds;

        if (race2 == "Амр")
          --America;
        else if (race2 == "Авс")
          --Australia;
        else if (race2 == "Афр")
          --Africa;
        else if (race2 == "Азя")
          --Asua;
        else if (race2 == "Евр")
          --Europe;

        howManyUsingCards--;
        cardsOfZooInHand.remove(cardsOfZooInHand.indexOf(card_item));
        delete card_item;
        --deleteCards;
        if (deleteCards != 1 and deleteCards != 0)
          deleteCardsText->setPlainText(
              "Вам надо удалить " + QString::number(deleteCards) + " карты");
        else if (deleteCards == 1)
          deleteCardsText->setPlainText(
              "Вам надо удалить " + QString::number(deleteCards) + " картy");

        if (isZagar) {
          money += 4;
          moneyText->setPlainText(QString::number(money));
          if (deleteCards == 0) {
            emit HideButton();
            isZagar = false;
          }
        }

        if (howManyUsingCards == 0) {
          deleteCards = 0;
        }
        if (deleteCards == 0) {
          deleteCardsText->hide();
        }
      }
      return;
    }

    if (isCard) {
      if (isUmnui) {
        ActiveCard = card_item;
        SortCardsZooInHand();
        isUmnui = false;
        return;
      }

      else if (!card_item->GetActiv() and !oneOfCardsActive) {
        item->setPos(item->pos() + QPointF(0, displacementForPrety));
        item->update();
        this->update(QRectF(0, 0, this->width(), this->height()));
        card_item->SetActiv(true);
        oneOfCardsActive = true;
        ActiveCard = card_item;
      }

      else if (card_item->GetActiv()) {
        item->setPos(item->pos() - QPointF(0, displacementForPrety));
        item->update();
        this->update(QRectF(0, 0, this->width(), this->height()));
        card_item->SetActiv(false);
        oneOfCardsActive = false;
        if (ActiveCard->GetSkill() == "Ассоциации") {
          emit HideAssociations();
          projects = false;
        }
        if (ActiveCard->GetSkill() == "Карты") {
          howManyCardsCanBuy = 0;
          if (zacelenie1 and !zacelenie2 and
              animalsSkill.indexOf(card_item->GetSkill()) != -1 and
              howManyFreePavs > 0) {
            zacelenieAnimalsa = card_item;
            zacelenie2 = true;
            return;
          }
          deleteCards = 0;
          deleteCardsText->hide();
        }
      }
    }

    if (isSponsors and cardsOfZooInHand.indexOf(card_item) != -1 and
        sponsorsName.indexOf(card_item->GetFile()) != -1 and
        ActiveCard->GetPower() >= card_item->GetPower()) {
      SposorsSkills(card_item->GetFile());
      isSponsors = false;
      SortCardsZooInHand();

      if (cardsOfZooInHand.indexOf(card_item) <= 4) {
        int size1 =
            cardsOfZooInHand.size() - 1 < 4 ? cardsOfZooInHand.size() - 1 : 4;

        for (int y = cardsOfZooInHand.indexOf(card_item) + 1; size1 >= y; y++) {
          Cards *card = cardsOfZooInHand[y];
          card->moveBy(-150, 0);
        }

        if (cardsOfZooInHand.size() > 5) {
          Cards *card = cardsOfZooInHand[5];
          card->moveBy(600, -240);
        }
      }

      int size2 = cardsOfZooInHand.indexOf(card_item) > 6
                      ? cardsOfZooInHand.indexOf(card_item)
                      : 6;
      for (int y = size2; cardsOfZooInHand.size() > y; y++) {
        Cards *card = cardsOfZooInHand[y];
        card->moveBy(-150, 0);
      }

      cardsOfZooInHand.remove(cardsOfZooInHand.indexOf(card_item));
      delete card_item;
    }

    QGraphicsPolygonItem *pol = dynamic_cast<QGraphicsPolygonItem *>(item);

    foreach (QGraphicsPolygonItem *block, blocks) {
      if (pol == block) return;
    }

    if (zacelenie1 and zacelenie2) {
      foreach (QVector<QGraphicsPolygonItem *> Pav, PavsOnBlocks) {
        foreach (QGraphicsPolygonItem *poligon, Pav) {
          if (pol == poligon) {
            isZacelenie = true;
            pavForZacelenie = Pav;
          }
        }
      }
    }

    if (isZacelenie and zacelenieAnimalsa->GetMoney() <= money and
        zacelenieAnimalsa->GetSize() <= pavForZacelenie.size()) {
      this->removeItem(zacelenieAnimalsa);

      if (cardsOfZooInHand.indexOf(zacelenieAnimalsa) <= 4) {
        int size1 =
            cardsOfZooInHand.size() - 1 < 4 ? cardsOfZooInHand.size() - 1 : 4;

        for (int y = cardsOfZooInHand.indexOf(zacelenieAnimalsa) + 1;
             size1 >= y; y++) {
          Cards *card = cardsOfZooInHand[y];
          card->moveBy(-150, 0);
        }

        if (cardsOfZooInHand.size() > 5) {
          Cards *card = cardsOfZooInHand[5];
          card->moveBy(600, -240);
        }
      }

      int size2 = cardsOfZooInHand.indexOf(zacelenieAnimalsa) > 6
                      ? cardsOfZooInHand.indexOf(card_item)
                      : 6;
      for (int y = size2; cardsOfZooInHand.size() > y; y++) {
        Cards *card = cardsOfZooInHand[y];
        card->moveBy(-150, 0);
      }

      QPixmap map(zacelenieAnimalsa->GetFile());

      foreach (QGraphicsPolygonItem *pol, pavForZacelenie) {
        pol->setBrush(map);
      }

      money -= zacelenieAnimalsa->GetMoney();
      moneyText->setPlainText(QString::number(money));

      popylaru += zacelenieAnimalsa->GetPopylaru();
      popylaruText->setPlainText(QString::number(popylaru));
      PopylaruEvent();

      PavsOnBlocks.remove(PavsOnBlocks.indexOf(pavForZacelenie));
      cardsOfZooInHand.remove(cardsOfZooInHand.indexOf(zacelenieAnimalsa));
      howManyFreePavs--;
      howManyCanZacelenie--;
      howManyUsingCards--;
      if (howManyCanZacelenie == 0 or howManyFreePavs == 0) {
        SortCardsZooInHand();
        zacelenie1 = false;
      }

      if(oneOfCardsActive) emit ButtonSignal("Без действ.");

      zacelenie2 = false;
      isZacelenie = false;

      AnimalsSkills(zacelenieAnimalsa->GetSkill());

      QString race = zacelenieAnimalsa->GetRace();

      QString race1 = race;
      race1 = race1.remove(3, 3);

      if (race1 == "Хищ") {
        if (isHisniki) {
          money += 3;
          moneyText->setPlainText(QString::number(money));
        }
      }

      else if (race1 == "Трв") {
        if (isTravoad) {
          money += 3;
          moneyText->setPlainText(QString::number(money));
        }
      }

      else if (race1 == "Прм") {
        if (isPrimatolog) {
          money += 3;
          moneyText->setPlainText(QString::number(money));
        }
      }

      else if (race1 == "Птц") {
        if (isOrintolog) {
          money += 3;
          moneyText->setPlainText(QString::number(money));
        }
      }

      this->update();
      delete zacelenieAnimalsa;
    }

    if (zacelenie1 and cardsOfZooInHand.indexOf(card_item) != -1 and
        card_item->GetRace() != "-" and howManyFreePavs > 0) {
      zacelenieAnimalsa = card_item;
      zacelenie2 = true;
      return;
    }

    if (buildNow and
        (pol == pav1[0] or pol == pav2[0] or pol == pav3[0] or pol == pav4[0] or
         pol == pav5[0] or pol == pavKiosk[0] or pol == voler[0])) {
      if (pol == pav1[0]) {
        nowPav = pav1;
        nowPavSize = 1;
      } else if (pol == pav2[0]) {
        nowPav = pav2;
        nowPavSize = 2;
      } else if (pol == pav3[0]) {
        nowPav = pav3;
        nowPavSize = 3;
      } else if (pol == pav4[0]) {
        nowPav = pav4;
        nowPavSize = 4;
      } else if (pol == pav5[0]) {
        nowPav = pav5;
        nowPavSize = 5;
      } else if (pol == pavKiosk[0]) {
        nowPav = pavKiosk;
        nowPavSize = 1;
      } else if (pol == voler[0]) {
        nowPav = voler;
        nowPavSize = 1;
      }
      QGraphicsPolygonItem *centerPol = nowPav[0];
      firstPointPav = centerPol->scenePos();
      this->update();
      move = true;
      return;
    }

    if (!move and ActiveCard->GetSkill() == "Строительство") {
      if (!buildNow and oneOfCardsActive) {
        this->addItem(build);
        if (ActiveCard->GetPower() >= 1 and money >= 2) {
          foreach (QGraphicsPolygonItem *pol, pav1) {
            this->addItem(pol);
            this->update();
          }
          foreach (QGraphicsPolygonItem *pol, pavKiosk) {
            this->addItem(pol);
            this->update();
          }
          foreach (QGraphicsPolygonItem *pol, voler) {
            this->addItem(pol);
            this->update();
          }
        }
        if (ActiveCard->GetPower() >= 2 and money >= 4) {
          foreach (QGraphicsPolygonItem *pol, pav2) {
            this->addItem(pol);
            this->update();
          }
        }
        if (ActiveCard->GetPower() >= 3 and money >= 6) {
          foreach (QGraphicsPolygonItem *pol, pav3) {
            this->addItem(pol);
            this->update();
          }
        }
        if (ActiveCard->GetPower() >= 4 and money >= 8) {
          foreach (QGraphicsPolygonItem *pol, pav4) {
            this->addItem(pol);
            this->update();
          }
        }
        if (ActiveCard->GetPower() >= 5 and money >= 10) {
          foreach (QGraphicsPolygonItem *pol, pav5) {
            this->addItem(pol);
            this->update();
          }
        }

        buildNow = true;
        howManyCanBuild = 1;
        this->update();

      } else if (!oneOfCardsActive) {
        this->removeItem(build);
        if (ActiveCard->GetPower() >= 1) {
          foreach (QGraphicsPolygonItem *pol, pav1) {
            this->removeItem(pol);
            this->update();
          }
          foreach (QGraphicsPolygonItem *pol, pavKiosk) {
            this->removeItem(pol);
            this->update();
          }
          foreach (QGraphicsPolygonItem *pol, voler) {
            this->removeItem(pol);
            this->update();
          }
        }
        if (ActiveCard->GetPower() >= 2) {
          foreach (QGraphicsPolygonItem *pol, pav2) {
            this->removeItem(pol);
            this->update();
          }
        }
        if (ActiveCard->GetPower() >= 3) {
          foreach (QGraphicsPolygonItem *pol, pav3) {
            this->removeItem(pol);
            this->update();
          }
        }
        if (ActiveCard->GetPower() >= 4) {
          foreach (QGraphicsPolygonItem *pol, pav4) {
            this->removeItem(pol);
            this->update();
          }
        }
        if (ActiveCard->GetPower() >= 5) {
          foreach (QGraphicsPolygonItem *pol, pav5) {
            this->removeItem(pol);
            this->update();
          }
        }
        buildNow = false;
        move = false;
        this->update();
      }
    }

    if (oneOfCardsActive and ActiveCard->GetSkill() == "Карты" and
        howManyCardsCanBuy == 0 and deleteCards == 0) {
      if (ActiveCard->GetPower() == 1 or ActiveCard->GetPower() == 2) {
        howManyCardsCanBuy = 1;
      } else if (ActiveCard->GetPower() == 3 or ActiveCard->GetPower() == 4) {
        howManyCardsCanBuy = 2;
      } else if (ActiveCard->GetPower() == 5) {
        howManyCardsCanBuy = 3;
      }

      if (ActiveCard->GetPower() == 1 or ActiveCard->GetPower() == 3 or
          ActiveCard->GetPower() == 5) {
        ++deleteCards;
        deleteCardsText->setPlainText("Вам нужно будет удалить 1 карту");
        deleteCardsText->show();
      }
    }

    if (howManyCardsCanBuy != 0) {
      int steps = howManyUsingCards;

      if (cardsOnShop.indexOf(card_item) != -1) {
        cardsOnShop.remove(cardsOnShop.indexOf(card_item));
        int secondFloor = 0;
        if (howManyUsingCards >= 5) {
          secondFloor = 240;
          steps -= 5;
        }
        Cards *new_card =
            new Cards(QPointF(200 + 150 * steps, 200 + secondFloor),
                      card_item->GetFile(), card_item->GetSkill(), 0,
                      card_item->GetRace(), card_item->GetMoney(),
                      card_item->GetSize(), card_item->GetPopylaru());

        cardsOfZooInHand.push_back(new_card);
        this->addItem(new_card);

        steps++;
        howManyUsingCards++;
        howManyCardsCanBuy--;
        delete card_item;

        QString race = new_card->GetRace();

        QString race1 = race;
        QString race2 = race.remove(0, 3);
        race1 = race1.remove(3, 3);

        if (race1 == "Хищ")
          ++predators;
        else if (race1 == "Трв")
          ++herbivores;
        else if (race1 == "Прм")
          ++primates;
        else if (race1 == "Реп")
          ++reptiles;
        else if (race1 == "Птц")
          ++birds;

        if (race2 == "Амр")
          ++America;
        else if (race2 == "Авс")
          ++Australia;
        else if (race2 == "Афр")
          ++Africa;
        else if (race2 == "Азя")
          ++Asua;
        else if (race2 == "Евр")
          ++Europe;

        if (howManyCardsCanBuy == 0) {
          ShopEvent();
        }
      }
      return;
    }

    if (ActiveCard->GetSkill() == "Животные" and ActiveCard->GetPower() > 1 and
        howManyFreePavs > 0) {
      if (oneOfCardsActive) {
        zacelenie1 = true;
        howManyCanZacelenie++;
        if (ActiveCard->GetPower() >= 5) howManyCanZacelenie++;
      }
      if (!oneOfCardsActive) {
        zacelenie1 = false;
        howManyCanZacelenie = 0;
      }
    }

    if (oneOfCardsActive and ActiveCard->GetSkill() == "Спонсоры") {
      emit ButtonSignal("Альт.Действ.");
      isSponsors = true;
    }

    if (oneOfCardsActive and ActiveCard->GetSkill() == "Ассоциации") {
      Associations(ActiveCard->GetPower());
      if (ActiveCard->GetPower() == (5 - isVeterenar)) {
        projects = true;
      }
    }
  }
}

void gameScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  if (move) {
    foreach (QGraphicsPolygonItem *pol, nowPav) {
      pol->setPos(event->scenePos() -
                  QPointF(pol->boundingRect().width() / 2,
                          pol->boundingRect().height() / 2));
    }
    this->update();
  }
}

void gameScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  if (move and buildNow) {
    move = false;
    int howManyCollisoin = 0;
    double lens;
    QVector<QGraphicsPolygonItem *> CollisoinBlocks;

    foreach (QGraphicsPolygonItem *block, blocks) {
      lens = sqrt(
          pow((block->boundingRect().center().x() - event->scenePos().x()), 2) +
          pow(block->boundingRect().center().y() - event->scenePos().y(), 2));

      if (lens < 10) {
        howManyCollisoin++;
        CollisoinBlocks.push_back(block);
        break;
      }
    }

    foreach (QGraphicsPolygonItem *pol, nowPav) {
      foreach (QGraphicsPolygonItem *block, blocks) {
        QPointF point = pol->sceneBoundingRect().center();
        lens = sqrt(pow((block->boundingRect().center().x() - point.x()), 2) +
                    pow(block->boundingRect().center().y() - point.y(), 2));

        if (lens < 10 and CollisoinBlocks.indexOf(block) == -1) {
          howManyCollisoin++;
          CollisoinBlocks.push_back(block);
          break;
        }
      }
    }
    if (howManyCollisoin != nowPavSize) {
      foreach (QGraphicsPolygonItem *pol, nowPav) {
        pol->setPos(firstPointPav);
        this->update();
      }

    } else {
      buildNow = false;
      this->removeItem(build);
      this->update();
      if (ActiveCard->GetPower() >= 1 and nowPav != pav1 and money >= 2) {
        foreach (QGraphicsPolygonItem *pol, pav1) {
          this->removeItem(pol);
          this->update();
        }
      }
      if (ActiveCard->GetPower() >= 1 and nowPav != pavKiosk and money >= 2) {
        foreach (QGraphicsPolygonItem *pol, pavKiosk) {
          this->removeItem(pol);
          this->update();
        }
      }
      if (ActiveCard->GetPower() >= 1 and nowPav != voler and money >= 2) {
        foreach (QGraphicsPolygonItem *pol, voler) {
          this->removeItem(pol);
          this->update();
        }
      }
      if (ActiveCard->GetPower() >= 2 and nowPav != pav2 and money >= 4) {
        foreach (QGraphicsPolygonItem *pol, pav2) {
          this->removeItem(pol);
          this->update();
        }
      }
      if (ActiveCard->GetPower() >= 3 and nowPav != pav3 and money >= 6) {
        foreach (QGraphicsPolygonItem *pol, pav3) {
          this->removeItem(pol);
          this->update();
        }
      }
      if (ActiveCard->GetPower() >= 4 and nowPav != pav4 and money >= 8) {
        foreach (QGraphicsPolygonItem *pol, pav4) {
          this->removeItem(pol);
          this->update();
        }
      }
      if (ActiveCard->GetPower() >= 5 and nowPav != pav5 and money >= 10) {
        foreach (QGraphicsPolygonItem *pol, pav5) {
          this->removeItem(pol);
          this->update();
        }
      }
      SortCardsZooInHand();
      money -= nowPavSize * 2;
      moneyText->setPlainText(QString::number(money));
      QGraphicsPolygonItem *centerBlock = CollisoinBlocks[0];
      foreach (QGraphicsPolygonItem *pol, nowPav) {
        pol->setPos(
            centerBlock->sceneBoundingRect().center() -
            QPointF(centerBlock->sceneBoundingRect().width() / 2.,
                    centerBlock->sceneBoundingRect().height() / 2. + 3));
      }

      if (nowPav != pavKiosk and nowPav != voler) {
        PavsOnBlocks.push_back(nowPav);
        howManyFreePavs++;
      } else if (nowPav == voler) {
        popylaru++;
        popylaruText->setPlainText(QString::number(popylaru));
        PopylaruEvent();
      } else {
        howManyKiosks++;
        incomeFromKiosks += 3;
        income = incomeFromKiosks + incomeFromPopylaru;
        incomeText->setPlainText(QString::number(income));
      }
      QGraphicsPolygonItem *centerPol = nowPav[0];
      QGraphicsPolygonItem *kiosk = pavKiosk[0];
      QGraphicsPolygonItem *vol = voler[0];
      QBrush brush = centerPol->brush();

      nowPav = Pavilions(nowPavSize);

      foreach (QGraphicsPolygonItem *pol, nowPav) {
        pol->setPos(firstPointPav);
        pol->setBrush(brush);
        this->update();
      }

      if (centerPol->brush() == kiosk->brush()) {
        pavKiosk = nowPav;
      } else if (centerPol->brush() == vol->brush()) {
        voler = nowPav;
      } else if (nowPavSize == 1) {
        pav1 = nowPav;
      } else if (nowPavSize == 2) {
        pav2 = nowPav;
      } else if (nowPavSize == 3) {
        pav3 = nowPav;
      } else if (nowPavSize == 4) {
        pav4 = nowPav;
      } else if (nowPavSize == 5) {
        pav5 = nowPav;
      }
      foreach (QGraphicsPolygonItem *block, CollisoinBlocks) {
        this->removeItem(block);
        blocks.remove(blocks.indexOf(block));
        this->update();
      }
    }
  }
}

void gameScene::wheelEvent(QGraphicsSceneWheelEvent *event) {
  if (buildNow) {
    if (event->delta() > 0) {
      rotation -= 60;
    } else {
      rotation += 60;
    }

    QGraphicsPolygonItem *kiosk = pavKiosk[0];
    QGraphicsPolygonItem *vol = voler[0];
    QGraphicsPolygonItem *center = nowPav[0];
    QBrush br = center->brush();
    QBrush brKiosk = kiosk->brush();
    QBrush brVol = vol->brush();

    QPointF centerPoint = center->sceneBoundingRect().center();

    int PavSize = nowPav.size();

    QVector<QGraphicsPolygonItem *> newNowPav = Pavilions(nowPav.size());

    foreach (QGraphicsPolygonItem *pol, nowPav) {
      delete pol;
    }

    nowPav = newNowPav;

    QGraphicsPolygonItem *centerPol = nowPav[0];
    foreach (QGraphicsPolygonItem *pol, nowPav) {
      pol->setPos(centerPoint - centerPol->boundingRect().center());
      pol->setBrush(br);
      this->addItem(pol);
    }

    if (br == brKiosk) {
      pavKiosk = nowPav;
    } else if (br == brVol) {
      voler = nowPav;
    } else if (PavSize == 1) {
      pav1 = nowPav;
    } else if (PavSize == 2) {
      pav2 = nowPav;
    } else if (PavSize == 3) {
      pav3 = nowPav;
    } else if (PavSize == 4) {
      pav4 = nowPav;
    } else if (PavSize == 5) {
      pav5 = nowPav;
    }
    this->update();
  }
}

void gameScene::SortCardsZooInHand() {
  if (oneOfCardsActive) {
    ActiveCard->setPos(ActiveCard->pos() - QPointF(0, displacementForPrety));
    oneOfCardsActive = false;
  }
  foreach (Cards *card, doingCards) {
    if (card != ActiveCard and card->GetPower() < ActiveCard->GetPower()) {
      card->UpPower();
      card->setPos(card->pos() + QPointF(150, 0));
    }
  }

  ActiveCard->moveBy(-150 * (ActiveCard->GetPower() - 1), 0);
  ActiveCard->PowerDown();
  ActiveCard->SetActiv(false);
}

void gameScene::ShopEvent() {
  bool isLunch = false;
  if (ActiveCard->GetSkill() == "Карты") {
    SortCardsZooInHand();
    if (lunchcheck + 2 < 8) {
      lunchcheck += 2;
      lunchchecker->moveBy(0, -145);
    } else {
      lunchchecker->moveBy(0, 145 * lunchcheck / 2.);
      lunchcheck = 0;
      isLunch = true;
    }
  }

  if (!cardsOnShop.isEmpty()) {
    if (cardsOnShop.size() == 1) {
      Cards *old_card = cardsOnShop[0];
      cardsOnShop.remove(cardsOnShop.indexOf(old_card));
      Cards *card1 = new Cards(QPointF(-650, -400), old_card->GetFile(),
                               old_card->GetSkill(), 0, old_card->GetRace(),
                               old_card->GetMoney(), old_card->GetSize(),
                               old_card->GetPopylaru());
      cardsOnShop.push_front(card1);

      delete old_card;

      this->addItem(card1);

    } else if (cardsOnShop.size() == 2) {
      Cards *old_card1 = cardsOnShop[0];
      cardsOnShop.remove(cardsOnShop.indexOf(old_card1));
      Cards *card1 = new Cards(QPointF(-500, -400), old_card1->GetFile(),
                               old_card1->GetSkill(), 0, old_card1->GetRace(),
                               old_card1->GetMoney(), old_card1->GetSize(),
                               old_card1->GetPopylaru());
      cardsOnShop.push_front(card1);

      Cards *old_card2 = cardsOnShop[1];
      cardsOnShop.remove(cardsOnShop.indexOf(old_card2));
      Cards *card2 = new Cards(QPointF(-650, -400), old_card2->GetFile(),
                               old_card2->GetSkill(), 0, old_card2->GetRace(),
                               old_card2->GetMoney(), old_card2->GetSize(),
                               old_card2->GetPopylaru());
      cardsOnShop.push_back(card2);

      delete old_card1;
      delete old_card2;

      this->addItem(card1);
      this->addItem(card2);
    }
  }

  for (int y = 150; cardsOnShop.size() < 3; y += 150) {
    Cards *shopCard = new Cards(QPointF(-200 - y, -400), cardsOfZooName.last(),
                                animalsSkill.last(), 0, animalsRace.last(),
                                animalsMoney.last(), animalsSize.last(),
                                animalsPopylaru.last());
    cardsOnShop.push_front(shopCard);
    cardsOfZooName.pop_back();
    animalsSkill.pop_back();
    animalsRace.pop_back();
    animalsMoney.pop_back();
    animalsSize.pop_back();
    animalsPopylaru.pop_back();
    this->addItem(shopCard);
  }

  if (isLunch) {
    Lunch();
  }
}

void gameScene::PopylaruEvent() {
  if (popylaru <= 4)
    incomeFromPopylaru = popylaru + 5;
  else if (popylaru <= 16)
    incomeFromPopylaru = 9 + (popylaru - 3) / 2;
  else if (popylaru <= 31)
    incomeFromPopylaru = 15 + (popylaru - 14) / 3;
  else if (popylaru <= 55)
    incomeFromPopylaru = 20 + (popylaru - 28) / 4;
  else if (popylaru <= 95)
    incomeFromPopylaru = 26 + (popylaru - 51) / 5;
  else
    incomeFromPopylaru = 34 + (popylaru - 90) / 6;
  income = incomeFromKiosks + incomeFromPopylaru;
  incomeText->setPlainText(QString::number(income));
  this->update();
  if(popylaru>equivalentForPopylaru) {
    if(finalGoal->GetFile()==":/cards/cards/Исследовательский зоопарк.png"){
      if(research>=3) {
        reburth++;
      }
      if(research>=4){
        reburth++;
      }
      if(research>=5){
        reburth++;
      }
      if(research>=6){
        reburth++;
      }
      ReburthEvent();
    }
    else if(finalGoal->GetFile()==":/cards/cards/Природоохранный зоопарк.png"){
      if(howManyActiveProjects>=1){
        reburth++;
      }
      if(howManyActiveProjects>=2){
        reburth++;
      }
      if(howManyActiveProjects==3){
        reburth++;
      }
      ReburthEvent();
    }
    else{
      if(blocks.size()>=6){
        reburth++;
      }
      if(blocks.size()>=12){
        reburth++;
      }
      if(blocks.size()>=18){
        reburth++;
      }
      if(blocks.size()>=24){
        reburth++;
      }
      ReburthEvent();
    }
    emit End(popylaru-equivalentForPopylaru);
  }
}

void gameScene::ReburthEvent()
{
  if(reburth<=10) equivalentForPopylaru = 112 - reburth*2;
  else equivalentForPopylaru = 94 - 3*(reburth-10);  if(popylaru>equivalentForPopylaru) {
    if(finalGoal->GetFile()==":/cards/cards/Исследовательский зоопарк.png"){
      if(research>=3) {
        reburth++;
      }
      if(research>=4){
        reburth++;
      }
      if(research>=5){
        reburth++;
      }
      if(research>=6){
        reburth++;
      }
      ReburthEvent();
    }
    else if(finalGoal->GetFile()==":/cards/cards/Природоохранный зоопарк.png"){
      if(howManyActiveProjects>=1){
        reburth++;
      }
      if(howManyActiveProjects>=2){
        reburth++;
      }
      if(howManyActiveProjects==3){
        reburth++;
      }
      ReburthEvent();
    }
    else{
      if(blocks.size()>=6){
        reburth++;
      }
      if(blocks.size()>=12){
        reburth++;
      }
      if(blocks.size()>=18){
        reburth++;
      }
      if(blocks.size()>=24){
        reburth++;
      }
      ReburthEvent();
    }
    emit End(popylaru-equivalentForPopylaru);
  }
}

void gameScene::Lunch() {

  if(zacelenie1){
    zacelenie1 = false;
    SortCardsZooInHand();
  }

  ActiveCard->SetSkill("-");

  deleteCards = howManyUsingCards - 3 - 2 * institutionForLunch;

  if (deleteCards != 1 and deleteCards != 0)
    deleteCardsText->setPlainText("Вам надо удалить " +
                                  QString::number(deleteCards) + " карты");
  else if (deleteCards == 1)
    deleteCardsText->setPlainText("Вам надо удалить " +
                                  QString::number(deleteCards) + " картy");

  deleteCardsText->show();

  firstPerson->setPos(firstPersonPoint);
  secondPerson->setPos(secondPersonPoint);
  treePerson->setPos(treePersonPoint);

  money += income;
  moneyText->setPlainText(QString::number(money));

  Cards *card = cardsOnShop.last();
  cardsOnShop.remove(cardsOnShop.size() - 1);
  delete card;
  ShopEvent();
}

void gameScene::AnimalsSkills(QString skill) {
  if (skill == "Стая") {
    popylaru += predators;
    popylaruText->setPlainText(QString::number(popylaru));
    PopylaruEvent();
    emit HideButton();
  } else if (skill == "Прыжок2") {
    money += 2;
    moneyText->setPlainText(QString::number(money));
    if (lunchcheck + 2 < 8) {
      lunchcheck += 2;
      lunchchecker->moveBy(0, -145);
    } else {
      lunchchecker->moveBy(0, 145 * lunchcheck / 2.);
      lunchcheck = 0;
      Lunch();
    }
    emit HideButton();
  } else if (skill == "Щелчок1") {
    howManyCardsCanBuy++;
    emit ButtonSignal("Без действ.");
  } else if (skill == "Загар3") {
    isZagar = true;
    deleteCards = 3;
    deleteCardsText->setPlainText("Вы можете удалить " +
                                  QString::number(deleteCards) + " карты");
    deleteCardsText->show();
    emit ButtonSignal("Без действ.");
  } else if (skill == "Быстрый1") {
    howManyCardsCanBuy++;
    emit ButtonSignal("Без действ.");
  } else if (skill == "Быстрый3") {
    howManyCardsCanBuy += 3;
    emit ButtonSignal("Без действ.");
  } else if (skill == "Умный") {
    isUmnui = true;
    emit ButtonSignal("Без действ.");
  } else if (skill == "Прыжок3") {
    money += 3;
    moneyText->setPlainText(QString::number(money));
    if (lunchcheck + 3 < 8) {
      lunchcheck += 3;
      lunchchecker->moveBy(0, -145 * 3. / 2);
    } else {
      lunchchecker->moveBy(0, 145 * lunchcheck / 2.);
      lunchcheck = 0;
      Lunch();
    }
    emit HideButton();
  }
}

void gameScene::SposorsSkills(QString file) {
  if (file == ":/cards/cards/Ветеринар.png") {
    isVeterenar = true;
  } else if (file == ":/cards/cards/Приматолог.png") {
    isPrimatolog = true;
  } else if (file == ":/cards/cards/Орнитолог.png") {
    isOrintolog = true;
  } else if (file == ":/cards/cards/Федеральные гранты.png") {
    incomeFromKiosks += 3;
    income = incomeFromKiosks + incomeFromPopylaru;
    incomeText->setPlainText(QString::number(income));
  } else if (file == ":/cards/cards/Эксперт по травоядным.png") {
    isTravoad = true;
  } else if (file == ":/cards/cards/Эксперт по хищникам.png") {
    isHisniki = true;
  }
}

void gameScene::ProjestAction(int buttonNumber) {
  int y = -1;

  if (1 <= buttonNumber <= 3) {
    y = 0;
  } else if (4 <= buttonNumber <= 6) {
    y = 1;
  } else if (7 <= buttonNumber <= 9) {
    y = 2;
  }

  Cards *project = ActiveProjects[y];
  buttonNumber %= 3;
  if (project->GetFile() == ":/cards/cards/Птицы.png") {
    if (buttonNumber == 1 and birds >= 2) {
      reburth += 2;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (buttonNumber == 2 and birds >= 4) {
      reburth += 4;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (birds >= 5) {
      reburth += 5;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    }
  } else if (project->GetFile() == ":/cards/cards/Травоядные") {
    if (buttonNumber == 1 and herbivores >= 2) {
      reburth += 2;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (buttonNumber == 2 and herbivores >= 4) {
      reburth += 4;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (herbivores >= 5) {
      reburth += 5;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    }
  } else if (project->GetFile() == ":/cards/cards/Хищники") {
    if (buttonNumber == 1 and predators >= 2) {
      reburth += 2;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (buttonNumber == 2 and predators >= 4) {
      reburth += 4;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (predators >= 5) {
      reburth += 5;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    }
  } else if (project->GetFile() == ":/cards/cards/Приматы.png") {
    if (buttonNumber == 1 and primates >= 2) {
      reburth += 2;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (buttonNumber == 2 and primates >= 4) {
      reburth += 4;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (primates >= 5) {
      reburth += 5;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    }
  } else if (project->GetFile() == ":/cards/cards/Исследования.png") {
    if (buttonNumber == 1 and research >= 2) {
      reburth += 2;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (buttonNumber == 2 and research >= 4) {
      reburth += 4;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (research >= 5) {
      reburth += 5;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    }
  } else if (project->GetFile() == ":/cards/cards/Австралия.png") {
    if (buttonNumber == 1 and Australia >= 2) {
      reburth += 2;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (buttonNumber == 2 and Australia >= 4) {
      reburth += 4;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (Australia >= 5) {
      reburth += 5;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    }
  } else if (project->GetFile() == ":/cards/cards/Азия.png") {
    if (buttonNumber == 1 and Asua >= 2) {
      reburth += 2;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (buttonNumber == 2 and Asua >= 4) {
      reburth += 4;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (Asua >= 5) {
      reburth += 5;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    }
  } else if (project->GetFile() == ":/cards/cards/Америка.png") {
    if (buttonNumber == 1 and America >= 2) {
      reburth += 2;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (buttonNumber == 2 and America >= 4) {
      reburth += 4;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (America >= 5) {
      reburth += 5;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    }
  } else if (project->GetFile() == ":/cards/cards/Африка.png") {
    if (buttonNumber == 1 and Africa >= 2) {
      reburth += 2;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (buttonNumber == 2 and Africa >= 4) {
      reburth += 4;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (Africa >= 5) {
      reburth += 5;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    }
  } else if (project->GetFile() == ":/cards/cards/Европа.png") {
    if (buttonNumber == 1 and Europe >= 2) {
      reburth += 2;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (buttonNumber == 2 and Europe >= 4) {
      reburth += 4;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    } else if (Europe >= 5) {
      reburth += 5;
      ReburthEvent();
      reburthText->setPlainText(QString::number(reburth) + "(" +
                                QString::number(equivalentForPopylaru) + ")");
      SortCardsZooInHand();
      emit HideAssociations();
    }
  }

if (howManyPersonsFree != 3 and howManyPersonsFree != 2) {
    return;
  }

  if (howManyPersonsFree == 3) {
    treePerson->setPos(1910, -470);
    howManyPersonsFree--;
  } else {
    firstPerson->setPos(1905, -470);
    secondPerson->setPos(1915, -470);
    howManyPersonsFree = 0;
  }
  
}

int gameScene::HowManyProjects() { return howManyActiveProjects; }

void gameScene::ProjectsOff()
{
  projects = false;
}

bool gameScene::IsVeterenar() { return isVeterenar; }

void gameScene::AltAction(QString info) {
  if (info == "Альт.Действ.") {
    if (lunchcheck + ActiveCard->GetPower() < 8) {
      lunchcheck += ActiveCard->GetPower();
      lunchchecker->moveBy(0, -145 * ActiveCard->GetPower() / 2.);
    } else {
      lunchchecker->moveBy(0, 145 * lunchcheck / 2.);
      lunchcheck = 0;
      Lunch();
    }
    money += ActiveCard->GetPower();
    moneyText->setPlainText(QString::number(money));
    SortCardsZooInHand();
  } else if (info == "Без действ.") {
    isZagar = false;
    isUmnui = false;
    howManyCardsCanBuy = 0;
    deleteCards = 0;
    deleteCardsText->hide();
    isZacelenie = false;
    zacelenie1 = false;
    zacelenie2 = false;
    if(oneOfCardsActive and ActiveCard->GetSkill()=="Животные"){
      SortCardsZooInHand();
    }
  }

  emit HideButton();
}

void gameScene::Association(int power) {
  if (power == 2) {
    if (howManyPersonsFree != 3 and howManyPersonsFree != 2) {
      return;
    }
    if (!firstAssociationFree) {
      return;
    }

    firstAssociationFree = false;

    if (howManyPersonsFree == 3) {
      treePerson->setPos(1110, -470);
      howManyPersonsFree--;
    } else {
      firstPerson->setPos(1105, -470);
      secondPerson->setPos(1115, -470);
      howManyPersonsFree = 0;
    }
    popylaru += 2;
    popylaruText->setPlainText(QString::number(popylaru));
    PopylaruEvent();
    emit HideAssociations();
    SortCardsZooInHand();
  }
}

void gameScene::AssociationCountry(QString country) {
  if (howManyPersonsFree != 3 and howManyPersonsFree != 2) {
    return;
  }

  if (!secondAssociationFree) {
    return;
  }

  secondAssociationFree = false;

  if (howManyPersonsFree == 3) {
    treePerson->setPos(1310, -470);
    howManyPersonsFree--;
  } else {
    firstPerson->setPos(1305, -470);
    secondPerson->setPos(1315, -470);
    howManyPersonsFree = 0;
  }

  if (country == "Амр") {
    popylaru += America;
    popylaruText->setPlainText(QString::number(popylaru));
    PopylaruEvent();
  } else if (country == "Афр") {
    popylaru += Africa;
    popylaruText->setPlainText(QString::number(popylaru));
    PopylaruEvent();
  } else if (country == "Авс") {
    popylaru += Australia;
    popylaruText->setPlainText(QString::number(popylaru));
    PopylaruEvent();
  } else if (country == "Азя") {
    popylaru += Asua;
    popylaruText->setPlainText(QString::number(popylaru));
    PopylaruEvent();
  } else {
    popylaru += Europe;
    popylaruText->setPlainText(QString::number(popylaru));
    PopylaruEvent();
  }
  emit HideAssociations();
  SortCardsZooInHand();
}

void gameScene::AssociationInstitutes(QString institution) {
  if (howManyPersonsFree != 3 and howManyPersonsFree != 2) {
    return;
  }

  if (!treeAssociationFree) {
    return;
  }

  treeAssociationFree = false;

  if (howManyPersonsFree == 3) {
    treePerson->setPos(1610, -470);
    howManyPersonsFree--;
  } else {
    firstPerson->setPos(1605, -470);
    secondPerson->setPos(1615, -470);
    howManyPersonsFree = 0;
  }

  if (institution == "Верх") {
    institutionForLunch = true;
    research++;
    researchText->setPlainText(QString::number(research));
  } else if (institution == "Лево") {
    research += 2;
    researchText->setPlainText(QString::number(research));
  } else {
    popylaru += 2;
    popylaruText->setPlainText(QString::number(popylaru));
    PopylaruEvent();
    research++;
    researchText->setPlainText(QString::number(research));
  }
  emit HideAssociations();
  SortCardsZooInHand();
}

QVector<QGraphicsPolygonItem *> gameScene::Pavilions(int size) {
  QVector<QGraphicsPolygonItem *> Pav;
  QPolygonF centerCell;
  for (int i = 0; i < 6; ++i) {
    qreal angle = 2 * M_PI * i / 6 + 55;
    centerCell << QPointF(50 * qCos(angle) + 50, 50 * qSin(angle) + 50);
  }
  QPointF center = centerCell.boundingRect().center();
  QTransform transform;
  transform.translate(center.x(), center.y());
  transform.rotate(rotation - 1);
  transform.translate(-center.x(), -center.y());
  centerCell = transform.map(centerCell);
  QGraphicsPolygonItem *pol = new QGraphicsPolygonItem(centerCell);
  Pav.push_back(pol);

  for (int i = 0; i < size - 1; ++i) {
    qreal angle = 2 * M_PI * i / 6;
    qreal x = 50 + (50 * sqrt(3)) * qCos(angle);
    qreal y = 50 + (50 * sqrt(3)) * qSin(angle);

    QPolygonF cell;
    for (int j = 0; j < 6; ++j) {
      qreal xj = x + 50 * qCos(2 * M_PI * j / 6 + 55);
      qreal yj = y + 50 * qSin(2 * M_PI * j / 6 + 55);
      cell << QPointF(xj, yj);
    }
    QTransform transform;
    transform.translate(center.x(), center.y());
    transform.rotate(rotation - 1);
    transform.translate(-center.x(), -center.y());
    cell = transform.map(cell);
    QGraphicsPolygonItem *pol1 = new QGraphicsPolygonItem(cell);
    Pav.push_back(pol1);
  }

  return Pav;
}

void gameScene::Start() {
  this->clear();

  const QPointF displacementForPrety(700, 100);

  QPen pen(Qt::gray);
  pen.setWidth(4);

  QPixmap *groy = new QPixmap(size_blocks, size_blocks);
  groy->load(":/img/img/Plant.png");
  QBrush brush1(*groy);

  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      double x = col * 3. / 2 * sideLength;
      int y = row * sqrt(3) * sideLength + (col % 2) * sqrt(3) / 2 * sideLength;

      QVector<QPoint> hexPoints;
      for (int i = 0; i < hex; ++i) {
        int angle_deg = Pi_6 * i;
        qreal angle_rad = M_PI / Pi_2 * angle_deg;
        int x_point = x + sideLength * cos(angle_rad);
        int y_point = y + sideLength * sin(angle_rad);
        hexPoints.append(QPoint(x_point - displacementForPrety.x(),
                                y_point - displacementForPrety.y()));
      }

      QPolygon pol;

      for (const auto &point : hexPoints) {
        pol << point;
      }

      QGraphicsPolygonItem *item = new QGraphicsPolygonItem(pol);

      item->setPen(pen);
      blocks.push_back(item);

      item->setBrush(brush1);

      this->addItem(item);
    }
  }

  const int wight_soviet = 780, height_soviet = 310;

  Cards *card1 =
      new Cards(onePowerPoint, ":/img/img/Животные.jpg", "Животные", 1);
  doingCards.push_back(card1);
  Cards *card2 =
      new Cards(twoPowerPoint, ":/img/img/Ассоциации.jpg", "Ассоциации", 2);
  doingCards.push_back(card2);
  Cards *card3 = new Cards(threePowerPoint, ":/img/img/Карты.jpg", "Карты", 3);
  doingCards.push_back(card3);
  Cards *card4 = new Cards(fourPowerPoint, ":/img/img/Строительство.jpg",
                           "Строительство", 4);
  doingCards.push_back(card4);
  Cards *card5 =
      new Cards(fifePowerPoint, ":/img/img/Спонсоры.jpg", "Спонсоры", 5);
  doingCards.push_back(card5);

  Cards *nonCard = new Cards(QPointF(0, 0), "-", "-", 0);

  ActiveCard = nonCard;

  soviet = new Maps(sovietPoint, ":/img/img/Совет Ассоциации.png", wight_soviet,
                    height_soviet);

  lunch = new Maps(QPointF(100, -150), ":/img/img/Отдых.png", 100, 630);

  build = new Maps(QPointF(200, 100), ":/img/img/стройка.jpg", 540, 360);

  QGraphicsTextItem *textMoney = new QGraphicsTextItem("Деньги:");
  textMoney->setPos(-870, 350);

  moneyText = new QGraphicsTextItem(QString::number(money));
  moneyText->setPos(-850, 365);

  QGraphicsTextItem *textIncome = new QGraphicsTextItem("Доход:");
  textIncome->setPos(-870, 380);

  income = incomeFromPopylaru + incomeFromKiosks;

  incomeText = new QGraphicsTextItem(QString::number(income));
  incomeText->setPos(-850, 395);

  QGraphicsTextItem *textPopylaru = new QGraphicsTextItem("Популярность:");
  textPopylaru->setPos(-870, 410);

  popylaruText = new QGraphicsTextItem(QString::number(popylaru));
  popylaruText->setPos(-850, 425);

  QGraphicsTextItem *textReburth = new QGraphicsTextItem("Очки возрождения:");
  textReburth->setPos(-870, 440);

  reburthText =
      new QGraphicsTextItem(QString::number(reburth) + "(" +
                            QString::number(equivalentForPopylaru) + ")");
  reburthText->setPos(-850, 455);

  QGraphicsTextItem *textResearch = new QGraphicsTextItem("Очки исследований:");
  textResearch->setPos(-870, 470);

  researchText = new QGraphicsTextItem(QString::number(research));
  researchText->setPos(-850, 495);

  QGraphicsTextItem *shop = new QGraphicsTextItem("<---Рынок");
  shop->setPos(-200, -320);

  QColor color;
  color = QColor::fromCmyk(0, 30, 61, 17);
  brush = new QBrush(color);

  pav1 = Pavilions(1);
  foreach (QGraphicsPolygonItem *pol, pav1) {
    pol->moveBy(250, 150);
    pol->setBrush(*brush);
  }

  pav2 = Pavilions(2);
  foreach (QGraphicsPolygonItem *pol, pav2) {
    pol->moveBy(450, 150);
    pol->setBrush(*brush);
  }

  pav3 = Pavilions(3);

  foreach (QGraphicsPolygonItem *pol, pav3) {
    pol->moveBy(700, 150);
    pol->setBrush(*brush);
  }

  pav4 = Pavilions(4);

  foreach (QGraphicsPolygonItem *pol, pav4) {
    pol->moveBy(300, 400);
    pol->setBrush(*brush);
  }

  pav5 = Pavilions(5);

  foreach (QGraphicsPolygonItem *pol, pav5) {
    pol->moveBy(600, 400);
    pol->setBrush(*brush);
  }

  pavKiosk = Pavilions(1);

  foreach (QGraphicsPolygonItem *pol, pavKiosk) {
    pol->moveBy(850, 150);
    QPixmap map(":/img/img/Киоск.png");
    QBrush br(map);
    pol->setBrush(br);
  }

  voler = Pavilions(1);

  foreach (QGraphicsPolygonItem *pol, voler) {
    pol->moveBy(850, 400);
    QPixmap map(":/img/img/Павильон.png");
    QBrush br(map);
    pol->setBrush(br);
  }

  this->addItem(card1);
  this->addItem(card2);
  this->addItem(card3);
  this->addItem(card4);
  this->addItem(card5);
  this->addItem(soviet);
  this->addItem(lunch);
  this->addItem(moneyText);
  this->addItem(textMoney);
  this->addItem(incomeText);
  this->addItem(textIncome);
  this->addItem(popylaruText);
  this->addItem(textPopylaru);
  this->addItem(reburthText);
  this->addItem(textReburth);
  this->addItem(researchText);
  this->addItem(textResearch);
  this->addItem(shop);

  firstPerson = new QGraphicsRectItem(-840, 300, 30, 30);
  firstPerson->setBrush(QColor::fromRgb(170, 0, 0));
  firstPersonPoint = firstPerson->pos();
  this->addItem(firstPerson);

  secondPerson = new QGraphicsRectItem(-800, 300, 30, 30);
  secondPerson->setBrush(QColor::fromRgb(170, 0, 0));
  secondPersonPoint = secondPerson->pos();
  this->addItem(secondPerson);

  treePerson = new QGraphicsRectItem(-820, 260, 30, 30);
  treePerson->setBrush(QColor::fromRgb(170, 0, 0));
  treePersonPoint = treePerson->pos();
  this->addItem(treePerson);

  lunchchecker = new QGraphicsRectItem(135, 430, 25, 25);
  lunchchecker->setBrush(Qt::black);
  this->addItem(lunchchecker);

  QRandomGenerator *gen = QRandomGenerator::global();
  int j = gen->bounded(0, 3);

  QString final;

  if (j == 0)
    final = ":/cards/cards/Исследовательский зоопарк.png";
  else if (j == 1)
    final = ":/cards/cards/Природоохранный зоопарк.png";
  else
    final = ":/cards/cards/Зоопарк натуралистов.png";

  finalGoal = new Cards(QPointF(75, -400), final);
  this->addItem(finalGoal);

  for (int i = 0; i < cardsOfZooName.size(); i++) {
    int j = gen->generate64() % (cardsOfZooName.size() - i);
    std::swap(cardsOfZooName[i], cardsOfZooName[j]);
    std::swap(animalsRace[i], animalsRace[j]);
    std::swap(animalsSkill[i], animalsSkill[j]);
    std::swap(animalsMoney[i], animalsMoney[j]);
    std::swap(animalsPopylaru[i], animalsPopylaru[j]);
    std::swap(animalsSize[i], animalsSize[j]);
  }

  for (int y = 150; 450 >= y; y += 150) {
    Cards *shopCard = new Cards(QPointF(-200 - y, -400), cardsOfZooName.last(),
                                animalsSkill.last(), 0, animalsRace.last(),
                                animalsMoney.last(), animalsSize.last(),
                                animalsPopylaru.last());
    cardsOnShop.push_front(shopCard);
    cardsOfZooName.pop_back();
    animalsSkill.pop_back();
    animalsRace.pop_back();
    animalsMoney.pop_back();
    animalsSize.pop_back();
    animalsPopylaru.pop_back();
    this->addItem(shopCard);
  }

  deleteCardsText = new QGraphicsTextItem(
      "Вам надо удалить " + QString::number(deleteCards) + " карты");
  deleteCardsText->setPos(200, 150);
  this->addItem(deleteCardsText);

  int secondFloor = 0;
  int steps = 0;
  for (int y = 0; 8 > y; y++) {
    if (howManyUsingCards >= 5 and steps >= 5) {
      secondFloor = 240;
      steps -= 5;
    }
    Cards *new_card = new Cards(QPointF(200 + 150 * steps, 200 + secondFloor),
                                cardsOfZooName.last(), animalsSkill.last(), 0,
                                animalsRace.last(), animalsMoney.last(),
                                animalsSize.last(), animalsPopylaru.last());
    cardsOfZooName.pop_back();
    animalsSkill.pop_back();
    animalsRace.pop_back();
    animalsMoney.pop_back();
    animalsSize.pop_back();
    animalsPopylaru.pop_back();
    cardsOfZooInHand.push_back(new_card);
    this->addItem(new_card);
    howManyUsingCards++;
    steps++;

    QString race = new_card->GetRace();

    QString race1 = race;
    QString race2 = race.remove(0, 3);

    race1 = race1.remove(3, 3);

    if (race1 == "Хищ")
      ++predators;
    else if (race1 == "Трв")
      ++herbivores;
    else if (race1 == "Прм")
      ++primates;
    else if (race1 == "Реп")
      ++reptiles;
    else if (race1 == "Птц")
      ++birds;

    if (race2 == "Амр")
      ++America;
    else if (race2 == "Авс")
      ++Australia;
    else if (race2 == "Афр")
      ++Africa;
    else if (race2 == "Азя")
      ++Asua;
    else if (race2 == "Евр")
      ++Europe;
  }

  QVector<QGraphicsPolygonItem *> firstPav = Pavilions(3);
  QGraphicsPolygonItem *startBlock = blocks[31];
  foreach (QGraphicsPolygonItem *pol, firstPav) {
    pol->setPos(startBlock->boundingRect().center() -
                QPointF(startBlock->boundingRect().width() / 2,
                        startBlock->boundingRect().height() / 2));
    pol->setBrush(*brush);
    this->addItem(pol);
  }

  double lens;
  QVector<QGraphicsPolygonItem *> CollisoinBlocks;

  foreach (QGraphicsPolygonItem *pol, firstPav) {
    foreach (QGraphicsPolygonItem *block, blocks) {
      QPointF point = pol->sceneBoundingRect().center();
      lens = sqrt(pow((block->boundingRect().center().x() - point.x()), 2) +
                  pow(block->boundingRect().center().y() - point.y(), 2));

      if (lens < 10 and CollisoinBlocks.indexOf(block) == -1) {
        CollisoinBlocks.push_back(block);
        break;
      }
    }
  }

  foreach (QGraphicsPolygonItem *block, CollisoinBlocks) {
    this->removeItem(block);
    blocks.remove(blocks.indexOf(block));
    this->update();
  }

  QVector<QGraphicsPolygonItem *> firstKiosk = Pavilions(1);

  QGraphicsPolygonItem *startBlock1 = blocks[30];

  foreach (QGraphicsPolygonItem *pol, firstKiosk) {
    pol->setPos(startBlock1->boundingRect().center() -
                QPointF(startBlock1->boundingRect().width() / 2,
                        startBlock1->boundingRect().height() / 2));
    QPixmap map(":/img/img/Киоск.png");
    QBrush br(map);
    pol->setBrush(br);
    this->addItem(pol);
  }

  this->removeItem(startBlock1);
  blocks.remove(10);
  this->update();

  PavsOnBlocks.push_back(firstPav);
}
