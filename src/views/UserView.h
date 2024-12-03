#ifndef USERVIEW_H
#define USERVIEW_H
#include <iostream>
#include <map>
#include <string>
using namespace std;

class UserView {

  public:
    // Constructor
    UserView() {};

    map<string, string> showLogin() {
        map<string, string> info;
        cout << "-----------------Dang nhap-------------------" << endl;
        cout << "Nhập tên đăng nhập: ";
        string username;
        getline(cin, username);
        info["username"] = username;

        cout << "Nhập mật khẩu: ";
        string password;
        getline(cin, password);
        info["password"] = password;

        cout << "--------------------------------------------" << endl;
        return info;
    }

    map<string, string> showRegisterA() {
        map<string, string> info;
        cout << "-----------------Dang ky-------------------" << endl;

        // Nhập tên đăng ký
        cout << "Nhập tên đăng ký: ";
        string username;
        getline(cin, username);
        info["username"] = username;

        // Nhập mật khẩu
        cout << "Nhập mật khẩu: ";
        string password;
        getline(cin, password);
        info["password"] = password;

        // Nhập vai trò
        cout << "Nhập vai trò (student/teacher): ";
        string role;
        getline(cin, role);
        info["role"] = role;

        // Nhập first name
        cout << "Nhập họ: ";
        string firstName;
        getline(cin, firstName);
        info["first_name"] = firstName;

        // Nhập last name
        cout << "Nhập tên: ";
        string lastName;
        getline(cin, lastName);
        info["last_name"] = lastName;

        cout << "--------------------------------------------" << endl;

        return info;
  }

};

#endif
