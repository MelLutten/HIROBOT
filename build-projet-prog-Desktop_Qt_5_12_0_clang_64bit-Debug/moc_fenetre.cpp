/****************************************************************************
** Meta object code from reading C++ file 'fenetre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../projet-prog/fenetre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_fenetre_t {
    QByteArrayData data[14];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fenetre_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fenetre_t qt_meta_stringdata_fenetre = {
    {
QT_MOC_LITERAL(0, 0, 7), // "fenetre"
QT_MOC_LITERAL(1, 8, 11), // "OnDifficile"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "OnFacile"
QT_MOC_LITERAL(4, 30, 8), // "OnNormal"
QT_MOC_LITERAL(5, 39, 7), // "OnPerso"
QT_MOC_LITERAL(6, 47, 6), // "OnHaut"
QT_MOC_LITERAL(7, 54, 5), // "OnBas"
QT_MOC_LITERAL(8, 60, 8), // "OnDroite"
QT_MOC_LITERAL(9, 69, 8), // "OnGauche"
QT_MOC_LITERAL(10, 78, 4), // "OnHG"
QT_MOC_LITERAL(11, 83, 4), // "OnHD"
QT_MOC_LITERAL(12, 88, 4), // "OnBG"
QT_MOC_LITERAL(13, 93, 4) // "OnBD"

    },
    "fenetre\0OnDifficile\0\0OnFacile\0OnNormal\0"
    "OnPerso\0OnHaut\0OnBas\0OnDroite\0OnGauche\0"
    "OnHG\0OnHD\0OnBG\0OnBD"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fenetre[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void fenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fenetre *_t = static_cast<fenetre *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnDifficile(); break;
        case 1: _t->OnFacile(); break;
        case 2: _t->OnNormal(); break;
        case 3: _t->OnPerso(); break;
        case 4: _t->OnHaut(); break;
        case 5: _t->OnBas(); break;
        case 6: _t->OnDroite(); break;
        case 7: _t->OnGauche(); break;
        case 8: _t->OnHG(); break;
        case 9: _t->OnHD(); break;
        case 10: _t->OnBG(); break;
        case 11: _t->OnBD(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject fenetre::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_fenetre.data,
    qt_meta_data_fenetre,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *fenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_fenetre.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int fenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
