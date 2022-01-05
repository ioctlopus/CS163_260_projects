#ifndef NODE_H
#define NODE_H

#include "event.h"

class Node{
public:
    Node();
    ~Node();
    Node(const Event& aEvent, Node* aNext, Node* aPrev);
    Node(const Node& aNode);
    void setData(const Event& aEvent);
    void setNext(Node* aNode);
    void setPrev(Node* aNode);
    Event getData() const;
    Node* getNext() const;
    Node* getPrev() const;
    const Node& operator= (const Node& aNode);
private:
    Event data;
    Node* next;
    Node* prev;
};

#endif
