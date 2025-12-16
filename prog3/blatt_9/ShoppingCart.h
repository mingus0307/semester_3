#include <iostream>
#include <vector>
#include "CartItem.h"

class ShoppingCart {
    private :
        std::vector<CartItem> vec; 
    public:
        ShoppingCart(); 
        void add(CartItem& ci);
        float getTotalCost(); 
        int getNumberOfItems(); 
        CartItem& getItem(int i);  
        int* getItemIDs(); 
}; 