#ifndef BST_H
#define BST_H

#include "node.h"

class bst{
public:
    bst();
    ~bst();
    bst(const bst& aTree);
    const bst& operator= (const bst& aTree);
    node* getRoot() const;
    void deepCopy(node*& newRoot, node* currRoot);
    void destroyTree(node*& currRoot);
    void deleteNode(node*& nodeToDelete);
    int remove(node*& currRoot, int aId);
    void add(int aNum, const char* aName);
    void insert(node*& currRoot, node* newNode);
    void harvest(const char* aName, int aStart, int aStop);
    void rHarvest(node*& currRoot, const char* aName, int aStart, int aStop);
    void prune(int aNum);
private:
    node* root;
};

#endif
