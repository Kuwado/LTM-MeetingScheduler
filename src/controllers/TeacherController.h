#ifndef TEACHERCONTROLLER_H
#define TEACHERCONTROLLER_H

#include "../models/User.h"
#include "../repository/TimeslotRepository.h"
#include "../utils/Utils.h"
#include <cppconn/prepared_statement.h>
#include <iostream>

using namespace std;

class TeacherController {
  private:
    TimeslotRepository timeslotRepository;
    Utils utils;

  public:
    TeacherController() {}

    void declareTimeslot(const int &teacher_id) {
        string startH, startM, endH, endM, day, month, year, type;
        bool done = false, typechosen = false;
        cout << "------------------------Khai bao thoi gian ranh--------------------------" << endl;

        while (!done) {
            cout << "Nhập thoi gian bat dau:" << endl;
            while (!utils.checkHour(startH)) {
                cout << "- Gio: ";
                getline(cin, startH);
                if (!utils.checkHour(startH)) {
                    cout << "Gio khong hop le!" << endl;
                }
            }
            while (!utils.checkMinute(startM)) {
                cout << "- Phut: ";
                getline(cin, startM);
                if (!utils.checkMinute(startM)) {
                    cout << "Phut khong hop le!" << endl;
                }
            }

            cout << "Nhập thoi gian ket thuc:" << endl;
            while (!utils.checkHour(endH)) {
                cout << "- Gio: ";
                getline(cin, endH);
                if (!utils.checkHour(endH)) {
                    cout << "Gio khong hop le!" << endl;
                }
            }
            while (!utils.checkMinute(endM)) {
                cout << "- Phut: ";
                getline(cin, endM);
                if (!utils.checkMinute(endM)) {
                    cout << "Phut khong hop le!" << endl;
                }
            }

            while (!utils.checkDay(day)) {
                cout << "Ngay: ";
                getline(cin, day);
                if (!utils.checkDay(day)) {
                    cout << "Ngay khong hop le!" << endl;
                }
            }
            while (!utils.checkMonth(month)) {
                cout << "Thang: ";
                getline(cin, month);
                if (!utils.checkMonth(month)) {
                    cout << "Thang khong hop le!" << endl;
                }
            }
            while (!utils.checkYear(year)) {
                cout << "Nam: ";
                getline(cin, year);
                if (!utils.checkYear(year)) {
                    cout << "Nam khong hop le!" << endl;
                }
            }

            while (!typechosen) {
                int choice = 0;
                cout << "Loai cuoc hen: 1. Ca nhan; 2. Nhom; 3. Ca hai;" << endl;
                cin >> choice;
                cin.ignore();
                switch (choice) {
                case 1:
                    type = "personal";
                    typechosen = true;
                    break;
                case 2:
                    type = "group";
                    typechosen = true;
                    break;
                case 3:
                    type = "both";
                    typechosen = true;
                    break;
                default:
                    cout << "Lua chon khong hop le" << endl;
                    break;
                }
            }

            cout << "--------------------------------------------" << endl;
            string start = startH + ":" + startM;
            string end = endH + ":" + endM;
            string date = year + "-" + month + "-" + day;
            Timeslot ts(start, end, date, type, teacher_id);
            timeslotRepository.create(ts);
            done = true;
        }
    }
};

#endif
