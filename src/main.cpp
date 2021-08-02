#include <iostream>
#include "person.h"
#include "number.h"

int main(){
    
   Number number;
   auto it = number.setNumber("9028270125");
   if(it.first != true)
   {
      std::cout<<it.second<<std::endl;
      std::cout<<number.getOperator()<<std::endl;
      std::cout<<number.getRegion()<<std::endl;
   }
   else
   {
      std::cout<<it.second<<std::endl;
      std::cout<<number.getOperator()<<std::endl;
      std::cout<<number.getRegion()<<std::endl;
   } 
   
   return 0;
}