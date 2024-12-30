/********************************************************************************
** Form generated from reading UI file 'timeslotcalendar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESLOTCALENDAR_H
#define UI_TIMESLOTCALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TimeslotCalendar
{
public:
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QLabel *label;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TimeslotCalendar)
    {
        if (TimeslotCalendar->objectName().isEmpty())
            TimeslotCalendar->setObjectName(QString::fromUtf8("TimeslotCalendar"));
        TimeslotCalendar->resize(600, 500);
        verticalLayout = new QVBoxLayout(TimeslotCalendar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        calendarWidget = new QCalendarWidget(TimeslotCalendar);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);

        label = new QLabel(TimeslotCalendar);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(TimeslotCalendar);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(TimeslotCalendar);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TimeslotCalendar);

        QMetaObject::connectSlotsByName(TimeslotCalendar);
    } // setupUi

    void retranslateUi(QDialog *TimeslotCalendar)
    {
        TimeslotCalendar->setWindowTitle(QApplication::translate("TimeslotCalendar", "Xem l\341\273\213ch", nullptr));
        label->setText(QApplication::translate("TimeslotCalendar", "C\303\241c khung th\341\273\235i gian c\303\263 s\341\272\265n:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeslotCalendar: public Ui_TimeslotCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESLOTCALENDAR_H
