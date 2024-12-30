/********************************************************************************
** Form generated from reading UI file 'meetingcalendarviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEETINGCALENDARVIEWER_H
#define UI_MEETINGCALENDARVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MeetingCalendarViewer
{
public:
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QLabel *weekLabel;
    QLabel *label;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MeetingCalendarViewer)
    {
        if (MeetingCalendarViewer->objectName().isEmpty())
            MeetingCalendarViewer->setObjectName(QString::fromUtf8("MeetingCalendarViewer"));
        MeetingCalendarViewer->resize(800, 600);
        verticalLayout = new QVBoxLayout(MeetingCalendarViewer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        calendarWidget = new QCalendarWidget(MeetingCalendarViewer);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);

        weekLabel = new QLabel(MeetingCalendarViewer);
        weekLabel->setObjectName(QString::fromUtf8("weekLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        weekLabel->setFont(font);

        verticalLayout->addWidget(weekLabel);

        label = new QLabel(MeetingCalendarViewer);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(MeetingCalendarViewer);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(MeetingCalendarViewer);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MeetingCalendarViewer);

        QMetaObject::connectSlotsByName(MeetingCalendarViewer);
    } // setupUi

    void retranslateUi(QDialog *MeetingCalendarViewer)
    {
        MeetingCalendarViewer->setWindowTitle(QApplication::translate("MeetingCalendarViewer", "L\341\273\213ch h\341\272\271n", nullptr));
        weekLabel->setText(QString());
        label->setText(QApplication::translate("MeetingCalendarViewer", "Danh s\303\241ch cu\341\273\231c h\341\272\271n:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeetingCalendarViewer: public Ui_MeetingCalendarViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEETINGCALENDARVIEWER_H
