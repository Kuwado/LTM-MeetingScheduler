#ifndef TEACHERCONTROLLER_H
#define TEACHERCONTROLLER_H

#include "../models/Meeting.h"
#include "../models/Response.h"
#include "../models/Timeslot.h"
#include "../models/User.h"

#include "../repository/MeetingRepository.h"
#include "../repository/TimeslotRepository.h"
#include "../repository/UserRepository.h"
#include "StudentController.h"
#include "TeacherController.h"

#include <cppconn/prepared_statement.h>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class TeacherController {
  private:
    UserRepository userRepository;
    TimeslotRepository timeslotRepo;
    // Utils utils;

  public:
    TeacherController() {}

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

    map<string, vector<Timeslot>> getTimeslotsFromResponse(const string &message) {
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

    map<string, vector<Meeting>> getMeetingsFromResponse(const string &message) {
        map<string, vector<Meeting>> meetings;
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
                Meeting meeting;
                meeting.setId(stoi(tokens[i]));
                meeting.setTeacherId(stoi(tokens[i + 1]));
                meeting.setStatus(tokens[i + 2]);
                meeting.setType(tokens[i + 3]);
                meeting.setReport(tokens[i + 4]);
                meeting.setStart(tokens[i + 5]);
                meeting.setEnd(tokens[i + 6]);
                meeting.setDate(tokens[i + 7]);
                meetings[date].push_back(meeting);
                i = i + 8;
            }
        }
        return meetings;
    }

    map<string, map<string, vector<pair<Meeting, vector<User>>>>>
    getMeetingsInWeeksFromResponse(const string &message) {
        map<string, map<string, vector<pair<Meeting, vector<User>>>>> meetings;
        vector<string> tokens = splitString(message, '|');
        string week = tokens[1];
        string date = tokens[3];
        int i = 2;
        while (i < tokens.size()) {
            if (tokens[i - 1] == "}" && tokens[i - 2] == "]") {
                week = tokens[i];
                i++;
            } else if ((tokens[i - 1] == "{" && tokens[i - 2] != "students") ||
                       (tokens[i - 1] == "]" && tokens[i - 2] == "}")) {
                date = tokens[i];
                i++;
            } else if (tokens[i] == "]" || tokens[i] == "[" || tokens[i] == "}" || tokens[i] == "{") {
                i++;
            } else {
                // [
                pair<Meeting, vector<User>> meetingWithUser;
                vector<User> students;
                Meeting meeting;
                meeting.setId(stoi(tokens[i]));
                meeting.setTeacherId(stoi(tokens[i + 1]));
                meeting.setStatus(tokens[i + 2]);
                meeting.setType(tokens[i + 3]);
                meeting.setReport(tokens[i + 4]);
                meeting.setStart(tokens[i + 5]);
                meeting.setEnd(tokens[i + 6]);
                meeting.setDate(tokens[i + 7]);
                meetingWithUser.first = meeting;
                // i + 8 == students; i + 9 == "{"
                i = i + 10; //
                while (tokens[i] != "}") {
                    User student;
                    student.setId(stoi(tokens[i]));
                    student.setFirstName(tokens[i + 1]);
                    student.setLastName(tokens[i + 2]);
                    students.push_back(student);
                    i = i + 3;
                }
                meetingWithUser.second = students;
                meetings[week][date].push_back(meetingWithUser);
            }
        }
        return meetings;
    }

    pair<Meeting, vector<User>> getMeetingFromResponse(const string &message) {
        pair<Meeting, vector<User>> meetingDetail;
        vector<User> students;
        vector<string> tokens = splitString(message, '|');

        Meeting meeting;
        meeting.setId(stoi(tokens[1]));
        meeting.setTeacherId(stoi(tokens[2]));
        meeting.setStatus(tokens[3]);
        meeting.setType(tokens[4]);
        meeting.setReport(tokens[5]);
        meeting.setStart(tokens[6]);
        meeting.setEnd(tokens[7]);
        meeting.setDate(tokens[8]);
        meetingDetail.first = meeting;
        // 9 = [
        int i = 10;
        while (i < tokens.size()) {
            if (tokens[i] == "]") {
                break;
            }
            User student;
            student.setId(stoi(tokens[i]));
            student.setFirstName(tokens[i + 1]);
            student.setLastName(tokens[i + 2]);
            students.push_back(student);
            i = i + 3;
        };
        meetingDetail.second = students;
        return meetingDetail;
    }
};

#endif
