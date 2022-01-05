#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList(){
    headSector = nullptr;
    headExposure = nullptr;
    headSpeed = nullptr;
}

//Shallow copy, since datalogger doesn't call for anything fancy:
void LinkedList::operator= (const LinkedList& aList){
    if(this == &aList)
        return;
    headSector = aList.getHeadSector();
    headExposure = aList.getHeadExposure();
    headSpeed = aList.getHeadSpeed();
}

//Shallow copy, since datalogger doesn't call for anything fancy:
LinkedList::LinkedList(const LinkedList& aList){
    this->headSector = nullptr;
    this->headExposure = nullptr;
    this->headSpeed = nullptr;
    *this = aList;
}

LinkedList::~LinkedList(){
    if(headSector){
        Node* curr = headSector;
        Node* tmp;
        while(curr->getNextSector()){
            tmp = curr;
            curr = curr->getNextSector();
            delete tmp;
        }
        delete curr;
    }
}

Node* LinkedList::getHeadSector() const{
    return headSector;
}

Node* LinkedList::getHeadExposure() const{
    return headExposure;
}

Node* LinkedList::getHeadSpeed() const{
    return headSpeed;
}

void LinkedList::setHeadSector(Node* aNode){
    headSector = aNode;
}

void LinkedList::setHeadExposure(Node* aNode){
    headExposure = aNode;
}

void LinkedList::setHeadSpeed(Node* aNode){
    headSpeed = aNode;
}

//Wrapper for inserting into all three threads:
void LinkedList::insert(const int aSector, const int aExposure, const int aSpeed){
    Node* newNode = new Node(aSector, aExposure, aSpeed);
    addNodeSector(newNode);
    addNodeExposure(newNode);
    addNodeSpeed(newNode);
}

void LinkedList::addNodeSector(Node* aNode){
    //Empty list:
    if(!headSector){
        headSector = aNode;
    }
    //Insert before head:
    else if(headSector->getSector() >= aNode->getSector()){
        aNode->setNextSector(headSector);
        headSector = aNode;
    }
    //Traverse until insertion point:
    else{
        Node* curr = headSector;
        Node* prev = nullptr;
        while(curr && aNode->getSector() > curr->getSector()){
            prev = curr;
            curr = curr->getNextSector();
        }
        prev->setNextSector(aNode);
        aNode->setNextSector(curr);        
    }
}

void LinkedList::addNodeExposure(Node* aNode){
    //Empty list:
    if(!headExposure){
        headExposure = aNode;
    }
    //Insert before head:
    else if(headExposure->getExposure() >= aNode->getExposure()){
        aNode->setNextExposure(headExposure);
        headExposure = aNode;
    }
    //Traverse until insertion point:
    else{
        Node* curr = headExposure;
        Node* prev = nullptr;
        while(curr && aNode->getExposure() > curr->getExposure()){
            prev = curr;
            curr = curr->getNextExposure();
        }
        prev->setNextExposure(aNode);
        aNode->setNextExposure(curr);
    }
}

void LinkedList::addNodeSpeed(Node* aNode){
    //Empty list:
    if(!headSpeed){
        headSpeed = aNode;
    }
    //Insert before head:
    else if(headSpeed->getSpeed() >= aNode->getSpeed()){
        aNode->setNextSpeed(headSpeed);
        headSpeed = aNode;
    }
    //Traverse until insertion point:
    else{
        Node* curr = headSpeed;
        Node* prev = nullptr;
        while(curr && aNode->getSpeed() > curr->getSpeed()){
            prev = curr;
            curr = curr->getNextSpeed();
        }
        prev->setNextSpeed(aNode);
        aNode->setNextSpeed(curr);
    }
}

bool LinkedList::hasSector(int aSector) const{
    bool found = false;
    if(headSector){
        Node* curr = headSector;
        //Traverse until found or end of list, whichever comes first:
        while(!found && curr){
            if(curr->getSector() == aSector)
                found = true;
            curr = curr->getNextSector();
        }
    }
    return found;
}

void LinkedList::removeBySector(int aSector){
    if(headSector){
        Node* nodeToRemove = headSector;
        Node* prev = nullptr;
        //Traverse until sector is found or end of list, whichever comes first:
        while(nodeToRemove && nodeToRemove->getSector() != aSector){
            prev = nodeToRemove;
            nodeToRemove = nodeToRemove->getNextSector();
        }
        //Beginning removal:
        if(nodeToRemove && !prev){
            headSector = nodeToRemove->getNextSector();
        }
        //Middle or end removal:
        else if(prev && nodeToRemove){
            prev->setNextSector(nodeToRemove->getNextSector());
        }
        deleteExposure(nodeToRemove);
        deleteSpeed(nodeToRemove);
        delete nodeToRemove;
    }
}

