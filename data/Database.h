#ifndef DATABASE_H
#define DATABASE_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <string>

using namespace std;

class Database {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    string host = "tcp://127.0.0.1:3306";
    string user = "root";
    string password = "your_password";
    string database = "ltm";

public:
    Database() {}
    // ~Database();
        
    bool connect() {
        try {
            driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect(host, user, password);
            con->setSchema(database);
            cout << "Connected to database successfully!" << endl;
            return true;
        } catch (sql::SQLException& e) {
            cerr << "Connection error: " << e.what() << endl;
            return false;
        }
    }

    void executeQuery(const string& query) {
        try {
            sql::Statement* stmt = con->createStatement();
            sql::ResultSet* res = stmt->executeQuery(query);
            while (res->next()) {
                cout << "Data: " << res->getString(1) << endl;
            }
            delete res;
            delete stmt;
        } catch (sql::SQLException& e) {
            cerr << "Query error: " << e.what() << endl;
        }
    }
};

#endif // DATABASE_H
