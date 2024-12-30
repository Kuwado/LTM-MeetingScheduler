#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H
<<<<<<< HEAD
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
=======

#include "../controllers/StudentController.h"
#include "../models/Timeslot.h"
#include <iostream>
#include <vector>
using namespace std;

class StudentView {
  public:
    StudentView() {}

    int showMenu() {
        int choice;
        while (true) {
            cout << "----------------Student Menu----------------" << endl;
            cout << "1. Xem va dat lich ranh cua giao vien" << endl;
            cout << "2. Huy lich gap giao vien" << endl;
            cout << "3. Xem lich gap trong 1 tuan" << endl;
            cout << "0. Dang xuat" << endl;
            cout << "Ban muon thuc hien chuc nang nao?" << endl;
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 0:
            case 1:
            case 2:
            case 3:
                return choice;
                break;
            default:
                cout << "Lua chon khong hop le, vui long thu lai!" << endl;
                break;
            }
        }
    }

    pair<string, int> showAllTeacher(const vector<User> &teachers) {
        pair<string, int> teacher;
        if (teachers.empty()) {
            cout << "Không có giáo viên nào để chọn." << endl;
            teacher.second = -1;
            return teacher;
        }

        cout << "------------Danh sách giáo viên------------" << endl;
        for (int i = 0; i < teachers.size(); i++) {
            cout << i + 1 << ". " << teachers[i].getFirstName() << " " << teachers[i].getLastName()
                 << " (ID: " << teachers[i].getId() << ")" << endl;
        }
        cout << "------------------------------------------" << endl;

        int choice;
        while (true) {
            cout << "Nhập số thứ tự của giáo viên bạn muốn xem: ";
            cin >> choice;
            cin.ignore();

            if (choice > 0 && choice <= teachers.size()) {
                teacher.first = teachers[choice - 1].getFirstName() + " " + teachers[choice - 1].getLastName();
                teacher.second = teachers[choice - 1].getId();
                return teacher;
            } else if (choice == 0) {
                teacher.second = -1;
                return teacher;
            }
            cout << "Lựa chọn không hợp lệ, vui lòng thử lại!" << endl;
        }
    }

    Timeslot showTimeslots(const map<string, vector<Timeslot>> &timeslots, const string &teacherName) {
        if (timeslots.empty()) {
            Timeslot ts;
            cout << "Ban chua khai bao thoi gian ranh" << endl;
            return ts;
        }

        map<int, Timeslot> editTimeslots;
        int index = 0, choice = 0;
        cout << "------------------Thoi gian ranh cua " << teacherName << "-------------------" << endl;
        for (const auto &ts : timeslots) {
            cout << "--Ngay: " << ts.first << endl;
            vector<Timeslot> tss = ts.second;
            for (int i = 0; i < tss.size(); i++) {
                index++;
                editTimeslots[index] = tss[i];
                cout << index << ". Tu: " << tss[i].getStart() << " - Den: " << tss[i].getEnd() << "( "
                     << tss[i].getType() << " )" << endl;
            }
        }

        cout << "-----------" << endl;
        while (true) {
            cout << "Ban co muon dang ky thoi gian nao? Nhap so dong can sua: ";
            cin >> choice;
            cin.ignore();
            if (choice > 0 && choice <= editTimeslots.size()) {
                return editTimeslots[choice];
            } else if (choice == 0) {
                Timeslot ts;
                ts.setId(-1);
                return ts;
            }
        }
    }

    Meeting showBookMeeting(const Timeslot &timeslot, const string &teacherName) {
        Meeting meeting;
        string type = timeslot.getType();
        cout << "Dat lich hen voi giao vien " << teacherName << endl;
        cout << "Ngay: " << timeslot.getDate() << endl;
        cout << "Tu: " << timeslot.getStart() << " - Den: " << timeslot.getEnd() << endl;
        if (type == "both") {
            int choice;
            while (true) {
                cout << "Ban muon hen theo phuong thuc nao? (1. Ca nhan, 2. Nhom)" << endl;
                cin >> choice;
                cin.ignore();
                if (choice == 1) {
                    type = "personal";
                    break;
                } else if (choice == 2) {
                    type = "group";
                    break;
                }
                cout << "Lua chon khong hop le, vui long thu lai!" << endl;
            }
        }
        cout << "Loai cuoc hop: " << type << endl;
        int opt;
        while (true) {
            cout << "Ban muon dat lich hen khong? (1. Co, 2. Khong)" << endl;
            cin >> opt;
            cin.ignore();
            if (opt == 1) {
                Meeting meet(type, timeslot.getId());
                return meet;
            } else if (opt == 2) {
                meeting.setId(-1);
                return meeting;
            }
            cout << "Lua chon khong hop le, vui long thu lai!" << endl;
        }

        return meeting;
    }

    int selectMeeting(const vector<Meeting> &meetings) {
        if (meetings.empty()) {
            cout << "Ban khong co lich hop nao." << endl;
            return -1;
        }

        cout << "------------Danh sách cuoc hop cua ban------------" << endl;
        for (size_t i = 0; i < meetings.size(); i++) {
            cout << i + 1 << ". " << "(ID giao vien: " << meetings[i].getTeacherId() << ")" << " "
                 << "Ngay: " << meetings[i].getDate() << " " << "Tu: " << meetings[i].getStart() << " "
                 << "Den: " << meetings[i].getEnd() << " " << "(" << meetings[i].getType() << ")";
        }
        cout << "------------------------------------------" << endl;
        int choice;
        while (true) {
            cout << "Nhap so thu tu cua cuoc hop ban mua huy: ";
            cin >> choice;
            cin.ignore();

            if (choice > 0 && choice <= meetings.size()) {
                return meetings[choice - 1].getId();
            }
            cout << "Lua chon khong hop le" << endl;
        }
    }

    Timeslot showAvailableSlots(const map<string, vector<Timeslot>> &timeslots) {
        if (timeslots.empty()) {
            cout << "Khong co thoi gian ranh cua giao vien." << endl;
            return Timeslot();
        }

        cout << "------------Thoi gian ranh cua giao vien-------------" << endl;
        map<int, Timeslot> choiceMap;
        int index = 1;

        for (const auto &entry : timeslots) {
            const string &date = entry.first;
            const vector<Timeslot> &slots = entry.second;

            for (const auto &slot : slots) {
                cout << index << ". Ngay: " << date << ", Tu: " << slot.getStart() << " - Den: " << slot.getEnd()
                     << " (" << slot.getType() << ")" << endl;
                choiceMap[index++] = slot;
            }
        }

        cout << "----------------------------------------------------" << endl;

        int choice;
        while (true) {
            cout << "Nhap so thu tu cua thoi gian ban muon chon: ";
            cin >> choice;
            cin.ignore();

            if (choiceMap.find(choice) != choiceMap.end()) {
                return choiceMap[choice];
            }
            cout << "Lua chon khong hop le, vui long thu lai!" << endl;
        }
    }
};

#endif
>>>>>>> main
