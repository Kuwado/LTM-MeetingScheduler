#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H
#include <iostream>
#include <map>
#include <string>
using namespace std;

class StudentView {

  public:
    // Constructor
    StudentView() {};
    int showTimeslot() {
        int teacher_id;
        cout << "-----------------Xem danh sach thoi gian ranh-------------------" << endl;
        cout << "Nhập teacher_id: ";
        cin >> teacher_id;

        cout << "--------------------------------------------" << endl;
        return teacher_id;
    }
  
};

#endif
