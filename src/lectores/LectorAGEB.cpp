#include "LectorAGEB.hpp"

void LectorAGEB::parser(string scad) {
    vector<string> vc;

    split(vc, scad, sep);

    Ageb age;

    int npuntos= atoi(vc[1].c_str());

    vector<Punto> vpuntos;

    creaPoligono(vc[2].c_str(), vpuntos);

    double cx=0;
    double cy=0;
    
    for(Punto &p: vpuntos){
        cx+=p.x;
        cy+=p.y;
    }

    age.x=cx/vpuntos.size();
    age.y=cy/vpuntos.size();

    age.estado_id = atoi(vc[4].c_str());
    age.municipio_id = atoi(vc[5].c_str());
    age.localidad_id = atoi(vc[6].c_str());

    vAgeb.push_back(age);
}