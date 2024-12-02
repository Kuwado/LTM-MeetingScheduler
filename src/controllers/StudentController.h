#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H

#include<iostream>
#include "../models/Meeting.h"
#include "../models/Response.h"
#include "../models/Timeslot.h"
#include "../repository/MeetingRepository.h"
#include "../repository/TimeslotRepository.h"
#include "../utils/Utils.h"
#include <cppconn/prepared_statement.h>

using namespace std;

class StudentController {
    private:
        MeetingRepository meetingRepository;
        TimeslotRepository timeslotRepository;
        Utils utils;
    public:
        StudentController(){}

        Response timeslot(const int &teacher_id) {
            Response res;
            map<string, vector<Timeslot>> ts = timeslotRepository.getTimeslotsByTeacherId(teacher_id);
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
        void viewTeacherTimeslots(const int &teacher_id) {
        map<string, vector<Timeslot>> timeslots = timeslotRepository.getTimeslotsByTeacherId(teacher_id);

        if (timeslots.empty()) {
            cout << "Giao vien nay chua khai bao thoi gian ranh" << endl;
            return;
        }

        cout << "------------------Lich ranh cua giao vien-------------------" << endl;
        for (const auto &ts : timeslots) {
            cout << "Ngay: " << ts.first << endl;
            vector<Timeslot> tss = ts.second;
            for (const auto &slot : tss) {
                cout << "- Tu: " << slot.getStart() << " - Den: " << slot.getEnd() << " (" << slot.getType() << ")" << endl;
            }
        }
    }
    void bookMeeting(vector<int> studentIds, int teacherId, string start, string end, string type, string date) {
             // TO-DO
    }    
};


#endif