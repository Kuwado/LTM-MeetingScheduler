#include "../data/Database.h"
#include "../src/controllers/TeacherController.h"
#include "../src/controllers/UserController.h"

#include "../src/models/User.h"
#include "models/Timeslot.h"
#include "repository/TimeslotRepository.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Database db;

    if (db.connect()) {
        cout << "connected" << endl;
    }

    UserController userController;
    User us1("kuwado", "123", "student", "Tanashi", "Kuwado");
    TimeslotRepository tr;
    Timeslot ts1("03:30", "06:00", "2024-11-20", "group", 7);
    // tr.create(ts1);
    TeacherController tc;
    // tc.declareTimeslot(6);
    // vector<Timeslot> tisls = tr.getTimeslotsByTeacherId(6);

    // for (int i = 0; i < tisls.size(); i++) {
    //     cout << tisls[i].getStart() << endl;
    // }

    // userController.create(us1);
    // User us2 = userController.getUserByUsername("haha123");
    // us2.show();
    // userController.registerAccount();

    tc.viewTimeslots(6);

    return 0;
}
