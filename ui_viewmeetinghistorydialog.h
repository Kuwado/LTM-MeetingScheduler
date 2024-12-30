/********************************************************************************
** Form generated from reading UI file 'viewmeetinghistorydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWMEETINGHISTORYDIALOG_H
#define UI_VIEWMEETINGHISTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ViewMeetingHistoryDialog
{
public:
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QLabel *label;
    QListWidget *meetingListWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ViewMeetingHistoryDialog)
    {
        if (ViewMeetingHistoryDialog->objectName().isEmpty())
            ViewMeetingHistoryDialog->setObjectName(QString::fromUtf8("ViewMeetingHistoryDialog"));
        ViewMeetingHistoryDialog->resize(800, 600);
        verticalLayout = new QVBoxLayout(ViewMeetingHistoryDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        calendarWidget = new QCalendarWidget(ViewMeetingHistoryDialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setMinimumSize(QSize(600, 400));

        verticalLayout->addWidget(calendarWidget);

        label = new QLabel(ViewMeetingHistoryDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        meetingListWidget = new QListWidget(ViewMeetingHistoryDialog);
        meetingListWidget->setObjectName(QString::fromUtf8("meetingListWidget"));
        meetingListWidget->setMinimumSize(QSize(0, 150));

        verticalLayout->addWidget(meetingListWidget);

        buttonBox = new QDialogButtonBox(ViewMeetingHistoryDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ViewMeetingHistoryDialog);

        QMetaObject::connectSlotsByName(ViewMeetingHistoryDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewMeetingHistoryDialog)
    {
        ViewMeetingHistoryDialog->setWindowTitle(QApplication::translate("ViewMeetingHistoryDialog", "L\341\273\213ch h\341\273\215p c\341\273\247a gi\303\241o vi\303\252n", nullptr));
        label->setText(QApplication::translate("ViewMeetingHistoryDialog", "Danh s\303\241ch cu\341\273\231c h\341\273\215p:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewMeetingHistoryDialog: public Ui_ViewMeetingHistoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWMEETINGHISTORYDIALOG_H
