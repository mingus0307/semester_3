#ifndef BABY_H
#define BABY_H
#include "Person.h"
class Baby : public Person {
    private: 

    public: 
        Baby(const Baby& b);
        Baby(Ort* geb, Ort* wohn, std::string name);
        virtual void setAlter(int a) override {if (a > 0) { throw std::exception();}}; 
}; 
#endif 