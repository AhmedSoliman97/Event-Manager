#include "SystemSleep.h"

SystemSleep::SystemSleep():EventsBase(High){};


void SystemSleep::executeEvent(){
    std::cout<<"SystemSleep is executing...\n";
    setupEvent();
};


void SystemSleep::setupEvent(){
    std::cout<<"SystemSleep Setup Called\n\n";
};


