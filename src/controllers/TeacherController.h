#ifndef TEACHERCONTROLLER_H
#define TEACHERCONTROLLER_H

#include "../models/Response.h"
#include "../models/Timeslot.h"
#include "../models/User.h"

#include "../repository/TimeslotRepository.h"
#include "../utils/Utils.h"
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class TeacherController {
  private:
    TimeslotRepository timeslotRepository;
    Utils utils;

  public:
    TeacherController() {}

    Response decalreTimeSlot(const Timeslot &timeslot) {
        Response res;
        bool same = timeslotRepository.check(timeslot.getStart(), timeslot.getEnd(), timeslot.getDate(),
                                             timeslot.getTeacherId());

        if (same) {
            res.setStatus(6);
            res.setMessage("Thoi gian bi trung");
            cout << "Trung" << endl;
        } else {
            timeslotRepository.create(timeslot);
            res.setStatus(0);
            res.setMessage("Tao thoi gian ranh thanh cong");
            cout << "ok" << endl;
        }

        return res;
    }

    // Response viewTimeslots(const int &teacher_id) {
    //     map<string, vector<Timeslot>> timeslots = timeslotRepository.getTimeslotsByTeacherId(teacher_id);
    //     }
};

#endif
