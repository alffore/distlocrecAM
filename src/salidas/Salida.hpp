#ifndef SALIDA_HPP
#define SALIDA_HPP

#include "../principal/distlocrecam.hpp"
#include <iomanip>


class Salida{

public:

    void imprimeSalidaLoc(string sarchivo,vector<Localidad> &vLoc, vector<Recurso> &vRec);

    void imprimeSalidaLocMnz(string sarchivo,vector<Localidad> &vLoc, vector<Recurso> &vRec);
};


#endif