/********************************************************************************
** Form generated from reading UI file 'meetingbooking.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEETINGBOOKING_H
#define UI_MEETINGBOOKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MeetingBooking
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *infoGroupBox;
    QFormLayout *formLayout;
    QLabel *dateLabelTitle;
    QLabel *dateLabel;
    QLabel *timeLabelTitle;
    QLabel *timeLabel;
    QLabel *typeLabelTitle;
    QLabel *typeLabel;
    QGroupBox *typeGroupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *personalRadio;
    QRadioButton *groupRadio;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MeetingBooking)
    {
        if (MeetingBooking->objectName().isEmpty())
            MeetingBooking->setObjectName(QString::fromUtf8("MeetingBooking"));
        MeetingBooking->resize(400, 300);
        verticalLayout = new QVBoxLayout(MeetingBooking);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        infoGroupBox = new QGroupBox(MeetingBooking);
        infoGroupBox->setObjectName(QString::fromUtf8("infoGroupBox"));
        formLayout = new QFormLayout(infoGroupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        dateLabelTitle = new QLabel(infoGroupBox);
        dateLabelTitle->setObjectName(QString::fromUtf8("dateLabelTitle"));

        formLayout->setWidget(0, QFormLayout::LabelRole, dateLabelTitle);

        dateLabel = new QLabel(infoGroupBox);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dateLabel);

        timeLabelTitle = new QLabel(infoGroupBox);
        timeLabelTitle->setObjectName(QString::fromUtf8("timeLabelTitle"));

        formLayout->setWidget(1, QFormLayout::LabelRole, timeLabelTitle);

        timeLabel = new QLabel(infoGroupBox);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, timeLabel);

        typeLabelTitle = new QLabel(infoGroupBox);
        typeLabelTitle->setObjectName(QString::fromUtf8("typeLabelTitle"));

        formLayout->setWidget(2, QFormLayout::LabelRole, typeLabelTitle);

        typeLabel = new QLabel(infoGroupBox);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, typeLabel);


        verticalLayout->addWidget(infoGroupBox);

        typeGroupBox = new QGroupBox(MeetingBooking);
        typeGroupBox->setObjectName(QString::fromUtf8("typeGroupBox"));
        verticalLayout_2 = new QVBoxLayout(typeGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        personalRadio = new QRadioButton(typeGroupBox);
        personalRadio->setObjectName(QString::fromUtf8("personalRadio"));

        verticalLayout_2->addWidget(personalRadio);

        groupRadio = new QRadioButton(typeGroupBox);
        groupRadio->setObjectName(QString::fromUtf8("groupRadio"));

        verticalLayout_2->addWidget(groupRadio);


        verticalLayout->addWidget(typeGroupBox);

        buttonBox = new QDialogButtonBox(MeetingBooking);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MeetingBooking);

        QMetaObject::connectSlotsByName(MeetingBooking);
    } // setupUi

    void retranslateUi(QDialog *MeetingBooking)
    {
        MeetingBooking->setWindowTitle(QApplication::translate("MeetingBooking", "\304\220\341\272\267t l\341\273\213ch h\341\272\271n", nullptr));
        infoGroupBox->setTitle(QApplication::translate("MeetingBooking", "Th\303\264ng tin l\341\273\213ch h\341\272\271n", nullptr));
        dateLabelTitle->setText(QApplication::translate("MeetingBooking", "Ng\303\240y:", nullptr));
        dateLabel->setText(QString());
        timeLabelTitle->setText(QApplication::translate("MeetingBooking", "Th\341\273\235i gian:", nullptr));
        timeLabel->setText(QString());
        typeLabelTitle->setText(QApplication::translate("MeetingBooking", "Lo\341\272\241i cu\341\273\231c h\341\273\215p:", nullptr));
        typeLabel->setText(QString());
        typeGroupBox->setTitle(QApplication::translate("MeetingBooking", "Ch\341\273\215n lo\341\272\241i cu\341\273\231c h\341\273\215p", nullptr));
        personalRadio->setText(QApplication::translate("MeetingBooking", "C\303\241 nh\303\242n", nullptr));
        groupRadio->setText(QApplication::translate("MeetingBooking", "Nh\303\263m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeetingBooking: public Ui_MeetingBooking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEETINGBOOKING_H
