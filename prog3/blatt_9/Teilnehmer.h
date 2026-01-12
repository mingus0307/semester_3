#ifndef Teilnehmer_H

#define Teilnehmer_H

class Teilnehmer{
    public: 
        int pos;  
        Teilnehmer(int pos);
        Teilnehmer() { pos = 0;}; 
        void setPos(int p); 
        int getPos() const; 
        virtual void weiter() = 0;
        virtual void print() = 0; 
}; 

#endif