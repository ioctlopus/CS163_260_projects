#ifndef EVENT_H
#define EVENT_H

#include "structuretype.h"

class Event{
public:
    Event();
    Event(int aSector, structure_type aType);
    ~Event();
    //Accessors/Mutators:
    int getSector() const;
    structure_type getType() const;
    void setSector(int aSector);
    void setType(structure_type aType);
private:
    int sector;
    structure_type type;
};

#endif
