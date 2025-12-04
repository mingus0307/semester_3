#include "ShoppingCart.h"
#include <vector>

using namespace std; 

ShoppingCart::ShoppingCart(){
    vec = vector<CartItem>(); 
}

void ShoppingCart::add(CartItem& ci){
    vec.push_back(ci); 
}

float ShoppingCart::getTotalCost(){
    float fin = 0;
    for (CartItem& ci : vec){
        fin += ci.getCost(); 
    }
    return fin; 
}

int ShoppingCart::getNumberOfItems(){
    return vec.size(); 
}

CartItem& ShoppingCart::getItem(int anz){
    return vec.at(anz); 
}

