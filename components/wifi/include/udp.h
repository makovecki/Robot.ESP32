#pragma once
#include "lwip/sockets.h"
class Udp
{
private:
    static void ReceiveTask(void *pvParameters);
    int s;
    in_port_t portIN;
    in_port_t portOUT;
    in_addr ip;
public:
    Udp(int port);
    ~Udp();
};


