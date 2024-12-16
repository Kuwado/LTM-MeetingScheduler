#ifndef MEETINGREPOSITORY_H
#define MEETINGREPOSITORY_H

#include "../../data/Database.h"
#include "../models/Meeting.h"
#include "../models/User.h"
#include "../models/Attendance.h"
#include "./AttendanceRepository.h"
#include "UserRepository.h"
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class MeetingRepository {
  private:
    Database db;
    UserRepository userRepo;

  public:
    MeetingRepository() {}

    void create(Meeting meeting, const int studentId) {
        if (db.connect()) {
            User user = userRepo.getUserById(meeting.getTeacherId());
            if (user.getId() == 0) {
                cout << "User khong ton tai!" << endl;
                return;
            } else if (user.getRole() != "teacher") {
                cout << "User khong phai giao vien!" << endl;
                return;
            }

            string query = "INSERT INTO meetings (teacher_id, status, type, report, start, end, date ) VALUES (?, ?, "
                           "?, ?, ?, ?, ?)";

            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, meeting.getTeacherId());
                pstmt->setString(2, meeting.getStatus());
                pstmt->setString(3, meeting.getType());
                pstmt->setString(4, meeting.getReport());
                pstmt->setString(5, meeting.getStart());
                pstmt->setString(6, meeting.getEnd());
                pstmt->setString(7, meeting.getDate());
                pstmt->executeUpdate();
                delete pstmt;
                int meetingId = 0;
                sql::Statement *stmt = db.getConnection()->createStatement();
                sql::ResultSet *res = stmt->executeQuery("SELECT LAST_INSERT_ID()");
                if (res->next()) {
                    meetingId = res->getInt(1); 
                }
                delete res;
                delete stmt;
                AttendanceRepository attendanceRepo;
                Attendance attendance(meetingId, studentId);
                attendanceRepo.create(attendance);
            } catch (sql::SQLException &e) {
                cerr << "Loi them cuoc hen: " << e.what() << endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
    }

    map<string, vector<Meeting>> getMeetingsByTeacherId(const int &teacher_id) {
        map<string, vector<Meeting>> timeslots;

        if (db.connect()) {
            string query = "SELECT * FROM meetings WHERE teacher_id = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, teacher_id);
                sql::ResultSet *res = pstmt->executeQuery();

                while (res->next()) {
                    Meeting meeting;
                    meeting.setId(res->getInt("id"));
                    meeting.setTeacherId(res->getInt("teacher_id"));
                    meeting.setStatus(res->getString("status"));
                    meeting.setType(res->getString("type"));
                    meeting.setReport(res->getString("report"));
                    meeting.setStart(res->getString("start"));
                    meeting.setEnd(res->getString("end"));
                    meeting.setDate(res->getString("date"));
                    string date = meeting.getDate();
                    timeslots[date].push_back(meeting);
                }
                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                std::cerr << "Lỗi khi lấy dữ liệu từ meetings: " << e.what() << std::endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }

        // Sắp xếp lại Timeslots trong mỗi ngày theo giờ tăng dần
        for (auto &entry : timeslots) {
            sort(entry.second.begin(), entry.second.end(),
                 [](const Meeting &a, const Meeting &b) { return a.getStart() < b.getStart(); });
        }

        return timeslots;
    }

    Meeting getMeetingById(const int &id) {
        Meeting meeting;
        if (db.connect()) {
            string query = "SELECT * FROM meetings WHERE id  = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, id);
                sql::ResultSet *res = pstmt->executeQuery();

                if (res->next()) {
                    meeting.setId(res->getInt("id"));
                    meeting.setStart(res->getString("start"));
                    meeting.setEnd(res->getString("end"));
                    meeting.setDate(res->getString("date"));
                    meeting.setType(res->getString("type"));
                    meeting.setStatus(res->getString("status"));
                    meeting.setTeacherId(res->getInt("teacher_id"));
                    meeting.setReport(res->getString("report"));
                }

                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                std::cerr << "Lỗi khi lấy dữ liệu từ timeslots: " << e.what() << std::endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
        return meeting;
    }

    void deleteMeeting (const int &id){
        if (db.connect()){
            string query = "DELETE FROM meetings WHERE id = ?";
            try
            {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, id);
                sql::ResultSet *res = pstmt->executeQuery();
            }
            catch (sql::SQLException &e) 
            {
                std::cerr << "Lỗi khi xoa meeting: " << e.what() << std::endl;
            }
        }else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
    }
};

#endif
