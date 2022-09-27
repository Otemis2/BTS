/****************************************************************************
** Meta object code from reading C++ file 'qmainwindowmorse.h'
**
** Created: Mon 4. Oct 12:27:38 2021
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qmainwindowmorse.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmainwindowmorse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMainWindowMorse[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      38,   17,   17,   17, 0x08,
      61,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QMainWindowMorse[] = {
    "QMainWindowMorse\0\0on_pBCode_clicked()\0"
    "on_pBQuitter_clicked()\0on_pBDecoder_clicked()\0"
};

void QMainWindowMorse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMainWindowMorse *_t = static_cast<QMainWindowMorse *>(_o);
        switch (_id) {
        case 0: _t->on_pBCode_clicked(); break;
        case 1: _t->on_pBQuitter_clicked(); break;
        case 2: _t->on_pBDecoder_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QMainWindowMorse::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMainWindowMorse::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QMainWindowMorse,
      qt_meta_data_QMainWindowMorse, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMainWindowMorse::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMainWindowMorse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMainWindowMorse::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMainWindowMorse))
        return static_cast<void*>(const_cast< QMainWindowMorse*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QMainWindowMorse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
