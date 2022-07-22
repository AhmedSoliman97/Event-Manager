#include "EventsManager.h"



void EventsManager::postEvent(EventsBase* event){
    EventsQueue.push(event);
    /** std::cout<<"event Pushed\n";  */
};

void EventsManager::startHandlingEvents(){
    thread = new std::thread(&EventsManager::executeEventHandelr,this);
};

void EventsManager::stopHandlingEvents(){
   isExecuteStopped = true;
   thread->join();
    delete thread;
};

/** just for checking... */
void EventsManager::printQueue(){
    while(!EventsQueue.empty()){
      EventsQueue.top()->executeEvent();
      EventsQueue.pop();
    }

}

void EventsManager::operator<<(EventsBase* event){
    if(event == nullptr){/** to check that we recieve not null address */
        return;
    };
    if(event ==lastEvent){
        return;
    }
    else{
       postEvent(event);
       lastEvent = event;
    }



};

void EventsManager::executeEventHandelr(){

   using namespace std::literals::chrono_literals;  /** to use the sleep_for function to sleep the thread for a certain time **/

   while(!isExecuteStopped || !EventsQueue.empty()){

        if(EventsQueue.empty()){
            std::cout<<"Queue is Empty and waiting for Event to Execute ....\n";
            std::this_thread::sleep_for(1s);   /** sleep the thread to 1sec then execute **/

        }
        else{
               while(!EventsQueue.empty()){ /** keep execute the events in the queue even after thread is stopped and do it with no delay  */

                if(isExecuteStopped){  /** to keep execute the events even after the time we detected in the main   [optional]*/
                    std::cout<<"thread is done but there is a some events in the queue...\n";
                    sleep(timeToExecuteEvent);
                }

                EventsQueue.top()->executeEvent();
                EventsBase* temp = EventsQueue.top();
                EventsQueue.pop();

                if(!isExecuteStopped){ /** to stop delay the thread when we stop it*/

                    std::this_thread::sleep_for(std::chrono::seconds((timeToExecuteEvent)));   /** wait to seconds then execute **/
                }

                 delete temp; /** to delete the event from the heap  */

              }
        }

   }

}

