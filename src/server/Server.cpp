#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <pthread.h>
#include <arpa/inet.h>
#include <unistd.h> // Thư viện cho close() trên Linux
#include <sys/socket.h>
#include <stdlib.h>

using namespace std;

class Server {
public:
    void init();
    void run();
    static void* handleClient(void* arg);  // Thay đổi để phù hợp với pthread

private:
    int serverSocket;
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
    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        string message(buffer);
        Server server;
        server.logMessage("Received: " + message);

        // Xử lý tin nhắn và gửi phản hồi
        string response = "Server received your message.";
        send(clientSocket, response.c_str(), response.size(), 0);
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
