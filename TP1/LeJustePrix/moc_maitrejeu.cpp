/****************************************************************************
** Meta object code from reading C++ file 'maitrejeu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "maitrejeu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maitrejeu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MaitreJeu_t {
    QByteArrayData data[9];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaitreJeu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaitreJeu_t qt_meta_stringdata_MaitreJeu = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MaitreJeu"
QT_MOC_LITERAL(1, 10, 4), // "avis"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 17), // "incrementeNbCoups"
QT_MOC_LITERAL(4, 34, 12), // "afficheCoups"
QT_MOC_LITERAL(5, 47, 8), // "victoire"
QT_MOC_LITERAL(6, 56, 13), // "doitContinuer"
QT_MOC_LITERAL(7, 70, 6), // "evalue"
QT_MOC_LITERAL(8, 77, 19) // "incrementationCoups"

    },
    "MaitreJeu\0avis\0\0incrementeNbCoups\0"
    "afficheCoups\0victoire\0doitContinuer\0"
    "evalue\0incrementationCoups"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaitreJeu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    0,   52,    2, 0x06 /* Public */,
       4,    1,   53,    2, 0x06 /* Public */,
       5,    0,   56,    2, 0x06 /* Public */,
       6,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   58,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void,

       0        // eod
};

void MaitreJeu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MaitreJeu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->avis((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->incrementeNbCoups(); break;
        case 2: _t->afficheCoups((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->victoire(); break;
        case 4: _t->doitContinuer(); break;
        case 5: _t->evalue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: _t->incrementationCoups(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MaitreJeu::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaitreJeu::avis)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MaitreJeu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaitreJeu::incrementeNbCoups)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MaitreJeu::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaitreJeu::afficheCoups)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MaitreJeu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaitreJeu::victoire)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MaitreJeu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaitreJeu::doitContinuer)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MaitreJeu::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MaitreJeu.data,
    qt_meta_data_MaitreJeu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MaitreJeu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaitreJeu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MaitreJeu.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MaitreJeu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MaitreJeu::avis(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MaitreJeu::incrementeNbCoups()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MaitreJeu::afficheCoups(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MaitreJeu::victoire()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MaitreJeu::doitContinuer()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
