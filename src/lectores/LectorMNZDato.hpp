#ifndef LECTORMNZDATO_HPP
#define LECTORMNZDATO_HPP

#include "LectorINT.hpp"
#include "../objetos/ManzanaDato.hpp"

class LectorMNZDato: public LectorINT{

public:

    LectorMNZDato(string& sarchivo, string sep, vector<ManzanaDato>& vMnzD): LectorINT(sarchivo, sep), vMnzD(vMnzD){}
    
    void parser(string scad) override;

private:
    vector<ManzanaDato>& vMnzD;
    
};



#endif