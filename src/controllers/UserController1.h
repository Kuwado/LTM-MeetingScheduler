#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include "../../data/Database.h"
#include "../models/User.h"
#include <string>

class UserController {
private:
    Database db;

public:
    UserController() {
        db.connect();
    }

    bool registerAccount(const User &user);
    bool login(const string &username, const string &password, User &loggedInUser);
    User getUserByUsername(const string &username);
};

#endif // USER_CONTROLLER_H
