#include "../Status.h"
#include "../controllers/ResponseController.h"
#include "../controllers/UserController.h"

#include "../models/Response.h"
#include "../models/User.h"
#include "../repository/UserRepository.h"
#include "../utils/MessageUtils.h"
#include <arpa/inet.h>
#include <fstream>
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

void processClientRequest(int clientSocket, const string &request) {
    string response;
    string command = request.substr(0, request.find('|'));
    vector<string> result = splitString(request, '|');
    Response res;

    if (command == "REGISTER") {
        string username = result[1];
        string password = result[2];
        string role = result[3];
        string first_name = result[4];
        string last_name = result[5];

        res = userController.registerA(username);
        if (res.getStatus() == 0) {
            User newUser(username, password, role, first_name, last_name);
            userRepo.create(newUser);
        }
        if (res.getStatus() == 0) {
            string message = res.getMessage();
            User newUser = userRepo.getUserByUsername(username);
            message = to_string(newUser.getId()) + "|" 
                + newUser.getUsername() + "|" 
                + newUser.getPassword() + "|" 
                + newUser.getRole() + "|" 
                + newUser.getFirstName() + "|" 
                + newUser.getLastName() + "|" + message;

            res.setMessage(message);
        }
    } else if (command == "LOGIN") {
        string username = result[1];
        string password = result[2];
        res = userController.login(username, password);
        if (res.getStatus() == 0) {
            User user = userRepo.getUserByUsername(username);
            string message = res.getMessage();
            message = to_string(user.getId()) + "|" + user.getRole() + "|" + message;
            res.setMessage(message);
        }
    } else if (command == "VIEW_TIME_SLOTS") {
        int teacher_id = stoi(result[1]);
        res = responseController.viewTimeslots(teacher_id);
    } else if (command == "UPDATE_TIME_SLOT") {
        res = responseController.updateTimeslot(request);
    } else if (command == "DECLARE_TIME_SLOT") {
        res = responseController.declareTimeslot(request);
    } else {
        response = MessageUtils::createMessage(Status::UNKNOWN_ERROR, "Yeu cau khong hop le");
    }

    response = to_string(res.getStatus()) + "|" + res.getMessage();

    // Ghi log phản hồi vào file
    logToFile("Server response: " + response);

    // Gửi phản hồi về client
    send(clientSocket, response.c_str(), response.size(), 0);
}

void handleClient(int clientSocket) {
    char buffer[BUFFER_SIZE];
    while (true) {
        // Nhận message từ client
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            break; // Ngắt kết nối
        }

        std::string request(buffer, bytesReceived);
        std::cout << "Received: " << request << std::endl;

        // Ghi log request vào file
        logToFile("Received: " + request);

        // Xử lý yêu cầu từ client
        processClientRequest(clientSocket, request);
    }

    // Đóng kết nối khi xử lý xong
    close(clientSocket);
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
