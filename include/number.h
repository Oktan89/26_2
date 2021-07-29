#pragma once
#include <iostream>
#include <string>

class Number
{

    std::string number;
    std::string _operator;
    std::string _region;
    void findOperator();

public:
    bool setNumber(const std::string &number);
    void print()
    {
        std::cout<<number<<std::endl;
        std::cout<<_operator<<std::endl;
        std::cout<<_region<<std::endl;
    }
};