#include "HardwareSendPacket.h"

HardwareSendPacket::HardwareSendPacket():EventsBase(High){};


void HardwareSendPacket::executeEvent(){

    std::cout<<"HardwareSendPacket is executing...\n";
    setupEvent();

}


void HardwareSendPacket::setupEvent(){
    std::cout<<"HardwareSendPacket Setup Called\n\n";

}


