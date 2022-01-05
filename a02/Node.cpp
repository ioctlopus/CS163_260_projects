#include "Node.h"

Node::Node(){
    data = Event();
    next = nullptr;
}

Node::Node(const Event& aEvent, Node* aNext, Node* aPrev){
    data = aEvent;
    next = aNext;
    prev = aPrev;
}

Node::~Node(){
    next = nullptr;
    prev = nullptr;
}

void Node::setData(const Event& aEvent){
    data = aEvent;
}

const Node& Node::operator= (const Node& aNode){
    if(this != &aNode){
        data = aNode.getData();
        next = aNode.getNext();
        prev = aNode.getPrev();
    }
    return *this;
}

Node::Node(const Node& aNode){
    this->next = nullptr;
    this->prev = nullptr;
    *this = aNode;
}

void Node::setNext(Node* aNode){
    next = aNode;
}

void Node::setPrev(Node* aNode){
    prev = aNode;
}

Event Node::getData() const{
    return data;
}

Node* Node::getNext() const{
    return next;
}

Node* Node::getPrev() const{
    return prev;
}
