#include <iostream>
#include "person.h"
#include "number.h"

int main(){
    
   Number number;
   std::cout<<number.setNumber("9180060444")<<std::endl;
   number.print();
   return 0;
}