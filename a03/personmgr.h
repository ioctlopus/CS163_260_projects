#ifndef PERMGR_H
#define PERMGR_H

#include "hashtable.h"

class personmgr{
public:
    void addPerson(const person& aPerson);
    person* findPerson(const char* aId);
    void printHtStats() const;
private:
    HashTable hTable;
};

#endif
