#ifndef EVENTSGENERATOR_H
#define EVENTSGENERATOR_H
#include<iostream>
#include<thread>
#include <stdlib.h>  /** srand, rand **/
#include <time.h>   /** to get the currentTime for the seed **/



class EventsBase;

class EventsGenerator
{
    public:
        EventsGenerator(const float& F);
        void stopGenerateHandelr();
        void startGenerateHandelr();
        EventsBase* getGeneratedEvent();


    private:
        float PeriodicTime;   /**  time to generate */
        std::thread* G_thread ;
        bool isGenerateStopped;   /** to stop the loop and get out of the loopFunction which execute in th thread*/
        EventsBase* Generated_Event;  /** to send to the eventManager to receive */
        void generateFactor();


};

#endif // EVENTSGENERATOR_H
