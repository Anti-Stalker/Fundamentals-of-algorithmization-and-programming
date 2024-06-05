#include "cell.h"
#include "QDebug"

Cell::Cell(Field *field, Coord cord) : _current_gen(0), _rotation(0)
{
    _field = field;
    _cord = cord;
    for (int i = 0; i < Settings::GENOME_SIZE; i++) {
        _genome.push_back(QRandomGenerator::global()->bounded(GEN_COUNT));
    }
}

Cell::Cell(Field *field, Coord cord, QVector<int> &genome) : _current_gen(0), _rotation(0), _genome(genome)
{
    _field = field;
    _cord = cord;
}

void Cell::Mutation()
{
    int number = QRandomGenerator::global()->bounded(_genome.size());
    int gen = QRandomGenerator::global()->bounded(GEN_COUNT);
    _genome[number] = gen;
}

void Cell::Move(Coord dif_cord)
{
    Coord next_cord = dif_cord+_cord;
    MoveCurrentGen(_field->getType(next_cord));

    if (_field->getType(next_cord) != Type::WALL && _field->getType(next_cord) != Type::CELL) {
        if (_field->getType(next_cord) == Type::POISON) {
            _hp = 0;
        }
        else if (_field->getType(next_cord) == Type::FOOD) {
            _field->kill(next_cord);
            _hp += Settings::FOOD_HEAL;
            _field->swapObject(_cord, next_cord);
            _cord = next_cord;
            _field->foodCountMinus();

        }
        else {
            _field->swapObject(_cord, next_cord);
            _cord = next_cord;
        }
    }
}

void Cell::Rotate(int gen)
{
    _rotation = (_rotation + gen) % DIRECT_NUMBER;
    _current_gen = (_current_gen + 1) % Settings::GENOME_SIZE;
}

void Cell::Eat(Coord dif_cord)
{
    Coord next_cord = dif_cord+_cord;
    MoveCurrentGen(_field->getType(next_cord));

    if (_field->getType(next_cord) == Type::FOOD || _field->getType(next_cord) == Type::POISON) {
        if (_field->getType(next_cord) == Type::POISON) {
            _field->setType(next_cord, Type::FOOD);
            _field->poisonCountMinus();
            _field->foodCountPlus();
        }
        else if (_field->getType(next_cord) == Type::FOOD) {
            _field->setType(next_cord, Type::VOID);
            _hp += Settings::FOOD_HEAL;
            _field->foodCountMinus();
        }
    }
}

void Cell::See(Coord dif_cord)
{
    Coord next_cord = dif_cord+_cord;
    MoveCurrentGen(_field->getType(next_cord));
}

void Cell::MoveCurrentGen(int gen)
{
    _current_gen = (_current_gen + gen) % Settings::GENOME_SIZE;
}

void Cell::Action()
{
    if (_hp > Settings::MAX_HP) {
        _hp = Settings::MAX_HP;
    }
    int command = _genome[_current_gen%_genome.size()];
    static int _action_count;

    if (command >= 0 && command < 8) {
        Move(Direction::getDirect(command + _rotation));
    }
    else if (command >= 8 && command < 16) {
        Eat(Direction::getDirect(command + _rotation));
    }
    else if (command >= 16 && command < 24) {
        See(Direction::getDirect(command + _rotation));
        if (_action_count <= MAX_ACTION_COUNT) {
            _action_count++;
           Action();
           return;
        }
    }
    else if (command >= 24 && command < 32) {
        Rotate(command);
        if (_action_count <= MAX_ACTION_COUNT) {
            _action_count++;
           Action();
           return;
        }
    }
    else {
        MoveCurrentGen(command);
        if (_action_count <= MAX_ACTION_COUNT) {
            _action_count++;
           Action();
           return;
        }
    }
    _hp--;
}

void Cell::MoveCurrentGen(Type type)
{
    if (type == Type::CELL) {
        _current_gen+=1;
    }
    else if (type == Type::POISON) {
        _current_gen+=2;
    }
    else if (type == Type::WALL) {
        _current_gen+=3;
    }
    else if (type == Type::FOOD) {
        _current_gen+=4;
    }
    else {
        _current_gen+=5;
    }
    _current_gen = _current_gen % Settings::GENOME_SIZE;
}

QVector<int> &Cell::getGenome() {
    return _genome;
}

QColor Cell::getColor()
{
    return Qt::blue;
}

Type Cell::getType()
{
    return Type::CELL;
}


