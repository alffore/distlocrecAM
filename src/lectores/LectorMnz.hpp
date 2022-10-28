#ifndef LECTORMNZ_H
#define LECTORMNZ_H

#include "LectorINT.hpp"
#include "../objetos/Manzana.hpp"

class LectorMnz: public LectorINT{

public:

    LectorMnz(string& sarchivo, string sep, vector<Manzana>& vMnz): LectorINT(sarchivo, sep), vMnz(vMnz){}
    
    void parser(string scad) override;


private:
    vector<Manzana>& vMnz;

};



#endif