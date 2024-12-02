#include "../data/Database.h"
#include "../src/controllers/ResponseController.h"
#include "../src/controllers/TeacherController.h"
#include "../src/controllers/UserController.h"
#include "../src/models/User.h"
#include "models/Response.h"
#include "models/Timeslot.h"
#include "utils/Utils.h"

#include "repository/TimeslotRepository.h"
#include "views/TeacherView.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    Database db;

    if (db.connect()) {
        cout << "connected" << endl;
    }

    UserController userController;
    Utils utils;
    User us1("kuwado", "123", "student", "Tanashi", "Kuwado");
    TimeslotRepository tr;
    Timeslot ts1("03:30", "06:00", "2024-11-20", "group", 7);
    // tr.create(ts1);
    TeacherController tc;
    ResponseController rc;
    // tc.declareTimeslot(6);
    // vector<Timeslot> tisls = tr.getTimeslotsByTeacherId(6);

    // for (int i = 0; i < tisls.size(); i++) {
    //     cout << tisls[i].getStart() << endl;
    // }

    // userController.create(us1);
    // User us2 = userController.getUserByUsername("haha123");
    // us2.show();
    // userController.registerAccount();

    // tc.viewTimeslots(6);
    vector<Timeslot> list = tr.getTimeSlotsAtSameDate(6, "2024-11-05");
    cout << list.size() << endl;
    cout << utils.checkTimeGreater("06:10:00", "06:15:00") << endl;
    TeacherView tv;
    const int a = 6;
    int choice = 0;
    choice = tv.showMenu();
    switch (choice) {
    case 1: {
        Timeslot tslot = tv.showDeclareTimeSlots(a);
        Response res = tc.decalreTimeSlot(tslot);
        break;
    }
    case 2: {
        // map<string, vector<Timeslot>> timeslots = tr.getTimeslotsByTeacherId(6);

        // Timeslot tslot = tv.showTimeslots(timeslots);
        Response res = rc.viewTimeslots(6);
        cout << res.getMessage() << endl;
        break;
    }
    default:
        break;
    }

    return 0;
}
