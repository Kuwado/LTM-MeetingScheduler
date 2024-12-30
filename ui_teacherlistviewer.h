/********************************************************************************
** Form generated from reading UI file 'teacherlistviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERLISTVIEWER_H
#define UI_TEACHERLISTVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TeacherListViewer
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TeacherListViewer)
    {
        if (TeacherListViewer->objectName().isEmpty())
            TeacherListViewer->setObjectName(QString::fromUtf8("TeacherListViewer"));
        TeacherListViewer->resize(400, 300);
        verticalLayout = new QVBoxLayout(TeacherListViewer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(TeacherListViewer);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(TeacherListViewer);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(TeacherListViewer);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TeacherListViewer);

        QMetaObject::connectSlotsByName(TeacherListViewer);
    } // setupUi

    void retranslateUi(QDialog *TeacherListViewer)
    {
        TeacherListViewer->setWindowTitle(QApplication::translate("TeacherListViewer", "Danh s\303\241ch gi\303\241o vi\303\252n", nullptr));
        label->setText(QApplication::translate("TeacherListViewer", "Ch\341\273\215n gi\303\241o vi\303\252n:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherListViewer: public Ui_TeacherListViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERLISTVIEWER_H
