#include "EventsBase.h"

EventsBase::EventsBase()
{
    //ctor
}
EventsBase::EventsBase(const int eventPriority){
    priority = eventPriority;
};

EventsBase::~EventsBase()
{
    //dtor
}
