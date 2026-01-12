#include <iostream>
#include "Hase.h"
#include "Igel.h"



using namespace std;

int main(void){

    Hase H; 
    Hase H2; 
    Igel I; 

    Teilnehmer* t[3]; 
    t[0] = &H; 
    t[1] = &I; 
    t[2] = &H2; 


    cout << "Start:" << endl;
    int highest {0}; 
    
    while(highest < 99){
        for(int i = 0; i < 3; i++){
            t[i]->weiter(); 
            t[i]->print(); 
            if(t[i]->pos > highest){highest = t[i]->pos;}
        }
        cout << endl; 
    }


    cout << "Ende" << endl; 
    return 0; 
}