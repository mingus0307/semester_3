#ifndef PERSON_H
#define PERSON_H
#include "Ort.h"
class Person {
    private:  
        Ort* geburtsort; 
        Ort* wohnort;
        int alter; 
        std::string name;  

    public:
        Person(Ort* g, Ort* w, int a, std::string n) : geburtsort(g), wohnort(w), alter(a), name(n) {};
        Person(const Person& p) : geburtsort(new Ort(*p.geburtsort)), wohnort(new Ort(*p.wohnort)), alter(p.alter), name(p.name) {}; 
        virtual void setAlter(int n);
        virtual ~Person(){delete wohnort; delete geburtsort; }  
        virtual const std::string getName() const;

};
#endif