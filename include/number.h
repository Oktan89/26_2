#pragma once
#include <iostream>
#include <string>

class Number
{

    std::string number;

public:
    bool setNumber(const std::string &number);
    void print()
    {
        std::cout<<number<<std::endl;
    }
};