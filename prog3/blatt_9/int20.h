#include <iostream> 
#include <ostream>

class int20 {
    private: 
        char zahl[20];
        void copy_from(const int20& b); 
        
    public: 
        int20(const char* a); 
        int20(const int20& i);
        int20& operator=(const int20& b); 
        int20 operator+(const int20& b);
        int20& operator+=(const int20& b);  
        bool operator < (const int20& b) const; 
        
        void print(std::ostream& os) const; 
        unsigned char get_digit(int pos) const; 

};

std::ostream& operator<<(std::ostream& os, const int20& a);  