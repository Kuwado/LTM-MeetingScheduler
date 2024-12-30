/********************************************************************************
** Form generated from reading UI file 'viewweeklymeetingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWWEEKLYMEETINGSDIALOG_H
#define UI_VIEWWEEKLYMEETINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ViewWeeklyMeetingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QCalendarWidget *calendarWidget;
    QLabel *meetingsLabel;
    QTreeWidget *meetingsTree;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ViewWeeklyMeetingsDialog)
    {
        if (ViewWeeklyMeetingsDialog->objectName().isEmpty())
            ViewWeeklyMeetingsDialog->setObjectName(QString::fromUtf8("ViewWeeklyMeetingsDialog"));
        ViewWeeklyMeetingsDialog->resize(800, 600);
        verticalLayout = new QVBoxLayout(ViewWeeklyMeetingsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(ViewWeeklyMeetingsDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        calendarWidget = new QCalendarWidget(ViewWeeklyMeetingsDialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGridVisible(true);

        verticalLayout->addWidget(calendarWidget);

        meetingsLabel = new QLabel(ViewWeeklyMeetingsDialog);
        meetingsLabel->setObjectName(QString::fromUtf8("meetingsLabel"));

        verticalLayout->addWidget(meetingsLabel);

        meetingsTree = new QTreeWidget(ViewWeeklyMeetingsDialog);
        meetingsTree->setObjectName(QString::fromUtf8("meetingsTree"));

        verticalLayout->addWidget(meetingsTree);

        buttonBox = new QDialogButtonBox(ViewWeeklyMeetingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ViewWeeklyMeetingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ViewWeeklyMeetingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ViewWeeklyMeetingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ViewWeeklyMeetingsDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewWeeklyMeetingsDialog)
    {
        ViewWeeklyMeetingsDialog->setWindowTitle(QApplication::translate("ViewWeeklyMeetingsDialog", "L\341\273\213ch h\341\272\271n", nullptr));
        titleLabel->setText(QApplication::translate("ViewWeeklyMeetingsDialog", "L\341\273\213ch h\341\272\271n c\341\273\247a b\341\272\241n", nullptr));
        titleLabel->setStyleSheet(QApplication::translate("ViewWeeklyMeetingsDialog", "font-size: 14pt; font-weight: bold;", nullptr));
        meetingsLabel->setText(QApplication::translate("ViewWeeklyMeetingsDialog", "Danh s\303\241ch cu\341\273\231c h\341\272\271n trong ng\303\240y", nullptr));
        meetingsLabel->setStyleSheet(QApplication::translate("ViewWeeklyMeetingsDialog", "font-weight: bold;", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = meetingsTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("ViewWeeklyMeetingsDialog", "Th\303\264ng tin cu\341\273\231c h\341\272\271n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewWeeklyMeetingsDialog: public Ui_ViewWeeklyMeetingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWWEEKLYMEETINGSDIALOG_H
