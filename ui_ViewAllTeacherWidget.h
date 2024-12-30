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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewAllTeacherWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *teacherTable;
    QPushButton *viewButton;

    void setupUi(QWidget *ViewAllTeacherWidget)
    {
        if (ViewAllTeacherWidget->objectName().isEmpty())
            ViewAllTeacherWidget->setObjectName(QString::fromUtf8("ViewAllTeacherWidget"));
        ViewAllTeacherWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(ViewAllTeacherWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        teacherTable = new QTableWidget(ViewAllTeacherWidget);
        if (teacherTable->columnCount() < 2)
            teacherTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        teacherTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        teacherTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        teacherTable->setObjectName(QString::fromUtf8("teacherTable"));

        verticalLayout->addWidget(teacherTable);

        viewButton = new QPushButton(ViewAllTeacherWidget);
        viewButton->setObjectName(QString::fromUtf8("viewButton"));

        verticalLayout->addWidget(viewButton);


        retranslateUi(ViewAllTeacherWidget);

        QMetaObject::connectSlotsByName(ViewAllTeacherWidget);
    } // setupUi

    void retranslateUi(QWidget *ViewAllTeacherWidget)
    {
        ViewAllTeacherWidget->setWindowTitle(QApplication::translate("ViewAllTeacherWidget", "Xem danh s\303\241ch gi\303\241o vi\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem = teacherTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ViewAllTeacherWidget", "H\341\273\215 t\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = teacherTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ViewAllTeacherWidget", "ID", nullptr));
        viewButton->setText(QApplication::translate("ViewAllTeacherWidget", "Xem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewAllTeacherWidget: public Ui_ViewAllTeacherWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWALLTEACHERWIDGET_H
