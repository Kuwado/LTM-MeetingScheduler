#ifndef TEACHERRESPONSECONTROLLER_H
#define TEACHERRESPONSECONTROLLER_H

#include "../models/Meeting.h"
#include "../models/Response.h"
#include "../models/Timeslot.h"
#include "../models/User.h"
#include "../repository/AttendanceRepository.h"
#include "../repository/MeetingRepository.h"
#include "../repository/TimeslotRepository.h"
#include "../repository/UserRepository.h"

#include <cppconn/prepared_statement.h>
#include <iostream>
#include <map>

using namespace std;

class TeacherResponseController {
  private:
    UserRepository userRepository;
    TimeslotRepository timeslotRepo;
    MeetingRepository meetingRepo;
    AttendanceRepository attendanceRepo;

  public:
    TeacherResponseController() {}

    vector<string> splitString(const string &str, char delimiter) {
        vector<string> tokens;
        string token;
        stringstream ss(str);

        // Sử dụng getline để tách chuỗi
        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    // Teacher
    Response viewTimeslots(const int &teacher_id) {
        Response res;
        User user = userRepository.getUserById(teacher_id);
        if (user.getId() == 0) {
            res.setStatus(8);
            res.setMessage("Giao vien khong ton tai|");
        } else {
            map<string, vector<Timeslot>> timeslots = timeslotRepo.getTimeslotsByTeacherId(teacher_id);
            if (timeslots.empty()) {
                res.setStatus(9);
                res.setMessage("Giao vien khong co lich ranh|");
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

    Response updateTimeslot(const string message) {
        Response res;
        vector<string> tokens = splitString(message, '|');
        int id = stoi(tokens[1]);
        string start = tokens[2];
        string end = tokens[3];
        string type = tokens[4];
        Timeslot ts = timeslotRepo.getTimeslotById(id);
        if (ts.getId() == 0) {
            res.setStatus(14);
            res.setMessage("Khong tim thay khe thoi gian|");
        } else if (timeslotRepo.check2(start, end, ts.getDate(), ts.getTeacherId(), id)) {
            res.setStatus(13);
            res.setMessage("Thoi gian khong hop le|");
        } else {
            timeslotRepo.updateTimeAndType(id, start, end, type);
            res.setStatus(0);
            res.setMessage("Sua doi thoi gian ranh thanh cong|");
        }

        return res;
    }

    Response declareTimeslot(const string message) {
        Response res;
        vector<string> tokens = splitString(message, '|');
        cout << message << endl;
        string start = tokens[1];
        string end = tokens[2];
        string date = tokens[3];
        string type = tokens[4];
        int teacher_id = stoi(tokens[5]);
        Timeslot ts(start, end, date, type, teacher_id);
        if (timeslotRepo.check(start, end, date, teacher_id)) {
            res.setStatus(13);
            res.setMessage("Thoi gian khong hop le|");
        } else {
            timeslotRepo.create(ts);
            res.setStatus(0);
            res.setMessage("Khai bao thoi gian ranh thanh cong|");
        }

        return res;
    }

    Response viewMeetings(const int &teacher_id) {
        Response res;
        User user = userRepository.getUserById(teacher_id);
        if (user.getId() == 0) {
            res.setStatus(8);
            res.setMessage("Giao vien khong ton tai");
        } else {
            map<string, vector<Meeting>> meetings = meetingRepo.getMeetingsByTeacherId(teacher_id);
            if (meetings.empty()) {
                res.setStatus(16);
                res.setMessage("Giao vien khong co lich hen");
            } else {
                string message = "";
                for (const auto &ts : meetings) {
                    message += ts.first + "|[";
                    vector<Meeting> tss = ts.second;
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

    Response viewMeeting(const int &meeting_id) {
        Response res;
        vector<User> students = attendanceRepo.getStudentsFromMeeting(meeting_id);

        Meeting meeting = meetingRepo.getMeetingById(meeting_id);
        string message = meeting.toString();
        message += "|[";
        for (const auto &student : students) {
            message += "|" + to_string(student.getId()) + "|" + student.getFirstName() + "|" + student.getLastName();
        }
        message += "|]|";
        res.setStatus(0);
        res.setMessage(message);

        return res;
    }
};

#endif
