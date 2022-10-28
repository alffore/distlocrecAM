#ifndef LECTORINT_HPP
#define LECTORINT_HPP


#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

#include "../objetos/Punto.hpp"

using namespace std;

using std::ifstream;


class LectorINT{

public:

    LectorINT(string &sarchivo, string sep) : sarchivo(sarchivo), sep(sep) {}

    static void split(vector <string> &theStringVector,
                      const string &theString, const string &theDelimiter);

    void inicia();

    virtual void parser(string scad);

protected:

    string sep;

    void creaPoligono(string scad, vector<Punto>& vpuntos);

private:

    string &sarchivo;


};


#endif
