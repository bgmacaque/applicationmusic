/****************************************************************************
** Meta object code from reading C++ file 'graphicneedle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../graphicneedle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicneedle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphicNeedle_t {
    QByteArrayData data[7];
    char stringdata[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GraphicNeedle_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GraphicNeedle_t qt_meta_stringdata_GraphicNeedle = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 7),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 6),
QT_MOC_LITERAL(4, 30, 8),
QT_MOC_LITERAL(5, 39, 8),
QT_MOC_LITERAL(6, 48, 3)
    },
    "GraphicNeedle\0goRight\0\0goLeft\0getAngle\0"
    "setAngle\0ang\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicNeedle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a,
       3,    0,   35,    2, 0x0a,
       4,    0,   36,    2, 0x0a,
       5,    1,   37,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QReal,
    QMetaType::Void, QMetaType::QReal,    6,

       0        // eod
};

void GraphicNeedle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicNeedle *_t = static_cast<GraphicNeedle *>(_o);
        switch (_id) {
        case 0: _t->goRight(); break;
        case 1: _t->goLeft(); break;
        case 2: { qreal _r = _t->getAngle();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = _r; }  break;
        case 3: _t->setAngle((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GraphicNeedle::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GraphicNeedle.data,
      qt_meta_data_GraphicNeedle,  qt_static_metacall, 0, 0}
};


const QMetaObject *GraphicNeedle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicNeedle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicNeedle.stringdata))
        return static_cast<void*>(const_cast< GraphicNeedle*>(this));
    return QWidget::qt_metacast(_clname);
}

int GraphicNeedle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
