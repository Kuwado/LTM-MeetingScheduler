#include <iostream>
#include "../data/Database.h"

int main() {
    Database db;

    if (db.connect()) {
        db.executeQuery("SELECT username FROM user");
        std::cout << "connected";
    }

    return 0;
}
