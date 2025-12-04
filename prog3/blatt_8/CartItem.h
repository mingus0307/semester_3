#include <iostream>

class CartItem {
    private: 
        std::string name; 
        int anz; 
        float preisProEinheit; 
    public: 
        CartItem(const std::string& name, int anz, float preisProEinheit);
        float getCost(); 

        const std::string& getName(); 
        int getAnzahl();
        float getPreisProEinheit(); 

        void setName(const std::string& name); 
        void setAnzahl(int anz); 
        void setPreisProEinheit(float preis); 
}; 