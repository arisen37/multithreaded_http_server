#include <http_server/socket_util.h>

int main(){
    int socketId = socket_util::createAndBindSocket(8080);
    listen(socketId , 5);

    //Try TCP Socket
    int clientSocket = accept(socketId , nullptr , nullptr);
    char buffer[1024] = {0};
    recv(clientSocket , buffer , sizeof(buffer) , 0);
    std::cout << "Message from client : " << buffer << std::endl;

    close(socketId);
}




