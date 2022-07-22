#include "Comparator.h"

#include"EventsBase.h"


Comparator::Comparator()
{
    //ctor
}
bool Comparator::operator()(EventsBase* obj1 , EventsBase* obj2){
    return obj1->priority < obj2->priority;     /** overload the operator < instead of (get,set)  **/
};
