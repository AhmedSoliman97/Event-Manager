#ifndef SYSTEMWAKEUP_H
#define SYSTEMWAKEUP_H

#include "EventsBase.h"


class SystemWakeup:public EventsBase
{

    public:
        SystemWakeup();
        void executeEvent();
        void setupEvent();
        int getPriority()const{
            return priority;
        };


};

#endif // SYSTEMWAKEUP_H
