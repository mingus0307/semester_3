#include "CartItem.h"

using namespace std; 

int CartItem::getAnzahl(){
    return anz; 
}

float CartItem::getPreisProEinheit(){
    return preisProEinheit; 
}

const string& CartItem::getName(){
    return name; 
}

void CartItem::setAnzahl(int anz){
    this->anz = anz; 
}

void CartItem::setPreisProEinheit(float preis){
    this->preisProEinheit = preis; 
}

void CartItem::setName(const string& name){
    this->name = name; 
}

CartItem::CartItem(const string& name, int anz, float preisProEinheit){
    this->name = name; 
    this->anz = anz; 
    this->preisProEinheit = preisProEinheit; 
}

float CartItem::getCost(){
    return anz * preisProEinheit; 
}

