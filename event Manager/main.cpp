#include <iostream>
#include <ctime>

#include "EventsManager.h"
#include "EventsGenerator.h"


int main()
{
        /*****************  Note *************************/
         /**i'm running two threads in parallel (generate and execute) ,i can run generate first then execute by just move the start
            and put it after the while loop down , but i guess in real there is lots of threads running together so i'm trying to be real .
            also i'm execute every event after (21 second ) we can change that easily. */
        /************************************************/

    const float Time_To_keep_generate_in_mintue = 1; /**  to detect minutes to run the threads within*/
    const float periodic_time_to_execute_event_from_the_qeueu_in_seconds = 6;  /** to execute event every 6 sec*/

    EventsManager& eventManager = EventsManager::createEventsManager(periodic_time_to_execute_event_from_the_qeueu_in_seconds);


    EventsGenerator generator(3);  /** to generate event every  3 sec */


     eventManager.startHandlingEvents();  /** start the thread  **/


    generator.startGenerateHandelr();       /** start the G_thread  **/

    /** start time out to get out of the operation **/
    std::time_t now = std::time(nullptr) ;      /** get the current time point  **/


    std::tm calendar_time = *std::localtime( std::addressof(now) ) ;   /** convert it to (local) calendar time  **/
    float initialTime = calendar_time.tm_min;
    const float finalTime = initialTime + Time_To_keep_generate_in_mintue;


      /********** running the threads for certain time ************************/
    while(finalTime != initialTime){


          eventManager<<generator.getGeneratedEvent();  /**** get event from event factor and push in the queue *****/

          /*** get the current time to compare to decide to get out of the loop or not ***/
          now = std::time(nullptr) ;
          calendar_time = *std::localtime( std::addressof(now) ) ;
          initialTime = calendar_time.tm_min;

      };
    /***************************************************************************/


    generator.stopGenerateHandelr();  /** call stop the factor  **/

    eventManager.stopHandlingEvents();   /** call stop the queue **/





    return 0;
}
