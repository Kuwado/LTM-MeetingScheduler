/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_1;
    QLabel *titleLabel;
    QLabel *studentLabel;
    QLabel *teacherLabel;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer_1;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(600, 500);
        MainMenu->setStyleSheet(QString::fromUtf8("\n"
"    QWidget {\n"
"        background-color: #f0f0f0;\n"
"        font-family: Arial;\n"
"    }\n"
"    QLabel {\n"
"        color: #333333;\n"
"    }\n"
"    QLabel#titleLabel {\n"
"        font-size: 24pt;\n"
"        font-weight: bold;\n"
"        color: #1a73e8;\n"
"        padding: 10px;\n"
"    }\n"
"    QLabel#studentLabel, QLabel#teacherLabel {\n"
"        font-size: 12pt;\n"
"        margin-top: 10px;\n"
"    }\n"
"    QPushButton {\n"
"        font-size: 14pt;\n"
"        padding: 12px 30px;\n"
"        border-radius: 8px;\n"
"        border: none;\n"
"        color: white;\n"
"        min-width: 200px;\n"
"    }\n"
"    QPushButton#loginButton {\n"
"        background-color: #1a73e8;\n"
"    }\n"
"    QPushButton#loginButton:hover {\n"
"        background-color: #1557b0;\n"
"    }\n"
"    QPushButton#registerButton {\n"
"        background-color: #34a853;\n"
"    }\n"
"    QPushButton#registerButton:hover {\n"
"        background-color: #2d8544;\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(MainMenu);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(40, -1, 40, -1);
        verticalSpacer_1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_1);

        titleLabel = new QLabel(MainMenu);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        studentLabel = new QLabel(MainMenu);
        studentLabel->setObjectName(QString::fromUtf8("studentLabel"));
        studentLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(studentLabel);

        teacherLabel = new QLabel(MainMenu);
        teacherLabel->setObjectName(QString::fromUtf8("teacherLabel"));
        teacherLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(teacherLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_1);

        loginButton = new QPushButton(MainMenu);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        buttonLayout->addWidget(loginButton);

        registerButton = new QPushButton(MainMenu);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));

        buttonLayout->addWidget(registerButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(buttonLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "\341\273\250ng d\341\273\245ng Qu\341\272\243n l\303\275 Cu\341\273\231c h\341\273\215p", nullptr));
        titleLabel->setText(QApplication::translate("MainMenu", "\341\273\250NG D\341\273\244NG QU\341\272\242N L\303\235 CU\341\273\230C H\341\273\214P", nullptr));
        studentLabel->setText(QApplication::translate("MainMenu", "Sinh vi\303\252n th\341\273\261c hi\341\273\207n:\n"
"\342\200\242 L\306\260u Vi\341\273\207t Ho\303\240n 20215054\n"
"\342\200\242 H\303\240 \304\220\303\254nh Nam 20215095\n"
"\342\200\242 Ph\341\272\241m Ho\303\240ng H\341\272\243i Nam 20215099", nullptr));
        teacherLabel->setText(QApplication::translate("MainMenu", "Gi\303\241o vi\303\252n h\306\260\341\273\233ng d\341\272\253n: C\303\264 Tr\306\260\306\241ng Th\341\273\213 Di\341\273\207u Linh", nullptr));
        loginButton->setText(QApplication::translate("MainMenu", "\304\220\304\203ng nh\341\272\255p", nullptr));
        registerButton->setText(QApplication::translate("MainMenu", "\304\220\304\203ng k\303\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
