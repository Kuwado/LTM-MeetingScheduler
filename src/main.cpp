#include "../data/Database.h"
#include "../src/controllers/UserController.h"
#include "../src/models/User.h"
#include "models/Timeslot.h"
#include "repository/TimeslotRepository.h"
#include <iostream>

using namespace std;

int main() {
    Database db;

    if (db.connect()) {
        cout << "connected" << endl;
    }

    UserController userController;
    User us1("kuwado", "123", "student", "Tanashi", "Kuwado");
    TimeslotRepository tr;
    Timeslot ts1("03:30", "06:00", "2024-11-20", "group", 6);
    tr.create(ts1);

    // userController.create(us1);
    // User us2 = userController.getUserByUsername("haha123");
    // us2.show();
    // userController.registerAccount();

    return 0;
}
