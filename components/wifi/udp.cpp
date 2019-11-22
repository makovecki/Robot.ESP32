#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "lwip/sockets.h"
#include <iostream>
#include "udp.h"
#include "broker.h"

void Udp::ReceiveTask(void *pvParameters)
{
    char rx_buffer[128];
    Udp *udp = static_cast<Udp *>(pvParameters);
    
    Broker *broker = new Broker();
    struct sockaddr_in source_addr; // Large enough for both IPv4 or IPv6
    socklen_t socklen = sizeof(source_addr);
    while (1) {
        if (udp->s<0) 
        {
            std::cout << "Unable to create socket!\n";
            break;
        }
        
        int len=recvfrom(udp->s, rx_buffer, sizeof(rx_buffer) - 1, 0, (struct sockaddr *)&source_addr, &socklen);
        //udp->portOUT = source_addr.sin_port;
        //udp->ip = source_addr.sin_addr;
        //std::cout << "Received:"<< len << " from port:"<< ntohs(source_addr.sin_port)<<"\n";
        if (len>=3) {
            auto reply=broker->ProcessMessage(rx_buffer);

            char tx_buffer[(reply.size())];
            uint16_t i = 0;
            for (auto c : reply) tx_buffer[i++] = c;

            int err = sendto(udp->s, &tx_buffer, sizeof(tx_buffer), 0, (struct sockaddr *)&source_addr, socklen);
            if (err < 0) {
                std::cout <<"Error occurred during sending\n";
            } 
        }
    }
    vTaskDelete(NULL);
}
Udp::Udp(int port)
{
    this->portIN = port;
    s = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    struct sockaddr_in dest_addr;
    dest_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    int e = bind(s, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (e < 0) {
        std::cout << "Unable to bind!\n";
    }
    int err = bind(s, (struct sockaddr *)&dest_addr, sizeof(dest_addr));

        if (err < 0) {
            std::cout << "Unable to bind!\n";
        }
    xTaskCreate(this->ReceiveTask, "udp_receive_task", 2048, this, 10, NULL);
    
}

Udp::~Udp()
{
}