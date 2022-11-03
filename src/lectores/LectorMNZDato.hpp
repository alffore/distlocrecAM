#ifndef LECTORMNZDATO_HPP
#define LECTORMNZDATO_HPP

#include "LectorINT.hpp"
#include "../objetos/Manzana.hpp"

class LectorMNZDato: public LectorINT{

public:

    LectorMNZDato(string& sarchivo, string sep, vector<Manzana>& vMnz): LectorINT(sarchivo, sep), vMnz(vMnz){}
    
    void parser(string scad) override;

private:
    vector<Manzana>& vMnz;
    
};



#endif