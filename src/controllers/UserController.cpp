#include "UserController1.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>

// Hàm đăng ký tài khoản
bool UserController::registerAccount(const User &user) {
    try {
        sql::PreparedStatement *pstmt;
        pstmt = db.getConnection()->prepareStatement(
            "INSERT INTO users(username, password, role, first_name, last_name) VALUES (?, ?, ?, ?, ?)");
        pstmt->setString(1, user.getUsername());
        pstmt->setString(2, user.getPassword());
        pstmt->setString(3, user.getRole());
        pstmt->setString(4, user.getFirstName());
        pstmt->setString(5, user.getLastName());
        pstmt->executeUpdate();
        delete pstmt;
        return true;
    } catch (sql::SQLException &e) {
        cerr << "Register error: " << e.what() << endl;
        return false;
    }
}

// Hàm đăng nhập
bool UserController::login(const string &username, const string &password, User &loggedInUser) {
    try {
        sql::PreparedStatement *pstmt;
        pstmt = db.getConnection()->prepareStatement(
            "SELECT * FROM users WHERE username = ? AND password = ?");
        pstmt->setString(1, username);
        pstmt->setString(2, password);
        sql::ResultSet *res = pstmt->executeQuery();
        if (res->next()) {
            // Gán thông tin người dùng nếu đăng nhập thành công
            loggedInUser.setId(res->getInt("id"));
            loggedInUser.setUsername(res->getString("username"));
            loggedInUser.setPassword(res->getString("password"));
            loggedInUser.setRole(res->getString("role"));
            loggedInUser.setFirstName(res->getString("first_name"));
            loggedInUser.setLastName(res->getString("last_name"));
            delete res;
            delete pstmt;
            return true;
        }
        delete res;
        delete pstmt;
        return false;
    } catch (sql::SQLException &e) {
        cerr << "Login error: " << e.what() << endl;
        return false;
    }
}

// Lấy thông tin người dùng bằng tên đăng nhập
User UserController::getUserByUsername(const string &username) {
    User user;
    try {
        sql::PreparedStatement *pstmt;
        pstmt = db.getConnection()->prepareStatement(
            "SELECT * FROM users WHERE username = ?");
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
        cerr << "Query error: " << e.what() << endl;
    }
    return user;
}
