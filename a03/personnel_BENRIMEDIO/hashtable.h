#ifndef HASH_H
#define HASH_H

#include "person.h"

#define HASH_START_MAGIC 4211

const size_t DEFAULT_CAP = 9973; 

struct Node{
    person personData;
    Node* next;
};

class HashTable{
public:
    HashTable();
    ~HashTable();
    const HashTable& operator= (const HashTable& aHt);
    HashTable(const HashTable& aHt);
    void nullInit();
    bool isEmpty() const;
    void statReport() const;
    size_t getCapacity() const;
    size_t getSize() const;
    Node** getData() const;
    void deleteData();
    person* findById(const char* idToFind);
    void addPerson(const person& aPerson);
    size_t generateKey(const char* aId) const;
private:
    size_t size;
    size_t capacity;
    Node** data;
};

#endif
