#include "LectorMNZDato.hpp"

/**
 * @brief 
 * 
 * @param scad 
 */
void LectorMNZDato::parser(string scad) {
    vector<string> vc;

    split(vc, scad, sep);

    int e = atoi(vc[0].c_str());
    int m = atoi(vc[1].c_str());
    int l = atoi(vc[2].c_str());

    for(auto &mnz: vMnz){
        if(mnz.pob<0 && mnz.localidad_id == l && mnz.municipio_id == m 
        && mnz.estado_id == e         
        &&  mnz.sageb_id == vc[3] && mnz.smanzana_id == vc[4]){

            mnz.pob = atol(vc[5].c_str());
            if(mnz.pob == 0){
                mnz.pob = 1;
            }
            return;
            
        }
    }
}