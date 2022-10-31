#ifndef LECTORMNZ_HPP
#define LECTORMNZ_HPP

#include "LectorINT.hpp"
#include "../objetos/Manzana.hpp"
#include "../coordenadas/Convierte2Dto3D.hpp"
#include "../coordenadas/CCG2CCL.hpp"

class LectorMNZ: public LectorINT{

public:

    LectorMNZ(string& sarchivo, string sep, vector<Manzana>& vMnz,Convierte2Dto3D &c2dto3d,CCG2CCL &c2c): 
    LectorINT(sarchivo, sep), vMnz(vMnz),c2dto3d(c2dto3d),c2c(c2c){}
    
    void parser(string scad) override;


private:
    vector<Manzana>& vMnz;
    Convierte2Dto3D &c2dto3d;
    CCG2CCL &c2c;
};



#endif