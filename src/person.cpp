#include <string>
#include <exception>
#include <iostream>
#include "person.h"
#include "number.h"

Person::Person(const std::string &name, const std::string &number)
{
    try
    {
        this->p_name = new std::string(name);
    }
    catch (std::exception &exception)
    {
        std::cout << "Person::name : " << exception.what() << std::endl;
    }

    try
    {
        this->p_number = new Number;
        if(number.size() != 0)
        {
            auto ret = p_number->setNumber(number);
            if(!ret.first)
            {
                std::cout<<ret.second<<std::endl; 
            }
        }
        
    }
    catch (std::exception &exception)
    {
        std::cout << "Person::nomber : " << exception.what() << std::endl;
    }
}

Person::~Person()
{
    delete p_name;
    delete p_number;
}

void Person::print()
{
    std::cout << ((p_name) ? p_name->c_str() : "No name") << " ";
    std::cout << ((p_number) ? p_number->getNumber() : "+7(___) ___ __ __") << std::endl;
}

std::pair<bool, const char*> Person::setNumber(const std::string &number)
{
    return p_number->setNumber(number);
}

void Person::setName(const std::string &name)
{
    p_name->replace(0, name.size(), name);
}

const char* Person::getName()
{
    
        return p_name->c_str(); 
       
}

const char* Person::getNumber()
{

    return p_number->getNumber();
        
}
 
Number* Person::getNumberInfo()
{
    return p_number;
}