#ifndef MEETINGREPOSITORY_H
#define MEETINGREPOSITORY_H

#include "../../data/Database.h"
#include "../models/Attendance.h"
#include "../models/Meeting.h"
#include "../models/User.h"
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

    // Lay lich hen chua hoan thanh
    map<string, vector<Meeting>> getWaitingMeetingsByTeacherId(const int &teacher_id) {
        map<string, vector<Meeting>> timeslots;

        if (db.connect()) {
            string query = "SELECT * FROM meetings WHERE teacher_id = ? AND (status = 'pending' OR status = "
                           "'confirmed' OR status = 'doing')";
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

    string getWeekName(const string &date) {
        struct tm tm = {};
        strptime(date.c_str(), "%Y-%m-%d", &tm); // Chuyển chuỗi ngày sang `tm`
        time_t time = mktime(&tm);               // Chuyển sang `time_t`

        // Lấy ngày đầu tuần
        int dayOfMonth = tm.tm_mday;
        int firstDayOfMonth = dayOfMonth - (tm.tm_wday == 0 ? 6 : (tm.tm_wday - 1));
        tm.tm_mday = firstDayOfMonth;
        mktime(&tm); // Ngày đầu tuần đầu tiên trong tháng

        // Tính số thứ tự tuần
        int weekNumber = 1 + (dayOfMonth - firstDayOfMonth) / 7;

        // Lấy tháng và ngày đầu/ cuối tuần
        char bufferStart[11], bufferEnd[11];
        strftime(bufferStart, sizeof(bufferStart), "%d/%m", &tm); // Ngày đầu tuần
        tm.tm_mday += 6;
        mktime(&tm); // Ngày cuối tuần
        strftime(bufferEnd, sizeof(bufferEnd), "%d/%m", &tm);

        // Trả về tên tuần
        char result[50];
        snprintf(result, sizeof(result), "Tuần %d tháng %d (%s - %s)", weekNumber, tm.tm_mon + 1, bufferStart,
                 bufferEnd);
        return string(result);
    }

    // Lay lich hen chua hen theo tuan
    map<string, map<string, vector<Meeting>>> getWaitingMeetingsInWeeksByTeacherId(const int &teacher_id) {
        map<string, map<string, vector<Meeting>>> meetings;

        if (db.connect()) {
            string query = "SELECT * FROM meetings WHERE teacher_id = ? AND (status = 'pending' OR status = "
                           "'confirmed' OR status = 'doing')";
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
                    string week = getWeekName(date);
                    meetings[week][date].push_back(meeting);
                }
                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                std::cerr << "Lỗi khi lấy dữ liệu từ meetings: " << e.what() << std::endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }

        // Sắp xếp lại meetings trong mỗi ngày theo giờ tăng dần
        for (auto &weekEntry : meetings) {
            for (auto &dayEntry : weekEntry.second) {
                sort(dayEntry.second.begin(), dayEntry.second.end(),
                     [](const Meeting &a, const Meeting &b) { return a.getStart() < b.getStart(); });
            }
        }

        return meetings;
    }

    map<string, vector<Meeting>> getDoneMeetingsByTeacherId(const int &teacher_id) {
        map<string, vector<Meeting>> timeslots;

        if (db.connect()) {
            string query = "SELECT * FROM meetings WHERE teacher_id = ? AND status = 'completed' ";
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

    void deleteMeeting(const int &id) {
        if (db.connect()) {
            string query = "DELETE FROM meetings WHERE id = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, id);
                sql::ResultSet *res = pstmt->executeQuery();
            } catch (sql::SQLException &e) {
                std::cerr << "Lỗi khi xoa meeting: " << e.what() << std::endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
    }

    void updateReport(const int &id, const string &report) {
        if (db.connect()) {
            string query = "UPDATE meetings SET report = ? WHERE id = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setString(1, report);
                pstmt->setInt(2, id);

                int rowsUpdated = pstmt->executeUpdate();
                if (rowsUpdated > 0) {
                    cout << "Cập nhật thành công meeting với id: " << id << endl;
                } else {
                    cout << "Không tìm thấy meeting với id: " << id << endl;
                }
                delete pstmt;
            } catch (sql::SQLException &e) {
                cerr << "Lỗi khi cập nhật meeting: " << e.what() << endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
    }

    void updateStatus(const int &id, const string &status) {
        if (db.connect()) {
            string query = "UPDATE meetings SET status = ? WHERE id = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setString(1, status);
                pstmt->setInt(2, id);

                int rowsUpdated = pstmt->executeUpdate();
                if (rowsUpdated > 0) {
                    cout << "Cập nhật thành công meeting với id: " << id << endl;
                } else {
                    cout << "Không tìm thấy meeting với id: " << id << endl;
                }
                delete pstmt;
            } catch (sql::SQLException &e) {
                cerr << "Lỗi khi cập nhật meeting: " << e.what() << endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
    }
};

#endif
