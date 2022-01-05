#include "linkedlist.h"

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList(){
    Node* curr = head;
    Node* tmp = nullptr;
    while(curr){
        tmp = curr;
        curr = curr->getNext();
        delete tmp;
    }
    delete curr;
}

//Just a helper for Rule of Three stuff:
Node* LinkedList::getTail() const{
    return tail;
}

//Deep copy:
LinkedList::LinkedList(const LinkedList& aList){
    Node* curr = aList.getTail();
    Event newData;
    while(curr){
        newData = curr->getData();
        insertFront(newData);
        curr = curr->getPrev();
    }
}

//Deep copy:
const LinkedList& LinkedList::operator= (const LinkedList& aList){
    if(this != &aList){
        Node* curr = head;
        Node* tmp = nullptr;
        Event newData;
        while(curr){
            tmp = curr;
            curr = curr->getNext();
            delete tmp;
        }
        delete curr;
        head = tail = nullptr;
        curr = aList.getTail();
        while(curr){
            newData = curr->getData();
            insertFront(newData);
            curr = curr->getPrev();
        }
    }
    return *this;
}

void LinkedList::insertFront(const Event& aEvent){
    Node* newNode;
    //Empty list:
    if(!head){
        newNode = new Node(aEvent, nullptr, nullptr);
        head = newNode;
        tail = newNode;
    }
    //Not empty list:
    else{
        newNode = new Node(aEvent, head, nullptr);
        head->setPrev(newNode);
        head = head->getPrev();
    }
}

//Remove oldest event:
void LinkedList::removeBack(Event& dest){
    Node* tmp;
    if(tail){
        tmp = tail->getPrev();
        if(tmp)
            tmp->setNext(nullptr);
        dest = tail->getData();
        delete tail;
        tail = tmp;
        if(!tail)
            head = nullptr;
    }
}

bool LinkedList::isEmpty() const{
    return head ? false : true;
}
