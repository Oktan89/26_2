#pragma once
#include <string>



class Person{
    std::string* p_name;
    std::string* p_number;
public:
    Person(): p_name(nullptr), p_number(nullptr) {}
    Person(const std::string &name, const std::string &number);
    ~Person(); 
    void print();
};