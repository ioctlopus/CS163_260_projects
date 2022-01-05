#include <iostream>
#include "builder.h"

builder::builder(){
    commList = LinkedList();
    sectStack = Stack();
    builderNum = 0;
    currSector = -1;
}

builder::~builder(){
    builderNum = 0;
    currSector = -1;
}

void builder::setBuilderNum(int aNum){
    builderNum = aNum;
}

bool builder::doCycle(){
    bool ret = false;
    Event currEvent;
    if(!commList.isEmpty()){
        commList.removeBack(currEvent);
        if(currEvent.getSector() != currSector)
            std::cout << "Builder #" << builderNum << ": Moving to sector " << currEvent.getSector() << std::endl;
        sectStack.push(currEvent);
        std::cout << "Builder #" << builderNum << ": Building a " << str(currEvent.getType()) << " in sector " << currEvent.getSector() << std::endl;
        currSector = currEvent.getSector();
        ret = true;
    }
    return ret;
}

void builder::addRequest(int aSector, structure_type aType){
    Event newEvent(aSector, aType); 
    commList.insertFront(newEvent);
    std::cout << "Builder #" << builderNum << ": Received request to build a " << str(aType) << " in sector " << aSector << std::endl;
}

void builder::returnHome(){
    Event currEvent = sectStack.pop();
    int currSect = currEvent.getSector();
    while(!sectStack.isEmpty()){
        std::cout << "Builder #" << builderNum << ": Connected to " << str(currEvent.getType()) << " in sector " << currSect << std::endl;
        currEvent = sectStack.pop();
        if(currEvent.getSector() != currSect)
            std::cout << "Builder #" <<builderNum << ": Moving to sector " << currEvent.getSector() << std::endl;
        currSect = currEvent.getSector();
    }
    std::cout << "Builder #" << builderNum << ": Connected to " << str(currEvent.getType()) << " in sector " << currSect << std::endl;
    std::cout << "Builder #" << builderNum << ": Arrived back at base." << std::endl;
}

