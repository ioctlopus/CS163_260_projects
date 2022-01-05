#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack{
public:
    Stack();
    ~Stack();
    Stack(const Stack& aStack);
    void push(const Event& aEvent);
    Event pop();
    Node* getBot() const;
    Event peek() const;
    bool isEmpty();
    void display();
    const Stack& operator= (const Stack& aStack);
private:
    Node* top;
    Node* bot;
};

#endif
