/****************************************************************************
** Meta object code from reading C++ file 'viewweeklymeetingsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/views/teacherviews/viewweeklymeetingsdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewweeklymeetingsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ViewWeeklyMeetingsDialog_t {
    QByteArrayData data[10];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewWeeklyMeetingsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewWeeklyMeetingsDialog_t qt_meta_stringdata_ViewWeeklyMeetingsDialog = {
    {
QT_MOC_LITERAL(0, 0, 24), // "ViewWeeklyMeetingsDialog"
QT_MOC_LITERAL(1, 25, 12), // "dateSelected"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 4), // "date"
QT_MOC_LITERAL(4, 44, 24), // "meetingItemDoubleClicked"
QT_MOC_LITERAL(5, 69, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 86, 4), // "item"
QT_MOC_LITERAL(7, 91, 6), // "column"
QT_MOC_LITERAL(8, 98, 6), // "accept"
QT_MOC_LITERAL(9, 105, 6) // "reject"

    },
    "ViewWeeklyMeetingsDialog\0dateSelected\0"
    "\0date\0meetingItemDoubleClicked\0"
    "QTreeWidgetItem*\0item\0column\0accept\0"
    "reject"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewWeeklyMeetingsDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    2,   37,    2, 0x08 /* Private */,
       8,    0,   42,    2, 0x08 /* Private */,
       9,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ViewWeeklyMeetingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ViewWeeklyMeetingsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dateSelected((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 1: _t->meetingItemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->accept(); break;
        case 3: _t->reject(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ViewWeeklyMeetingsDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_ViewWeeklyMeetingsDialog.data,
    qt_meta_data_ViewWeeklyMeetingsDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ViewWeeklyMeetingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewWeeklyMeetingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ViewWeeklyMeetingsDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ViewWeeklyMeetingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
