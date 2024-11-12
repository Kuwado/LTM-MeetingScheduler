#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

void init();
void connectToServer();
void sendMessage(const char* message);
void receiveMessage();
void cleanup();

SOCKET clientSocket;

void init() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        fprintf(stderr, "WSAStartup failed with error: %d\n", result);
        exit(1);
    }

    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        fprintf(stderr, "Socket creation failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        exit(1);
    }
}

void connectToServer() {
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080); // Server port
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost address

    int result = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (result == SOCKET_ERROR) {
        fprintf(stderr, "Connect failed with error: %d\n", WSAGetLastError());
        closesocket(clientSocket);
        WSACleanup();
        exit(1);
    }
    printf("Connected to the server successfully!\n");
}

void sendMessage(const char* message) {
    int result = send(clientSocket, message, strlen(message), 0);
    if (result == SOCKET_ERROR) {
        fprintf(stderr, "Send failed with error: %d\n", WSAGetLastError());
        closesocket(clientSocket);
        WSACleanup();
        exit(1);
    }
    printf("Message sent: %s\n", message);
}

void receiveMessage() {
    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0'; // Ensure null-termination
        printf("Received from server: %s\n", buffer);
    }
    else if (bytesReceived == 0) {
        printf("Connection closed by server.\n");
    }
    else {
        fprintf(stderr, "Receive failed with error: %d\n", WSAGetLastError());
    }
}

void cleanup() {
    closesocket(clientSocket);
    WSACleanup();
}

int main() {
    // Initialize client
    init();

    // Connect to the server
    connectToServer();

    // Send a message to the server
    sendMessage("Hello, Hoan!");

    // Receive the response from the server
    receiveMessage();

    // Clean up and close the connection
    cleanup();

    return 0;
}
