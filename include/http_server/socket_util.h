#ifndef SOCKET_UTIL_H
#define SOCKET_UTIL_H
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

namespace socket_util{
    int createAndBindSocket(int PORT);
};

#endif