#include <iostream>
#include <winsock2.h>
#include <string>
#include <vector>
#include <fstream>
#include <thread>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

class Server {
public:
    void init();
    void run();
    void handleClient(SOCKET clientSocket);

private:
    SOCKET serverSocket;
    vector<string> logs;

    void logMessage(const string& message) {
        logs.push_back(message);
        ofstream logFile("server_logs.txt", ios::app);
        logFile << message << endl;
        logFile.close();
    }
};

// Khởi tạo server
void Server::init() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);
}

void Server::run() {
    cout << "Server running on port 8080...\n";
    while (true) {
        SOCKET clientSocket = accept(serverSocket, NULL, NULL);
        thread(&Server::handleClient, this, clientSocket).detach();
    }
}

// Xử lý yêu cầu từ client
void Server::handleClient(SOCKET clientSocket) {
    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        string message(buffer);
        logMessage("Received: " + message);

        // Xử lý tin nhắn và gửi phản hồi
        string response = "Server received your message.";
        send(clientSocket, response.c_str(), response.size(), 0);
    }
    closesocket(clientSocket);
}

int main() {
    Server server;

    // Khởi tạo server
    server.init();

    // Chạy server
    server.run();

    return 0;
}
