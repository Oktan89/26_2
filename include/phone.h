#pragma once
#include <map>

class Person;

class Phone
{
    std::map<std::string, Person*> addresBok;
    std::map<std::string, Person*> p_addresBok;
    size_t maxName{10};
    void clear();
    void drawBook();
public:
    Phone();
    ~Phone();

    bool addPerson();
    

};