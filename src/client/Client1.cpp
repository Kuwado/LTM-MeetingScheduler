#include "../controllers/UserController.h"
#include "../utils/MessageUtils.h"
#include "../views/UserView.h"
#include "../views/ViewManager.h"
#include "Client.h"
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
UserController userController;
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

void sendRequestToServer(const string &command) {
send(clientSocket, command.c_str(), command.size(), 0);

// Nhận phản hồi từ server
char buffer[BUFFER_SIZE];
int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
if (bytesReceived > 0) {
string response(buffer, bytesReceived);
string cmd = command.substr(0, command.find('|'));
if (cmd == "LOGIN") {
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
}
cout << "Server response: " << response << endl;
}
}

void handleUserCommand() {
LoginView loginView([]() {
RegisterView registerView([]() {
LoginView loginView([]() {
RegisterView registerView([]() {
LoginView loginView([]() {});
loginView.showLoginWindow();
});
registerView.showRegisterWindow();
});
loginView.showLoginWindow();
});
registerView.showRegisterWindow();
});
loginView.showLoginWindow();
}

void closeConnection() { close(clientSocket); }

int main() {
connectToServer();
handleUserCommand();
closeConnection();
return 0;
}
