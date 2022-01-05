#include <iostream>
#include <cstring>
#include "bst.h"

bst::bst(){
    root = nullptr;
}

//Recursive destruction:
void bst::destroyTree(node*& currRoot){
    if(currRoot){
        destroyTree(currRoot->left);
        destroyTree(currRoot->right);
        delete currRoot;
        currRoot = nullptr;
    }
}

bst::~bst(){
    destroyTree(root);
}

//Just a helper for a few functions:
node* bst::getRoot() const{
    return root;
}

//Recursive copy:
void bst::deepCopy(node*& newRoot, node* currRoot){
    if(currRoot){
        newRoot = new node(*currRoot);
        deepCopy(newRoot->left, currRoot->left);
        deepCopy(newRoot->right, currRoot->right);
    }
    else{
        newRoot = nullptr;
    }
}

const bst& bst::operator= (const bst& aTree){
    if(this != &aTree){
        destroyTree(root);
        deepCopy(root, aTree.getRoot());
    }
    return *this;
}

//Entirely dependent on functional assignment overload:
bst::bst(const bst& aTree){
    *this = aTree;
}

//Wrapper for insertion:
void bst::add(int aNum, const char* aName){
    node* aNode = new node(aNum, aName);
    insert(root, aNode);
    std::cout << "Planting " << aName << " in box " << aNum << std::endl; 
}

//Recursive insert:
void bst::insert(node*& currRoot, node* newNode){
    if(!currRoot){
        currRoot = newNode;
    }
    else if(newNode->getId() <  currRoot->getId()){
        insert(currRoot->left, newNode);
    }
    else{
        insert(currRoot->right, newNode);
    }
}

//Wrapper for recursive harvest:
void bst::harvest(const char* aName, int aStart, int aStop){
    std::cout << "Harvesting " << aName << " from boxes " << aStart
              << " to " << aStop << ". The following boxes will be harvested: ";
    rHarvest(root, aName, aStart, aStop);
    std::cout << std::endl << std::endl;
}

//Inorder but with bounds-checking to determine direction:
void bst::rHarvest(node*& currRoot, const char* aName, int aStart, int aStop){
    if(currRoot){
        if(aStart < currRoot->getId()){
            rHarvest(currRoot->left, aName, aStart, aStop);
        }
        if(aStart <= currRoot->getId() && aStop >= currRoot->getId()){
            char* buffer = new char[currRoot->sizeFood() + 1];
            currRoot->getFood(buffer);
            if(!strcmp(buffer, aName)){
                std::cout << currRoot->getId() << " ";
            }
            delete [] buffer;
        }
        if(aStop >= currRoot->getId()){
            rHarvest(currRoot->right, aName, aStart, aStop);
        }
    }
}

//Delete individual node:
void bst::deleteNode(node*& nodeToDelete){
    node* tmp = nullptr;

    //Leaf:
    if(!nodeToDelete->left && !nodeToDelete->right){
        delete nodeToDelete;
        nodeToDelete = nullptr;
    }
    //Nothing at the left:
    else if(!nodeToDelete->left){
        tmp = nodeToDelete;
        nodeToDelete = nodeToDelete->right;
        tmp->right = nullptr;
        delete tmp;
    }
    //Nothing at the right:
    else if(!nodeToDelete->right){
        tmp = nodeToDelete;
        nodeToDelete = nodeToDelete->left;
        tmp->left = nullptr;
        delete tmp;
    }
    //Both children occupied:
    else{
        node* prev = nullptr;
        node* curr = nodeToDelete->right;
        while(curr->left){
            prev = curr;
            curr = curr->left;
        }
        
        //Copy data but not left/right:
        char* buffer = new char[curr->sizeFood() + 1];
        curr->getFood(buffer);
        nodeToDelete->setFood(buffer);
        delete [] buffer;
        nodeToDelete->setId(curr->getId());
        
        //Rethread everything and actually delete the node:
        if(!prev){
            nodeToDelete->right = curr->right;
        }
        else{
            prev->left = curr->right;
        }
        curr->right = nullptr;
        delete curr;
    }
}

//Recursive removal. Uses deleteNode() as helper:
int bst::remove(node*& currRoot, int aId){
    int ret = 0;
    if(currRoot){
        if(currRoot->getId() == aId){
            ret = currRoot->getId();
            deleteNode(currRoot);
        }
        else if(aId < currRoot->getId()){
            ret = remove(currRoot->left, aId);
        }
        else{
            ret = remove(currRoot->right, aId);
        }
    }
    return ret;
}

//Wrapper for removal helpers:
void bst::prune(int aNum){
    std::cout << "Pruning box number " << remove(root, aNum) << "." << std::endl;
}
