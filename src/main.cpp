#include <iostream>
#include "person.h"
int main(){
    
   Person person("Ruslan", "+7 902 827 01 25");
   Person o;
   person.print();
   o.print();
   return 0;
}