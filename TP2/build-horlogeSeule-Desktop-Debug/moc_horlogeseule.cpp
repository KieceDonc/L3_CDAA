/****************************************************************************
** Meta object code from reading C++ file 'horlogeseule.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../horlogeSeule/horlogeseule.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'horlogeseule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_horlogeSeule_t {
    QByteArrayData data[7];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_horlogeSeule_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_horlogeSeule_t qt_meta_stringdata_horlogeSeule = {
    {
QT_MOC_LITERAL(0, 0, 12), // "horlogeSeule"
QT_MOC_LITERAL(1, 13, 7), // "exitApp"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 16), // "onEndCountSignal"
QT_MOC_LITERAL(4, 39, 9), // "timerSlot"
QT_MOC_LITERAL(5, 49, 20), // "onStartButtonClicked"
QT_MOC_LITERAL(6, 70, 13) // "stopCountdown"

    },
    "horlogeSeule\0exitApp\0\0onEndCountSignal\0"
    "timerSlot\0onStartButtonClicked\0"
    "stopCountdown"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_horlogeSeule[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void horlogeSeule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        horlogeSeule *_t = static_cast<horlogeSeule *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exitApp(); break;
        case 1: _t->onEndCountSignal(); break;
        case 2: _t->timerSlot(); break;
        case 3: _t->onStartButtonClicked(); break;
        case 4: _t->stopCountdown(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (horlogeSeule::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&horlogeSeule::exitApp)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (horlogeSeule::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&horlogeSeule::onEndCountSignal)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject horlogeSeule::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_horlogeSeule.data,
      qt_meta_data_horlogeSeule,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *horlogeSeule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *horlogeSeule::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_horlogeSeule.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int horlogeSeule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void horlogeSeule::exitApp()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void horlogeSeule::onEndCountSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
