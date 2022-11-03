#include "LectorMNZDato.hpp"

/**
 * @brief 
 * 
 * @param scad 
 */
void LectorMNZDato::parser(string scad) {
    vector<string> vc;

    split(vc, scad, sep);

    for(auto &mnz: vMnz){
        if(mnz.pob<0 && mnz.sestado_id == vc[0] && mnz.smunicipio_id == vc[1] 
        && mnz.slocalidad_id == vc[2] && mnz.sageb_id == vc[3] 
        && mnz.smanzana_id == vc[4]){
            mnz.pob = atol(vc[5].c_str());
            if(mnz.pob == 0){
                mnz.pob = 1;
            }
            return;
        }
    }
}