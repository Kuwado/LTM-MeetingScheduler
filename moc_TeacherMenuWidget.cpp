/****************************************************************************
** Meta object code from reading C++ file 'TeacherMenuWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/views/teacherviews/TeacherMenuWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TeacherMenuWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TeacherMenuWidget_t {
    QByteArrayData data[10];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TeacherMenuWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TeacherMenuWidget_t qt_meta_stringdata_TeacherMenuWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TeacherMenuWidget"
QT_MOC_LITERAL(1, 18, 14), // "actionSelected"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "action"
QT_MOC_LITERAL(4, 41, 32), // "on_declareTimeSlotButton_clicked"
QT_MOC_LITERAL(5, 74, 34), // "on_checkAvailabilityButton_cl..."
QT_MOC_LITERAL(6, 109, 29), // "on_viewMeetingsButton_clicked"
QT_MOC_LITERAL(7, 139, 28), // "on_viewHistoryButton_clicked"
QT_MOC_LITERAL(8, 168, 35), // "on_viewWeeklyMeetingsButton_c..."
QT_MOC_LITERAL(9, 204, 23) // "on_logoutButton_clicked"

    },
    "TeacherMenuWidget\0actionSelected\0\0"
    "action\0on_declareTimeSlotButton_clicked\0"
    "on_checkAvailabilityButton_clicked\0"
    "on_viewMeetingsButton_clicked\0"
    "on_viewHistoryButton_clicked\0"
    "on_viewWeeklyMeetingsButton_clicked\0"
    "on_logoutButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TeacherMenuWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TeacherMenuWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TeacherMenuWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actionSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_declareTimeSlotButton_clicked(); break;
        case 2: _t->on_checkAvailabilityButton_clicked(); break;
        case 3: _t->on_viewMeetingsButton_clicked(); break;
        case 4: _t->on_viewHistoryButton_clicked(); break;
        case 5: _t->on_viewWeeklyMeetingsButton_clicked(); break;
        case 6: _t->on_logoutButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TeacherMenuWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeacherMenuWidget::actionSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TeacherMenuWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_TeacherMenuWidget.data,
    qt_meta_data_TeacherMenuWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TeacherMenuWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TeacherMenuWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TeacherMenuWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TeacherMenuWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void TeacherMenuWidget::actionSelected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE