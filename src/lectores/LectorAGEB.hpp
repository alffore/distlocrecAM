#ifndef LECTORAGEB_H
#define LECTORAGEB_H

#include "LectorINT.hpp"
#include "../objetos/Ageb.hpp"

class LectorAGEB: public LectorINT{

public:

    LectorAGEB(string& sarchivo, string sep, vector<Ageb>& vAgeb): LectorINT(sarchivo, sep), vAgeb(vAgeb){}
    
    void parser(string scad) override;


private:
    vector<Ageb>& vAgeb;

};


#endif