#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <unistd.h>
#include <cstring>

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

const int PORT = 8080;

int main() {
    WSADATA wsaData;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        cerr << "WSAStartup failed: " << iResult << endl;
        return 1;
    }

    int server_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        cerr << "Socket is not created: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        cerr << "Bind Error: " << WSAGetLastError() << endl;
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    if (listen(server_fd, 3) == SOCKET_ERROR) {
        cerr << "Listen error: " << WSAGetLastError() << endl;
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    cout << "Server is listening, connections is waiting..." << endl;

    int new_socket;
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) == INVALID_SOCKET) {
        cerr << "Accept error: " << WSAGetLastError() << endl;
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    int valread = recv(new_socket, buffer, 1024, 0);
    cout << "Client message: " << buffer << endl;

    const char* message = "Server response: The message is received!";
    send(new_socket, message, strlen(message), 0);

    // Close socket
    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();

    return 0;
}
