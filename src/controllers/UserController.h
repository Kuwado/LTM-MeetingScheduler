#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "../models/User.h"
#include "../repository/UserRepository.h"
#include <cppconn/prepared_statement.h>
#include <iostream>

using namespace std;

class UserController {
  private:
    UserRepository userRepository;

  public:
    UserController() {}

    User getUserByUsername(const string &username) {
        User user = userRepository.getUserByUsername(username);
        if (user.getId() == 0) {
            cout << "Khong co user " << endl;
            return User();
        }
        return user;
    }

    User getUserById(const int &id) {
        User user = userRepository.getUserById(id);
        return user;
    }

    void create(const User &user) { userRepository.create(user); }

    void login() {
        string username, password;
        bool loggedIn = false;

        while (!loggedIn) {
            cout << "Nhập tên đăng nhập: ";
            getline(cin, username);
            cout << "Nhập mật khẩu: ";
            getline(cin, password);
            cout << "--------------------------------------------" << endl;

            User user = userRepository.getUserByUsername(username);
            if (user.getId() == 0) {
                cout << "Tên đăng nhập không chính xác!" << endl;
            } else if (user.getPassword() != password) {
                cout << "Mật khẩu không chính xác!" << endl;
            } else {
                cout << "Xin chào, " << username << "!!!" << endl;
                loggedIn = true;
            }
        }
    }

    void registerAccount() {
        bool choiceChoosen = false, usernameExist = true;
        int choice;
        string username, password, role, first_name, last_name;
        cout << "------------------------Dang ky--------------------------" << endl;
        while (!choiceChoosen) {
            cout << "1. Hoc sinh\n" << "2. Giao vien\n" << "Ban la ai (1 hoac 2): ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
            case 1:
                role = "student";
                choiceChoosen = true;
                cout << "Ban la hoc sinh" << endl;
                break;
            case 2:
                role = "teacher";
                choiceChoosen = true;
                cout << "Ban la giao vien" << endl;
                break;
            default:
                cout << "Lua chon khong phu hop (1 hoac 2)" << endl;
                break;
            }
        }

        while (usernameExist) {
            cout << "Nhập tên đăng nhập: ";
            getline(cin, username);
            if (userRepository.checkUsernameExists(username)) {
                cout << "Ten dang nhap da ton tai" << endl;
            } else {
                usernameExist = false;
            }
        }

        cout << "Nhập mật khẩu: ";
        getline(cin, password);
        cout << "Nhập ho: ";
        getline(cin, first_name);
        cout << "Nhập ten: ";
        getline(cin, last_name);
        User user(username, password, role, first_name, last_name);
        userRepository.create(user);
        cout << "--------------------------------------------" << endl;
    }
};

#endif
