#include <cstring>
#include "hashtable.h"

HashTable::HashTable(){
    size = 0;
    capacity = DEFAULT_CAP;
    data = new Node*[capacity];
    nullInit();
}

HashTable::~HashTable(){
    deleteData();
}

void HashTable::nullInit(){
    for(size_t i = 0; i < capacity; i++)
        data[i] = nullptr;
}

bool HashTable::isEmpty() const{
    bool found = false;
    for(size_t i = 0; i < capacity && !found; i++){
        if(data[i])
            found = true;
    }
    return found;
}

void HashTable::statReport() const{
    unsigned int numEntries = 0;
    for(size_t i = 0; i < capacity; i++){
        if(data[i])
            numEntries++;
    }
    std::cout << "Table uses " << numEntries << " out of " << capacity << " entries." << std::endl;
}

//Deep copy:
const HashTable& HashTable::operator= (const HashTable& aHt){
    if(this != &aHt){
        //Destroy current data and prepare table for copy:
        deleteData();
        data = new Node*[capacity];
        capacity = aHt.getCapacity();
        size = aHt.getSize();
        Node** pData = aHt.getData();
        
        //Iterate through data for copy:
        for(size_t i = 0; i < capacity; i++){
            if(!pData[i]){
                data[i] = nullptr;
            }
            else{
                //First part of chain:
                data[i] = new Node;
                data[i]->personData = pData[i]->personData;
                
                //Rest of chain:
                Node* nodeFrom = pData[i]->next;
                Node* nodeTo = data[i];
                while(nodeFrom){
                    nodeTo->next = new Node;
                    nodeTo->next->personData = nodeFrom->personData;
                    nodeTo = nodeTo->next;
                    nodeFrom = nodeFrom->next;
                }
                nodeTo->next = nullptr;
            }
        }

    }
    return *this;
}

//Deep copy:
HashTable::HashTable(const HashTable& aHt){
    //Create new table and iterate through array for copy:
    data = new Node*[capacity];
    Node** pData = aHt.getData();
    for(size_t i = 0; i < capacity; i++){
        if(!pData[i]){
            data[i] = nullptr;
        }
        else{
            //First part of chain:
            data[i] = new Node;
            data[i]->personData = pData[i]->personData;

            //Rest of chain:
            Node* nodeFrom = pData[i]->next;
            Node* nodeTo = data[i];
            while(nodeFrom){
                nodeTo->next = new Node;
                nodeTo->next->personData = nodeFrom->personData;
                nodeTo = nodeTo->next;
                nodeFrom = nodeFrom->next;
            }
            nodeTo->next = nullptr;
        }
    }
}

//Accessors:
size_t HashTable::getCapacity() const{
    return capacity;
}

size_t HashTable::getSize() const{
    return size;
}

Node** HashTable::getData() const{
    return data;
}

//Helper to avoid rewriting code:
void HashTable::deleteData(){
    for(size_t i = 0; i < capacity; i++){
        Node* curr = data[i];
        Node* tmp = nullptr;
        while(curr){
            tmp = curr->next;
            curr->next = nullptr;
            delete curr;
            curr = tmp;
        }
    }
    delete [] data;
}

void HashTable::addPerson(const person& aPerson){
    char* buffer = new char[aPerson.sizeId() + 1];
    aPerson.getId(buffer);
    size_t index = generateKey(buffer);
    Node* newNode = new Node;
    newNode->personData = aPerson;
    newNode->next = data[index];
    data[index] = newNode;
    size++;
    delete [] buffer;
}

person* HashTable::findById(const char* idToFind){
    char* buffer;
    person* ret = nullptr;
    size_t index = generateKey(idToFind);
    Node* curr = data[index];
    while(curr){
        buffer = new char[curr->personData.sizeId() + 1];
        curr->personData.getId(buffer);
        if(!strcmp(idToFind, buffer)){
            ret = &(curr->personData);
            curr = nullptr;
        }
        else{
            curr = curr->next;
        }
        delete [] buffer;
    }
    return ret;
}

//Surprisingly efficient considering I was just messing with bitwise operators to improve speed:
size_t HashTable::generateKey(const char* aId) const{
    char ch;
    size_t ret = HASH_START_MAGIC;
    while(*aId){
        ch = *aId;
        ret = (ret << 3) + ret + static_cast<int>(ch);
        aId++;
    }
    ret = ret % capacity;
    return ret;
}