void LinkedList::deleteExposure(Node* aNode){
    Node* curr = headExposure;
    Node* prev = nullptr;
    //Find node:
    while(curr && curr != aNode){
        prev = curr;
        curr = curr->getNextExposure();
    }
    //Beginning removal:
    if(curr && !prev){
        headExposure = curr->getNextSector();
    }
    //Middle or end removal:
    else if(curr && prev){
        prev->setNextExposure(curr->getNextExposure());
    }
}

void LinkedList::deleteSpeed(Node* aNode){
    Node* curr = headSpeed;
    Node* prev = nullptr;
    //Find node:
    while(curr && curr != aNode){
        prev = curr;
        curr = curr->getNextSpeed();
    }
    //Beginning removal:
    if(curr && !prev){
        headSpeed = curr->getNextSpeed();
    }
    //Middle or end removal:
    else if(curr && prev){
        prev->setNextSpeed(curr->getNextSpeed());
    }
}

//Just print sectors as a comma-separated list:
void LinkedList::printSectors() const{
    Node* curr = headSector;
    while(curr){
        std::cout << curr->getSector();
        if(curr->getNextSector())
            std::cout << ", ";
        else
            std::cout << std::endl;
        curr = curr->getNextSector();
    }
}

void LinkedList::printBySector() const{
    Node* curr = headSector;
    while(curr){
        curr->printNode();
        curr = curr->getNextSector();
    }
}

void LinkedList::printByExposure() const{
    Node* curr = headExposure;
    while(curr){
        curr->printNode();
        curr = curr->getNextExposure();
    }
}

void LinkedList::printBySpeed() const{
    Node* curr = headSpeed;
    while(curr){
        curr->printNode();
        curr = curr->getNextSpeed();
    }
}

void LinkedList::printAverages() const{
    Node* curr = headSector;
    Node* currAvgNode = nullptr;
    int speed = 0, exposure = 0, numSectors = 0;
    int currSector = 1;
    while(curr){
        //Traverse until a sector with data:
        for(int i = currSector; curr->getSector() != currSector; i++, currSector++){
            std::cout << "Sector: #" << i << "   -- no data --" << std::endl;
        }
        currSector = curr->getSector();
        //Average data for all of this sector, traversing until a new sector is reached:
        for(currAvgNode = curr; currAvgNode && currAvgNode->getSector() == currSector; currAvgNode = currAvgNode->getNextSector()){
            speed += currAvgNode->getSpeed();
            exposure += currAvgNode->getExposure();
            numSectors++;
        }
        speed /= numSectors;
        exposure /= numSectors;
        //Print averages and reset values:
        std::cout << "Sector: #" << currSector << " " << exposure << "% exposure, "
                  << speed << " km/hr windspeed" << std::endl;
        speed = 0;
        numSectors = 0;
        exposure = 0;
        curr = curr->getNextSector();
    }
}

void LinkedList::printHistogramExposure() const{
    Node* curr = headExposure;
    int numOccurrences = 0, currExposure = 0;
    while(curr){
        //Start with lowest value. Increment until next value is reached:
        currExposure = curr->getExposure();
        for(Node* tmp = curr; tmp && tmp->getExposure() == currExposure; tmp = tmp->getNextExposure()){
            numOccurrences++;
            curr = tmp;
        }
        std::cout << currExposure << ", " << numOccurrences << std::endl;
        numOccurrences = 0;
        if(curr){
            //Continue traversal and print 0 for all values not contained in the list between lowest and highest:
            curr = curr->getNextExposure();
            for(int i = currExposure + 1; curr && i < curr->getExposure(); i++)
                std::cout << i << ", 0" << std::endl;
        }
    }
}

void LinkedList::printHistogramSpeed() const{
    Node* curr = headSpeed;
    int numOccurrences = 0, currSpeed = 0;
    while(curr){
        //Start with lowest value. Increment until next value is reached:
        currSpeed = curr->getSpeed();
        for(Node* tmp = curr; tmp && tmp->getSpeed() == currSpeed; tmp = tmp->getNextSpeed()){
            numOccurrences++;
            curr = tmp;
        }
        std::cout << currSpeed << ", " << numOccurrences << std::endl;
        numOccurrences = 0;
        if(curr){
            //Continue traversal and print 0 for all values not contained in the list between lowest and highest:
            curr = curr->getNextSpeed();
            for(int i = currSpeed + 1; curr && i < curr->getSpeed(); i++)
                std::cout << i << ", 0" << std::endl;
        }
    }
}
