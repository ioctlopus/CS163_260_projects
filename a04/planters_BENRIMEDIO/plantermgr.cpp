#include "plantermgr.h"

plantermgr::plantermgr(){

}

plantermgr::~plantermgr(){

}

void plantermgr::plant(int aNum, const char* aName){
    data.add(aNum, aName);
}

void plantermgr::harvest(const char* aName, int aStart, int aStop){
    data.harvest(aName, aStart, aStop);
}

void plantermgr::prune(int aNum){
    data.prune(aNum);
}
