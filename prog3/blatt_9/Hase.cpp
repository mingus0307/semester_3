#include <iostream>
#include "Hase.h"
#include <random>

void Hase::weiter() {
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_real_distribution<>dist(-10, 10); 
    int val = dist(gen);

    this->pos += val; 
    if (this->pos > 99){this->pos = 99;}
}

void Hase::print(){
    for(int i = 0; i < 100; i++){
        if(pos == i){
            std::cout << "H"; 
        }else{
            std::cout << "-"; 
        }
    }
    std::cout<< std::endl; 
}