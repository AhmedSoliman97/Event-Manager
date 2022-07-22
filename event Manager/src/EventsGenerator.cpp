#include "EventsGenerator.h"
#include "SystemShutdown.h"
#include "SystemSleep.h"
#include "SystemWakeup.h"

#include "HardwareReceivePacket.h"
#include "HardwareSendPacket.h"

EventsGenerator::EventsGenerator(const float& F):PeriodicTime(F),isGenerateStopped(false),Generated_Event(nullptr){};

void EventsGenerator::stopGenerateHandelr(){
      isGenerateStopped= true;
      G_thread->join();
      delete G_thread;
      Generated_Event = nullptr;  /** because we already delete the heap in the event manager so it's pointing to no thing*/

};

void EventsGenerator::startGenerateHandelr(){
    G_thread = new std::thread(&EventsGenerator::generateFactor,this);
};

EventsBase* EventsGenerator::getGeneratedEvent(){

    if(Generated_Event == nullptr)
        std::cout<<"No Event Generated yet\n";
    return Generated_Event;
};

void EventsGenerator::generateFactor(){

    using namespace std::literals::chrono_literals;  /** to use the sleep_for function to sleep the thread for a certain time */
    if(isGenerateStopped)                             /** when we stop generating Events */
        std::cout<<"Generating Events is Done\n";

    while(!isGenerateStopped){

        srand (time(NULL));
        int randomEvent = rand() % 5 + 1;    /** get a random value for random operation */
           switch(randomEvent){
              case(1):
                {
                    Generated_Event = new SystemShutdown ; /** polymorphic object  from child SystemShutdown*/
                    //Generated_Event = tempObj;
                    std::cout<<"SystemShutdown   generated \n" ;
                }
              break;
              case(2):
                  {
                     Generated_Event = new SystemSleep ;  /** polymorphic object  from child SystemSleep*/
                        //Generated_Event = tempObj;
                        std::cout<<"SystemSleep   generated \n" ;
                  }

              break;
              case(3):
                  {
                     Generated_Event = new SystemWakeup ;  /** polymorphic object  from child SystemWakeup*/
                     //Generated_Event = tempObj;
                     std::cout<<"SystemWakeup   generated \n" ;

                  }

              break;
              case(4):
                  {
                     Generated_Event = new HardwareReceivePacket ;  /** polymorphic object  from child HardwareReceivePacket*/
                     //Generated_Event = tempObj;
                     std::cout<<"HardwareReceivePacket   generated \n" ;
                  }

              break;
              case(5):
                  {
                      Generated_Event = new HardwareSendPacket ;  /** polymorphic object  from child HardwareSendPacket*/
                      //Generated_Event = tempObj;
                       std::cout<<"HardwareSendPacket   generated \n" ;
                  }

              break;

              default:
                  //
                  ;
            }

            std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(PeriodicTime)));   /** wait to PeriodicTime **/

    }


};


