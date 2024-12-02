#include "../controllers/ClientController.h"
#include "../controllers/ResponseController.h"
#include "../controllers/TeacherController.h"
#include "../controllers/UserController.h"

#include "../utils/MessageUtils.h"
#include "../views/TeacherView.h"
#include "../views/UserView.h"

#include <arpa/inet.h>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

using namespace std;

int clientSocket;
struct sockaddr_in serverAddr;
TeacherView teacherView;
UserController userController;
ClientController clientController;
ResponseController responseController;
TeacherController teacherController;
int user_id = 6;
string role = "none";

void connectToServer() {
    // Tạo socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        std::cerr << "Lỗi tạo socket" << std::endl;
        exit(1);
    }

    // Cấu hình địa chỉ server
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    // Kết nối tới server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Lỗi kết nối tới server" << std::endl;
        exit(1);
    }
}

vector<string> splitString(const string &str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);

    // Sử dụng getline để tách chuỗi
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string sendRequestToServer(const string &command) {
    send(clientSocket, command.c_str(), command.size(), 0);

    // Nhận phản hồi từ server
    char buffer[BUFFER_SIZE];
    int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
    if (bytesReceived > 0) {
        string response(buffer, bytesReceived);
        // cout << "Server response: " << response << endl;
        return response;
    }
    return "100";
}

void registerView() {
    int choice;
    std::string role, username, password, first_name, last_name;

    // Chọn vai trò
    std::cout << "1. Hoc sinh\n2. Giao vien\nBan la ai (1 hoac 2): ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
    case 1:
        role = "student";
        break;
    case 2:
        role = "teacher";
        break;
    default:
        std::cout << "Lua chon khong phu hop!" << std::endl;
        return;
    }

    // Nhập thông tin đăng ký
    std::cout << "Nhập tên đăng nhập: ";
    std::getline(std::cin, username);
    std::cout << "Nhập mật khẩu: ";
    std::getline(std::cin, password);
    std::cout << "Nhập ho: ";
    std::getline(std::cin, first_name);
    std::cout << "Nhập ten: ";
    std::getline(std::cin, last_name);

    // Tạo message register và gửi đến server
    std::string registerCommand =
        "REGISTER|" + username + "|" + password + "|" + role + "|" + first_name + "|" + last_name;
    sendRequestToServer(registerCommand);
}

void handleUserCommand() {
    std::string command;
    while (true) {
        std::cout << "Nhap lenh (REGISTER, LOGIN, EXIT): ";
        std::getline(std::cin, command);

        if (command == "EXIT") {
            break;
        }

        if (command == "REGISTER") {
            registerView();
        } else if (command == "LOGIN") {
            UserView uv;
            map<string, string> info = uv.showLogin();
            string loginCommand = "LOGIN|" + info["username"] + "|" + info["password"];
            string response = sendRequestToServer(loginCommand);
            vector<string> result = splitString(response, '|');
            if (result[0] == "0") {
                user_id = stoi(result[1]);
                role = result[2];
                cout << user_id << " - " << role << endl;
                response = result[0] + "|" + result[3];
            } else {
                user_id = 0;
                role = "none";
            }
            if (role == "teacher") {
                cout << "Xin chao giao vien" << endl;
            } else if (role == "student") {
                cout << "Xin chao hoc sinh" << endl;
            }

        } else if (command == "VIEW") {

        } else {
            std::cout << "Lenh khong hop le. Vui long nhap lai!" << std::endl;
        }
    }
}

// Teacher
void handleDeclareTimeSlot() {
    Timeslot ts = teacherView.showDeclareTimeSlots(user_id);
    string request = "DECLARE_TIME_SLOT|" + ts.toStringDeclare();
    cout << request << endl;
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    }
}

void handleUpdateTimeslot(const Timeslot &timeslot) {
    Timeslot tsUpdate = teacherView.showUpdateTimeslot(timeslot);
    string request = "UPDATE_TIME_SLOT|" + tsUpdate.toStringUpdate();
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    }
}

void handleViewTimeslots() {
    string request = "VIEW_TIME_SLOTS|" + to_string(user_id);
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        map<string, vector<Timeslot>> timeslots = clientController.viewTimeslots(response);
        Timeslot ts = teacherView.showTimeslots(timeslots);
        if (ts.getId() == -1) {
            return;
        }
        // Detail Timeslot
        int choice = teacherView.showTimeslot(ts);
        if (choice == 0) {
            handleViewTimeslots();
        } else {
            handleUpdateTimeslot(ts);
            handleViewTimeslots();
        }

    } else if (status == "8") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    } else if (status == "9") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    }
}

void handleTeacherMenu() {
    int choice = teacherView.showMenu();
    switch (choice) {
    case 1:
        handleDeclareTimeSlot();
        handleTeacherMenu();
        break;
    case 2:
        handleViewTimeslots();
        handleTeacherMenu();
        break;
    case 3:
        break;
    case 4:
        break;

    default:
        break;
    }
}

void closeConnection() { close(clientSocket); }

int main() {
    connectToServer();
    // handleUserCommand();
    handleTeacherMenu();
    closeConnection();
    return 0;
}
