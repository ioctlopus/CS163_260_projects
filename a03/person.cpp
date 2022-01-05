#include <cstring>
#include "person.h"

person::person(){
    id = nullptr;
    fname = nullptr;
    lname = nullptr;
    familyId = nullptr;
}

person::person(const char* aId, const char* aFname, const char* aLname, const char* aFamilyId){
    id = new char[strlen(aId) + 1];
    fname = new char[strlen(aFname) + 1];
    lname = new char[strlen(aLname) + 1];
    familyId = new char[strlen(aFamilyId) + 1];
    strcpy(id, aId);
    strcpy(fname, aFname);
    strcpy(lname, aLname);
    strcpy(familyId, aFamilyId);
}

person::~person(){
    if(id)
        delete [] id;
    if(fname)
        delete [] fname;
    if(lname)
        delete [] lname;
    if(familyId)
        delete [] familyId;
}

const person& person::operator= (const person& aPerson){
    char* buffer;
    if(this != &aPerson){
        if(id)
            delete [] id;
        if(fname)
            delete [] fname;
        if(lname)
            delete [] fname;
        if(familyId)
            delete [] familyId;
        buffer = new char[aPerson.sizeId() + 1];
        aPerson.getId(buffer);
        setId(buffer);
        delete [] buffer;
        buffer = new char[aPerson.sizeFname() + 1];
        aPerson.getFname(buffer);
        setFname(buffer);
        delete [] buffer;
        buffer = new char[aPerson.sizeLname() + 1];
        aPerson.getLname(buffer);
        setLname(buffer);
        delete [] buffer;
        buffer = new char[aPerson.sizeFamilyId() + 1];
        aPerson.getFamilyId(buffer);
        setFamilyId(buffer);
        delete [] buffer;
    }
    return *this;
}

person::person(const person& aPerson){
    char* buffer;
    buffer = new char[aPerson.sizeId() + 1];
    aPerson.getId(buffer);
    setId(buffer);
    delete [] buffer;
    buffer = new char[aPerson.sizeFname() + 1];
    aPerson.getFname(buffer);
    setFname(buffer);
    delete [] buffer;
    buffer = new char[aPerson.sizeLname() + 1];
    aPerson.getLname(buffer);
    setLname(buffer);
    delete [] buffer;
    buffer = new char[aPerson.sizeFamilyId() + 1];
    aPerson.getFamilyId(buffer);
    setFamilyId(buffer);
    delete [] buffer;
}

std::ostream& operator<< (std::ostream& out, const person& aPerson){
    char* buffer = new char[aPerson.sizeId()+ 1];
    aPerson.getId(buffer);
    out << "ID: " << buffer << "\n";
    delete [] buffer;
    buffer = new char[aPerson.sizeFname() + 1];
    aPerson.getFname(buffer);
    out << "First Name: " << buffer << "\n";
    delete [] buffer;
    buffer = new char[aPerson.sizeLname() + 1];
    aPerson.getLname(buffer);
    out << "Last Name: " << buffer
        << std::endl;
    delete [] buffer;
    return out;
}

void person::getId(char* dest) const{
    if(id){
        strcpy(dest, id);
    }
    else{
        strcpy(dest, "\0");
    }
}

void person::getFname(char* dest) const{
    if(fname){
        strcpy(dest, fname);
    }
    else{
        strcpy(dest, "\0");
    }
}

void person::getLname(char* dest) const{
    if(lname){
        strcpy(dest, lname);
    }
    else{
        strcpy(dest, "\0");
    }
}

void person::getFamilyId(char* dest) const{
    if(familyId){
        strcpy(dest, familyId);
    }
    else{
        strcpy(dest, "\0");
    }
}

void person::setId(const char* aId){
    if(id)
        delete [] id;
    id = new char[strlen(aId) + 1];
    strcpy(id, aId);
}

void person::setFname(const char* aFname){
    if(fname)
        delete [] fname;
    fname = new char[strlen(aFname) + 1];
    strcpy(fname, aFname);
}

void person::setLname(const char* aLname){
    if(lname)
        delete [] lname;
    lname = new char[strlen(aLname) + 1];
    strcpy(lname, aLname);
}

void person::setFamilyId(const char* aFamilyId){
    if(familyId)
        delete [] familyId;
    familyId = new char[strlen(aFamilyId) + 1];
    strcpy(familyId, aFamilyId);
}

size_t person::sizeId() const{
    return strlen(id);
}

size_t person::sizeFname() const{
    return strlen(fname);
}

size_t person::sizeLname() const{
    return strlen(lname);
}

size_t person::sizeFamilyId() const{
    return strlen(familyId);
}
