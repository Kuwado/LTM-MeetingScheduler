/********************************************************************************
** Form generated from reading UI file 'StudentMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTMENU_H
#define UI_STUDENTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StudentMenu
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *scheduleButton;
    QPushButton *viewMeetingsButton;
    QPushButton *logoutButton;

    void setupUi(QDialog *StudentMenu)
    {
        if (StudentMenu->objectName().isEmpty())
            StudentMenu->setObjectName(QString::fromUtf8("StudentMenu"));
        StudentMenu->resize(300, 200);
        verticalLayout = new QVBoxLayout(StudentMenu);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scheduleButton = new QPushButton(StudentMenu);
        scheduleButton->setObjectName(QString::fromUtf8("scheduleButton"));

        verticalLayout->addWidget(scheduleButton);

        viewMeetingsButton = new QPushButton(StudentMenu);
        viewMeetingsButton->setObjectName(QString::fromUtf8("viewMeetingsButton"));

        verticalLayout->addWidget(viewMeetingsButton);

        logoutButton = new QPushButton(StudentMenu);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));

        verticalLayout->addWidget(logoutButton);


        retranslateUi(StudentMenu);

        QMetaObject::connectSlotsByName(StudentMenu);
    } // setupUi

    void retranslateUi(QDialog *StudentMenu)
    {
        StudentMenu->setWindowTitle(QApplication::translate("StudentMenu", "Student Menu", nullptr));
        scheduleButton->setText(QApplication::translate("StudentMenu", "Xem v\303\240 \304\221\341\272\267t l\341\273\213ch r\341\272\243nh c\341\273\247a gi\303\241o vi\303\252n", nullptr));
        viewMeetingsButton->setText(QApplication::translate("StudentMenu", "Xem l\341\273\213ch g\341\272\267p trong tu\341\272\247n", nullptr));
        logoutButton->setText(QApplication::translate("StudentMenu", "\304\220\304\203ng xu\341\272\245t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentMenu: public Ui_StudentMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTMENU_H
