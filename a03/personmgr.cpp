#include "personmgr.h"

void personmgr::addPerson(const person& aPerson){
    hTable.addPerson(aPerson);
}

person* personmgr::findPerson(const char* aId){
    person* ret = hTable.findById(aId);
    return ret;
}

void personmgr::printHtStats() const{
    hTable.statReport();
}
