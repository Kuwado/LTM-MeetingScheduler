#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>

using namespace std;
using namespace sql::mysql;

int main() {
    try {
        // Khởi tạo driver
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        // Kết nối đến cơ sở dữ liệu MySQL
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "badboy0507");  // Thay đổi "root" và "your_password" theo thông tin của bạn

        // Kết nối thành công
        cout << "Kết nối thành công!" << endl;

        // Tạo statement để truy vấn cơ sở dữ liệu
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT 'Hello, MySQL!'");

        // Hiển thị kết quả
        while (res->next()) {
            cout << res->getString(1) << endl;
        }

        // Giải phóng tài nguyên
        delete res;
        delete stmt;
        delete con;

    }
    catch (sql::SQLException& e) {
        cout << "SQLException: " << e.what() << endl;
    }
    return 0;
}
