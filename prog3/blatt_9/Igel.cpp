#include <iostream>
#include "Igel.h"

void Igel::weiter() {
    this->pos += 1; 
}

void Igel::print(){
    for(int i = 0; i < 100; i++){
        if(pos == i){
            std::cout << "I"; 
        }else{
            std::cout << "-"; 
        }
    }
    std::cout<< std::endl; 
}