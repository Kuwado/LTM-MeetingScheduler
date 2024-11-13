#ifndef DATABASE_H
#define DATABASE_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <string>

class Database {
public:
    Database(const std::string& user, const std::string& password, const std::string& db);
    ~Database();

    bool connect();
    void executeQuery(const std::string& query);

private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    std::string user;
    std::string password;
    std::string database;
};

#endif // DATABASE_H
