/********************************************************************************
** Form generated from reading UI file 'timeslotdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESLOTDIALOG_H
#define UI_TIMESLOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TimeslotDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QDateEdit *dateEdit;
    QLabel *label_2;
    QTimeEdit *startTimeEdit;
    QLabel *label_3;
    QTimeEdit *endTimeEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioPersonal;
    QRadioButton *radioGroup;
    QRadioButton *radioBoth;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TimeslotDialog)
    {
        if (TimeslotDialog->objectName().isEmpty())
            TimeslotDialog->setObjectName(QString::fromUtf8("TimeslotDialog"));
        TimeslotDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(TimeslotDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(TimeslotDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dateEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        startTimeEdit = new QTimeEdit(groupBox);
        startTimeEdit->setObjectName(QString::fromUtf8("startTimeEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, startTimeEdit);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        endTimeEdit = new QTimeEdit(groupBox);
        endTimeEdit->setObjectName(QString::fromUtf8("endTimeEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, endTimeEdit);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(TimeslotDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioPersonal = new QRadioButton(groupBox_2);
        radioPersonal->setObjectName(QString::fromUtf8("radioPersonal"));
        radioPersonal->setChecked(true);

        verticalLayout_2->addWidget(radioPersonal);

        radioGroup = new QRadioButton(groupBox_2);
        radioGroup->setObjectName(QString::fromUtf8("radioGroup"));

        verticalLayout_2->addWidget(radioGroup);

        radioBoth = new QRadioButton(groupBox_2);
        radioBoth->setObjectName(QString::fromUtf8("radioBoth"));

        verticalLayout_2->addWidget(radioBoth);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(TimeslotDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TimeslotDialog);

        QMetaObject::connectSlotsByName(TimeslotDialog);
    } // setupUi

    void retranslateUi(QDialog *TimeslotDialog)
    {
        TimeslotDialog->setWindowTitle(QApplication::translate("TimeslotDialog", "Khai b\303\241o th\341\273\235i gian r\341\272\243nh", nullptr));
        groupBox->setTitle(QApplication::translate("TimeslotDialog", "Th\341\273\235i gian", nullptr));
        label->setText(QApplication::translate("TimeslotDialog", "Ng\303\240y:", nullptr));
        label_2->setText(QApplication::translate("TimeslotDialog", "Th\341\273\235i gian b\341\272\257t \304\221\341\272\247u:", nullptr));
        label_3->setText(QApplication::translate("TimeslotDialog", "Th\341\273\235i gian k\341\272\277t th\303\272c:", nullptr));
        groupBox_2->setTitle(QApplication::translate("TimeslotDialog", "Lo\341\272\241i cu\341\273\231c h\341\272\271n", nullptr));
        radioPersonal->setText(QApplication::translate("TimeslotDialog", "C\303\241 nh\303\242n", nullptr));
        radioGroup->setText(QApplication::translate("TimeslotDialog", "Nh\303\263m", nullptr));
        radioBoth->setText(QApplication::translate("TimeslotDialog", "C\341\272\243 hai", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeslotDialog: public Ui_TimeslotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESLOTDIALOG_H
