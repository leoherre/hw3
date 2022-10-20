#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

//Functor to compare time
typedef struct EventLess {
    bool operator()(Event* one, Event* two){
    return (one->time < two->time);
  }
} EventLess;
	
#endif
