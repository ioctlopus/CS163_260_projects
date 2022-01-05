#ifndef NODE_H
#define NODE_H
#include "Survey_data.h"
class Node{
public:
    //Constructors and destructors:
    Node();
    ~Node();
    Node(const int aSector, const int aExposure, const int aSpeed);
    //Accessors/Mutators:
    void setData(const Survey_data& aData);
    void setNextSector(Node* aNode);
    void setNextExposure(Node* aNode);
    void setNextSpeed(Node* aNode);
    Survey_data getData() const;
    int getSector() const;
    int getExposure() const;
    int getSpeed() const;
    Node* getNextSector() const;
    Node* getNextExposure() const;
    Node* getNextSpeed() const;
    //Helpers and Miscellaneous:
    void printNode() const;
    //Rule of Three stuff:
    void operator= (const Node& aNode);
    Node(const Node& aNode);
private:
    Survey_data data;
    Node* nextSector;
    Node* nextExposure;
    Node* nextSpeed;
};

#endif
