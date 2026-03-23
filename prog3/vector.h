const int N =  5;
class Vektor {
    private:
        double* elems;
    public:

    Vektor() {
        elems = new double[N];
    }
    ~Vektor() {
        delete[] elems;
    }

    Vektor& operator = (const Vektor& v){
        if (this == &v){
            return *this; 
        }

        delete [] elems; 
        elems = new double[N]; 

        for (int i = 0; i < N; i++){
            elems[i] = v.elems[i]; 
        }

        return *this; 
    }

    Vektor(const Vektor& v){
        elems = nullptr; 

        *this = v; 
    }

    Vektor& operator += (const Vektor& v){
        for (int i = 0; i < N; i++){
            elems[i] += v.elems[i]; 
        }
        return *this; 
    }

    Vektor operator + (const Vektor& v) const {
        Vektor fin {*this}; 

        fin += v; 
        return fin; 
    }

    bool operator == (const Vektor& v) const {
        bool isSame = true; 

        for (int i = 0; i < N; i++){
            if (elems[i] != v.elems[i]){
                return false; 
            }
        }
        return isSame; 
    }
};