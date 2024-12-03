#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "../models/Response.h"
#include "../models/User.h"
#include "../repository/UserRepository.h"
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <map>

using namespace std;

class UserController {
  private:
    UserRepository userRepository;

  public:
    UserController() {}

    Response login(const string &username, const string &password) {
        Response res;
        User user = userRepository.getUserByUsername(username);
        if (user.getId() == 0) {
            res.setStatus(1);
            res.setMessage("Tên đăng nhập không chính xác!");
        } else if (user.getPassword() != password) {
            res.setStatus(2);
            res.setMessage("Mật khẩu không chính xác!");
        } else {
            res.setStatus(0);
            res.setMessage("Dang nhap thanh cong");
        }

        return res;
    }

    Response registerA(const string &username) {
        Response res;
        User user = userRepository.getUserByUsername(username);
        if (user.getId() != 0) {
            res.setStatus(3);
            res.setMessage("Tên đăng nhập da ton tai!");
        } else {
            res.setStatus(0);
            res.setMessage("Dang ky thanh cong");
        }

        return res;
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
