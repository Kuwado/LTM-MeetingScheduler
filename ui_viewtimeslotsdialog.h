/********************************************************************************
** Form generated from reading UI file 'viewtimeslotsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWTIMESLOTSDIALOG_H
#define UI_VIEWTIMESLOTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ViewTimeslotsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QCalendarWidget *calendarWidget;
    QLabel *timeslotsLabel;
    QListWidget *timeslotsList;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ViewTimeslotsDialog)
    {
        if (ViewTimeslotsDialog->objectName().isEmpty())
            ViewTimeslotsDialog->setObjectName(QString::fromUtf8("ViewTimeslotsDialog"));
        ViewTimeslotsDialog->resize(600, 500);
        verticalLayout = new QVBoxLayout(ViewTimeslotsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(ViewTimeslotsDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        calendarWidget = new QCalendarWidget(ViewTimeslotsDialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGridVisible(true);

        verticalLayout->addWidget(calendarWidget);

        timeslotsLabel = new QLabel(ViewTimeslotsDialog);
        timeslotsLabel->setObjectName(QString::fromUtf8("timeslotsLabel"));

        verticalLayout->addWidget(timeslotsLabel);

        timeslotsList = new QListWidget(ViewTimeslotsDialog);
        timeslotsList->setObjectName(QString::fromUtf8("timeslotsList"));
        timeslotsList->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout->addWidget(timeslotsList);

        buttonBox = new QDialogButtonBox(ViewTimeslotsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ViewTimeslotsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ViewTimeslotsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ViewTimeslotsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ViewTimeslotsDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewTimeslotsDialog)
    {
        ViewTimeslotsDialog->setWindowTitle(QApplication::translate("ViewTimeslotsDialog", "L\341\273\213ch th\341\273\235i gian r\341\272\243nh", nullptr));
        titleLabel->setText(QApplication::translate("ViewTimeslotsDialog", "L\341\273\213ch c\341\273\247a b\341\272\241n", nullptr));
        titleLabel->setStyleSheet(QApplication::translate("ViewTimeslotsDialog", "font-size: 14pt; font-weight: bold;", nullptr));
        timeslotsLabel->setText(QApplication::translate("ViewTimeslotsDialog", "Th\341\273\235i gian r\341\272\243nh trong ng\303\240y", nullptr));
        timeslotsLabel->setStyleSheet(QApplication::translate("ViewTimeslotsDialog", "font-weight: bold;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewTimeslotsDialog: public Ui_ViewTimeslotsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTIMESLOTSDIALOG_H
