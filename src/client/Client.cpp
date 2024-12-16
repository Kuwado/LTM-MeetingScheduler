#include "../controllers/ClientController.h"
#include "../controllers/ResponseController.h"
#include "../controllers/TeacherController.h"
#include "../controllers/UserController.h"

#include "../utils/MessageUtils.h"
#include "../views/StudentView.h"
#include "../views/TeacherView.h"
#include "../views/UserView.h"

#include <algorithm>
#include <arpa/inet.h>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <utility>
#include <vector>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

using namespace std;

int clientSocket;
struct sockaddr_in serverAddr;
TeacherView teacherView;
StudentView studentView;
UserView userView;
UserController userController;
ClientController clientController;
ResponseController responseController;
TeacherController teacherController;
int user_id = 0;
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

bool endsWith(const string &str, const string &suffix) {
    if (str.size() >= suffix.size()) {
        return str.substr(str.size() - suffix.size()) == suffix;
    }
    return false;
}

string sendRequestToServer(const string &command) {
    // send(clientSocket, command.c_str(), command.size(), 0);
    int totalSize = command.size();
    int offset = 0;

    // Gửi chuỗi theo từng phần nhỏ
    while (offset < totalSize) {
        // Tính toán độ dài của phần gửi
        int partSize = min(BUFFER_SIZE, totalSize - offset);

        // Gửi phần chuỗi
        int bytesSent = send(clientSocket, command.c_str() + offset, partSize, 0);

        if (bytesSent < 0) {
            cerr << "Lỗi khi gửi dữ liệu!" << endl;
            break;
        }

        // Cập nhật offset để gửi phần tiếp theo
        offset += bytesSent;
    }

    // Nhận phản hồi từ server
    char buffer[BUFFER_SIZE];
    string response;
    while (true) {
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            break; // Kết thúc khi không nhận thêm dữ liệu hoặc có lỗi
        }
        // Chuyển buffer thành string
        string partResponse(buffer, bytesReceived);

        // Thêm phần phản hồi vào response
        response += partResponse;

        if (endsWith(partResponse, "|<END>")) {
            response = response.substr(0, response.length() - 6);
            break;
        }
    }

    return response.empty() ? "100" : response;
}

void logout() {
    user_id = 0;
    role = "none";
}

// Teacher
void handleDeclareTimeSlot() {
    Timeslot ts = teacherView.showDeclareTimeSlots(user_id);
    string request = "DECLARE_TIME_SLOT|" + ts.toStringDeclare() + "|<END>";
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
    string request = "UPDATE_TIME_SLOT|" + tsUpdate.toStringUpdate() + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    }
}

void handleViewTimeslots() {
    string request = "VIEW_TIME_SLOTS|" + to_string(user_id) + "|<END>";
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

void handleEditReport(const int &meeting_id, const string &report) {
    string request = "ENTER_MEETING_REPORT|" + to_string(meeting_id) + "|" + report + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    vector<string> tokens = splitString(response, '|');
    cout << tokens[1] << endl;
}

void handleUpdateStatus(const int &meeting_id, const string &mstatus) {
    string request = "UPDATE_MEETING_STATUS|" + to_string(meeting_id) + "|" + mstatus + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    vector<string> tokens = splitString(response, '|');
    cout << tokens[1] << endl;
}

void handleTeacherViewMeeting(const int &meeting_id) {
    string request = "VIEW_MEETING|" + to_string(meeting_id) + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        pair<Meeting, vector<User>> meetingDetail = teacherController.getMeetingFromResponse(response);
        int choice = teacherView.showMeeting(meetingDetail.first, meetingDetail.second);
        if (choice == 0) {
            return;
        } else if (choice == 1) {
            string report = teacherView.showEditReport();
            handleEditReport(meeting_id, report);
            handleTeacherViewMeeting(meeting_id);
        } else if (choice == 2) {
            string status = teacherView.showUpdateStatus();
            handleUpdateStatus(meeting_id, status);
            handleTeacherViewMeeting(meeting_id);
        }
    }
}

void handleTeacherViewMeetings() {
    string request = "VIEW_MEETINGS|" + to_string(user_id) + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        map<string, vector<Meeting>> meetings = teacherController.getMeetingsFromResponse(response);
        Meeting meeting = teacherView.showMeetings(meetings);
        if (meeting.getId() == -1) {
            return;
        }
        // Detail Meeting
        handleTeacherViewMeeting(meeting.getId());
        handleTeacherViewMeetings();
    } else if (status == "16") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    }
}

void handleTeacherViewHistoryMeeting(const int &meeting_id) {
    string request = "VIEW_MEETING|" + to_string(meeting_id) + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        pair<Meeting, vector<User>> meetingDetail = teacherController.getMeetingFromResponse(response);
        int choice = teacherView.showMeetingHistory(meetingDetail.first, meetingDetail.second);
        if (choice == 0) {
            return;
        } else if (choice == 1) {
            string report = teacherView.showEditReport();
            handleEditReport(meeting_id, report);
            handleTeacherViewHistoryMeeting(meeting_id);
        }
    }
}

