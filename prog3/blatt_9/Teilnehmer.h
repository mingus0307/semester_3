class Teilnehmer{
    public: 
        int pos; 
    private: 
        void setPos(int p); 
        int getPos() const; 
        virtual void weiter() const;
}; 