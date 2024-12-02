#ifndef TIMESLOTREPOSITORY_H
#define TIMESLOTREPOSITORY_H

#include "../../data/Database.h"
#include "../models/Timeslot.h"
#include "../models/User.h"
#include "../utils/Utils.h"
#include "UserRepository.h"
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class TimeslotRepository {
  private:
    Database db;
    UserRepository userRepo;
    Utils utils;

  public:
    TimeslotRepository() {}

    bool check(const Timeslot &timeslot) {
        vector<Timeslot> tsList = getTimeSlotsAtSameDate(timeslot.getTeacherId(), timeslot.getDate());
        for (const Timeslot &ts : tsList) {
            if (!(utils.checkTimeGreater(ts.getStart(), timeslot.getEnd()) ||
                  utils.checkTimeGreater(timeslot.getStart(), ts.getEnd()))) {
                return true;
            }
        }
        return false;
    }

    void create(const Timeslot &timeslot) {
        if (db.connect()) {
            User user = userRepo.getUserById(timeslot.getTeacherId());
            if (user.getId() == 0) {
                cout << "User khong ton tai!" << endl;
                return;
            } else if (user.getRole() != "teacher") {
                cout << "User khong phai giao vien!" << endl;
                return;
            }

            string query = "INSERT INTO timeslots (start, end, date, type, teacher_id) VALUES (?, ?, ?, ?, ?)";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setString(1, timeslot.getStart());
                pstmt->setString(2, timeslot.getEnd());
                pstmt->setString(3, timeslot.getDate());
                pstmt->setString(4, timeslot.getType());
                pstmt->setInt(5, timeslot.getTeacherId());

                pstmt->executeUpdate();
                cout << "Khai bao thoi gian: " << timeslot.getStart() << " - " << timeslot.getEnd() << " ( "
                     << timeslot.getDate() << " )" << endl;
                delete pstmt;
            } catch (sql::SQLException &e) {
                cerr << "Loi them khe thoi gian: " << e.what() << endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
    }

    void updateTimeAndType(const int &id, const string &start, const string &end, const string &type) {
        if (db.connect()) {
            string query = "UPDATE timeslots SET start = ?, end = ?, type = ? WHERE id = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setString(1, start);
                pstmt->setString(2, end);
                pstmt->setString(3, type);
                pstmt->setInt(4, id);

                int rowsUpdated = pstmt->executeUpdate();
                if (rowsUpdated > 0) {
                    cout << "Cập nhật thành công timeslot với id: " << id << endl;
                } else {
                    cout << "Không tìm thấy timeslot với id: " << id << endl;
                }
                delete pstmt;
            } catch (sql::SQLException &e) {
                cerr << "Lỗi khi cập nhật thời gian: " << e.what() << endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
    }

    map<string, vector<Timeslot>> getTimeslotsByTeacherId(const int &teacher_id) {
        map<string, vector<Timeslot>> timeslotsByDate;
        Database db;

        if (db.connect()) {
            string query = "SELECT * FROM timeslots WHERE teacher_id = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, teacher_id);
                sql::ResultSet *res = pstmt->executeQuery();

                while (res->next()) {
                    Timeslot ts;
                    ts.setId(res->getInt("id"));
                    ts.setStart(res->getString("start"));
                    ts.setEnd(res->getString("end"));
                    ts.setDate(res->getString("date"));
                    ts.setType(res->getString("type"));
                    ts.setStatus(res->getString("status"));
                    ts.setTeacherId(res->getInt("teacher_id"));

                    string date = ts.getDate();
                    timeslotsByDate[date].push_back(ts);
                }

                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                std::cerr << "Lỗi khi lấy dữ liệu từ timeslots: " << e.what() << std::endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }

        // Sắp xếp lại Timeslots trong mỗi ngày theo giờ tăng dần
        for (auto &entry : timeslotsByDate) {
            sort(entry.second.begin(), entry.second.end(),
                 [](const Timeslot &a, const Timeslot &b) { return a.getStart() < b.getStart(); });
        }

        return timeslotsByDate;
    }

    vector<Timeslot> getTimeSlotsAtSameDate(const int &teacher_id, const string &date) {
        vector<Timeslot> tsList;
        if (db.connect()) {
            string query = "SELECT * FROM timeslots WHERE teacher_id = ? AND date = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, teacher_id);
                pstmt->setString(2, date);
                sql::ResultSet *res = pstmt->executeQuery();

                while (res->next()) {
                    Timeslot ts;
                    ts.setId(res->getInt("id"));
                    ts.setStart(res->getString("start"));
                    ts.setEnd(res->getString("end"));
                    ts.setDate(res->getString("date"));
                    ts.setType(res->getString("type"));
                    ts.setStatus(res->getString("status"));
                    ts.setTeacherId(res->getInt("teacher_id"));
                    tsList.push_back(ts);
                }

                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                std::cerr << "Lỗi khi lấy dữ liệu từ timeslots: " << e.what() << std::endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
        return tsList;
    }
};

#endif
