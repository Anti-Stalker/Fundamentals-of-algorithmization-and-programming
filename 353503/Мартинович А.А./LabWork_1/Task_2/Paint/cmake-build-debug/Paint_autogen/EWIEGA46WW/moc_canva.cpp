/****************************************************************************
** Meta object code from reading C++ file 'canva.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../canva.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canva.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Canva_t {
    uint offsetsAndSizes[20];
    char stringdata0[6];
    char stringdata1[32];
    char stringdata2[1];
    char stringdata3[26];
    char stringdata4[6];
    char stringdata5[32];
    char stringdata6[33];
    char stringdata7[34];
    char stringdata8[35];
    char stringdata9[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Canva_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Canva_t qt_meta_stringdata_Canva = {
    {
        QT_MOC_LITERAL(0, 5),  // "Canva"
        QT_MOC_LITERAL(6, 31),  // "signalMouseDoubleLeftClickEvent"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 25),  // "QGraphicsSceneMouseEvent*"
        QT_MOC_LITERAL(65, 5),  // "event"
        QT_MOC_LITERAL(71, 31),  // "signalMousePressLeftButtonEvent"
        QT_MOC_LITERAL(103, 32),  // "signalMousePressRightButtonEvent"
        QT_MOC_LITERAL(136, 33),  // "signalMouseReleaseLeftButtonE..."
        QT_MOC_LITERAL(170, 34),  // "signalMouseReleaseRightButton..."
        QT_MOC_LITERAL(205, 20)   // "signalMouseMoveEvent"
    },
    "Canva",
    "signalMouseDoubleLeftClickEvent",
    "",
    "QGraphicsSceneMouseEvent*",
    "event",
    "signalMousePressLeftButtonEvent",
    "signalMousePressRightButtonEvent",
    "signalMouseReleaseLeftButtonEvent",
    "signalMouseReleaseRightButtonEvent",
    "signalMouseMoveEvent"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Canva[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       5,    1,   53,    2, 0x06,    3 /* Public */,
       6,    1,   56,    2, 0x06,    5 /* Public */,
       7,    1,   59,    2, 0x06,    7 /* Public */,
       8,    1,   62,    2, 0x06,    9 /* Public */,
       9,    1,   65,    2, 0x06,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject Canva::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_Canva.offsetsAndSizes,
    qt_meta_data_Canva,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Canva_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Canva, std::true_type>,
        // method 'signalMouseDoubleLeftClickEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>,
        // method 'signalMousePressLeftButtonEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>,
        // method 'signalMousePressRightButtonEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>,
        // method 'signalMouseReleaseLeftButtonEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>,
        // method 'signalMouseReleaseRightButtonEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>,
        // method 'signalMouseMoveEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>
    >,
    nullptr
} };

void Canva::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Canva *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalMouseDoubleLeftClickEvent((*reinterpret_cast< std::add_pointer_t<QGraphicsSceneMouseEvent*>>(_a[1]))); break;
        case 1: _t->signalMousePressLeftButtonEvent((*reinterpret_cast< std::add_pointer_t<QGraphicsSceneMouseEvent*>>(_a[1]))); break;
        case 2: _t->signalMousePressRightButtonEvent((*reinterpret_cast< std::add_pointer_t<QGraphicsSceneMouseEvent*>>(_a[1]))); break;
        case 3: _t->signalMouseReleaseLeftButtonEvent((*reinterpret_cast< std::add_pointer_t<QGraphicsSceneMouseEvent*>>(_a[1]))); break;
        case 4: _t->signalMouseReleaseRightButtonEvent((*reinterpret_cast< std::add_pointer_t<QGraphicsSceneMouseEvent*>>(_a[1]))); break;
        case 5: _t->signalMouseMoveEvent((*reinterpret_cast< std::add_pointer_t<QGraphicsSceneMouseEvent*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Canva::*)(QGraphicsSceneMouseEvent * );
            if (_t _q_method = &Canva::signalMouseDoubleLeftClickEvent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Canva::*)(QGraphicsSceneMouseEvent * );
            if (_t _q_method = &Canva::signalMousePressLeftButtonEvent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Canva::*)(QGraphicsSceneMouseEvent * );
            if (_t _q_method = &Canva::signalMousePressRightButtonEvent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Canva::*)(QGraphicsSceneMouseEvent * );
            if (_t _q_method = &Canva::signalMouseReleaseLeftButtonEvent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Canva::*)(QGraphicsSceneMouseEvent * );
            if (_t _q_method = &Canva::signalMouseReleaseRightButtonEvent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Canva::*)(QGraphicsSceneMouseEvent * );
            if (_t _q_method = &Canva::signalMouseMoveEvent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *Canva::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Canva::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Canva.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int Canva::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Canva::signalMouseDoubleLeftClickEvent(QGraphicsSceneMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Canva::signalMousePressLeftButtonEvent(QGraphicsSceneMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Canva::signalMousePressRightButtonEvent(QGraphicsSceneMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Canva::signalMouseReleaseLeftButtonEvent(QGraphicsSceneMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Canva::signalMouseReleaseRightButtonEvent(QGraphicsSceneMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Canva::signalMouseMoveEvent(QGraphicsSceneMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
