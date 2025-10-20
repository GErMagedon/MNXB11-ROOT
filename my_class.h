#ifndef __MY_CLASS_H__
#define __MY_CLASS_H__
#include <TObject.h>
#include <iostream>
#include <cmath>

class my_class : public TObject {
    public:
    my_class(); // default constructor
    my_class(Double_t px, Double_t py, Double_t pz); // some other constructor
    virtual ~my_class(); // destructor
    void magnitude();
    Double_t getPx() const {return px;} 
    Double_t getPy() const {return py;}
    Double_t getPz() const {return pz;}

    private:
    // some private members
    ClassDef(my_class, 1); // my_class
    Double_t px;
    Double_t py;
    Double_t pz;
    Double_t mp; // magnitude of p
};

#endif // __MY_CLASS_H__