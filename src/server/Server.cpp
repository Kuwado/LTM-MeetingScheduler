#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <pthread.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sstream>
#include "../controllers/UserController1.h"  // Bao gồm UserController

using namespace std;

class Server {
public:
    void init();
    void run();
    static void* handleClient(void* arg);

private:
    int serverSocket;
    vector<string> logs;
    
    // Phương thức để ghi log vào tệp
    void logMessage(const string& message) {
        logs.push_back(message);
        ofstream logFile("server_logs.txt", ios::app);
        logFile << message << endl;
        logFile.close();
    }
};

// Khởi tạo server
void Server::init() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Socket creation failed" << endl;
        exit(1);
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        cerr << "Bind failed" << endl;
        close(serverSocket);
        exit(1);
    }

    if (listen(serverSocket, 5) == -1) {
        cerr << "Listen failed" << endl;
        close(serverSocket);
        exit(1);
    }
}

void Server::run() {
    cout << "Server running on port 8080...\n";
    while (true) {
        int clientSocket = accept(serverSocket, NULL, NULL);
        if (clientSocket == -1) {
            cerr << "Accept failed" << endl;
            continue;
        }

        pthread_t threadId;
        // Tạo một luồng mới để xử lý client
        if (pthread_create(&threadId, NULL, &Server::handleClient, (void*)(&clientSocket)) != 0) {
            cerr << "Failed to create thread" << endl;
            close(clientSocket);
        }
    }
}

// Xử lý yêu cầu từ client
void* Server::handleClient(void* arg) {
    int clientSocket = *((int*)arg);
    char buffer[1024] = {0};
    UserController userController;

    // Nhận yêu cầu từ client
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        string request(buffer);
        stringstream ss(request);
        string command, data;
        getline(ss, command, '|');
        getline(ss, data);

        Server server;
        server.logMessage("Received: " + request);

        if (command == "REGISTER") {
            // Tách thông tin đăng ký từ client
            stringstream dataStream(data);
            string username, password, role, firstName, lastName;
            getline(dataStream, username, ',');
            getline(dataStream, password, ',');
            getline(dataStream, role, ',');
            getline(dataStream, firstName, ',');
            getline(dataStream, lastName);

            User user(username, password, role, firstName, lastName);
            bool success = userController.registerAccount(user);
            string response;
            if (success) {
                cout << username << " - Viet Nammmmmmmmmmmmmmmmmmmm" << endl;
                response = "SUCCESS|Tài khoản đã được đăng ký thành công.";
            } else {
                response = "FAIL|Lỗi trong quá trình đăng ký.";
            }
            send(clientSocket, response.c_str(), response.size(), 0);

        } else if (command == "LOGIN") {
            // Tách thông tin đăng nhập từ client
            stringstream dataStream(data);
            string username, password;
            getline(dataStream, username, ',');
            getline(dataStream, password);

            User loggedInUser;
            bool success = userController.login(username, password, loggedInUser);
            string response;
            if (success) {
                cout << username << " - Viet Nammmmmmmmmmmmmmmmmmmm" << endl;
                response = "SUCCESS|Đăng nhập thành công.";
            } else {
                response = "FAIL|Tên đăng nhập hoặc mật khẩu không chính xác.";
            }
            send(clientSocket, response.c_str(), response.size(), 0);

        } else {
            string response = "FAIL|Lệnh không hợp lệ.";
            send(clientSocket, response.c_str(), response.size(), 0);
        }
    }
    close(clientSocket);
    return NULL;
}

int main() {
    Server server;

    // Khởi tạo server
    server.init();

    // Chạy server
    server.run();

    return 0;
}
