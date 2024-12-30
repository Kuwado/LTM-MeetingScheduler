/********************************************************************************
** Form generated from reading UI file 'update_timeslot_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_TIMESLOT_DIALOG_H
#define UI_UPDATE_TIMESLOT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UpdateTimeslotDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QTimeEdit *startTimeEdit;
    QLabel *label_2;
    QTimeEdit *endTimeEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioPersonal;
    QRadioButton *radioGroup;
    QRadioButton *radioBoth;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *UpdateTimeslotDialog)
    {
        if (UpdateTimeslotDialog->objectName().isEmpty())
            UpdateTimeslotDialog->setObjectName(QString::fromUtf8("UpdateTimeslotDialog"));
        UpdateTimeslotDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(UpdateTimeslotDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(UpdateTimeslotDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        startTimeEdit = new QTimeEdit(groupBox);
        startTimeEdit->setObjectName(QString::fromUtf8("startTimeEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, startTimeEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        endTimeEdit = new QTimeEdit(groupBox);
        endTimeEdit->setObjectName(QString::fromUtf8("endTimeEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, endTimeEdit);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(UpdateTimeslotDialog);
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

        buttonBox = new QDialogButtonBox(UpdateTimeslotDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(UpdateTimeslotDialog);

        QMetaObject::connectSlotsByName(UpdateTimeslotDialog);
    } // setupUi

    void retranslateUi(QDialog *UpdateTimeslotDialog)
    {
        UpdateTimeslotDialog->setWindowTitle(QApplication::translate("UpdateTimeslotDialog", "C\341\272\255p nh\341\272\255t th\341\273\235i gian r\341\272\243nh", nullptr));
        groupBox->setTitle(QApplication::translate("UpdateTimeslotDialog", "Th\341\273\235i gian", nullptr));
        label->setText(QApplication::translate("UpdateTimeslotDialog", "Th\341\273\235i gian b\341\272\257t \304\221\341\272\247u:", nullptr));
        label_2->setText(QApplication::translate("UpdateTimeslotDialog", "Th\341\273\235i gian k\341\272\277t th\303\272c:", nullptr));
        groupBox_2->setTitle(QApplication::translate("UpdateTimeslotDialog", "Lo\341\272\241i cu\341\273\231c h\341\272\271n", nullptr));
        radioPersonal->setText(QApplication::translate("UpdateTimeslotDialog", "C\303\241 nh\303\242n", nullptr));
        radioGroup->setText(QApplication::translate("UpdateTimeslotDialog", "Nh\303\263m", nullptr));
        radioBoth->setText(QApplication::translate("UpdateTimeslotDialog", "C\341\272\243 hai", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UpdateTimeslotDialog: public Ui_UpdateTimeslotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_TIMESLOT_DIALOG_H
