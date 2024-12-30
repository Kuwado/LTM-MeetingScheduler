/********************************************************************************
** Form generated from reading UI file 'teacherviewmeetingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERVIEWMEETINGSDIALOG_H
#define UI_TEACHERVIEWMEETINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TeacherViewMeetingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QLabel *label;
    QListWidget *meetingListWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TeacherViewMeetingsDialog)
    {
        if (TeacherViewMeetingsDialog->objectName().isEmpty())
            TeacherViewMeetingsDialog->setObjectName(QString::fromUtf8("TeacherViewMeetingsDialog"));
        TeacherViewMeetingsDialog->resize(800, 600);
        verticalLayout = new QVBoxLayout(TeacherViewMeetingsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        calendarWidget = new QCalendarWidget(TeacherViewMeetingsDialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setMinimumSize(QSize(600, 400));

        verticalLayout->addWidget(calendarWidget);

        label = new QLabel(TeacherViewMeetingsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        meetingListWidget = new QListWidget(TeacherViewMeetingsDialog);
        meetingListWidget->setObjectName(QString::fromUtf8("meetingListWidget"));
        meetingListWidget->setMinimumSize(QSize(0, 150));

        verticalLayout->addWidget(meetingListWidget);

        buttonBox = new QDialogButtonBox(TeacherViewMeetingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TeacherViewMeetingsDialog);

        QMetaObject::connectSlotsByName(TeacherViewMeetingsDialog);
    } // setupUi

    void retranslateUi(QDialog *TeacherViewMeetingsDialog)
    {
        TeacherViewMeetingsDialog->setWindowTitle(QApplication::translate("TeacherViewMeetingsDialog", "L\341\273\213ch h\341\273\215p c\341\273\247a gi\303\241o vi\303\252n", nullptr));
        label->setText(QApplication::translate("TeacherViewMeetingsDialog", "Danh s\303\241ch cu\341\273\231c h\341\273\215p:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherViewMeetingsDialog: public Ui_TeacherViewMeetingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERVIEWMEETINGSDIALOG_H
