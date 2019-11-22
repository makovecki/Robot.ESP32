#pragma once
#include <iostream> 
#include <list> 
#include <iterator> 
#include "processor.h"
using namespace std;
class Broker
{
private:
    Processor* GetProcessor(uint8_t type);
public:
    Broker(/* args */);
    list<char> ProcessMessage(char *buffer);
    ~Broker();
};


