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

    Response viewMeetingsStudent(const string &request) {
        Response res;
        vector<string> tokens = trc.splitString(request, '|');
        int student_id = stoi(tokens[1]);
        User student = userRepository.getUserById(student_id);
        if (student.getId() == 0 || student.getRole() != "student") {
            res.setStatus(17);
            res.setMessage("Khong tim thay sinh vien|");
            return res;
        } else {
            map<string, map<string, vector<Meeting>>> meetings =
                meetingRepository.getMeetingsInWeeksByStudentId(student_id);
            if (meetings.empty()) {
                res.setStatus(16);
                res.setMessage("Ban khong co lich hop nao|");
                return res;
            } else {
                string message = "";
                for (const auto &week : meetings) {
                    const string weekName = week.first;
                    const map<string, vector<Meeting>> dailyMeetings = week.second;
                    message += weekName + "|{";
                    for (const auto &day : dailyMeetings) {
                        const string dayName = day.first;
                        vector<Meeting> mts = day.second;
                        message += "|" + dayName + "|[";
                        for (int i = 0; i < mts.size(); i++) {
                            message += "|" + mts[i].toString();
                            User teacher = userRepository.getTeacherFromMeeting(mts[i].getId());
                            message += "|teacher|{";
                            message += "|" + to_string(teacher.getId()) + "|" + teacher.getFirstName() + "|" +
                                       teacher.getLastName();
                            message += "|}";
                        }
                        message += "|]";
                    }
                    message += "|}|";
                }
                res.setStatus(0);
                res.setMessage(message);
            }
        }

        return res;
    }

    Response viewMeetingStudent(const string &request) {
        Response res;
        vector<string> tokens = trc.splitString(request, '|');
        int meeting_id = stoi(tokens[1]);
        User teacher = userRepository.getTeacherFromMeeting(meeting_id);

        Meeting meeting = meetingRepository.getMeetingById(meeting_id);
        string message = meeting.toString();
        message += "|[";
        message += "|" + to_string(teacher.getId()) + "|" + teacher.getFirstName() + "|" + teacher.getLastName();
        message += "|]|";
        res.setStatus(0);
        res.setMessage(message);

        return res;
    }

    Response cancelMeeting(const string &request) {
        Response res;
        vector<string> tokens = trc.splitString(request, '|');
        int student_id = stoi(tokens[1]);
        int meeting_id = stoi(tokens[2]);
        Meeting meeting = meetingRepository.getMeetingById(meeting_id);
        if (meeting.getId() == 0) {
            res.setStatus(12);
            res.setMessage("Khong tim thay meeting de huy|");
            return res;
        }
        if (meeting.getType() == "group") {
            vector<Attendance> attendances = attendanceRepository.getAttendancesByMeetingId(meeting_id);
            if (attendances.size() == 1) {
                meetingRepository.deleteMeeting(meeting_id);
            }
        }
        if (meeting.getType() == "personal") {
            timeslotRepository.updateStatus(meeting.getTimeslotId(), "free");
            meetingRepository.deleteMeeting(meeting_id);
        }
        attendanceRepository.deleteAttendanceByMeetingIdAndStudentId(meeting_id, student_id);
        res.setStatus(0);
        res.setMessage("Huy lich hen thanh cong|");
        return res;
    }
};

#endif