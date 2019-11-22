#include "wifi.h"
//#include "persistance.h"
//#include <iostream>
//#define Coalesce(a,b) a.empty() ? b : a;
extern "C" void app_main()
{
    new WiFi();
    //Persistance* p=new Persistance();
    //std::string s= Coalesce(p->GetString("test"),"Default value");
    //std::cout <<s<<"\n";
}