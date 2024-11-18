#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../utils/MessageUtils.h"
#include "../controllers/UserController.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int clientSocket;
struct sockaddr_in serverAddr;
UserController userController;

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

void sendRequestToServer(const std::string &command) {
    send(clientSocket, command.c_str(), command.size(), 0);

    // Nhận phản hồi từ server
    char buffer[BUFFER_SIZE];
    int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
    if (bytesReceived > 0) {
        std::string response(buffer, bytesReceived);
        std::cout << "Server response: " << response << std::endl;
    }
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
            userController.registerAccount();
        } else if (command == "LOGIN") {
            userController.login();
        } else {
            std::cout << "Lenh khong hop le. Vui long nhap lai!" << std::endl;
        }

        // Sau khi thực hiện command, gửi yêu cầu đến server
        sendRequestToServer(command);
    }
}

void closeConnection() {
    close(clientSocket);
}

int main() {
    connectToServer();
    handleUserCommand();
    closeConnection();
    return 0;
}
