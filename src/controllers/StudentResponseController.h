#ifndef STUDENTRESPONSECONTROLLER_H
#define STUDENTRESPONSECONTROLLER_H

#include <iostream>
#include <vector>
#include "../repository/UserRepository.h"
#include "../repository/MeetingRepository.h"
#include "../repository/TimeslotRepository.h"
#include "../repository/AttendanceRepository.h"
#include "../models/Response.h"
#include "../models/User.h"
#include "../models/Meeting.h"
#include "../models/Attendance.h"
#include "./TeacherResponseController.h"
using namespace std;

class StudentResponseController {
    private:
        UserRepository userRepository;
        MeetingRepository meetingRepository;
        TimeslotRepository timeslotRepository;
        AttendanceRepository attendanceRepository;
        TeacherResponseController trc;        
    public:
        StudentResponseController () {}

    Response getAllTeacher() {
        Response res;
        vector<User> teachers = userRepository.getAllTeachers();

        if (teachers.empty()) {
            res.setStatus(8); 
            res.setMessage("Khong co giao vien nao trong he thong");
        } else {
            string message = "";
            for (int i = 0; i < teachers.size(); i++){
                message += teachers[i].toStringProfile() + "|";
            }
            res.setStatus(0); 
            res.setMessage(message);
        }

        return res;
    }

    Response bookMeeting(const string request) {
        Response res;
        vector<string> tokens = trc.splitString(request, '|');
        string start = tokens[1];
        string end = tokens[2];
        string date = tokens[3];
        string type = tokens[4];
        int teacher_id = stoi(tokens[5]);
        int time_slot_id = stoi(tokens[6]);
        int student_id = stoi(tokens[7]);
        if (start.empty() || end.empty() || date.empty() || type.empty() || teacher_id <= 0 || time_slot_id <= 0 || student_id <= 0) {
            res.setStatus(13); 
            res.setMessage("Du lieu khong hop le |");
            return res;
        }

        Timeslot timeslot = timeslotRepository.getTimeslotById(time_slot_id);
        if (timeslot.getId() == 0) {
            res.setStatus(14);
            res.setMessage("Khong tim thay timeslot |");
            return res;
        }

        Meeting newMeeting(teacher_id, "pending", type, start, end, date);

        meetingRepository.create(newMeeting, student_id);

        if (timeslot.getType() == "personal") {
            timeslotRepository.updateStatus(time_slot_id, "busy");
        }

        res.setStatus(0);
        res.setMessage("Dat lich hop thanh cong |");

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
        if (meetings.empty()){
            res.setStatus(16);
            res.setMessage("Ban khong co lich hop nao |");
            return res;
        }
        string message = "";
        for ( auto &meeting : meetings) {
            message += meeting.toString();
        }
        res.setStatus(0);
        res.setMessage(message);
        return res;
    }

    Response cancelMeeting(const string request){
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