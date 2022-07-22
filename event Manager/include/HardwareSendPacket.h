#ifndef HARDWARESENDPACKET_H
#define HARDWARESENDPACKET_H

#include "EventsBase.h"

class HardwareSendPacket:public EventsBase
{

    public:
        HardwareSendPacket();
        void executeEvent();
        void setupEvent();
        int getPriority()const{
            return priority;
        };
};

#endif // HARDWARESENDPACKET_H
