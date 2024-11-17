#ifndef UTILS_H
#define UTILS_H
#include <cctype>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Utils {

  public:
    // Constructor
    Utils() {};

    vector<int> getCurrentDateTimeVector() {
        time_t t = time(nullptr);
        tm *now = localtime(&t);
        vector<int> dateTime = {now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min};
        return dateTime;
    }

    vector<int> getDateVector(const string &stringDate) {
        vector<int> dateVector;
        istringstream ss(stringDate);
        string token;

        while (getline(ss, token, '-')) {
            dateVector.push_back(stoi(token));
        }
        return dateVector;
    }

    vector<int> getTimeVector(const string &stringTime) {
        vector<int> timeVector;
        istringstream ss(stringTime);
        string token;

        while (getline(ss, token, ':')) {
            timeVector.push_back(stoi(token));
        }
        return timeVector;
    }

    bool checkHour(const string &hour) {
        if (hour.length() != 2)
            return false;

        for (char c : hour) {
            if (!isdigit(c))
                return false;
        }

        int h = stoi(hour);
        return h >= 0 && h <= 23;
    }

    bool checkMinute(const string &minute) {
        if (minute.length() != 2)
            return false;

        for (char c : minute) {
            if (!isdigit(c))
                return false;
        }

        int h = stoi(minute);
        return h >= 0 && h <= 59;
    }

    bool checkDay(const string &day) {
        if (day.length() != 2)
            return false;

        for (char c : day) {
            if (!isdigit(c))
                return false;
        }

        int h = stoi(day);
        return h >= 1 && h <= 31;
    }

    bool checkMonth(const string &month) {
        if (month.length() != 2)
            return false;

        for (char c : month) {
            if (!isdigit(c))
                return false;
        }

        int h = stoi(month);
        return h >= 1 && h <= 12;
    }

    bool checkYear(const string &year) {
        if (year.length() != 4)
            return false;

        for (char c : year) {
            if (!isdigit(c))
                return false;
        }

        int h = stoi(year);
        return h >= 1000 && h <= 2500;
    }
};

#endif
