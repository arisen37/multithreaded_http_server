#include "../utils/socket_util.h"
#include <cstring>

int main(){
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    connect(clientSocket , (struct sockaddr*)&serverAddress , sizeof(serverAddress));

    const char* message = "Hello Server!";
    send(clientSocket , message , strlen(message) , 0);
    close(clientSocket);
}