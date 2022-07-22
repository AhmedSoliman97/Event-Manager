#include "SystemShutdown.h"

SystemShutdown::SystemShutdown():EventsBase(Low){};


void SystemShutdown::executeEvent(){
    std::cout<<"SystemShutdown is executing...\n";
    setupEvent();
};

void SystemShutdown::setupEvent(){
    std::cout<<"SystemShutdown Setup Called\n\n";

}

