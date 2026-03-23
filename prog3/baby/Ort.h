#ifndef ORT_H
#define ORT_H
#include <cstddef>
#include <string>
class Ort{
    public:
        std::string* stadt; 
        int einwohner; 
        int wohnjahre; 
        Ort(std::string* s, int e, int w) : stadt(s), einwohner(e), wohnjahre(w) {}; 
        Ort(const Ort& o){
            stadt = nullptr; 
            stadt = new std::string(*o.stadt); 
            einwohner = o.einwohner; 
            wohnjahre = o.wohnjahre; 
        };

        Ort& operator = (const Ort& o){
            if (this == &o){return *this;}

            delete stadt; 
            this->stadt = new std::string(*o.stadt); 
            this->einwohner = o.einwohner; 
            this->wohnjahre = o.wohnjahre; 
            return *this; 
        }; 

        bool operator == (const Ort& o) const {
            if (this == &o){return true;}

            if (einwohner == o.einwohner && wohnjahre == o.wohnjahre && *stadt == *o.stadt){
                return true; 
            }
            return false; 
        };
};
#endif
