#ifndef SYSTEMSHUTDOWN_H
#define SYSTEMSHUTDOWN_H


#include "EventsBase.h"

class SystemShutdown:public EventsBase
{

    public:
        SystemShutdown();
        void executeEvent();
        void setupEvent();
        int getPriority()const{
            return priority;
        };

};

#endif // SYSTEMSHUTDOWN_H
