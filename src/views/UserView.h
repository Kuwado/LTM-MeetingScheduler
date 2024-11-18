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
};

#endif
