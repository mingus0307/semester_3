#include "Teilnehmer.h"

class Hase : public Teilnehmer {

    public:
        virtual void weiter() override; 
        virtual void print() override;  
        Hase() : Teilnehmer(){}; 
        
};