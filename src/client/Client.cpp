#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h> // Thư viện cho close() trên Linux
#include <sys/socket.h>
#include <stdlib.h>

using namespace std;

class Client {
public:
    void init();
    void connectToServer();
    void sendMessage(const string& message);
    void receiveMessage();
    int clientSocket; // Thay SOCKET thành int trên Linux
};

void Client::init() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        cerr << "Socket creation failed with error" << endl;
        exit(1);
    }
}

void Client::connectToServer() {
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080); // Server port
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost address

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

void Client::receiveMessage() {
    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0'; // Ensure null-termination
        cout << "Received from server: " << buffer << endl;
    }
    else if (bytesReceived == 0) {
        cout << "Connection closed by server." << endl;
    }
    else {
        cerr << "Receive failed with error" << endl;
    }
}

int main() {
    Client client;

    // Initialize client
    client.init();

    // Connect to the server
    client.connectToServer();

    // Send a message to the server
    client.sendMessage("Hello, Serveraijnaisfn!");

    // Receive the response from the server
    client.receiveMessage();

    // Clean up and close the connection
    close(client.clientSocket);

    return 0;
}
