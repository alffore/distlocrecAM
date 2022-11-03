
#include "LectorLoc.hpp"

#define CANT_TIPOREC 25


/**
 * @brief 
 * 
 * @param scad 
 */
void LectorLoc::parser(string scad) {
    vector<string> vc;

    split(vc,scad,sep);

    Localidad loc;

    loc.lon = atof(vc[4].c_str());
    loc.lat = atof(vc[3].c_str());
   
    c2dto3d.lonlat2xyz(loc.lon,loc.lat,loc.x,loc.y,loc.z);

    loc.pob = atof(vc[5].c_str());

    loc.estado_id=atoi(vc[0].c_str());
    loc.municipio_id=atoi(vc[1].c_str());
    loc.localidad_id=atoi(vc[2].c_str());

    loc.conapo_id=(loc.estado_id*1000+loc.municipio_id)*10000+loc.localidad_id;

    for(size_t i=0;i<CANT_TIPOREC;i++){
        loc.vdist.push_back(4);
        loc.vidrec.push_back(1E6);
    }

    vLoc.push_back(loc);
}