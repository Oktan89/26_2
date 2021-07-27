#pragma once
#include <iostream>
#include <exception>

class Person{
    char* p_name;
    char* p_number;
public:
    Person(const char* name = "noname");
    ~Person();
    void print(){
        std::cout<<p_name<<std::endl;
    }
};