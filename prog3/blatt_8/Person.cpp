#include <iostream>
#include "Person.h"

using namespace std;
 

Person::Person(const string name, int year){
    this->name = name; 
    this->year = year; 
} 

Person::Person(){
    name = ""; 
    year = 0; 
}

void Person::print(){
    cout<< this->name << " ist " << this->year << " geboren " << '\n'; 
}