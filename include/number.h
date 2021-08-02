#pragma once
#include <iostream>
#include <utility>
#include <string>
#include <ostream>

class Number
{
    // Номер телефона
    std::string number;
    // Сотовый оператор
    std::string _operator;
    // Регион регистрации телефона
    std::string _region;
    /**
     * @brief Ищет название оператора по номеру
     * 
     * @return std::pair<bool, const char*> Возвращает false или true если оператор найден и соответсвенно описание ошибки или корректный номер телефона
     */
    std::pair<bool, const char*> findOperator();
    friend std::ostream& operator<< (std::ostream &out, const Number *number);

public:
    /**
     * @brief Set the Number object
     * 
     * @param number Строка с номером в формате +7(...) ... .. ..
     * @return std::pair<bool, const char*> true or false and code error or corectly number
     */
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