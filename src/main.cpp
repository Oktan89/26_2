#include <iostream>
#include "phone.h"


int main(){
    
    Phone runPhone;
    std::string command;
    do{
        std::cout<<"Enter command :";
        std::getline(std::cin, command);

        if (command == "add")
        {
            runPhone.addPerson();
        }
        else if (command == "call")
        {
            std::cout<<"Enter name or number contact: ";
            std::getline(std::cin, command);
            runPhone.callPerson(command);
        }
        else if(command == "sms")
        {
            std::cout<<"Enter name or number contact: ";
            std::getline(std::cin, command);
            std::string sms;
            std::cout<<"Enter sms message: ";
            std::getline(std::cin, sms);
            runPhone.sendMessage(command, sms);
        }
        else
        {
            std::cout<<"Please enter the command [add], [call], [sms], [exit]"<<std::endl;
        }
        

    }while(command != "exit");
    std::cout<<"Phone power off"<<std::endl;
   return 0;
}