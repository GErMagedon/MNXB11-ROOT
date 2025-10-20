#include "my_class.h"
ClassImp(my_class)

// default constructor
// initialize all members to null
my_class::my_class() : TObject(), px(0), py(0), pz(0)
{
}

// another constructor
my_class::my_class(Double_t px_, Double_t py_, Double_t pz_) : px(px_), py(py_), pz(pz_), TObject()
{
    void magnitude();
}

// destructor
my_class::~my_class(){
}

// function calculating module
void my_class::magnitude(){
    mp = std::sqrt(px * px + py * py + pz * pz);
}