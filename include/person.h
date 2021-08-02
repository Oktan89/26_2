#pragma once
#include <string>
#include <utility>
#include "number.h"

//class Number;

class Person
{
    std::string *p_name;
    Number* p_number;

public:
    Person() : p_name(nullptr), p_number(nullptr) {}
    Person(const std::string &name, const std::string &number);
    void setName(const std::string &name);
    std::pair<bool, const char*> setNumber(const std::string &number);
    std::pair<bool, const char*> getName();
    std::pair<bool, const char*> getNumber();
    Number* getNumberInfo();
    ~Person();
    void print();
};