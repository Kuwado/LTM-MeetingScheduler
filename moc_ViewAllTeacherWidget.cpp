/****************************************************************************
** Meta object code from reading C++ file 'ViewAllTeacherWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/views/studentviews/ViewAllTeacherWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewAllTeacherWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ViewAllTeacherWidget_t {
    QByteArrayData data[10];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewAllTeacherWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewAllTeacherWidget_t qt_meta_stringdata_ViewAllTeacherWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ViewAllTeacherWidget"
QT_MOC_LITERAL(1, 21, 15), // "teacherSelected"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 9), // "teacherId"
QT_MOC_LITERAL(4, 48, 11), // "teacherName"
QT_MOC_LITERAL(5, 60, 11), // "backClicked"
QT_MOC_LITERAL(6, 72, 26), // "on_tableWidget_cellClicked"
QT_MOC_LITERAL(7, 99, 3), // "row"
QT_MOC_LITERAL(8, 103, 6), // "column"
QT_MOC_LITERAL(9, 110, 18) // "on_btnBack_clicked"

    },
    "ViewAllTeacherWidget\0teacherSelected\0"
    "\0teacherId\0teacherName\0backClicked\0"
    "on_tableWidget_cellClicked\0row\0column\0"
    "on_btnBack_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewAllTeacherWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   40,    2, 0x08 /* Private */,
       9,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,

       0        // eod
};

void ViewAllTeacherWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ViewAllTeacherWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->teacherSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->backClicked(); break;
        case 2: _t->on_tableWidget_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_btnBack_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ViewAllTeacherWidget::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ViewAllTeacherWidget::teacherSelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ViewAllTeacherWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ViewAllTeacherWidget::backClicked)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ViewAllTeacherWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ViewAllTeacherWidget.data,
    qt_meta_data_ViewAllTeacherWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ViewAllTeacherWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewAllTeacherWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ViewAllTeacherWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ViewAllTeacherWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ViewAllTeacherWidget::teacherSelected(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ViewAllTeacherWidget::backClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
