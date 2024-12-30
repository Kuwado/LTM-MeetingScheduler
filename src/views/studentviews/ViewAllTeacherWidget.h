#ifndef VIEWALLTEACHERWIDGET_H
#define VIEWALLTEACHERWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include "../../models/User.h"


namespace Ui {
class ViewAllTeacherWidget;
}

class ViewAllTeacherWidget : public QWidget {
    Q_OBJECT

public:
    explicit ViewAllTeacherWidget(const std::vector<User> &teachers, QWidget *parent = nullptr);
    ~ViewAllTeacherWidget();

    std::pair<std::string, int> getSelectedTeacher();

signals:
    void teacherSelected(const std::pair<std::string, int> &teacher);

private:
    Ui::ViewAllTeacherWidget *ui;
    std::vector<User> teacherList;
};

#endif // VIEWALLTEACHERWIDGET_H
