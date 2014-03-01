/****************************************************************************
** Meta object code from reading C++ file 'confwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../confwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'confwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConfWindow_t {
    QByteArrayData data[10];
    char stringdata[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ConfWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ConfWindow_t qt_meta_stringdata_ConfWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 11),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 14),
QT_MOC_LITERAL(4, 39, 12),
QT_MOC_LITERAL(5, 52, 5),
QT_MOC_LITERAL(6, 58, 15),
QT_MOC_LITERAL(7, 74, 9),
QT_MOC_LITERAL(8, 84, 9),
QT_MOC_LITERAL(9, 94, 14)
    },
    "ConfWindow\0setAuthPage\0\0setOptionsPage\0"
    "setSkinsPage\0apply\0activeRelogTime\0"
    "activated\0activeAll\0activeSavePass\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a,
       3,    0,   50,    2, 0x0a,
       4,    0,   51,    2, 0x0a,
       5,    0,   52,    2, 0x0a,
       6,    1,   53,    2, 0x0a,
       8,    0,   56,    2, 0x0a,
       9,    0,   57,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    QMetaType::Bool,

       0        // eod
};

void ConfWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfWindow *_t = static_cast<ConfWindow *>(_o);
        switch (_id) {
        case 0: _t->setAuthPage(); break;
        case 1: _t->setOptionsPage(); break;
        case 2: _t->setSkinsPage(); break;
        case 3: _t->apply(); break;
        case 4: _t->activeRelogTime((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: { bool _r = _t->activeAll();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->activeSavePass();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject ConfWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ConfWindow.data,
      qt_meta_data_ConfWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *ConfWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfWindow.stringdata))
        return static_cast<void*>(const_cast< ConfWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ConfWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
