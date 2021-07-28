#include <iostream>
#include "person.h"
int main(){
    
   Person person("Ruslan", "+79028270125");
   Person o;
   person.print();
   o.print();
   return 0;
}