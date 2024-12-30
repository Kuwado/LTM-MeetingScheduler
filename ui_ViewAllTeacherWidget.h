/********************************************************************************
** Form generated from reading UI file 'ViewAllTeacherWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWALLTEACHERWIDGET_H
#define UI_VIEWALLTEACHERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewAllTeacherWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *btnBack;

    void setupUi(QWidget *ViewAllTeacherWidget)
    {
        if (ViewAllTeacherWidget->objectName().isEmpty())
            ViewAllTeacherWidget->setObjectName(QString::fromUtf8("ViewAllTeacherWidget"));
        ViewAllTeacherWidget->resize(600, 400);
        verticalLayout = new QVBoxLayout(ViewAllTeacherWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ViewAllTeacherWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(ViewAllTeacherWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        btnBack = new QPushButton(ViewAllTeacherWidget);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));

        verticalLayout->addWidget(btnBack);


        retranslateUi(ViewAllTeacherWidget);

        QMetaObject::connectSlotsByName(ViewAllTeacherWidget);
    } // setupUi

    void retranslateUi(QWidget *ViewAllTeacherWidget)
    {
        ViewAllTeacherWidget->setWindowTitle(QApplication::translate("ViewAllTeacherWidget", "Danh s\303\241ch gi\303\241o vi\303\252n", nullptr));
        label->setText(QApplication::translate("ViewAllTeacherWidget", "Danh s\303\241ch gi\303\241o vi\303\252n", nullptr));
        btnBack->setText(QApplication::translate("ViewAllTeacherWidget", "Quay l\341\272\241i", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewAllTeacherWidget: public Ui_ViewAllTeacherWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWALLTEACHERWIDGET_H
