#include <cstring>
#include <iostream>
#include <ostream>
#include <string.h>
#include "int20.h"
 

int20::int20(const char* a){
    // auffüllen mit nullen 
    int len_a = strlen(a); 
    for (int i = 0; i < 20; i++){
        zahl[i] = '0';  
    }

    // wir kopieren die Zahl ans Ende des Arrays
    for (int i = 0; i < len_a; i++){
        zahl[20 - len_a + i] = a[i];
    }
}
void int20::copy_from(const int20& b){
    std::memcpy(this->zahl, b.zahl, 20);
}
int20::int20(const int20& b){
     copy_from(b); 
}

int20& int20::operator=(const int20& b){
    if(this != &b){
        copy_from(b);  
    }
    return *this; 
}
unsigned char int20::get_digit(int pos) const {
    return zahl[19 - pos] - '0';
}

int20 int20::operator+(const int20& b){
    int20 result(*this);
    result += b; 
    return result;  
}

int20& int20::operator+=(const int20& b){
    unsigned char i; 
    unsigned char uebertrag= 0;

    for (i= 0; i<20; i++) {
        unsigned char sum= get_digit(i) + b.get_digit( i) + uebertrag;
        if (sum > 9) uebertrag= 1; else uebertrag= 0;
        this->zahl[19-i]= '0' + (sum % 10);
    }
    return *this; 
}

bool int20::operator<(const int20& b) const {

    for(int i = 0; i < 20; i++){
        if(this->zahl[i] == b.zahl[i]){
            continue;
        }
        if(this->zahl[i] < b.zahl[i]){
            return true; 
        }else{
            return false; 
        }
    }
    return false; 
}


void int20::print(std::ostream& os){
    bool lead = true; 
    for (int i = 0; i < 20; i++){
        if(this->zahl[i] == '0' && lead == true){
            continue;
        }
        lead = false; 
        os << this->zahl[i]; 
    }

    os << std::endl; 
}

int main() {

    std::cout << "=== Konstruktor-Test ===\n";
    int20 a("123");
    int20 b("999");
    int20 c("00000000000000000001");

    a.print(std::cout); std::cout << "  (erwartet: 000...123)\n";
    b.print(std::cout); std::cout << "  (erwartet: 000...999)\n";
    c.print(std::cout); std::cout << "  (erwartet: 000...001)\n\n";

    std::cout << "Copy-Konstruktor \n";
    int20 d(a);
    d.print(std::cout); std::cout << "  (Kopie von a)\n\n";

    std::cout << " Zuweisungsoperator\n";
    int20 e("0");
    e = b;
    e.print(std::cout); std::cout << "  (nach e = b)\n\n";

    std::cout << " operator+ \n";
    int20 sum1 = a + c;
    a.print(std::cout); std::cout << " + ";
    c.print(std::cout); std::cout << " = ";
    sum1.print(std::cout); std::cout << "  (erwartet: 124)\n\n";

    std::cout << " operator+= \n";
    int20 sum2("500");
    sum2 += a;
    sum2.print(std::cout); std::cout << "  (500 += 123 → 623)\n\n";

    std::cout << " Übertrag-Test \n";
    int20 big1("99999999999999999999");
    int20 big2("1");
    int20 bigSum = big1 + big2;
    bigSum.print(std::cout);
    std::cout << "  (Überlauf wird ignoriert)\n\n";

    std::cout << " Vergleich operator< \n";
    std::cout << "a < b ? " << (a < b) << "  (erwartet: 1)\n";
    std::cout << "b < a ? " << (b < a) << "  (erwartet: 0)\n";
    std::cout << "a < d ? " << (a < d) << "  (erwartet: 0, gleich)\n\n";

    std::cout << " get_digit-Test \n";
    std::cout << "Ziffern von a (123): ";
    for (int i = 0; i < 5; ++i) {
        std::cout << (int)a.get_digit(i) << " ";
    }
    std::cout << " (erwartet: 3 2 1 0 0)\n";

    return 0;
}





