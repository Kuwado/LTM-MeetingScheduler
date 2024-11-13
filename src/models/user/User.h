#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User {
protected:
    string username;
    string password;
    string role;

public:
    // Constructor
    User(const string& uname, const string& pass, const string &role);
    void login();
    virtual void registerUser() = 0;
    void showProfile();

};

#endif
