/****************************************************************************
** Meta object code from reading C++ file 'appsigne.h'
**
** Created: Wed 16. Dec 12:24:18 2020
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../appsigne.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appsigne.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Appsigne[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      34,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Appsigne[] = {
    "Appsigne\0\0on_pbCalculer_clicked()\0"
    "on_pbSuivant_clicked()\0"
};

void Appsigne::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Appsigne *_t = static_cast<Appsigne *>(_o);
        switch (_id) {
        case 0: _t->on_pbSuivant_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Appsigne::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Appsigne::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Appsigne,
      qt_meta_data_Appsigne, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Appsigne::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Appsigne::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Appsigne::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Appsigne))
        return static_cast<void*>(const_cast< Appsigne*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Appsigne::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
