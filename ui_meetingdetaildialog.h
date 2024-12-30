/********************************************************************************
** Form generated from reading UI file 'meetingdetaildialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEETINGDETAILDIALOG_H
#define UI_MEETINGDETAILDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MeetingDetailDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *infoGroupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *dateLabel;
    QLabel *label_2;
    QLabel *startTimeLabel;
    QLabel *label_3;
    QLabel *endTimeLabel;
    QLabel *label_4;
    QLabel *typeLabel;
    QLabel *label_5;
    QLabel *statusLabel;
    QGroupBox *reportGroupBox;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *reportTextEdit;
    QPushButton *editReportButton;
    QGroupBox *studentsGroupBox;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *studentsTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *editStatusButton;
    QPushButton *backButton;

    void setupUi(QDialog *MeetingDetailDialog)
    {
        if (MeetingDetailDialog->objectName().isEmpty())
            MeetingDetailDialog->setObjectName(QString::fromUtf8("MeetingDetailDialog"));
        MeetingDetailDialog->resize(600, 700);
        verticalLayout = new QVBoxLayout(MeetingDetailDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        infoGroupBox = new QGroupBox(MeetingDetailDialog);
        infoGroupBox->setObjectName(QString::fromUtf8("infoGroupBox"));
        formLayout = new QFormLayout(infoGroupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(infoGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        dateLabel = new QLabel(infoGroupBox);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dateLabel);

        label_2 = new QLabel(infoGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        startTimeLabel = new QLabel(infoGroupBox);
        startTimeLabel->setObjectName(QString::fromUtf8("startTimeLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, startTimeLabel);

        label_3 = new QLabel(infoGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        endTimeLabel = new QLabel(infoGroupBox);
        endTimeLabel->setObjectName(QString::fromUtf8("endTimeLabel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, endTimeLabel);

        label_4 = new QLabel(infoGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        typeLabel = new QLabel(infoGroupBox);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));

        formLayout->setWidget(3, QFormLayout::FieldRole, typeLabel);

        label_5 = new QLabel(infoGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        statusLabel = new QLabel(infoGroupBox);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        formLayout->setWidget(4, QFormLayout::FieldRole, statusLabel);


        verticalLayout->addWidget(infoGroupBox);

        reportGroupBox = new QGroupBox(MeetingDetailDialog);
        reportGroupBox->setObjectName(QString::fromUtf8("reportGroupBox"));
        verticalLayout_2 = new QVBoxLayout(reportGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        reportTextEdit = new QTextEdit(reportGroupBox);
        reportTextEdit->setObjectName(QString::fromUtf8("reportTextEdit"));
        reportTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(reportTextEdit);

        editReportButton = new QPushButton(reportGroupBox);
        editReportButton->setObjectName(QString::fromUtf8("editReportButton"));

        verticalLayout_2->addWidget(editReportButton);


        verticalLayout->addWidget(reportGroupBox);

        studentsGroupBox = new QGroupBox(MeetingDetailDialog);
        studentsGroupBox->setObjectName(QString::fromUtf8("studentsGroupBox"));
        verticalLayout_3 = new QVBoxLayout(studentsGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        studentsTextEdit = new QTextEdit(studentsGroupBox);
        studentsTextEdit->setObjectName(QString::fromUtf8("studentsTextEdit"));
        studentsTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(studentsTextEdit);


        verticalLayout->addWidget(studentsGroupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        editStatusButton = new QPushButton(MeetingDetailDialog);
        editStatusButton->setObjectName(QString::fromUtf8("editStatusButton"));

        horizontalLayout->addWidget(editStatusButton);

        backButton = new QPushButton(MeetingDetailDialog);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout->addWidget(backButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MeetingDetailDialog);

        QMetaObject::connectSlotsByName(MeetingDetailDialog);
    } // setupUi

    void retranslateUi(QDialog *MeetingDetailDialog)
    {
        MeetingDetailDialog->setWindowTitle(QApplication::translate("MeetingDetailDialog", "Th\303\264ng tin l\341\273\213ch h\341\272\271n", nullptr));
        infoGroupBox->setTitle(QApplication::translate("MeetingDetailDialog", "Th\303\264ng tin chung", nullptr));
        label->setText(QApplication::translate("MeetingDetailDialog", "Ng\303\240y:", nullptr));
        dateLabel->setText(QString());
        label_2->setText(QApplication::translate("MeetingDetailDialog", "T\341\273\253:", nullptr));
        startTimeLabel->setText(QString());
        label_3->setText(QApplication::translate("MeetingDetailDialog", "\304\220\341\272\277n:", nullptr));
        endTimeLabel->setText(QString());
        label_4->setText(QApplication::translate("MeetingDetailDialog", "Lo\341\272\241i:", nullptr));
        typeLabel->setText(QString());
        label_5->setText(QApplication::translate("MeetingDetailDialog", "Tr\341\272\241ng th\303\241i:", nullptr));
        statusLabel->setText(QString());
        reportGroupBox->setTitle(QApplication::translate("MeetingDetailDialog", "V\304\203n b\341\272\243n cu\341\273\231c h\341\273\215p", nullptr));
        editReportButton->setText(QApplication::translate("MeetingDetailDialog", "Ch\341\273\211nh s\341\273\255a v\304\203n b\341\272\243n", nullptr));
        studentsGroupBox->setTitle(QApplication::translate("MeetingDetailDialog", "Ng\306\260\341\273\235i h\341\272\271n", nullptr));
        editStatusButton->setText(QApplication::translate("MeetingDetailDialog", "C\341\272\255p nh\341\272\255t tr\341\272\241ng th\303\241i", nullptr));
        backButton->setText(QApplication::translate("MeetingDetailDialog", "Quay l\341\272\241i", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeetingDetailDialog: public Ui_MeetingDetailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEETINGDETAILDIALOG_H
