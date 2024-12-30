/********************************************************************************
** Form generated from reading UI file 'meetinghistorydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEETINGHISTORYDIALOG_H
#define UI_MEETINGHISTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MeetingHistoryDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
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
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *reportTextEdit;
    QPushButton *editButton;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QListWidget *studentsListWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MeetingHistoryDialog)
    {
        if (MeetingHistoryDialog->objectName().isEmpty())
            MeetingHistoryDialog->setObjectName(QString::fromUtf8("MeetingHistoryDialog"));
        MeetingHistoryDialog->resize(600, 500);
        verticalLayout = new QVBoxLayout(MeetingHistoryDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(MeetingHistoryDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        dateLabel = new QLabel(groupBox);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));

        gridLayout->addWidget(dateLabel, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        startLabel = new QLabel(groupBox);
        startLabel->setObjectName(QString::fromUtf8("startLabel"));

        gridLayout->addWidget(startLabel, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        endLabel = new QLabel(groupBox);
        endLabel->setObjectName(QString::fromUtf8("endLabel"));

        gridLayout->addWidget(endLabel, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        typeLabel = new QLabel(groupBox);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));

        gridLayout->addWidget(typeLabel, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        statusLabel = new QLabel(groupBox);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        gridLayout->addWidget(statusLabel, 4, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(MeetingHistoryDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        reportTextEdit = new QTextEdit(groupBox_2);
        reportTextEdit->setObjectName(QString::fromUtf8("reportTextEdit"));
        reportTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(reportTextEdit);

        editButton = new QPushButton(groupBox_2);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        verticalLayout_2->addWidget(editButton);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(MeetingHistoryDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        studentsListWidget = new QListWidget(groupBox_3);
        studentsListWidget->setObjectName(QString::fromUtf8("studentsListWidget"));

        verticalLayout_3->addWidget(studentsListWidget);


        verticalLayout->addWidget(groupBox_3);

        buttonBox = new QDialogButtonBox(MeetingHistoryDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MeetingHistoryDialog);

        QMetaObject::connectSlotsByName(MeetingHistoryDialog);
    } // setupUi

    void retranslateUi(QDialog *MeetingHistoryDialog)
    {
        MeetingHistoryDialog->setWindowTitle(QApplication::translate("MeetingHistoryDialog", "Th\303\264ng tin l\341\273\213ch h\341\272\271n", nullptr));
        groupBox->setTitle(QApplication::translate("MeetingHistoryDialog", "Th\303\264ng tin chi ti\341\272\277t", nullptr));
        label->setText(QApplication::translate("MeetingHistoryDialog", "Ng\303\240y:", nullptr));
        dateLabel->setText(QString());
        label_2->setText(QApplication::translate("MeetingHistoryDialog", "T\341\273\253:", nullptr));
        startLabel->setText(QString());
        label_3->setText(QApplication::translate("MeetingHistoryDialog", "\304\220\341\272\277n:", nullptr));
        endLabel->setText(QString());
        label_4->setText(QApplication::translate("MeetingHistoryDialog", "Lo\341\272\241i:", nullptr));
        typeLabel->setText(QString());
        label_5->setText(QApplication::translate("MeetingHistoryDialog", "Tr\341\272\241ng th\303\241i:", nullptr));
        statusLabel->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MeetingHistoryDialog", "V\304\203n b\341\272\243n cu\341\273\231c h\341\273\215p", nullptr));
        editButton->setText(QApplication::translate("MeetingHistoryDialog", "Ch\341\273\211nh s\341\273\255a v\304\203n b\341\272\243n", nullptr));
        groupBox_3->setTitle(QApplication::translate("MeetingHistoryDialog", "Ng\306\260\341\273\235i h\341\272\271n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeetingHistoryDialog: public Ui_MeetingHistoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEETINGHISTORYDIALOG_H
