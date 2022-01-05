#ifndef LIST_H
#define LIST_H
#include "Node.h"
class LinkedList{
public:
    //Default Constructors/Destructors:
    LinkedList();
    ~LinkedList();
    //Accessors/Mutators:
    Node* getHeadSector() const;
    Node* getHeadExposure() const;
    Node* getHeadSpeed() const;
    void setHeadSector(Node* aNode);
    void setHeadExposure(Node* aNode);
    void setHeadSpeed(Node* aNode);
    //Functionality:
    void addNodeSector(Node* aNode);
    void addNodeExposure(Node* aNode);
    void addNodeSpeed(Node* aNode);
    void insert(const int aSector, const int aExposure, const int aSpeed);
    bool hasSector(int aSector) const;
    void removeBySector(int aSector);
    void deleteExposure(Node* aNode);
    void deleteSpeed(Node* aNode);
    void printSectors() const;
    void printBySector() const;
    void printByExposure() const;
    void printBySpeed() const;
    void printAverages() const;
    void printHistogramExposure() const;
    void printHistogramSpeed() const;
    //Rule of three stuff:
    void operator= (const LinkedList& aList);
    LinkedList(const LinkedList& aList);
private:
    Node* headSector;
    Node* headExposure;
    Node* headSpeed;
};
#endif
