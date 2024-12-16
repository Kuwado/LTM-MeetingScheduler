#ifndef ATTENDANCEREPOSITORY_H
#define ATTENDANCEREPOSITORY_H

#include "../../data/Database.h"
#include "../models/Attendance.h"
#include "../models/Meeting.h"
#include "../models/User.h"
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

  public:
    AttendanceRepository() {}

    void create(Attendance attendance) {
        if (db.connect()) {
            // User user = userRepo.getUserById(attendance.getTeacherId());
            // if (user.getId() == 0) {
            //     cout << "User khong ton tai!" << endl;
            //     return;
            // }

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
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
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
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }

        return students;
    }
};

#endif
