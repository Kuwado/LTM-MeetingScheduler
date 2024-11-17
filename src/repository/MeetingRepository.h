#ifndef MEETINGREPOSITORY_H
#define MEETINGREPOSITORY_H

#include "../../data/Database.h"
#include "../models/Meeting.h"
#include "../models/User.h"
#include "UserRepository.h"
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <vector>

using namespace std;

class MeetingRepository {
  private:
    Database db;
    UserRepository userRepo;

  public:
    MeetingRepository() {}

    void create(Meeting meeting) {
        if (db.connect()) {
            User user = userRepo.getUserById(meeting.getTeacherId());
            if (user.getId() == 0) {
                cout << "User khong ton tai!" << endl;
                return;
            } else if (user.getRole() != "teacher") {
                cout << "User khong phai giao vien!" << endl;
                return;
            }

            string query =
                "INSERT INTO meetings (teacher_id, status, type, start, end, date ) VALUES (?, ?, ?, ?, ?, ?)";

            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, meeting.getTeacherId());
                pstmt->setString(2, meeting.getStatus());
                pstmt->setString(3, meeting.getType());
                pstmt->setString(4, meeting.getStart());
                pstmt->setString(5, meeting.getEnd());
                pstmt->setString(6, meeting.getDate());
                pstmt->executeUpdate();
                meeting.show();
                delete pstmt;
            } catch (sql::SQLException &e) {
                cerr << "Loi them cuoc hen: " << e.what() << endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
    }

    vector<Meeting> getMeetingsByTeacherId(const int &teacher_id) {
        vector<Meeting> timeslots;

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
                    meeting.setStart(res->getString("start"));
                    meeting.setEnd(res->getString("end"));
                    meeting.setDate(res->getString("date"));
                    timeslots.push_back(meeting);
                }
                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                std::cerr << "Lỗi khi lấy dữ liệu từ meetings: " << e.what() << std::endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }

        return timeslots;
    }
};

#endif
