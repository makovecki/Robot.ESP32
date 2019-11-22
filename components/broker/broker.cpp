#include "broker.h"
#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std;
list<char> Broker::ProcessMessage(char *buffer)
{
    uint8_t messageType = *(buffer);
    Processor *processor=GetProcessor(messageType);

    int16_t messageSize = (*(buffer+1)<<8 ) + (*(buffer+2) );
    auto tmp= processor->ProcessMessage(buffer+3,messageSize);
    delete processor;
    return tmp;
}
Processor* Broker::GetProcessor(uint8_t type)
{
    Processor* p= new EchoProcessor();
    return p;
}

Broker::Broker(/* args */)
{
}

Broker::~Broker()
{
}