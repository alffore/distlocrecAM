#ifndef LECTORLOC_HPP
#define LECTORLOC_HPP

#include "LectorINT.hpp"
#include "../objetos/Localidad.hpp"
#include "../coordenadas/Convierte2Dto3D.hpp"


class LectorLoc: public LectorINT{

public:
    LectorLoc(string& sarchivo,string sep,vector<Localidad>& vLoc,Convierte2Dto3D &c2dto3d): LectorINT(sarchivo,sep),vLoc(vLoc),c2dto3d(c2dto3d){}

    void parser(string scad) override;

private:
    vector<Localidad>& vLoc;
    Convierte2Dto3D &c2dto3d;
};


#endif