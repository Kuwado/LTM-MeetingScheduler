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
    src/views/teacherviews/TeacherMenuWidget.cpp \
    src/views/studentviews/ViewAllTeacherWidget.cpp \
    src/views/studentviews/teacherlistviewer.cpp \
    src/views/studentviews/timeslotcalendar.cpp \
    src/views/studentviews/meetingbooking.cpp \
    src/views/studentviews/meetingcalendarviewer.cpp \
    src/views/studentviews/MeetingDialog.cpp \
    src/views/studentviews/StudentMenu.cpp \


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
    src/views/teacherviews/TeacherMenuWidget.h \
    src/views/studentviews/ViewAllTeacherWidget.h \
    src/views/studentviews/teacherlistviewer.h \
    src/views/studentviews/timeslotcalendar.h \
    src/views/studentviews/meetingbooking.h \
    src/views/studentviews/meetingcalendarviewer.h \
    src/views/studentviews/MeetingDialog.h \
    src/views/studentviews/StudentMenu.h \

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
    src/views/teacherviews/TeacherMenuWidget.ui \
    src/views/studentviews/ViewAllTeacherWidget.ui \
    src/views/studentviews/teacherlistviewer.ui \
    src/views/studentviews/timeslotcalendar.ui \
    src/views/studentviews/meetingbooking.ui \
    src/views/studentviews/meetingcalendarviewer.ui \
    src/views/studentviews/MeetingDialog.ui \
    src/views/studentviews/StudentMenu.ui \



INCLUDEPATH += \
    src \
    src/views \
    src/controllers \
    src/utils

CONFIG += c++11

LIBS += -lpthread -lmysqlcppconn