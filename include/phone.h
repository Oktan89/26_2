#pragma once
#include <map>

class Person;

class Phone
{
    std::map<std::string, Person*> addresBok;
    size_t maxName{10};
    void clear();
    void drawBook();
public:
    Phone();
    ~Phone();

    bool addPerson();

};