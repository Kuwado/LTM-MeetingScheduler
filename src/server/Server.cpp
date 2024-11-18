#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../controllers/UserController.h"
#include "../Status.h"
#include "../utils/MessageUtils.h"
#include <fstream>

#define PORT 8080
#define BUFFER_SIZE 1024

UserController userController;

// Hàm ghi log vào file
void logToFile(const std::string &message) {
    std::ofstream logFile("server_logs.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.close();
    }
}

void processClientRequest(int clientSocket, const std::string &request) {
    std::string response;
    std::string command = request.substr(0, request.find('|'));

    // Sử dụng switch-case để xử lý yêu cầu từ client
    if (command == "REGISTER") {
        response = MessageUtils::createMessage(Status::SUCCESS, "Dang ky thanh cong");
    } else if (command == "LOGIN") {
        response = MessageUtils::createMessage(Status::SUCCESS, "Dang nhap thanh cong");
    } else {
        response = MessageUtils::createMessage(Status::UNKNOWN_ERROR, "Yeu cau khong hop le");
    }

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
