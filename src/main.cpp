#include "../data/Database.h"
#include "../src/controllers/UserController.h"
#include "../src/models/User.h"
#include <iostream>

int main() {
    Database db;

    if (db.connect()) {
        db.executeQuery("SELECT username FROM user");

        std::cout << "connected";
    }

    UserController userController;
    User us1("haha123", "123", "student", "Viet ox", "Hoan oy");

    userController.create(us1);
    // User us2 = userController.getUserByUsername("haha");
    // us2.show();

    return 0;
}
