#include "Database.h"
#include <cppconn/exception.h>
#include <iostream>

Database::Database(const std::string& user, const std::string& password, const std::string& db)
    : user(user), password(password), database(db), driver(NULL), con(NULL) {}

Database::~Database() {
    if (con) {
        delete con;
    }
}

bool Database::connect() {
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", user, password);
        con->setSchema(database);
        std::cout << "Connected to database successfully!" << std::endl;
        return true;
    } catch (sql::SQLException& e) {
        std::cerr << "Connection error: " << e.what() << std::endl;
        return false;
    }
}

void Database::executeQuery(const std::string& query) {
    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery(query);
        while (res->next()) {
            std::cout << "Data: " << res->getString(1) << std::endl;
        }
        delete res;
        delete stmt;
    } catch (sql::SQLException& e) {
        std::cerr << "Query error: " << e.what() << std::endl;
    }
}


// int main() {
//     Database db("root", "your_password", "ltm");

//     if (db.connect()) {
//         // db.executeQuery("SELECT * FROM your_table");
//         std::cout << "connected";
//     }
//     return 0;
// }