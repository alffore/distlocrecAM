//
// Created by alfonso on 6/13/22.
//

#include "LectorMNZ.hpp"

/**
 *
 * @param scad
 */

void LectorMNZ::parser(string scad) {
    vector<string> vc;

    split(vc, scad, sep);

    Manzana mnz;

    
    vector<Punto> vpuntos;

    creaPoligono(vc[2].c_str(), vpuntos);

    float cx=0;
    float cy=0;
    
    for(Punto &p: vpuntos){
        cx+=p.x;
        cy+=p.y;
    }

    mnz.x=cx/vpuntos.size();
    mnz.y=cy/vpuntos.size();

    c2c.invierte(mnz.lon,mnz.lat,mnz.x,mnz.y);
    c2dto3d.lonlat2xyz(mnz.lon,mnz.lat,mnz.x,mnz.y,mnz.z);
    
    mnz.estado_id = atoi(vc[4].c_str());
    mnz.municipio_id = atoi(vc[5].c_str());
    mnz.localidad_id = atoi(vc[6].c_str());

    mnz.mid = vc[3];
    mnz.sestado_id = vc[4];
    mnz.smunicipio_id = vc[5];
    mnz.slocalidad_id = vc[6];
    mnz.sageb_id = vc[7];
    mnz.smanzana_id = vc[8];

    vMnz.push_back(mnz);
}
