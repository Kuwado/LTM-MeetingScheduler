/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_1;
    QLabel *titleLabel;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *backButton;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(400, 300);
        LoginWidget->setStyleSheet(QString::fromUtf8("\n"
"    QWidget {\n"
"      background-color: #f0f0f0;\n"
"      font-size: 12pt;\n"
"    }\n"
"    QLineEdit {\n"
"      padding: 5px;\n"
"      border: 1px solid #999;\n"
"      border-radius: 4px;\n"
"      background-color: white;\n"
"    }\n"
"    QPushButton {\n"
"      padding: 8px 16px;\n"
"      border-radius: 4px;\n"
"      min-width: 100px;\n"
"      background-color: #2196F3;\n"
"      color: white;\n"
"      border: none;\n"
"    }\n"
"    QPushButton:hover {\n"
"      background-color: #1976D2;\n"
"    }\n"
"    QPushButton#backButton {\n"
"      background-color: #757575;\n"
"    }\n"
"    QPushButton#backButton:hover {\n"
"      background-color: #616161;\n"
"    }\n"
"    QLabel {\n"
"      color: #333;\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(LoginWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_1);

        titleLabel = new QLabel(LoginWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(15);
        usernameLabel = new QLabel(LoginWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameLabel);

        usernameLineEdit = new QLineEdit(LoginWidget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));
        usernameLineEdit->setMinimumSize(QSize(200, 30));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameLineEdit);

        passwordLabel = new QLabel(LoginWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(LoginWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setMinimumSize(QSize(200, 30));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordLineEdit);


        verticalLayout->addLayout(formLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        backButton = new QPushButton(LoginWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        buttonLayout->addWidget(backButton);

        loginButton = new QPushButton(LoginWidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        buttonLayout->addWidget(loginButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(buttonLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QApplication::translate("LoginWidget", "\304\220\304\203ng nh\341\272\255p", nullptr));
        titleLabel->setText(QApplication::translate("LoginWidget", "\304\220\304\202NG NH\341\272\254P H\341\273\206 TH\341\273\220NG", nullptr));
        usernameLabel->setText(QApplication::translate("LoginWidget", "T\303\252n \304\221\304\203ng nh\341\272\255p:", nullptr));
        passwordLabel->setText(QApplication::translate("LoginWidget", "M\341\272\255t kh\341\272\251u:", nullptr));
        backButton->setText(QApplication::translate("LoginWidget", "Quay l\341\272\241i", nullptr));
        loginButton->setText(QApplication::translate("LoginWidget", "\304\220\304\203ng nh\341\272\255p", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
