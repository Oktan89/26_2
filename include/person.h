#pragma once
#include <string>



class Person{
    std::string* name;
    std::string* number;
public:
    Person(): name(nullptr), number(nullptr) {}
    Person(const std::string &name, const std::string &number);
    ~Person(); 
    void print();
};