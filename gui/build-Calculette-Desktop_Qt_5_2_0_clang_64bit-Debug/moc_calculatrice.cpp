/****************************************************************************
** Meta object code from reading C++ file 'calculatrice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Calculette/calculatrice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculatrice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Calculatrice_t {
    QByteArrayData data[22];
    char stringdata[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Calculatrice_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Calculatrice_t qt_meta_stringdata_Calculatrice = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 3),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 11),
QT_MOC_LITERAL(4, 30, 10),
QT_MOC_LITERAL(5, 41, 10),
QT_MOC_LITERAL(6, 52, 7),
QT_MOC_LITERAL(7, 60, 6),
QT_MOC_LITERAL(8, 67, 6),
QT_MOC_LITERAL(9, 74, 5),
QT_MOC_LITERAL(10, 80, 10),
QT_MOC_LITERAL(11, 91, 10),
QT_MOC_LITERAL(12, 102, 11),
QT_MOC_LITERAL(13, 114, 11),
QT_MOC_LITERAL(14, 126, 11),
QT_MOC_LITERAL(15, 138, 10),
QT_MOC_LITERAL(16, 149, 6),
QT_MOC_LITERAL(17, 156, 10),
QT_MOC_LITERAL(18, 167, 11),
QT_MOC_LITERAL(19, 179, 2),
QT_MOC_LITERAL(20, 182, 13),
QT_MOC_LITERAL(21, 196, 14)
    },
    "Calculatrice\0run\0\0additionner\0soustraire\0"
    "multiplier\0diviser\0modulo\0racine\0carre\0"
    "getNombre1\0getNombre2\0getOperande\0"
    "std::string\0getResultat\0setNombre1\0"
    "nombre\0setNombre2\0setOperande\0op\0"
    "reInitialiser\0setIniResultat\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculatrice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a,
       3,    0,  100,    2, 0x0a,
       4,    0,  101,    2, 0x0a,
       5,    0,  102,    2, 0x0a,
       6,    0,  103,    2, 0x0a,
       7,    0,  104,    2, 0x0a,
       8,    0,  105,    2, 0x0a,
       9,    0,  106,    2, 0x0a,
      10,    0,  107,    2, 0x0a,
      11,    0,  108,    2, 0x0a,
      12,    0,  109,    2, 0x0a,
      14,    0,  110,    2, 0x0a,
      15,    1,  111,    2, 0x0a,
      17,    1,  114,    2, 0x0a,
      18,    1,  117,    2, 0x0a,
      20,    0,  120,    2, 0x0a,
      21,    0,  121,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int,
    0x80000000 | 13,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, 0x80000000 | 13,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Calculatrice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Calculatrice *_t = static_cast<Calculatrice *>(_o);
        switch (_id) {
        case 0: _t->run(); break;
        case 1: _t->additionner(); break;
        case 2: _t->soustraire(); break;
        case 3: _t->multiplier(); break;
        case 4: _t->diviser(); break;
        case 5: _t->modulo(); break;
        case 6: _t->racine(); break;
        case 7: _t->carre(); break;
        case 8: { int _r = _t->getNombre1();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: { int _r = _t->getNombre2();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { std::string _r = _t->getOperande();
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = _r; }  break;
        case 11: { int _r = _t->getResultat();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: _t->setNombre1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setNombre2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setOperande((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 15: _t->reInitialiser(); break;
        case 16: _t->setIniResultat(); break;
        default: ;
        }
    }
}

const QMetaObject Calculatrice::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Calculatrice.data,
      qt_meta_data_Calculatrice,  qt_static_metacall, 0, 0}
};


const QMetaObject *Calculatrice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculatrice::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Calculatrice.stringdata))
        return static_cast<void*>(const_cast< Calculatrice*>(this));
    return QObject::qt_metacast(_clname);
}

int Calculatrice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
