#include <iostream>
#include "ShoppingCart.h"

using namespace std; 


int main(void){
    CartItem a = CartItem("Hundefutter", 6, 3.0);
    CartItem b = CartItem("Kekse", 4, 1.59);
    CartItem c = CartItem("Milch", 1, 0.69);
    CartItem d = CartItem("Erdbeermarmelade", 3, 2.19);
    CartItem e = d; 

    ShoppingCart cart = ShoppingCart(); 
    cart.add(a); 
    cart.add(b); 
    cart.add(c); 
    cart.add(d); 
    cart.add(e); 

    int* arr = cart.getItemIDs(); 

    for(int i = 0; i < cart.getNumberOfItems(); i++){
        cout << "ID: " << arr[i] 
             << " Name: " << cart.getItem(i).getName() 
             << '\n' << '\n';   
    }
    delete[] arr; 

    cout << "Anzahl der Items im Einkaufswagen: "<< cart.getNumberOfItems() << '\n';

    cout << "\nItems im Einkaufswagen:\n";
    for (int i = 0; i < cart.getNumberOfItems(); ++i) {
        cout << " - " << cart.getItem(i).getName()
             << " (" << cart.getItem(i).getAnzahl()
             << " Stück: " << cart.getItem(i).getPreisProEinheit()
             << " €)" << '\n';
    }

    cout << "\nGesamtkosten: " << cart.getTotalCost() << " €" << '\n';

    

    return 0;

}

