#ifndef STUDENTRESPONSECONTROLLER_H
#define STUDENTRESPONSECONTROLLER_H

#include "../models/Attendance.h"
#include "../models/Meeting.h"
#include "../models/Response.h"
#include "../models/User.h"
#include "../repository/AttendanceRepository.h"
#include "../repository/MeetingRepository.h"
#include "../repository/TimeslotRepository.h"
#include "../repository/UserRepository.h"
#include "./TeacherResponseController.h"
#include <iostream>
#include <vector>
using namespace std;

class StudentResponseController {
  private:
    UserRepository userRepository;
    MeetingRepository meetingRepository;
    TimeslotRepository timeslotRepository;
    AttendanceRepository attendanceRepository;
    TeacherResponseController trc;

  public:
    StudentResponseController() {}

    Response getAllTeacher() {
        Response res;
        vector<User> teachers = userRepository.getAllTeachers();

        if (teachers.empty()) {
            res.setStatus(8);
            res.setMessage("Khong co giao vien nao trong he thong");
        } else {
            string message = "";
            for (int i = 0; i < teachers.size(); i++) {
                message += teachers[i].toStringProfile() + "|";
            }
            res.setStatus(0);
            res.setMessage(message);
        }

        return res;
    }

    Response viewFreeTimeslots(const int &teacher_id) {
        Response res;
        User user = userRepository.getUserById(teacher_id);
        if (user.getId() == 0) {
            res.setStatus(8);
            res.setMessage("Giao vien khong ton tai|");
        } else {
            map<string, vector<Timeslot>> timeslots = timeslotRepository.getFreeTimeslotsByTeacherId(teacher_id);
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

    Response bookMeeting(const string &request) {
        Response res;
        vector<string> tokens = trc.splitString(request, '|');
        int student_id = stoi(tokens[1]);
        int timeslot_id = stoi(tokens[2]);
        string type = tokens[3];

        User student = userRepository.getUserById(student_id);
        if (student.getId() == 0) {
            res.setStatus(17);
            res.setMessage("Sinh vien khong ton tai|");
            return res;
        }

        Timeslot timeslot = timeslotRepository.getTimeslotById(timeslot_id);
        if (timeslot.getId() == 0) {
            res.setStatus(10);
            res.setMessage("Khong tim thay timeslot|");
            return res;
        }

        // Kiem tra xem meeting ton tai chua
        Meeting meeting = meetingRepository.getMeetingByTimeslotId(timeslot_id);
        if (meeting.getId() != 0 && meeting.getType() == "personal") {
            res.setStatus(20);
            res.setMessage("Cuoc hen da ton tai|");
            return res;
        } else if (meeting.getId() == 0) {
            // Tao meeting
            Meeting newMeeting(type, timeslot_id);
            meetingRepository.create(newMeeting);
            meeting = meetingRepository.getMeetingByTimeslotId(timeslot_id);
        }

        // Update type cho timeslot neu no la both
        if (timeslot.getType() == "both") {
            timeslotRepository.updateType(timeslot_id, type);
        }

        if (type == "personal") {
            timeslotRepository.updateStatus(timeslot_id, "busy");
        }

        // Them attendance
        // Kiem tra attendance ton tai chua
        Attendance att = attendanceRepository.getAttendanceByMeetingIdAndStudentId(meeting.getId(), student_id);
        if (att.getId() == 0) {
            Attendance newAttendance(meeting.getId(), student_id);
            attendanceRepository.create(newAttendance);
        } else {
            res.setStatus(19);
            res.setMessage("Sinh vien da dang ky cuoc hen nay|");
            return res;
        }

        res.setStatus(0);
        res.setMessage("Dat lich hop thanh cong|");

        return res;
    }

    Response getMeetingsByStudent(const string request) {
        Response res;
        vector<string> tokens = trc.splitString(request, '|');
        int student_id = stoi(tokens[1]);
        if (student_id <= 0) {
            res.setStatus(13);
            res.setMessage("Du lieu khong hop le |");
            return res;
        }
        vector<Meeting> meetings = attendanceRepository.getMeetingsByStudentId(student_id);
        if (meetings.empty()) {
            res.setStatus(16);
            res.setMessage("Ban khong co lich hop nao |");
            return res;
        }
        string message = "";
        for (auto &meeting : meetings) {
            message += meeting.toString();
        }
        res.setStatus(0);
        res.setMessage(message);
        return res;
    }

    Response cancelMeeting(const string request) {
        Response res;
        vector<string> tokens = trc.splitString(request, '|');
        int meeting_id = stoi(tokens[1]);
        int student_id = stoi(tokens[2]);
        if (meeting_id <= 0 || student_id <= 0) {
            res.setStatus(13);
            res.setMessage("Du lieu khong hop le |");
            return res;
        }
        Meeting meeting = meetingRepository.getMeetingById(meeting_id);
        if (meeting.getId() == 0) {
            res.setStatus(14);
            res.setMessage("Khong tim thay meeting de huy |");
            return res;
        }
        meetingRepository.deleteMeeting(meeting_id);
        int teacher_id = meeting.getTeacherId();
        string start = meeting.getStart();
        string end = meeting.getEnd();
        Timeslot timeslot = timeslotRepository.getTimeslotByDetails(teacher_id, start, end);
        if (timeslot.getId() != 0) {
            timeslotRepository.updateStatus(timeslot.getId(), "free");
        }
        attendanceRepository.deleteAttendanceByMeetingAndStudent(meeting_id, student_id);
        res.setStatus(0);
        res.setMessage("Huy meeting thanh cong |");
        return res;
    }
};

#endif