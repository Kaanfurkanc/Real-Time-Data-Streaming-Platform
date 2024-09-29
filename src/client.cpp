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

    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cerr << "Socket is not created: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        cerr << "Connection failed: " << WSAGetLastError() << endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    const char* message = "Client message: Hello, server!";
    send(sock, message, strlen(message), 0);
    cout << "Message sent to server" << endl;

    int valread = recv(sock, buffer, 1024, 0);
    cout << "Server response: " << buffer << endl;

    closesocket(sock);
    WSACleanup();

    return 0;
}
