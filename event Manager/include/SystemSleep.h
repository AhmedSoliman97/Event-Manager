#ifndef SYSTEMSLEEP_H
#define SYSTEMSLEEP_H


#include "EventsBase.h"

class SystemSleep:public EventsBase
{

    public:
        SystemSleep();
        void executeEvent();
        void setupEvent();
        int getPriority()const{
            return priority;
        };


};

#endif // SYSTEMSLEEP_H
