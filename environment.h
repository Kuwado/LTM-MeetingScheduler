#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <iostream>
using namespace std;

class Environment {
  private:
    string host = "tcp://127.0.0.1:3306";
    string user = "root";
    string password = "your_password";

  public:
    // Constructor
    Environment() {};

    // Getters
    string getHost() const { return host; }
    string getUser() const { return user; }
    string getPassword() const { return password; }

    // Setters
};

#endif
