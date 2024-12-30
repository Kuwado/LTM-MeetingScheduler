#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "../models/Response.h"
#include "../models/User.h"
#include "../repository/UserRepository.h"
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class UserController {
  private:
    UserRepository userRepository;

  public:
    UserController() {}

    vector<string> splitString(const string &str, char delimiter) {
        vector<string> tokens;
        string token;
        stringstream ss(str);

        // Sử dụng getline để tách chuỗi
        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    Response login(const string &username, const string &password) {
        Response res;
        User user = userRepository.getUserByUsername(username);
        if (user.getId() == 0) {
            res.setStatus(1);
            res.setMessage("Tên đăng nhập không chính xác!|");
        } else if (user.getPassword() != password) {
            res.setStatus(2);
            res.setMessage("Mật khẩu không chính xác!|");
        } else {
            res.setStatus(0);
            string message = to_string(user.getId()) + "|" + user.getRole() + "|" + "Dang nhap thanh cong|";
            res.setMessage(message);
        }

        return res;
    }

    Response registerAccount(const string &message) {
        vector<string> tokens = splitString(message, '|');
        Response res;
        string username = tokens[1];
        string password = tokens[2];
        string role = tokens[3];
        string first_name = tokens[4];
        string last_name = tokens[5];
        User user = userRepository.getUserByUsername(username);
        if (user.getId() != 0) {
            res.setStatus(3);
            res.setMessage("Tên đăng nhập da ton tai!|");
        } else {
            User newUser(username, password, role, first_name, last_name);
            userRepository.create(newUser);
            User user = userRepository.getUserByUsername(username);
            string message = "Dang ky thanh cong|" + to_string(user.getId()) + "|" + user.getRole() + "|";
            res.setStatus(0);
            res.setMessage(message);
        }
        return res;
    }
};

#endif
