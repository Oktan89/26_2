#include "person.h"

Person::Person(const char* name){

    int  s_name = 0;
    p_name = nullptr;
    p_number = nullptr;
    
        while(name[s_name] != '\0'){
            ++s_name;
        }
        ++s_name;
    
        try{
            //throw std::runtime_error("bad alloc");
            p_name = new char[s_name];
        }catch(std::exception &exception){
            std::cout<<"Error "<<exception.what()<<std::endl;
        }
    
        if(p_name){
            for(int i = 0; i < s_name; ++i){
                p_name[i] = name[i];
            }
        }      
        
}

Person::~Person(){
    delete p_name;
    delete p_number;
}