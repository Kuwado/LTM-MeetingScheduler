#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

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
            cout << "2. Xem lich gap trong tuan" << endl;
            cout << "0. Dang xuat" << endl;
            cout << "Ban muon thuc hien chuc nang nao?" << endl;
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 0:
            case 1:
            case 2:
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

    Meeting showMeetingsInWeeks(const map<string, map<string, vector<pair<Meeting, User>>>> &meetings) {
        if (meetings.empty()) {
            Meeting meeting;
            cout << "Ban chua co cuoc hen nao" << endl;
            return meeting;
        }

        map<int, Meeting> editMeetings;
        int index = 0, choice = 0;
        cout << "------------------Lich hen cua ban theo tuan-------------------" << endl;
        for (const auto &week : meetings) {
            cout << "---------------" << week.first << "---------------" << endl;
            map<string, vector<pair<Meeting, User>>> dailyMeetings = week.second;
            for (const auto &day : dailyMeetings) {
                cout << "----Ngay: " << day.first << endl;
                vector<pair<Meeting, User>> currentMeetings = day.second;
                for (int i = 0; i < currentMeetings.size(); i++) {
                    index++;
                    Meeting currentMeeting = currentMeetings[i].first;
                    editMeetings[index] = currentMeeting;
                    User teacher = currentMeetings[i].second;
                    cout << index << ". Tu: " << currentMeeting.getStart() << " - Den: " << currentMeeting.getEnd()
                         << "( " << currentMeeting.getType() << " - " << currentMeeting.getStatus() << " ). ";
                    cout << "Giao vien huong dan: " << teacher.getFirstName() << " " << teacher.getLastName() << endl;
                }
            }
            cout << "" << endl;
        }

        cout << "-----------" << endl;
        while (true) {
            cout << "Ban co muon xem chi tiet hoac sua doi? Nhap so dong can sua: ";
            cin >> choice;
            cin.ignore();
            if (choice > 0 && choice <= editMeetings.size()) {
                return editMeetings[choice];
            } else if (choice == 0) {
                Meeting meeting;
                meeting.setId(-1);
                return meeting;
            }
        }
    }

    int showMeeting(const Meeting &meeting, const User &teacher) {
        int choice;
        cout << "-------------Thong tin lich hen-----------------" << endl;
        cout << "Ngay: " << meeting.getDate() << endl;
        cout << "Tu: " << meeting.getStart() << endl;
        cout << "Den: " << meeting.getEnd() << endl;
        cout << "Loai: " << meeting.getType() << endl;
        cout << "Trang thai: " << meeting.getStatus() << endl;
        cout << "Van ban cuoc hop: " << meeting.getReport() << endl;
        cout << "Giao vien: " << teacher.getFirstName() << " " << teacher.getLastName() << endl;
        cout << "------------------" << endl;
        while (true) {
            cout << "Ban co muon huy lich hen khong (1 de huy, 0 de quai lai)" << endl;
            cin >> choice;
            cin.ignore();
            if (choice == 0 || choice == 1) {
                return choice;
            }
        }
    }
};

#endif
