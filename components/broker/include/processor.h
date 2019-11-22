#pragma once
#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std;
class Processor
{
public:
    Processor(/* args */){}
    virtual list<char> ProcessMessage(char *message, int16_t messageSize) = 0;
    virtual ~Processor() =0;
};



class EchoProcessor : public Processor
{
public:
    EchoProcessor(/* args */) {}
    list<char> ProcessMessage(char *message, int16_t messageSize);
    ~EchoProcessor() {}
};


