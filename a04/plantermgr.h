#ifndef PLANTMGR_H
#define PLANTMGR_H

#include "bst.h"

class plantermgr{
public:
    plantermgr();
    ~plantermgr();
    void plant(int aNum, const char* aName);
    void harvest(const char* aName, int aStart, int aStop);
    void prune(int aNum);
private:
    bst data;
};

#endif
