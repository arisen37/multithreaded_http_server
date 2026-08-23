#include <http_server/socket_util.h>
#include <thread>
#include <mutex>

std::mutex cout_lock;

void AcceptTCPConnection(int clientSocket){
    char *buffer = (char *)(malloc(sizeof(char)*1024));
    bool end_of_headers = false;
    int pointer = 0;
    while(!end_of_headers){
        int byte_rec = recv(clientSocket , buffer + pointer, 1024 * sizeof(char) , 0);

        // client closed connection or error occurred -> stop waiting for more data
        if(byte_rec <= 0){
            break;
        }

        for(int i = 0 ; i < pointer + byte_rec && i < pointer + 1024 - 4 ; i++){
            if(buffer[i] == '\r' && buffer[i+1] == '\n' && buffer[i+2] == '\r' && buffer[i+3] == '\n'){
                end_of_headers = true;
            }
        }

        if(!end_of_headers){
            char *temp = (char *)(realloc(buffer , (pointer + 1024)*sizeof(char)));
            buffer = temp;
            pointer += 1024;
        }
    }

    cout_lock.lock();
    std::cout << buffer << std::endl;
    cout_lock.unlock();
    free(buffer);
    close(clientSocket);
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




