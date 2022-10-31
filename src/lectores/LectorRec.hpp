#ifndef LECTORREC_H
#define LECTORREC_H

#include "LectorINT.hpp"
#include "../objetos/Recurso.hpp"
#include "../coordenadas/Convierte2Dto3D.hpp"


class LectorRec: public LectorINT{

public:
    LectorRec(string& sarchivo,string sep,vector<Recurso>& vRec,Convierte2Dto3D &c2dto3d): LectorINT(sarchivo,sep),vRec(vRec),c2dto3d(c2dto3d){}

    void parser(string scad) override;

private:
    vector<Recurso>& vRec;
    Convierte2Dto3D &c2dto3d;
};


#endif