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

int* ShoppingCart::getItemIDs(){
    int* ids = new int[this->getNumberOfItems()](); 

    for (int i = 0; i < this->getNumberOfItems(); i++){
        ids[i] = vec.at(i).getID(); 
    }
    return ids; 
}

