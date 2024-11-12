#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

SOCKET serverSocket;

// Function to log messages to a file
void logMessage(const char* message) {
    FILE* logFile = fopen("server_logs.txt", "a");
    if (logFile != NULL) {
        fprintf(logFile, "%s\n", message);
        fclose(logFile);
    }
}

// Client request handling function
DWORD WINAPI handleClient(LPVOID clientSocketPtr) {
    SOCKET clientSocket = *(SOCKET*)clientSocketPtr;
    free(clientSocketPtr);

    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        printf("Received: %s\n", buffer);
        logMessage(buffer);

        // Send response to the client
        const char* response = "Server received your message.";
        send(clientSocket, response, strlen(response), 0);
    }
    closesocket(clientSocket);
    return 0;
}

// Server initialization function
void initServer() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed with error: %d\n", WSAGetLastError());
        exit(1);
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        fprintf(stderr, "Socket creation failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        exit(1);
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        fprintf(stderr, "Bind failed with error: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        exit(1);
    }

    if (listen(serverSocket, 5) == SOCKET_ERROR) {
        fprintf(stderr, "Listen failed with error: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        exit(1);
    }

    printf("Server running on port 8080...\n");
}

// Server run function
void runServer() {
    while (1) {
        SOCKET* clientSocketPtr = (SOCKET*)malloc(sizeof(SOCKET));
        *clientSocketPtr = accept(serverSocket, NULL, NULL);
        if (*clientSocketPtr == INVALID_SOCKET) {
            fprintf(stderr, "Accept failed with error: %d\n", WSAGetLastError());
            free(clientSocketPtr);
            continue;
        }

        // Create and detach the client handler thread
        DWORD threadId;
        CreateThread(NULL, 0, handleClient, clientSocketPtr, 0, &threadId);
    }
}


int main() {
    // Initialize server
    initServer();

    // Run server
    runServer();

    // Close server socket and clean up
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
