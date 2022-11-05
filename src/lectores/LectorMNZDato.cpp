#include "LectorMNZDato.hpp"

/**
 * @brief 
 * 
 * @param scad 
 */
void LectorMNZDato::parser(string scad) {
    vector<string> vc;

    split(vc, scad, sep);

    ManzanaDato mnzd;

    mnzd.sestado_id=vc[0];
    mnzd.smunicipio_id=vc[1];
    mnzd.slocalidad_id=vc[2];

    mnzd.estado_id = atoi(vc[0].c_str());
    mnzd.municipio_id= atoi(vc[1].c_str());
    mnzd.localidad_id= atoi(vc[2].c_str());

    mnzd.conapo_id=(mnzd.estado_id*1000+mnzd.municipio_id)*10000+mnzd.localidad_id;

    mnzd.sageb_id=vc[3];
    mnzd.smanzana_id=vc[4];

    mnzd.manazana_id=atoi(vc[4].c_str());

    mnzd.pob= atol(vc[5].c_str());

    vMnzD.push_back(mnzd);

}