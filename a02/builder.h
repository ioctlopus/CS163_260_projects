#ifndef BUILDER_H
#define BUILDER_H

#include "linkedlist.h"
#include "stack.h"

class builder{
public:
    builder();
    ~builder();
    void setBuilderNum(int aNum);
    bool doCycle();
    void addRequest(int aSector, structure_type aType);
    void returnHome();
private:
    LinkedList commList;
    Stack sectStack;
    int builderNum;
    int currSector;
};

#endif
