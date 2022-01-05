#include <iostream>
#include "stack.h"

Stack::Stack(){
    top = nullptr;
    bot = nullptr;
}

Stack::~Stack(){
    while(!isEmpty())
        pop();
}

//Deep copy:
const Stack& Stack::operator= (const Stack& aStack){
    if(this != &aStack){
        while(!isEmpty())
            pop();
        Event newData;
        Node* curr = aStack.getBot();
        while(curr){
            newData = curr->getData();
            push(newData);
            curr = curr->getNext();
        }
    }
    return *this;
}

//Deep copy:
Stack::Stack(const Stack& aStack){
    Node* curr = aStack.getBot();
    Event newData;
    while(curr){
        newData = curr->getData();
        push(newData);
        curr = curr->getNext();
    }
}

//Just a helper for Rule of Three stuff:
Node* Stack::getBot() const{
    return bot;
}

Event Stack::peek() const{
    Event ret;
    if(top){
        ret = top->getData();
    }
    else{
        ret.setSector(-1);
        ret.setType(UNK);
    }
    return ret;
}

void Stack::push(const Event& aEvent){
    Node* newNode = new Node(aEvent, top, nullptr);
    if(isEmpty())
        bot = newNode;
    top = newNode;
}

Event Stack::pop(){
    Node* tmp = top;
    Event ret;
    if(tmp){
        top = top->getNext();
        ret = tmp->getData();
        delete tmp;
    }
    if(isEmpty())
        top = bot = nullptr;
    return ret;
}

bool Stack::isEmpty(){
    return top ? false : true;
}
