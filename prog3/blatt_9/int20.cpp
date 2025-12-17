#include <cstring>
#include <iostream>
#include <string.h>
#include "int20.h"
 

int20::int20(const char* a){
    // auffüllen mit nullen 
    int len_a = strlen(a); 
    for (int i = 0; i < 20; i++){
        zahl[i] = '0';  
    }

    // wir kopieren die Zahl ans Ende des Arrays
    for (int i = 0; i < len_a; i++){
        zahl[20 - len_a + i] = a[i];
    }
}
void int20::copy_from(const int20& b){
    std::memcpy(this->zahl, b.zahl, 20);
}
int20::int20(const int20& b){
     copy_from(b); 
}

int20& int20::operator=(const int20& b){
    if(this != &b){
        copy_from(b);  
    }
    return *this; 
}
unsigned char int20::get_digit(int pos) const {
    return zahl[19 - pos] - '0';
}

int20 int20::operator+(const int20& b){
    int20 result(*this);
    result += b; 
    return result;  
}

int20& int20::operator+=(const int20& b){
    unsigned char i; 
    unsigned char uebertrag= 0;

    for (i= 0; i<20; i++) {
        unsigned char sum= get_digit(i) + b.get_digit( i) + uebertrag;
        if (sum > 9) uebertrag= 1; else uebertrag= 0;
        this->zahl[19-i]= '0' + (sum % 10);
    }
    return *this; 
}

bool int20::operator<(const int20& b){
    //return true wenn this an einer stelle von links nach rechts größer ist
    // andernfalls false
    //erste Stelle an der der Unterschied passiert ist entscheidend 
}






