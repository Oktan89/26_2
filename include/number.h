#pragma once
#include <iostream>
#include <utility>
#include <string>

class Number
{

    std::string number;
    std::string _operator;
    std::string _region;
    /**
     * @brief Ищет название оператора по номеру
     * 
     * @return std::pair<bool, const char*> Возвращает false или true если оператор найден и соответсвенно описание ошибки или корректный номер телефона
     */
    std::pair<bool, const char*> findOperator();

public:
    std::pair<bool, const char*> setNumber(const std::string &number);
    const char* getNumber();
    const char* getOperator();
    const char* getRegion();
    void print()
    {
        std::cout<<number<<std::endl;
        std::cout<<_operator<<std::endl;
        std::cout<<_region<<std::endl;
    }
};