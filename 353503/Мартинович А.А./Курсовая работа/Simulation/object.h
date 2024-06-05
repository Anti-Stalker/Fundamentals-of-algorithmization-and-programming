#ifndef OBJECT_H
#define OBJECT_H
#include "QColor"
#include "Consts.h"
#include "coord.h"
#include "field.h"
#include "settings.h"

class Field;

class Object
{
public:
    explicit Object();
    ~Object();
    Object(Field *field, Type type);

    virtual QColor getColor();
    virtual Type getType();
    virtual void Action();

    int getHP();
    void setType(const Type &type);
    void kill();
    Coord& getCoord();
    void setHP(int value);

protected:
    int _hp;
    Coord _cord;
    Type _type{Type::VOID};
    Field *_field;

    void setCord(Coord& new_cord);
};

#endif // OBJECT_H
