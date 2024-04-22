/****************************************************************************
** Meta object code from reading C++ file 'log.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../arcivos/log.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'log.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ven_t {
    QByteArrayData data[15];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ven_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ven_t qt_meta_stringdata_ven = {
    {
QT_MOC_LITERAL(0, 0, 3), // "ven"
QT_MOC_LITERAL(1, 4, 13), // "checkPassword"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 10), // "getWeather"
QT_MOC_LITERAL(4, 30, 12), // "weatherReply"
QT_MOC_LITERAL(5, 43, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 58, 5), // "reply"
QT_MOC_LITERAL(7, 64, 17), // "toggleTemperature"
QT_MOC_LITERAL(8, 82, 11), // "descargaimg"
QT_MOC_LITERAL(9, 94, 12), // "cambiarFondo"
QT_MOC_LITERAL(10, 107, 15), // "bloquearUsuario"
QT_MOC_LITERAL(11, 123, 18), // "desbloquearUsuario"
QT_MOC_LITERAL(12, 142, 10), // "updateTime"
QT_MOC_LITERAL(13, 153, 13), // "bloquearClave"
QT_MOC_LITERAL(14, 167, 16) // "desbloquearClave"

    },
    "ven\0checkPassword\0\0getWeather\0"
    "weatherReply\0QNetworkReply*\0reply\0"
    "toggleTemperature\0descargaimg\0"
    "cambiarFondo\0bloquearUsuario\0"
    "desbloquearUsuario\0updateTime\0"
    "bloquearClave\0desbloquearClave"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ven[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    1,   71,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    1,   75,    2, 0x0a /* Public */,
       9,    0,   78,    2, 0x0a /* Public */,
      10,    0,   79,    2, 0x0a /* Public */,
      11,    0,   80,    2, 0x0a /* Public */,
      12,    0,   81,    2, 0x0a /* Public */,
      13,    0,   82,    2, 0x0a /* Public */,
      14,    0,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ven::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ven *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkPassword(); break;
        case 1: _t->getWeather(); break;
        case 2: _t->weatherReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->toggleTemperature(); break;
        case 4: _t->descargaimg((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->cambiarFondo(); break;
        case 6: _t->bloquearUsuario(); break;
        case 7: _t->desbloquearUsuario(); break;
        case 8: _t->updateTime(); break;
        case 9: _t->bloquearClave(); break;
        case 10: _t->desbloquearClave(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ven::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ven.data,
    qt_meta_data_ven,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ven::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ven::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ven.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ven::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
