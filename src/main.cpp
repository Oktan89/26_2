#include <iostream>
#include "person.h"
#include "number.h"

int main(){
    
   Number number;
   std::cout<<number.setNumber("17")<<std::endl;
   number.print();
   return 0;
}