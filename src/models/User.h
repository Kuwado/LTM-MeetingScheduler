#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User {
protected:
    string username;
    string password;

public:
    virtual void login() = 0;
    virtual void registerUser() = 0;
    virtual ~User() {}
};

#endif