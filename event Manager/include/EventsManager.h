#ifndef EVENTSMANAGER_H
#define EVENTSMANAGER_H
#include<thread>
#include<queue>
#include<vector>



#include <unistd.h>
#include <windows.h>


#include"Comparator.h"

class EventsManager
{
    EventsManager(const EventsManager& other)=delete;

     private:
        EventsManager(const int& timeToExecute):isExecuteStopped(false),lastEvent(nullptr),timeToExecuteEvent(timeToExecute){};
        std::thread* thread ;
        std::priority_queue<EventsBase*,std::vector<EventsBase*>,Comparator> EventsQueue;
        bool isExecuteStopped;   /** to check whether to stop the thread or not */
        EventsBase* lastEvent;  /** to check that the event is not the same one so we only push different events(as address) */
        void executeEventHandelr();
        void postEvent(EventsBase* event);
        int timeToExecuteEvent;


     public:
        static EventsManager& createEventsManager(const int& timer){
            static EventsManager obj(timer);
            return obj;
        };
        void printQueue();  /** just for checking... */
        void startHandlingEvents();
        void stopHandlingEvents();
        void operator<<(EventsBase* event);


};

#endif // EVENTSMANAGER_H
