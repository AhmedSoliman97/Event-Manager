#ifndef HARDWARERECEIVEPACKET_H
#define HARDWARERECEIVEPACKET_H

#include "EventsBase.h"

class HardwareReceivePacket:public EventsBase
{
    public:
        HardwareReceivePacket();
        void executeEvent();
        void setupEvent();
        int getPriority()const{
            return priority;
        };

};

#endif // HARDWARERECEIVEPACKET_H
