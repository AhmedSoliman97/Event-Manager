#ifndef EVENTSBASE_H
#define EVENTSBASE_H
#include<iostream>

enum priorityLevel{
    High=1,
    Medium,
    Low
};

class EventsBase
{
    public:
        EventsBase();
        EventsBase(const int eventPriority);
        virtual ~EventsBase();
        virtual void executeEvent()=0;
        virtual void setupEvent()=0;   /** i didn't do another 2classes just for separation between system and hardware and inheriete from two 2 classes int the events
                                            cause i think it's lots of code for the same thing    */
        virtual int getPriority()const=0;

    protected:
        int priority;


};

#endif // EVENTSBASE_H
