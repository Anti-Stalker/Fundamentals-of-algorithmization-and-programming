#include "hero.h"

Hero::Hero(QString name, QString image, int health, int mana, Ability* abilities) {
    this->name = name;
    this->image = image;
    this->health = health;
    this->mana = mana;
    this->abilities = abilities;
}

QString Hero::getName() {
    return this->name;
}

QString Hero::getImage() {
    return this->image;
}

int Hero::getHealth() {
    return this->health;
}

int Hero::getMana() {
    return this->mana;
}

Ability* Hero::getAbilities() {
    return this->abilities;
}

void Hero::castSkill(int ind) {

}

void Hero::getDamage(int damage) {
    currentHP -= damage;
}

void Hero::useItem() {

}

void Hero::addGold(int gold) {
    this->currentGold += gold;
}

void Hero::removeGold(int gold) {
    this->currentGold -= gold;
}

int Hero::getGold() {
    return this->currentGold;
}

int Hero::getCurrentHP() {
    return this->currentHP;
}

int Hero::getCurrentMana() {
    return this->currentMana;
}

void Hero::removeMana(int mana) {
    this->currentMana -= mana;
}

void Hero::addMaxHP(int health) {
    this->health += health;
}

void Hero::addHP(int hp) {
    this->currentHP += hp;
}
void Hero::addMaxMana(int mana) {
    this->mana += mana;
}
void Hero::addMana(int mana) {
    this->currentMana += mana;
}

void Hero::setCurrentHP(int hp) {
    this->currentHP = hp;
}

void Hero::setCurrentMana(int mana) {
    this->currentMana = mana;
}

int Hero::getIsSilenced() {
    return this->isSilenced;
}

int Hero::getIsStanned() {
    return this->isStanned;
}

int Hero::getIsPeriodic() {
    return this->isPeriodic;
}
int Hero::getPeriodicDamage() {
    return this->periodicDamage;
}


void Hero::setSilence(int silence) {
    this->isSilenced = silence;
}

void Hero::setStanned(int stanned) {
    this->isStanned = stanned;
}

void Hero::setPeriodic(int per) {
    this->isPeriodic = per;
}

void Hero::addPeriodicDamage(int perDam) {
    if (perDam > this->periodicDamage) {
        this->periodicDamage = perDam;
    }
}

void Hero::setPeriodicDamage(int pd) {
    this->periodicDamage = pd;
}

void Hero::decreasePeriodic() {
    this->isPeriodic--;
    if (!isPeriodic) {
        this->periodicDamage = 0;
    }
}

void Hero::turnLinked() {
    this->linked = true;
}
void Hero::offLinked() {
    this->linked = false;
}

void Hero::useKaya() {
    for (int i = 0; i < 3; i++) {
        abilities[i].damage += abilities[i].damage*0.15;
    }
}
