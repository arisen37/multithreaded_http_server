#include <http_server/socket_util.h>
#include <thread>
#include <mutex>

std::mutex cout_lock;

void AcceptTCPConnection(int clientSocket){
    char buffer[1024] = {0};
    recv(clientSocket , buffer , sizeof(buffer) , 0);
    cout_lock.lock();
    std::cout << "Message from " << clientSocket << " " << buffer << std::endl;
    cout_lock.unlock();
}

int main(){
    int socketId = socket_util::createAndBindSocket(8080);
    listen(socketId , 10);

    while(true){
        //KEEP Listening for new connections
        int clientSocket = accept(socketId, nullptr , nullptr);
        std::thread worker(AcceptTCPConnection , clientSocket);

        worker.detach();
    }

    close(socketId);
}




