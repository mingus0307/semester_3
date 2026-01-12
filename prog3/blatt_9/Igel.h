#include "Teilnehmer.h"

class Igel : public Teilnehmer {


    public:
        virtual void weiter() override; 
        virtual void print() override;
        Igel() : Teilnehmer(){} 
};