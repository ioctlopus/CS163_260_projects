#include <iostream>
#include "Node.h"

Node::Node(){
    nextSector = nullptr;
    nextExposure = nullptr;
    nextSpeed = nullptr;
}

Node::~Node(){
    nextSector = nullptr;
    nextExposure = nullptr;
    nextSpeed = nullptr;
}

Node::Node(const int aSector, const int aExposure, const int aSpeed){
    nextSector = nullptr;
    nextExposure = nullptr;
    nextSpeed = nullptr;
    data.setSector(aSector);
    data.setExposure(aExposure);
    data.setSpeed(aSpeed);
}

void Node::operator= (const Node& aNode){
    if(this == &aNode)
        return;
    data = aNode.getData();
    nextSector = aNode.getNextSector();
    nextExposure = aNode.getNextExposure();
    nextSpeed = aNode.getNextSpeed();
}

Node::Node(const Node& aNode){
    this->nextSector = nullptr;
    this->nextExposure = nullptr;
    this->nextSpeed = nullptr;
    *this = aNode;
}

void Node::setData(const Survey_data& aData){
    data = aData;
}

void Node::setNextSector(Node* aNode){
    nextSector = aNode;
}

void Node::setNextExposure(Node* aNode){
    nextExposure = aNode;
}

void Node::setNextSpeed(Node* aNode){
    nextSpeed = aNode;
}

Survey_data Node::getData() const{
    return data;
}

int Node::getSector() const{
    return data.getSector();
}

int Node::getExposure() const{
    return data.getExposure();
}

int Node::getSpeed() const{
    return data.getSpeed();
}

Node* Node::getNextSector() const{
    return nextSector;
}

Node* Node::getNextExposure() const{
    return nextExposure;
}

Node* Node::getNextSpeed() const{
    return nextSpeed;
}

void Node::printNode() const{
    data.printData();
}

