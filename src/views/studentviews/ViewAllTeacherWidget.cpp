#include "ViewAllTeacherWidget.h"
#include "../../../ui_ViewAllTeacherWidget.h"
#include <QMessageBox>


ViewAllTeacherWidget::ViewAllTeacherWidget(const std::vector<User> &teachers, QWidget *parent)
    : QWidget(parent), ui(new Ui::ViewAllTeacherWidget), teacherList(teachers) {
    ui->setupUi(this);

    // Cấu hình bảng
    ui->teacherTable->setColumnCount(2);
    ui->teacherTable->setHorizontalHeaderLabels(QStringList() << "Họ tên" << "ID");
    ui->teacherTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->teacherTable->setSelectionMode(QAbstractItemView::SingleSelection);

    // Thêm dữ liệu vào bảng
    for (size_t i = 0; i < teachers.size(); ++i) {
        ui->teacherTable->insertRow(i);
        ui->teacherTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(teachers[i].getFirstName() + " " + teachers[i].getLastName())));
        ui->teacherTable->setItem(i, 1, new QTableWidgetItem(QString::number(teachers[i].getId())));
    }

    // Kết nối nút "Xem"
    connect(ui->viewButton, &QPushButton::clicked, this, [this]() {
        auto selectedItems = ui->teacherTable->selectedItems();
        if (!selectedItems.isEmpty()) {
            int row = selectedItems.first()->row();
            std::pair<std::string, int> teacher = {
                teacherList[row].getFirstName() + " " + teacherList[row].getLastName(),
                teacherList[row].getId()
            };
            emit teacherSelected(teacher);
            close();
        } else {
            QMessageBox::warning(this, "Lỗi", "Vui lòng chọn một giáo viên!");
        }
    });
}

ViewAllTeacherWidget::~ViewAllTeacherWidget() {
    delete ui;
}

std::pair<std::string, int> ViewAllTeacherWidget::getSelectedTeacher() {
    auto selectedItems = ui->teacherTable->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();
        return {teacherList[row].getFirstName() + " " + teacherList[row].getLastName(), teacherList[row].getId()};
    }
    return {"", -1};
}
