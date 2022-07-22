#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "EventsBase.h"

class Comparator
{
    public:
        bool operator()(EventsBase* obj1 , EventsBase* obj2){
             return obj1->getPriority() > obj2->getPriority();
        };

};

#endif // COMPARATOR_H
