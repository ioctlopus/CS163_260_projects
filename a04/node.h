#ifndef NODE_H
#define NODE_H

#include <cstddef>

class node{
public:
    //Declared these public to avoid lengthy workarounds for passing by reference. Basically
    //just the node and the box in the same class without having a separate struct:
    node* left;
    node* right;
    
    node();
    node(int aId, const char* aFood);
    node(const node& aNode);
    ~node();
    int getId() const;
    void getFood(char* dest) const;
    void setId(int aId);
    void setFood(const char* aFood);
    size_t sizeFood() const;
private:
    int id;
    char* food;
};

#endif
