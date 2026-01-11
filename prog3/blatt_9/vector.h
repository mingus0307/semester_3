const int N = 0;

class Vector {
    private:
        double* elems;
    public:
        Vector() {elems = new double[N];}
        Vector(const Vector& v); 

        ~Vector() {delete[] elems;}
        Vector& operator=(const Vector& v); 
        Vector operator+(const Vector& a); 
        Vector& operator+=(const Vector& v) ;
        bool operator==(const Vector& v); 

};