#include "vector.h"
#include <iostream>

Vector& Vector::operator = (const Vector& v){
    if (this == &v){
        return *this; 
    }
    delete [] elems; 

    for (int i = 0; i < N; i++){
        elems[i] = v.elems[i]; 
    }

    return *this;
}

Vector::Vector(const Vector& v){
    elems = nullptr; 
    *this = v; 
}

Vector Vector::operator+(const Vector& b){
    Vector fin {*this}; 
     
    for (int i = 0; i < N; i++){
        fin.elems[i] = this->elems[i] + b.elems[i]; 
    }

    return fin; 
}

Vector& Vector::operator+=(const Vector& v){
    for (int i = 0; i < N; i++){
        this->elems[i] += v.elems[i]; 
    }

    return *this; 
}

bool Vector::operator==(const Vector& v){

    for (int i; i < N; i++){
        if(this->elems[i] != v.elems[i]){
            return false; 
        }
    }

    return true; 

}