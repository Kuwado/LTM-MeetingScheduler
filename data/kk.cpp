#include <iostream>
#include "Database.h"

int main() {
    Database db("root", "your_password", "ltm");

    if (db.connect()) {
        // db.executeQuery("SELECT * FROM your_table");
        std::cout << "connected";
    }
    return 0;
}
