#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H

#include "../models/Response.h"
#include "../models/User.h"
#include "../repository/TimeslotRepository.h"
#include "../repository/UserRepository.h"
#include "StudentController.h"
#include "TeacherController.h"

#include <cppconn/prepared_statement.h>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class StudentController {
  private:
    TeacherController tc;
    UserRepository userRepository;
    TimeslotRepository timeslotRepo;
    Utils utils;

  public:
    StudentController() {}

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

    vector<User> getAllTeacher(const string &message) {
        vector<User> teachers;

        vector<string> tokens = splitString(message, '|');
        int i = 1;

        while (i < tokens.size()) {
            User user;
            user.setId(stoi(tokens[i]));
            user.setFirstName(tokens[i + 1]);
            user.setLastName(tokens[i + 2]);
            teachers.push_back(user);
            i = i + 3;
        }

        return teachers;
    }

    map<string, vector<Timeslot>> viewTimeslots(const string &message) {
        map<string, vector<Timeslot>> timeslots;
        vector<string> tokens = splitString(message, '|');
        string date = tokens[1];
        int i = 2;
        while (i < tokens.size()) {
            if (tokens[i - 1] == "]") {
                date = tokens[i];
                i++;
            } else if (tokens[i] == "]" || tokens[i] == "[") {
                i++;
            } else {
                // [
                Timeslot ts;
                ts.setId(stoi(tokens[i]));
                ts.setStart(tokens[i + 1]);
                ts.setEnd(tokens[i + 2]);
                ts.setDate(tokens[i + 3]);
                ts.setType(tokens[i + 4]);
                ts.setStatus(tokens[i + 5]);
                ts.setTeacherId(stoi(tokens[i + 6]));
                timeslots[date].push_back(ts);
                i = i + 7;
            }
        }
        return timeslots;
    }

    map<string, map<string, vector<pair<Meeting, User>>>> getMeetingsInWeeksFromResponse(const string &message) {
        map<string, map<string, vector<pair<Meeting, User>>>> meetings;
        vector<string> tokens = splitString(message, '|');
        string week = tokens[1];
        string date = tokens[3];
        int i = 2;
        while (i < tokens.size()) {
            if (tokens[i - 1] == "}" && tokens[i - 2] == "]") {
                week = tokens[i];
                i++;
            } else if ((tokens[i - 1] == "{" && tokens[i - 2] != "teacher") ||
                       (tokens[i - 1] == "]" && tokens[i - 2] == "}")) {
                date = tokens[i];
                i++;
            } else if (tokens[i] == "]" || tokens[i] == "[" || tokens[i] == "}" || tokens[i] == "{") {
                i++;
            } else {
                // [
                pair<Meeting, User> meetingWithUser;
                User teacher;
                Meeting meeting;
                meeting.setId(stoi(tokens[i]));
                meeting.setTimeslotId(stoi(tokens[i + 1]));
                meeting.setStatus(tokens[i + 2]);
                meeting.setType(tokens[i + 3]);
                meeting.setReport(tokens[i + 4]);
                meeting.setStart(tokens[i + 5]);
                meeting.setEnd(tokens[i + 6]);
                meeting.setDate(tokens[i + 7]);
                meetingWithUser.first = meeting;
                // i + 8 == students; i + 9 == "{"
                i = i + 10; //
                teacher.setId(stoi(tokens[i]));
                teacher.setFirstName(tokens[i + 1]);
                teacher.setLastName(tokens[i + 2]);
                i = i + 3;

                meetingWithUser.second = teacher;
                meetings[week][date].push_back(meetingWithUser);
            }
        }
        return meetings;
    }

    pair<Meeting, User> getMeetingFromResponse(const string &message) {
        pair<Meeting, User> meetingDetail;
        User teacher;
        vector<string> tokens = splitString(message, '|');

        Meeting meeting;
        meeting.setId(stoi(tokens[1]));
        meeting.setTimeslotId(stoi(tokens[2]));
        meeting.setStatus(tokens[3]);
        meeting.setType(tokens[4]);
        meeting.setReport(tokens[5]);
        meeting.setStart(tokens[6]);
        meeting.setEnd(tokens[7]);
        meeting.setDate(tokens[8]);
        meetingDetail.first = meeting;
        // 9 = [
        teacher.setId(stoi(tokens[10]));
        teacher.setFirstName(tokens[11]);
        teacher.setLastName(tokens[12]);
        meetingDetail.second = teacher;
        return meetingDetail;
    }
};

#endif