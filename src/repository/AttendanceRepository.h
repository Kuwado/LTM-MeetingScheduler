#ifndef ATTENDANCEREPOSITORY_H
#define ATTENDANCEREPOSITORY_H

#include "../../data/Database.h"
#include "../models/Attendance.h"
#include "../models/Meeting.h"
#include "../models/User.h"
#include "../repository/MeetingRepository.h"
#include "UserRepository.h"
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class AttendanceRepository {
  private:
    Database db;
    UserRepository userRepo;
    // MeetingRepository mr;

  public:
    AttendanceRepository() {}

    void create(Attendance attendance) {
        if (db.connect()) {
            string query = "INSERT INTO attendances (meeting_id, student_id ) VALUES (?, ?)";

            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, attendance.getMeetingId());
                pstmt->setInt(2, attendance.getStudentId());
                pstmt->executeUpdate();
                delete pstmt;
            } catch (sql::SQLException &e) {
                cerr << "Loi them cuoc hen: " << e.what() << endl;
            }
            db.disconnect();
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
    }

    Attendance getAttendanceByMeetingIdAndStudentId(const int &meeting_id, const int &student_id) {
        Attendance attendance;

        if (db.connect()) {
            string query = "SELECT * FROM attendances WHERE meeting_id = ? AND student_id = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, meeting_id);
                pstmt->setInt(2, student_id);
                sql::ResultSet *res = pstmt->executeQuery();

                if (res->next()) {
                    attendance.setId(res->getInt("id"));
                    attendance.setMeetingId(res->getInt("meeting_id"));
                    attendance.setStudentId(res->getInt("student_id"));
                }

                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                std::cerr << "Lỗi khi lấy dữ liệu từ attendances: " << e.what() << std::endl;
            }
            db.disconnect();
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }

        return attendance;
    }

    vector<User> getStudentsFromMeeting(const int &meeting_id) {
        vector<User> students;

        if (db.connect()) {
            string query = "SELECT * FROM attendances WHERE meeting_id = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, meeting_id);
                sql::ResultSet *res = pstmt->executeQuery();

                while (res->next()) {
                    User student = userRepo.getUserById(res->getInt("student_id"));
                    students.push_back(student);
                }
                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                std::cerr << "Lỗi khi lấy dữ liệu từ meetings: " << e.what() << std::endl;
            }
            db.disconnect();
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }

        return students;
    }

    vector<Meeting> getMeetingsByStudentId(const int &student_id) {
        vector<Meeting> meetings;

        if (db.connect()) {
            string query = "SELECT meeting_id FROM attendances WHERE student_id = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, student_id);
                sql::ResultSet *res = pstmt->executeQuery();

                // while (res->next()) {
                //     Meeting meeting = mr.getMeetingById(res->getInt("meeting_id"));
                //     meetings.push_back(meeting);
                // }

            } catch (sql::SQLException &e) {
                std::cerr << "Lỗi khi lấy dữ liệu từ attendance: " << e.what() << std::endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }

        return meetings;
    }

    void deleteAttendanceByMeetingAndStudent(const int &meeting_id, const int &student_id) {
        if (db.connect()) {
            string query = "DELETE FROM attendances WHERE meeting_id = ? AND student_id = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, meeting_id);
                pstmt->setInt(2, student_id);
                pstmt->executeQuery();
            } catch (sql::SQLException &e) {
                std::cerr << "Lỗi khi xoa du lieu: " << e.what() << std::endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
    }
};

#endif
