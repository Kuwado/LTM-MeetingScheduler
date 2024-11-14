#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "../../data/Database.h"
#include "../models/User.h"
#include <cppconn/prepared_statement.h>
#include <iostream>

using namespace std;

class UserController {
  private:
    Database db;

  public:
    UserController() {}

    User getUserByUsername(const string &username) {
        User user;

        if (db.connect()) {
            string query = "SELECT * FROM users WHERE username = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setString(1, username);
                sql::ResultSet *res = pstmt->executeQuery();

                if (res->next()) {
                    user.setId(res->getInt("id"));
                    user.setUsername(res->getString("username"));
                    user.setPassword(res->getString("password"));
                    user.setRole(res->getString("role"));
                    user.setFirstName(res->getString("first_name"));
                    user.setLastName(res->getString("last_name"));
                }
                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                cerr << "Loi lay du lieu user: " << e.what() << endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }

        return user;
    }

    User getUserById(const int &id) {
        User user;

        if (db.connect()) {
            string query = "SELECT * FROM users WHERE id = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setInt(1, id);
                sql::ResultSet *res = pstmt->executeQuery();

                if (res->next()) {
                    user.setId(res->getInt("id"));
                    user.setUsername(res->getString("username"));
                    user.setPassword(res->getString("password"));
                    user.setRole(res->getString("role"));
                    user.setFirstName(res->getString("first_name"));
                    user.setLastName(res->getString("last_name"));
                }
                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                cerr << "Loi lay du lieu user: " << e.what() << endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
        return user;
    }

    bool checkUsernameExists(const string &username) {
        if (db.connect()) {
            string query = "SELECT COUNT(*) FROM users WHERE username = ?";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setString(1, username);

                sql::ResultSet *res = pstmt->executeQuery();
                if (res->next() && res->getInt(1) > 0) {
                    delete res;
                    delete pstmt;
                    return true;
                }

                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                cerr << "Lỗi khi kiểm tra username: " << e.what() << endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }

        return false; // Username không tồn tại
    }

    void create(const User &user) {
        if (db.connect()) {
            if (checkUsernameExists(user.getUsername())) {
                cout << "Ten dang nhap da ton tai!" << endl;
                return;
            }
            string query = "INSERT INTO users (username, password, role, first_name, last_name) VALUES (?, ?, ?, ?, ?)";
            try {
                sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(query);
                pstmt->setString(1, user.getUsername());
                pstmt->setString(2, user.getPassword());
                pstmt->setString(3, user.getRole());
                pstmt->setString(4, user.getFirstName());
                pstmt->setString(5, user.getLastName());

                pstmt->executeUpdate();
                cout << "User: " << user.getUsername() << " da duoc tao thanh cong" << endl;
                delete pstmt;
            } catch (sql::SQLException &e) {
                cerr << "Loi them user: " << e.what() << endl;
            }
        } else {
            cout << "Lỗi không thể truy cập cơ sở dữ liệu." << endl;
        }
    }
};

#endif
