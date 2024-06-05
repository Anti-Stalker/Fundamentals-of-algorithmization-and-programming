#include "object.h"
#include "QRandomGenerator"


Object::Object(): _field(), _hp(Settings::MAX_HP) {}

Object::~Object(){}

Object::Object(Field *field, Type type) : _type(type), _field(field), _hp(Settings::MAX_HP) {
}

QColor Object::getColor()
{
    if (_type == Type::CELL) {
        return Qt::blue;
    }
    else if (_type == Type::WALL) {
        return Qt::black;
    }
    else if (_type == Type::FOOD) {
        return Qt::green;
    }
    else if (_type == Type::POISON) {
        return Qt::red;
    }
    else {
        return Qt::gray;
    }
}

Type Object::getType()
{
    return _type;
}

void Object::Action() {}

int Object::getHP() {
    return _hp;
}

void Object::setType(const Type &type)
{
    _type = type;
}

void Object::kill()
{
    _hp = 0;
}

Coord &Object::getCoord()
{
    return _cord;
}

void Object::setHP(int value)
{
    _hp = 0;
}

void Object::setCord(Coord &new_cord)
{
    _field->swapObject(_cord, new_cord);
}
