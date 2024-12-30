/********************************************************************************
** Form generated from reading UI file 'TeacherMenuWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERMENUWIDGET_H
#define UI_TEACHERMENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherMenuWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QPushButton *declareTimeSlotButton;
    QPushButton *checkAvailabilityButton;
    QPushButton *viewMeetingsButton;
    QPushButton *viewHistoryButton;
    QPushButton *viewWeeklyMeetingsButton;
    QPushButton *logoutButton;

    void setupUi(QWidget *TeacherMenuWidget)
    {
        if (TeacherMenuWidget->objectName().isEmpty())
            TeacherMenuWidget->setObjectName(QString::fromUtf8("TeacherMenuWidget"));
        TeacherMenuWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(TeacherMenuWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(TeacherMenuWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setPointSize(18);
        titleLabel->setFont(font);

        verticalLayout->addWidget(titleLabel);

        declareTimeSlotButton = new QPushButton(TeacherMenuWidget);
        declareTimeSlotButton->setObjectName(QString::fromUtf8("declareTimeSlotButton"));

        verticalLayout->addWidget(declareTimeSlotButton);

        checkAvailabilityButton = new QPushButton(TeacherMenuWidget);
        checkAvailabilityButton->setObjectName(QString::fromUtf8("checkAvailabilityButton"));

        verticalLayout->addWidget(checkAvailabilityButton);

        viewMeetingsButton = new QPushButton(TeacherMenuWidget);
        viewMeetingsButton->setObjectName(QString::fromUtf8("viewMeetingsButton"));

        verticalLayout->addWidget(viewMeetingsButton);

        viewHistoryButton = new QPushButton(TeacherMenuWidget);
        viewHistoryButton->setObjectName(QString::fromUtf8("viewHistoryButton"));

        verticalLayout->addWidget(viewHistoryButton);

        viewWeeklyMeetingsButton = new QPushButton(TeacherMenuWidget);
        viewWeeklyMeetingsButton->setObjectName(QString::fromUtf8("viewWeeklyMeetingsButton"));

        verticalLayout->addWidget(viewWeeklyMeetingsButton);

        logoutButton = new QPushButton(TeacherMenuWidget);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));

        verticalLayout->addWidget(logoutButton);


        retranslateUi(TeacherMenuWidget);

        QMetaObject::connectSlotsByName(TeacherMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *TeacherMenuWidget)
    {
        TeacherMenuWidget->setWindowTitle(QApplication::translate("TeacherMenuWidget", "Teacher Menu", nullptr));
        titleLabel->setText(QApplication::translate("TeacherMenuWidget", "Teacher Menu", nullptr));
        declareTimeSlotButton->setText(QApplication::translate("TeacherMenuWidget", "Khai b\303\241o th\341\273\235i gian r\341\272\243nh", nullptr));
        checkAvailabilityButton->setText(QApplication::translate("TeacherMenuWidget", "Ki\341\273\203m tra th\341\273\235i gian r\341\272\243nh", nullptr));
        viewMeetingsButton->setText(QApplication::translate("TeacherMenuWidget", "Xem l\341\273\213ch h\341\272\271n v\341\273\233i sinh vi\303\252n", nullptr));
        viewHistoryButton->setText(QApplication::translate("TeacherMenuWidget", "Xem l\341\273\213ch s\341\273\255 cu\341\273\231c h\341\272\271n", nullptr));
        viewWeeklyMeetingsButton->setText(QApplication::translate("TeacherMenuWidget", "Xem l\341\273\213ch h\341\272\271n theo tu\341\272\247n", nullptr));
        logoutButton->setText(QApplication::translate("TeacherMenuWidget", "\304\220\304\203ng xu\341\272\245t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherMenuWidget: public Ui_TeacherMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERMENUWIDGET_H
