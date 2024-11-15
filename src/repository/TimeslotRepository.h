#ifndef TIMESLOTREPOSITORY_H
#define TIMESLOTREPOSITORY_H

#include "../../data/Database.h"
#include "../models/Timeslot.h"
#include <cppconn/prepared_statement.h>
#include <iostream>

using namespace std;

class TimeslotRepository {
  private:
    Database db;

  public:
    TimeslotRepository() {}

    void create(const Timeslot &timeslot) {
        if (db.connect()) {
            // if (checkUsernameExists(user.getUsername())) {
            //     cout << "Ten dang nhap da ton tai!" << endl;
            //     return;
            // }
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
};

#endif