void handleTeacherViewHistory() {
    string request = "VIEW_HISTORY|" + to_string(user_id) + "|<END>";
    string response = sendRequestToServer(request);
    string status = response.substr(0, response.find('|'));
    if (status == "0") {
        map<string, vector<Meeting>> meetings = teacherController.getMeetingsFromResponse(response);
        Meeting meeting = teacherView.showHistory(meetings);
        if (meeting.getId() == -1) {
            return;
        }
        // Detail Meeting
        handleTeacherViewHistoryMeeting(meeting.getId());
        handleTeacherViewHistory();
    } else if (status == "18") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    }
}

void handleTeacherMenu() {
    int choice = teacherView.showMenu();
    switch (choice) {
    case 0:
        logout();
        break;
    case 1:
        handleDeclareTimeSlot();
        handleTeacherMenu();
        break;
    case 2:
        handleViewTimeslots();
        handleTeacherMenu();
        break;
    case 3:
        handleTeacherViewMeetings();
        handleTeacherMenu();
        break;
    case 4:
        handleTeacherViewHistory();
        handleTeacherMenu();
        break;

    default:
        break;
    }
}

// Student
void handleStudentCommand(const string &cmd) {
    cout << cmd << endl;
    if (cmd == "FETCH_ALL_TEACHER") {
        string requestTeacher = "FETCH_ALL_TEACHER|";
        string responseTeacher = sendRequestToServer(requestTeacher);
        string statusTeacher = responseTeacher.substr(0, responseTeacher.find("|"));
        if (statusTeacher == "0") {
            vector<User> teachers = clientController.parseTeachersFromResponse(responseTeacher);
            int teacherId = studentView.selectTeacher(teachers);
            string request = cmd + "|" + to_string(teacherId);
            cout << request << endl;
            string response = sendRequestToServer(request);
            string status = response.substr(0, response.find('|'));
            cout << status << endl;
            if (status == "0") {
                map<string, vector<Timeslot>> timeslots = clientController.viewTimeslots(response);
                Timeslot ts = studentView.showAvailableSlots(timeslots);
            }
        }
    }
}

void handleStudentMenu() {
    int choice = studentView.showMenu();
    switch (choice) {
    case 0:
        logout();
        break;
    case 1:
        handleStudentCommand("FETCH_ALL_TEACHER");
        handleStudentMenu();
        break;
    case 2:
        // handleViewTimeslots();
        // handleTeacherMenu();
        break;
    case 3:
        break;
    case 4:
        break;

    default:
        break;
    }
}

void handleLogin() {
    map<string, string> info = userView.showLogin();
    string loginCommand = "LOGIN|" + info["username"] + "|" + info["password"] + "|<END>";
    string response = sendRequestToServer(loginCommand);
    vector<string> result = splitString(response, '|');
    if (result[0] == "0") {
        user_id = stoi(result[1]);
        role = result[2];
        cout << user_id << " - " << role << endl;
        response = result[0] + "|" + result[3];
    } else if (result[0] == "1" || result[0] == "2") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
        handleLogin();
    } else {
        logout();
    }
    if (role == "teacher" && user_id != 0) {
        handleTeacherMenu();
    } else if (role == "student" && user_id != 0) {
        handleStudentMenu();
    }
}

void handleRegister() {
    map<string, string> info = userView.showRegisterA(); // Lấy thông tin đăng ký
    string registerCommand = "REGISTER|" + info["username"] + "|" + info["password"] + "|" + info["role"] + "|" +
                             info["first_name"] + "|" + info["last_name"] + "|<END>";

    // Gửi lệnh đăng ký tới server
    string response = sendRequestToServer(registerCommand);

    // Phân tích phản hồi từ server
    vector<string> result = splitString(response, '|');
    if (result[0] == "0") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
        user_id = stoi(tokens[2]);
        role = tokens[3];
        if (role == "teacher" && user_id != 0) {
            handleTeacherMenu();
        } else if (role == "student" && user_id != 0) {
            handleStudentMenu();
        }
    } else if (result[0] == "3") {
        vector<string> tokens = splitString(response, '|');
        cout << tokens[1] << endl;
    }
}

void handleUserMenu() {
    int choice = userView.showMenu();
    switch (choice) {
    case 1:
        handleLogin();
        handleUserMenu();
        break;
    case 2:
        handleRegister();
        handleUserMenu();
        break;
    default:
        break;
    }
}

void closeConnection() { close(clientSocket); }

int main() {
    connectToServer();
    handleUserMenu();
    closeConnection();
    return 0;
}
