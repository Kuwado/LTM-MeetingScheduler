/********************************************************************************
** Form generated from reading UI file 'MeetingDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEETINGDIALOG_H
#define UI_MEETINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MeetingDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *dateLabel;
    QLabel *label_2;
    QLabel *startLabel;
    QLabel *label_3;
    QLabel *endLabel;
    QLabel *label_4;
    QLabel *typeLabel;
    QLabel *label_5;
    QLabel *statusLabel;
    QLabel *label_6;
    QLabel *teacherLabel;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *reportBrowser;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *backButton;

    void setupUi(QDialog *MeetingDialog)
    {
        if (MeetingDialog->objectName().isEmpty())
            MeetingDialog->setObjectName(QString::fromUtf8("MeetingDialog"));
        MeetingDialog->resize(600, 500);
        verticalLayout = new QVBoxLayout(MeetingDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(MeetingDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        dateLabel = new QLabel(groupBox);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dateLabel);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        startLabel = new QLabel(groupBox);
        startLabel->setObjectName(QString::fromUtf8("startLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, startLabel);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        endLabel = new QLabel(groupBox);
        endLabel->setObjectName(QString::fromUtf8("endLabel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, endLabel);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        typeLabel = new QLabel(groupBox);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));

        formLayout->setWidget(3, QFormLayout::FieldRole, typeLabel);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        statusLabel = new QLabel(groupBox);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        formLayout->setWidget(4, QFormLayout::FieldRole, statusLabel);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        teacherLabel = new QLabel(groupBox);
        teacherLabel->setObjectName(QString::fromUtf8("teacherLabel"));

        formLayout->setWidget(5, QFormLayout::FieldRole, teacherLabel);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(MeetingDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        reportBrowser = new QTextBrowser(groupBox_2);
        reportBrowser->setObjectName(QString::fromUtf8("reportBrowser"));

        verticalLayout_2->addWidget(reportBrowser);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancelButton = new QPushButton(MeetingDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        backButton = new QPushButton(MeetingDialog);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout->addWidget(backButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MeetingDialog);

        QMetaObject::connectSlotsByName(MeetingDialog);
    } // setupUi

    void retranslateUi(QDialog *MeetingDialog)
    {
        MeetingDialog->setWindowTitle(QApplication::translate("MeetingDialog", "Th\303\264ng tin l\341\273\213ch h\341\272\271n", nullptr));
        groupBox->setTitle(QApplication::translate("MeetingDialog", "Th\303\264ng tin l\341\273\213ch h\341\272\271n", nullptr));
        label->setText(QApplication::translate("MeetingDialog", "Ng\303\240y:", nullptr));
        dateLabel->setText(QString());
        label_2->setText(QApplication::translate("MeetingDialog", "T\341\273\253:", nullptr));
        startLabel->setText(QString());
        label_3->setText(QApplication::translate("MeetingDialog", "\304\220\341\272\277n:", nullptr));
        endLabel->setText(QString());
        label_4->setText(QApplication::translate("MeetingDialog", "Lo\341\272\241i:", nullptr));
        typeLabel->setText(QString());
        label_5->setText(QApplication::translate("MeetingDialog", "Tr\341\272\241ng th\303\241i:", nullptr));
        statusLabel->setText(QString());
        label_6->setText(QApplication::translate("MeetingDialog", "Gi\303\241o vi\303\252n:", nullptr));
        teacherLabel->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MeetingDialog", "V\304\203n b\341\272\243n cu\341\273\231c h\341\273\215p", nullptr));
        cancelButton->setText(QApplication::translate("MeetingDialog", "H\341\273\247y l\341\273\213ch h\341\272\271n", nullptr));
        backButton->setText(QApplication::translate("MeetingDialog", "Quay l\341\272\241i", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeetingDialog: public Ui_MeetingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEETINGDIALOG_H
