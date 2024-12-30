QT += core gui widgets

TEMPLATE = app
TARGET = client1

SOURCES += \
    src/client/Client1.cpp \
    src/views/teacherviews/timeslotdialog.cpp \
    src/views/teacherviews/viewtimeslotsdialog.cpp \
    src/views/teacherviews/update_timeslot_dialog.cpp \
    src/views/teacherviews/teacherviewmeetingsdialog.cpp \
    src/views/teacherviews/meetingdetaildialog.cpp \
    src/views/teacherviews/meetingcalendarwidget.cpp \
    src/views/teacherviews/meetinghistorydialog.cpp \
    src/views/teacherviews/viewmeetinghistorydialog.cpp \
    src/views/teacherviews/viewweeklymeetingsdialog.cpp \
    src/views/userviews/loginwidget.cpp \
    src/views/userviews/mainmenu.cpp \
    src/views/userviews/registerwidget.cpp \
    # Thêm các file .cpp khác

HEADERS += \
    src/views/teacherviews/timeslotdialog.h \
    src/views/teacherviews/viewtimeslotsdialog.h \
    src/views/teacherviews/update_timeslot_dialog.h \
    src/views/teacherviews/teacherviewmeetingsdialog.h \
    src/views/teacherviews/meetingdetaildialog.h \
    src/views/teacherviews/meetingcalendarwidget.h \
    src/views/teacherviews/meetinghistorydialog.h \
    src/views/teacherviews/viewmeetinghistorydialog.h \
    src/views/teacherviews/viewweeklymeetingsdialog.h \
    src/views/userviews/loginwidget.h \
    src/views/userviews/mainmenu.h \
    src/views/userviews/registerwidget.h \
    # Thêm các file .h khác

FORMS += \
    src/views/teacherviews/timeslotdialog.ui \
    src/views/teacherviews/viewtimeslotsdialog.ui \
    src/views/teacherviews/update_timeslot_dialog.ui \
    src/views/teacherviews/teacherviewmeetingsdialog.ui \
    src/views/teacherviews/meetingdetaildialog.ui \
    src/views/teacherviews/meetinghistorydialog.ui \
    src/views/teacherviews/viewmeetinghistorydialog.ui \
    src/views/teacherviews/viewweeklymeetingsdialog.ui \
    src/views/userviews/loginwidget.ui \
    src/views/userviews/mainmenu.ui \
    src/views/userviews/registerwidget.ui \


INCLUDEPATH += \
    src \
    src/views \
    src/controllers \
    src/utils

CONFIG += c++11

LIBS += -lpthread -lmysqlcppconn