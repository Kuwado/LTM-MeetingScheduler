#include <iostream>
#include <winsock2.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

class Client {
public:
    void init();
    void connectToServer();
    void sendMessage(const string& message);
    void receiveMessage();
    SOCKET clientSocket;



};

void Client::init() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        cerr << "WSAStartup failed with error: " << result << endl;
        exit(1);
    }

    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "Socket creation failed with error: " << WSAGetLastError() << endl;
        WSACleanup();
        exit(1);
    }
}

void Client::connectToServer() {
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080); // Server port
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost address

    int result = connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if (result == SOCKET_ERROR) {
        cerr << "Connect failed with error: " << WSAGetLastError() << endl;
        closesocket(clientSocket);
        WSACleanup();
        exit(1);
    }
    cout << "Connected to the server successfully!" << endl;
}

void Client::sendMessage(const string& message) {
    int result = send(clientSocket, message.c_str(), message.size(), 0);
    if (result == SOCKET_ERROR) {
        cerr << "Send failed with error: " << WSAGetLastError() << endl;
        closesocket(clientSocket);
        WSACleanup();
        exit(1);
    }
    cout << "Message sent: " << message << endl;
}

void Client::receiveMessage() {
    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0'; // Ensure null-termination
        cout << "Received from server: " << buffer << endl;
    }
    else {
        cerr << "Receive failed with error: " << WSAGetLastError() << endl;
    }
}

int main() {
    Client client;

    // Initialize client
    client.init();

    // Connect to the server
    client.connectToServer();

    // Send a message to the server
    client.sendMessage("Hello, Server2!");

    // Receive the response from the server
    client.receiveMessage();

    // Clean up and close the connection
    closesocket(client.clientSocket);
    WSACleanup();

    return 0;
}
