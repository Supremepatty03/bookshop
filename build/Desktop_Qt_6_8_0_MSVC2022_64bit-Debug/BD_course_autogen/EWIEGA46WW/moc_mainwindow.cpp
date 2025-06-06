/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../BD_course/mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_login_success",
    "",
    "userID",
    "on_detailsRequested",
    "bookID",
    "on_cartButton",
    "on_lobbyButton",
    "on_addToCart",
    "on_removeFromCart",
    "bookId",
    "on_singleOrderRequested",
    "on_addNewAdressButton",
    "on_orderCancelButton",
    "on_confirmOrderButton",
    "on_profileButton",
    "on_outProfileButton",
    "on_returnFromUsersOrderButton",
    "onDeleteBook",
    "on_addButton_clicked",
    "on_addDeclinedButton",
    "on_AdminButton"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  116,    2, 0x0a,    1 /* Public */,
       4,    1,  119,    2, 0x0a,    3 /* Public */,
       6,    0,  122,    2, 0x0a,    5 /* Public */,
       7,    0,  123,    2, 0x0a,    6 /* Public */,
       8,    1,  124,    2, 0x0a,    7 /* Public */,
       9,    1,  127,    2, 0x0a,    9 /* Public */,
      11,    1,  130,    2, 0x0a,   11 /* Public */,
      12,    0,  133,    2, 0x0a,   13 /* Public */,
      13,    0,  134,    2, 0x0a,   14 /* Public */,
      14,    1,  135,    2, 0x0a,   15 /* Public */,
      15,    0,  138,    2, 0x0a,   17 /* Public */,
      16,    0,  139,    2, 0x0a,   18 /* Public */,
      17,    0,  140,    2, 0x0a,   19 /* Public */,
      18,    1,  141,    2, 0x0a,   20 /* Public */,
      19,    0,  144,    2, 0x0a,   22 /* Public */,
      20,    0,  145,    2, 0x0a,   23 /* Public */,
      21,    0,  146,    2, 0x0a,   24 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_login_success'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_detailsRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_cartButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lobbyButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addToCart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_removeFromCart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_singleOrderRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_addNewAdressButton'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_orderCancelButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_confirmOrderButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_profileButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_outProfileButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_returnFromUsersOrderButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteBook'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_addButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addDeclinedButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_AdminButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_login_success((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_detailsRequested((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_cartButton(); break;
        case 3: _t->on_lobbyButton(); break;
        case 4: _t->on_addToCart((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_removeFromCart((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_singleOrderRequested((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: { QString _r = _t->on_addNewAdressButton();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->on_orderCancelButton(); break;
        case 9: _t->on_confirmOrderButton((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_profileButton(); break;
        case 11: _t->on_outProfileButton(); break;
        case 12: _t->on_returnFromUsersOrderButton(); break;
        case 13: _t->onDeleteBook((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_addButton_clicked(); break;
        case 15: _t->on_addDeclinedButton(); break;
        case 16: _t->on_AdminButton(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
