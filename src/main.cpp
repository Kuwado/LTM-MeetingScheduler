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
    User us1("kuwado", "123", "student", "Tanashi", "Kuwado");

    // userController.create(us1);
    // User us2 = userController.getUserByUsername("haha123");
    // us2.show();
    userController.registerAccount();

    return 0;
}
