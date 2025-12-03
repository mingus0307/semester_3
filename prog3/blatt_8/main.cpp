#include "Person.h"

int main(void){
    Person arr[] = {
        Person("Daniel", 1998), 
        Person("Max", 1997)
    }; 

    for (Person& p : arr){
        p.print(); 
    }
}