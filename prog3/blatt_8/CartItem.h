#include <iostream>

class CartItem {
    private: 
        std::string name; 
        int anz; 
        float preisProEinheit; 
        static int last_id; 
        int id;
        static int getnNextID(); 
    public: 
        CartItem(const std::string& name, int anz, float preisProEinheit);
        float getCost(); 

        const std::string& getName(); 
        int getAnzahl();
        float getPreisProEinheit(); 
        int getID(); 

        void setName(const std::string& name); 
        void setAnzahl(int anz); 
        void setPreisProEinheit(float preis); 
}; 