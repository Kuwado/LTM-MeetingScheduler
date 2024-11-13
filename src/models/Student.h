#ifndef STUDENT_H
#define STUDENT_H
#include "user/User.h"

#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

class Student : public User {
public:

    Student(const string& uname, const string& pass) : User(uname, pass, "student") {}

    void registerUser() override {
        cout << "Nhập tên đăng nhập của học sinh: ";
        getline(cin, username);
        cout << "Nhập mật khẩu của học sinh: ";
        getline(cin, password);

        ofstream outFile("../data/students.txt", ios::app);
        if (!outFile) {
            cerr << "Lỗi mở file" << endl;
            return;
        }
        outFile << "Username: " << username << ", Password: " << password << endl;
        outFile.close();

        cout << "Đăng ký thành công tài khoản học sinh!" << endl;
    }

    void viewSchedule() {

    }

    void bookMeeting() {

    }
};

#endif