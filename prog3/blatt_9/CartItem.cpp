#include "CartItem.h"

using namespace std; 

int CartItem::last_id = 0; 

int CartItem::getnNextID(){
    last_id++; 
    return last_id; 
}

int CartItem::getID()const{
    return id; 
}

int CartItem::getAnzahl() const {
    return anz; 
}

float CartItem::getPreisProEinheit() const{
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

CartItem::CartItem(const string& name, int anz, float preisProEinheit)
    : id {getnNextID()} {
    
    this->name = name; 
    this->anz = anz; 
    this->preisProEinheit = preisProEinheit; 
}

CartItem::CartItem(const CartItem& c)
    : id {getnNextID()}{
    
    this->name = c.name; 
    this->anz = c.anz; 
    this->preisProEinheit = c.preisProEinheit; 

}

CartItem& CartItem::operator=(const CartItem& c){   
    if(this != &c){
        name = c.name; 
        anz = c.anz; 
        preisProEinheit = c.preisProEinheit; 
    }
    return *this; 

}

float CartItem::getCost() const {
    return anz * preisProEinheit; 
}

