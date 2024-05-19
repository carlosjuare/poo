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
    QByteArrayData data[18];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ven_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ven_t qt_meta_stringdata_ven = {
    {
QT_MOC_LITERAL(0, 0, 3), // "ven"
QT_MOC_LITERAL(1, 4, 18), // "usuarioAutenticado"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "nombreUsuario"
QT_MOC_LITERAL(4, 38, 10), // "getWeather"
QT_MOC_LITERAL(5, 49, 12), // "weatherReply"
QT_MOC_LITERAL(6, 62, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 77, 5), // "reply"
QT_MOC_LITERAL(8, 83, 17), // "toggleTemperature"
QT_MOC_LITERAL(9, 101, 11), // "descargaimg"
QT_MOC_LITERAL(10, 113, 12), // "cambiarFondo"
QT_MOC_LITERAL(11, 126, 15), // "bloquearUsuario"
QT_MOC_LITERAL(12, 142, 18), // "desbloquearUsuario"
QT_MOC_LITERAL(13, 161, 10), // "updateTime"
QT_MOC_LITERAL(14, 172, 13), // "bloquearClave"
QT_MOC_LITERAL(15, 186, 16), // "desbloquearClave"
QT_MOC_LITERAL(16, 203, 12), // "slot_validar"
QT_MOC_LITERAL(17, 216, 13) // "iniciarSesion"

    },
    "ven\0usuarioAutenticado\0\0nombreUsuario\0"
    "getWeather\0weatherReply\0QNetworkReply*\0"
    "reply\0toggleTemperature\0descargaimg\0"
    "cambiarFondo\0bloquearUsuario\0"
    "desbloquearUsuario\0updateTime\0"
    "bloquearClave\0desbloquearClave\0"
    "slot_validar\0iniciarSesion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ven[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   82,    2, 0x0a /* Public */,
       5,    1,   83,    2, 0x0a /* Public */,
       8,    0,   86,    2, 0x0a /* Public */,
       9,    1,   87,    2, 0x0a /* Public */,
      10,    0,   90,    2, 0x0a /* Public */,
      11,    0,   91,    2, 0x0a /* Public */,
      12,    0,   92,    2, 0x0a /* Public */,
      13,    0,   93,    2, 0x0a /* Public */,
      14,    0,   94,    2, 0x0a /* Public */,
      15,    0,   95,    2, 0x0a /* Public */,
      16,    0,   96,    2, 0x0a /* Public */,
      17,    0,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
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

void ven::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ven *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->usuarioAutenticado((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
        case 11: _t->slot_validar(); break;
        case 12: _t->iniciarSesion(); break;
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ven::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ven::usuarioAutenticado)) {
                *result = 0;
                return;
            }
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ven::usuarioAutenticado(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
