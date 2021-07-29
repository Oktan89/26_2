#include <string>
#include <exception>
#include <iostream>
#include "person.h"

Person::Person(const std::string &name, const std::string &number)
{
    try
    {
        this->name = new std::string(name);
    }
    catch (std::exception &exception)
    {
        std::cout << "Person::name : " << exception.what() << std::endl;
    }

    try
    {
        this->number = new std::string(number);
    }
    catch (std::exception &exception)
    {
        std::cout << "Person::nomber : " << exception.what() << std::endl;
    }
}

Person::~Person()
{
    delete name;
    delete number;
}

void Person::print()
{
    std::cout << ((name) ? name->c_str() : "No name") << " ";
    std::cout << ((number) ? number->c_str() : "+7(___) ___ __ __") << std::endl;
}