#include <iostream>
#include <cstring>
#include "node.h"

node::node(){
    id = 0;
    food = nullptr;
    left = nullptr;
    right = nullptr;
}

node::node(int aId, const char* aFood){
    id = aId;
    food = new char[strlen(aFood) + 1];
    strcpy(food, aFood);
    left = nullptr;
    right = nullptr;
}

node::node(const node& aNode){
    char* buffer = new char[aNode.sizeFood() + 1];
    aNode.getFood(buffer);
    setFood(buffer);
    id = aNode.getId();
}

node::~node(){
    id = 0;
    if(food)
        delete [] food;
    left = nullptr;
    right = nullptr;
}

int node::getId() const{
    return id;
}

void node::getFood(char* dest) const{
    strcpy(dest, food);
}

void node::setId(int aId){
    id = aId;
}

void node::setFood(const char* aFood){
    if(food)
        delete [] food;
    food = new char[strlen(aFood) + 1];
    strcpy(food, aFood);
}

size_t node::sizeFood() const{
    return strlen(food);
}


