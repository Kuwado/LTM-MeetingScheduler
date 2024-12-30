#include "../Status.h"
#include "../controllers/ResponseController.h"
#include "../controllers/StudentResponseController.h"
#include "../controllers/TeacherResponseController.h"
#include "../controllers/UserController.h"
#include "../models/Response.h"
#include "../models/User.h"
#include "../repository/UserRepository.h"
#include "../utils/MessageUtils.h"
#include <arpa/inet.h>
#include <fstream>
#include <ifaddrs.h>
#include <iostream>
#include <map>
#include <netinet/in.h>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <vector>
#define PORT 8080
#define BUFFER_SIZE 1024

using namespace std;

ResponseController responseController;
StudentResponseController studentResponseController;
TeacherResponseController teacherResponseController;
UserController userController;
UserRepository userRepo;

// Hàm ghi log vào file
void logToFile(const std::string &message) {
    std::ofstream logFile("server_logs.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.close();
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

char randomChar() {
    // Tạo ký tự ngẫu nhiên từ các ký tự chữ cái và số
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    return chars[rand() % (sizeof(chars) - 1)];
}

void processClientRequest(int clientSocket, const string &request) {
    string response;
    string command = request.substr(0, request.find('|'));
    vector<string> result = splitString(request, '|');
    Response res;

    if (command == "REGISTER") {
        res = userController.registerAccount(request);
    } else if (command == "LOGIN") {
        string username = result[1];
        string password = result[2];
        res = userController.login(username, password);
    } else if (command == "VIEW_TIME_SLOTS") {
        int teacher_id = stoi(result[1]);
        res = teacherResponseController.viewTimeslots(teacher_id);
    } else if (command == "UPDATE_TIME_SLOT") {
        res = teacherResponseController.updateTimeslot(request);
    } else if (command == "DECLARE_TIME_SLOT") {
        res = teacherResponseController.declareTimeslot(request);
    } else if (command == "VIEW_MEETINGS") {
        int teacher_id = stoi(result[1]);
        res = teacherResponseController.viewMeetings(teacher_id);
    } else if (command == "VIEW_MEETING") {
        int meeting_id = stoi(result[1]);
        res = teacherResponseController.viewMeeting(meeting_id);
    } else if (command == "VIEW_MEETINGS_IN_WEEKS") {
        int meeting_id = stoi(result[1]);
        res = teacherResponseController.viewMeetingsInWeeks(meeting_id);
    } else if (command == "VIEW_HISTORY") {
        int teacher_id = stoi(result[1]);
        res = teacherResponseController.viewHistory(teacher_id);
    } else if (command == "ENTER_MEETING_REPORT") {
        res = teacherResponseController.updateReport(request);
    } else if (command == "UPDATE_MEETING_STATUS") {
        res = teacherResponseController.updateStatus(request);
    } else if (command == "TEST") {
        cout << request << endl;
        string randomString = "";
        // Tạo chuỗi dài 3000 ký tự ngẫu nhiên
        for (int i = 0; i < 3000; ++i) {
            randomString += randomChar();
        }
        res.setStatus(123);
        res.setMessage(randomString + "|");
    } else if (command == "FETCH_ALL_TEACHER") {
        res = studentResponseController.getAllTeacher();
    } else if (command == "VIEW_FREE_TIME_SLOTS") {
        int teacher_id = stoi(result[1]);
        res = studentResponseController.viewFreeTimeslots(teacher_id);
    } else if (command == "BOOK_MEETING") {
        res = studentResponseController.bookMeeting(request);
    }
    // else if (command == "FETCH_STUDENT_MEETINGS"){
    //      res = studentResponseController.getMeetingsByStudent(request);
    //  } else if (command == "CANCEL_MEETING"){
    //      res = studentResponseController.cancelMeeting(request);
    //  }
    else {
        response = MessageUtils::createMessage(Status::UNKNOWN_ERROR, "Yeu cau khong hop le");
    }

    response = to_string(res.getStatus()) + "|" + res.getMessage();

    // Ghi log phản hồi vào file

    // Gửi phản hồi về client
    // send(clientSocket, response.c_str(), response.size(), 0);
    int totalSize = response.size();
    int offset = 0;
    // Gửi chuỗi theo từng phần nhỏ
    while (offset < totalSize) {
        // Tính toán độ dài của phần gửi
        int partSize = min(BUFFER_SIZE, totalSize - offset);

        // Gửi phần chuỗi
        int bytesSent = send(clientSocket, response.c_str() + offset, partSize, 0);
        string sentResponse(response.c_str() + offset, bytesSent);
        logToFile("Server response: " + sentResponse);

        if (bytesSent < 0) {
            cerr << "Lỗi khi gửi dữ liệu!" << endl;
            break;
        }

        // Cập nhật offset để gửi phần tiếp theo
        offset += bytesSent;
    }
}

void handleClient(int clientSocket) {
    char buffer[BUFFER_SIZE];
    string partialMessage;
    while (true) {
        // Nhận message từ client
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            break; // Ngắt kết nối
        }

        string request(buffer, bytesReceived);
        cout << "Received: " << request << endl;

        // Ghi log request vào file
        logToFile("Received: " + request);

        // Xử lý yêu cầu từ client
        if (endsWith(request, "|<END>")) {
            partialMessage += request;
            partialMessage = partialMessage.substr(0, partialMessage.length() - 6);
            processClientRequest(clientSocket, partialMessage); // Process the full message
            partialMessage.clear();                             // Clear buffer for next message
        } else {
            partialMessage += request; // Append to the existing buffer
        }
    }

    // Đóng kết nối khi xử lý xong
    close(clientSocket);
}

void printServerIP() {
    struct ifaddrs *interfaces = nullptr;
    getifaddrs(&interfaces);

    cout << "Server IP Address:" << endl;
    for (struct ifaddrs *addr = interfaces; addr != nullptr; addr = addr->ifa_next) {
        if (addr->ifa_addr && addr->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)addr->ifa_addr;
            char ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(ipv4->sin_addr), ip, INET_ADDRSTRLEN);
            cout << " - " << ip << endl;
        }
    }
    freeifaddrs(interfaces);
}

void startServer() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrLen = sizeof(clientAddr);

    // Tạo socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Lỗi tạo socket" << std::endl;
        return;
    }

    // Cấu hình địa chỉ server
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Gắn socket vào địa chỉ
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Lỗi bind socket" << std::endl;
        return;
    }

    // Lắng nghe kết nối
    if (listen(serverSocket, 5) < 0) {
        std::cerr << "Lỗi lắng nghe kết nối" << std::endl;
        return;
    }

    std::cout << "Server đang chạy trên cổng " << PORT << std::endl;

    while (true) {
        // Chấp nhận kết nối từ client
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrLen);
        if (clientSocket < 0) {
            std::cerr << "Lỗi chấp nhận kết nối" << std::endl;
            continue;
        }

        // Tạo thread mới để xử lý client
        std::thread clientThread(handleClient, clientSocket);
        clientThread.detach();
    }

    // Đóng socket server
    close(serverSocket);
}

int main() {
    startServer();
    return 0;
}
