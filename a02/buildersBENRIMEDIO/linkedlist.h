#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& aList);
    Node* getTail() const;
    const LinkedList& operator= (const LinkedList& aList);
    void insertFront(const Event& aEvent);
    void removeBack(Event& dest);
    bool isEmpty() const;
private:
    Node* head;
    Node* tail;
};

#endif
