#include <iostream>
#include "phone.h"


int main(){
    
   Phone test;

   test.addPerson();
   test.callPerson("Ruslan");
   test.sendMessage("Ruslan", "Privet kak dela!!! ^)))");
   return 0;
}