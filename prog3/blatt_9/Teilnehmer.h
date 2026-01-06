class Teilnehmer{
    public: 
        int pos;  
        Teilnehmer(int pos);
        void setPos(int p); 
        int getPos() const; 
        virtual void weiter();
}; 