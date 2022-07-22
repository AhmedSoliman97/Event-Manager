#include "HardwareReceivePacket.h"

HardwareReceivePacket::HardwareReceivePacket():EventsBase(Low){};

void HardwareReceivePacket::executeEvent(){

    std::cout<<"HardwareReceivePacket is executing...\n";
    setupEvent();

}

void HardwareReceivePacket::setupEvent(){
    std::cout<<"HardwareReceivePacket Setup Called\n\n";

}

