#include "event.h"

Event::Event(){
    ;
}

Event::Event(int aSector, structure_type aType){
    sector = aSector;
    type = aType;
}

Event::~Event(){
    ;
}

int Event::getSector() const{
    return sector;
}

structure_type Event::getType() const{
    return type;
}

void Event::setSector(int aSector){
    sector = aSector;
}

void Event::setType(structure_type aType){
    type = aType;
}
