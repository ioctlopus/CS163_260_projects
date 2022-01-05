#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class person{
public:
    person();
    person(const char* id, const char* fname, const char* lname, const char* familyId);
    ~person();
    const person& operator= (const person& aPerson);
    person(const person& aPerson);
    friend std::ostream& operator<< (std::ostream& out, const person& aPerson);
    void getId(char* dest) const;
    void getFname(char* dest) const;
    void getLname(char* dest) const;
    void getFamilyId(char* dest) const;
    void setId(const char* aId);
    void setFname(const char* aFname);
    void setLname(const char* aLname);
    void setFamilyId(const char* aFamilyId);
    size_t sizeId() const;
    size_t sizeFname() const;
    size_t sizeLname() const;
    size_t sizeFamilyId() const;
private:
    char* id;
    char* fname;
    char* lname;
    char* familyId;
}; 

#endif
