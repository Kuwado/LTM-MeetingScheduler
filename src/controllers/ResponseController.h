#ifndef RESPONSECONTROLLER_H
#define RESPONSECONTROLLER_H

#include "../models/Response.h"
#include "../models/User.h"
#include "../repository/TimeslotRepository.h"
#include "../repository/UserRepository.h"

#include <cppconn/prepared_statement.h>
#include <iostream>
#include <map>

using namespace std;

class ResponseController {
  private:
    UserRepository userRepository;
    TimeslotRepository timeslotRepo;

  public:
    ResponseController() {}

    Response viewTimeslots(const int &teacher_id) {
        Response res;
        User user = userRepository.getUserById(teacher_id);
        if (user.getId() == 0) {
            res.setStatus(8);
            res.setMessage("Giao vien khong ton tai");
        } else {
            map<string, vector<Timeslot>> timeslots = timeslotRepo.getTimeslotsByTeacherId(teacher_id);
            if (timeslots.empty()) {
                res.setStatus(9);
                res.setMessage("Giao vien khong co lich ranh");
            } else {
                string message = "";
                for (const auto &ts : timeslots) {
                    message += ts.first + "|[";
                    vector<Timeslot> tss = ts.second;
                    for (int i = 0; i < tss.size(); i++) {
                        message += "|" + tss[i].toString();
                    }
                    message += "|]|";
                }
                res.setStatus(0);
                res.setMessage(message);
            }
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
