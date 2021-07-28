#include <string>
#include <exception>
#include <iostream>
#include "person.h"

Person::Person(const std::string &name, const std::string &number){
    try{
        p_name = new std::string(name);
    }catch(std::exception &exception){
        std::cout<<"Person::name : "<<exception.what()<<std::endl;
    }
    
    try{
        p_number = new std::string(number);
    }catch(std::exception &exception){
        std::cout<<"Person::nomber : "<<exception.what()<<std::endl;
    }
    
}

Person::~Person(){
    delete p_name;
    delete p_number;
}

void Person::print(){
    std::cout<< ((p_name)? p_name->c_str() : "No name")<<" ";
    std::cout<< ((p_number)? p_number->c_str() : "+7(___) ___ __ __")<<std::endl;
}