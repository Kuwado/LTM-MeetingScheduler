/********************************************************************************
** Form generated from reading UI file 'registerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIDGET_H
#define UI_REGISTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QLabel *roleLabel;
    QHBoxLayout *roleLayout;
    QRadioButton *studentRadio;
    QRadioButton *teacherRadio;
    QLabel *firstNameLabel;
    QLineEdit *firstNameLineEdit;
    QLabel *lastNameLabel;
    QLineEdit *lastNameLineEdit;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *backButton;
    QPushButton *registerButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *RegisterWidget)
    {
        if (RegisterWidget->objectName().isEmpty())
            RegisterWidget->setObjectName(QString::fromUtf8("RegisterWidget"));
        RegisterWidget->resize(400, 500);
        RegisterWidget->setStyleSheet(QString::fromUtf8("\n"
"    QWidget {\n"
"        background-color: #f0f0f0;\n"
"        font-family: Arial;\n"
"    }\n"
"    QLabel {\n"
"        color: #333333;\n"
"    }\n"
"    QLineEdit {\n"
"        padding: 8px;\n"
"        border: 1px solid #999;\n"
"        border-radius: 4px;\n"
"        background-color: white;\n"
"        min-height: 20px;\n"
"    }\n"
"    QPushButton {\n"
"      padding: 8px 16px;\n"
"      border-radius: 4px;\n"
"      min-width: 100px;\n"
"      background-color: #2196F3;\n"
"      color: white;\n"
"      border: none;\n"
"    }\n"
"    QPushButton#registerButton {\n"
"        background-color: #34a853;\n"
"    }\n"
"    QPushButton#registerButton:hover {\n"
"        background-color: #2d8544;\n"
"    }\n"
"    QPushButton#registerButton:disabled {\n"
"        background-color: #cccccc;\n"
"    }\n"
"    QPushButton#backButton {\n"
"        background-color: #757575;\n"
"    }\n"
"    QPushButton#backButton:hover {\n"
"        background-color: #616161;\n"
"    }\n"
"    QRadioButton {\n"
"     "
                        "   color: #333333;\n"
"        spacing: 8px;\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(RegisterWidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(RegisterWidget);
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
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(15);
        usernameLabel = new QLabel(RegisterWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameLabel);

        usernameLineEdit = new QLineEdit(RegisterWidget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameLineEdit);

        passwordLabel = new QLabel(RegisterWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(RegisterWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordLineEdit);

        roleLabel = new QLabel(RegisterWidget);
        roleLabel->setObjectName(QString::fromUtf8("roleLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, roleLabel);

        roleLayout = new QHBoxLayout();
        roleLayout->setObjectName(QString::fromUtf8("roleLayout"));
        studentRadio = new QRadioButton(RegisterWidget);
        studentRadio->setObjectName(QString::fromUtf8("studentRadio"));

        roleLayout->addWidget(studentRadio);

        teacherRadio = new QRadioButton(RegisterWidget);
        teacherRadio->setObjectName(QString::fromUtf8("teacherRadio"));

        roleLayout->addWidget(teacherRadio);


        formLayout->setLayout(2, QFormLayout::FieldRole, roleLayout);

        firstNameLabel = new QLabel(RegisterWidget);
        firstNameLabel->setObjectName(QString::fromUtf8("firstNameLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, firstNameLabel);

        firstNameLineEdit = new QLineEdit(RegisterWidget);
        firstNameLineEdit->setObjectName(QString::fromUtf8("firstNameLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, firstNameLineEdit);

        lastNameLabel = new QLabel(RegisterWidget);
        lastNameLabel->setObjectName(QString::fromUtf8("lastNameLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lastNameLabel);

        lastNameLineEdit = new QLineEdit(RegisterWidget);
        lastNameLineEdit->setObjectName(QString::fromUtf8("lastNameLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lastNameLineEdit);


        verticalLayout->addLayout(formLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        backButton = new QPushButton(RegisterWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        buttonLayout->addWidget(backButton);

        registerButton = new QPushButton(RegisterWidget);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setEnabled(false);

        buttonLayout->addWidget(registerButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(RegisterWidget);

        QMetaObject::connectSlotsByName(RegisterWidget);
    } // setupUi

    void retranslateUi(QWidget *RegisterWidget)
    {
        RegisterWidget->setWindowTitle(QApplication::translate("RegisterWidget", "\304\220\304\203ng k\303\275 t\303\240i kho\341\272\243n", nullptr));
        titleLabel->setText(QApplication::translate("RegisterWidget", "\304\220\304\202NG K\303\235 T\303\200I KHO\341\272\242N", nullptr));
        usernameLabel->setText(QApplication::translate("RegisterWidget", "T\303\252n \304\221\304\203ng k\303\275:", nullptr));
        passwordLabel->setText(QApplication::translate("RegisterWidget", "M\341\272\255t kh\341\272\251u:", nullptr));
        roleLabel->setText(QApplication::translate("RegisterWidget", "Vai tr\303\262:", nullptr));
        studentRadio->setText(QApplication::translate("RegisterWidget", "Sinh vi\303\252n", nullptr));
        teacherRadio->setText(QApplication::translate("RegisterWidget", "Gi\303\241o vi\303\252n", nullptr));
        firstNameLabel->setText(QApplication::translate("RegisterWidget", "H\341\273\215:", nullptr));
        lastNameLabel->setText(QApplication::translate("RegisterWidget", "T\303\252n:", nullptr));
        backButton->setText(QApplication::translate("RegisterWidget", "Quay l\341\272\241i", nullptr));
        registerButton->setText(QApplication::translate("RegisterWidget", "\304\220\304\203ng k\303\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWidget: public Ui_RegisterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIDGET_H
