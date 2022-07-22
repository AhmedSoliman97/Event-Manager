#include "SystemWakeup.h"

SystemWakeup::SystemWakeup():EventsBase(Medium){};


void SystemWakeup::executeEvent(){
    std::cout<<"SystemWakeup is executing...\n";
    setupEvent();
};


void SystemWakeup::setupEvent(){
    std::cout<<"SystemWakeup Setup Called\n\n";
};

