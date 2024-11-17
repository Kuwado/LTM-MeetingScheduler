#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h> // Thư viện cho close() trên Linux
#include <sys/socket.h>
#include <stdlib.h>

using namespace std;

class Client {
public:
    Client(const string& serverIP, int serverPort);
    ~Client();
    void init();
    void connectToServer();
    void sendMessage(const string& message);
    string receiveMessage();
    void handleUserCommands();

private:
    int clientSocket;
    sockaddr_in serverAddr;
    string serverIP;
    int serverPort;
};

Client::Client(const string& serverIP, int serverPort)
    : serverIP(serverIP), serverPort(serverPort), clientSocket(-1) {}

Client::~Client() {
    if (clientSocket != -1) {
        close(clientSocket);
    }
}

void Client::init() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        cerr << "Socket creation failed with error" << endl;
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    if (inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr) <= 0) {
        cerr << "Invalid address/ Address not supported" << endl;
        exit(1);
    }
}

void Client::connectToServer() {
    int result = connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if (result == -1) {
        cerr << "Connect failed with error" << endl;
        close(clientSocket);
        exit(1);
    }
    cout << "Connected to the server successfully!" << endl;
}

void Client::sendMessage(const string& message) {
    int result = send(clientSocket, message.c_str(), message.size(), 0);
    if (result == -1) {
        cerr << "Send failed with error" << endl;
        close(clientSocket);
        exit(1);
    }
    cout << "Message sent: " << message << endl;
}

string Client::receiveMessage() {
    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0'; // Đảm bảo chuỗi kết thúc bằng ký tự null
        return string(buffer);
    } else if (bytesReceived == 0) {
        cout << "Connection closed by server." << endl;
    } else {
        cerr << "Receive failed with error" << endl;
    }
    return "";
}

void Client::handleUserCommands() {
    string command;
    cout << "Enter command (REGISTER or LOGIN): ";
    getline(cin, command);

    if (command == "REGISTER") {
        string username, password, role, firstName, lastName;
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);
        cout << "Role (student/teacher): ";
        getline(cin, role);
        cout << "First Name: ";
        getline(cin, firstName);
        cout << "Last Name: ";
        getline(cin, lastName);

        // Tạo thông điệp theo định dạng yêu cầu
        string message = "REGISTER|" + username + "," + password + "," + role + "," + firstName + "," + lastName;
        sendMessage(message);

    } else if (command == "LOGIN") {
        string username, password;
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);

        // Tạo thông điệp theo định dạng yêu cầu
        string message = "LOGIN|" + username + "," + password;
        sendMessage(message);

    } else {
        cout << "Invalid command!" << endl;
        return;
    }

    // Nhận phản hồi từ server
    string response = receiveMessage();
    cout << "Server response: " << response << endl;
}

int main() {
    // Khởi tạo client với địa chỉ server là 127.0.0.1 và cổng 8080
    Client client("127.0.0.1", 8080);

    // Initialize và kết nối đến server
    client.init();
    client.connectToServer();

    // Gửi lệnh do người dùng nhập
    client.handleUserCommands();

    return 0;
}
