#include <iostream> 

class Person{
    private: 
        std::string name; 
        int year; 
    public: 
        Person();
        Person(const std::string name, int year); 
        void print(); 
};