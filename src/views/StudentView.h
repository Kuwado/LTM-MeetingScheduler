#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include "../models/Timeslot.h"
#include "../controllers/StudentController.h"
#include <vector>
#include <iostream>
using namespace std;

class StudentView {
    public:
        StudentView() {}

    int showMenu() {
        int choice;
        while (true) {
            cout << "----------------Student Menu----------------" << endl;
            cout << "1. Xem lich ranh cua giao vien" << endl;
            cout << "2. Dat lich gap giao vien" << endl;
            cout << "3. Huy lich gap giao vien" << endl;
            cout << "4. Xem lich gap trong 1 tuan" << endl;
            cout << "Ban muon thuc hien chuc nang nao?" << endl;
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
                return choice;
                break;
            default:
                cout << "Lua chon khong hop le, vui long thu lai!" << endl;
                break;
            }
        }
    }

    int selectTeacher(const vector<User> &teachers) {

        if (teachers.empty()) {
            cout << "Không có giáo viên nào để chọn." << endl;
            return -1;
        }

        cout << "------------Danh sách giáo viên------------" << endl;
        for (size_t i = 0; i < teachers.size(); i++) {
            cout << i + 1 << ". " 
                << teachers[i].getFirstName() << " " 
                << teachers[i].getLastName() 
                << " (ID: " << teachers[i].getId() << ")" << endl;
        }
        cout << "------------------------------------------" << endl;

        int choice;
        while (true) {
            cout << "Nhập số thứ tự của giáo viên bạn muốn xem: ";
            cin >> choice;
            cin.ignore();

            if (choice > 0 && choice <= teachers.size()) {
                return teachers[choice - 1].getId();
            }
            cout << "Lựa chọn không hợp lệ, vui lòng thử lại!" << endl;
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
                cout << index << ". Ngay: " << date
                    << ", Tu: " << slot.getStart()
                    << " - Den: " << slot.getEnd()
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