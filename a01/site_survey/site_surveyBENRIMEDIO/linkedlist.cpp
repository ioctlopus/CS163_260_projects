#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList(){
    headSector = nullptr;
    headExposure = nullptr;
    headSpeed = nullptr;
}

//Shallow copy, since datalogger doesn't call for anything fancy:
LinkedList& LinkedList::operator= (const LinkedList& aList){
    if(this != &aList){
        headSector = aList.getHeadSector();
        headExposure = aList.getHeadExposure();
        headSpeed = aList.getHeadSpeed();
    }
    return *this;
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
            if(curr->getSector() == aSector){
                found = true;
            }
            curr = curr->getNextSector();
        }
    }
    return found;
}

void LinkedList::removeBySector(int aSector){
//    while(hasSector(aSector)){
        Node* nodeToRemove = headSector;
        Node* prev = nullptr;
        //Traverse until sector is found or end of list, whichever comes first:  
        while(nodeToRemove && nodeToRemove->getSector() != aSector){
            prev = nodeToRemove;
            nodeToRemove = nodeToRemove->getNextSector();
        }
        if(nodeToRemove){
            //Beginning removal:
            if(!prev){
                headSector = nodeToRemove->getNextSector();
            }
            //End removal:
            else if(!nodeToRemove->getNextSector()){
                prev->setNextSector(nullptr);
            }
            //Middle removal:
            else{
                prev->setNextSector(nodeToRemove->getNextSector());
            }
        
            deleteExposure(nodeToRemove);
            deleteSpeed(nodeToRemove);
            delete nodeToRemove;
//        }
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
    if(curr){
        //Beginning removal:
        if(!prev){
            headExposure = curr->getNextExposure();
        }
        //End removal:
        else if(!curr->getNextExposure()){
            prev->setNextExposure(nullptr);
        }
        //Middle removal:
        else{
            prev->setNextExposure(curr->getNextExposure());
        }
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
    if(curr){
        //Beginning removal:
        if(!prev){
            headSpeed = curr->getNextSpeed();
        }
        //End removal:
        else if(!curr->getNextSpeed()){
            prev->setNextSpeed(nullptr);
        }
        //Middle removal:
        else{
            prev->setNextSpeed(curr->getNextSpeed());
        }
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
    int exposure = 0, speed = 0, numSects = 0;
    int currSector = 1, sectorRange;
    //Handle sectors prior to first:
    if(curr){
        currSector = curr->getSector();
    }
    for(int i = 1; i < currSector; i++){
        std::cout << "Sector: #" << i << "  -- no data -- " << std::endl;
    }
    //Averages per sector for valid sectors:
    while(curr){
        currSector = curr->getSector();
        speed = 0;
        exposure = 0;
        numSects = 0;
        while(curr && curr->getSector() == currSector){
            speed += curr->getSpeed();
            exposure += curr->getExposure();
            numSects++;
            curr = curr->getNextSector();
        }
        if(numSects){
            speed /= numSects;
            exposure /= numSects;
            std::cout << "Sector: #" << currSector << " " << exposure << "% exposure, "
                      << speed << " km/hr windspeed" << std::endl;
        }
        //Handle sectors in between valid sectors with data:
        if(curr){
            sectorRange = curr->getSector() - currSector;
            for(int i = 1; i < sectorRange; i++){
                std::cout << "Sector: #" << i + currSector << "  -- no data -- " << std::endl;
            }
        }
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
