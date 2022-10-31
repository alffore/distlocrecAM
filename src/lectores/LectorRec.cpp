
#include "LectorRec.hpp"

void LectorRec::parser(string scad) {
    vector<string> vc;

    split(vc,scad,sep);

    Recurso rec;

    rec.lon = atof(vc[4].c_str());
    rec.lat = atof(vc[3].c_str());

    c2dto3d.lonlat2xyz(rec.lon,rec.lat,rec.x,rec.y,rec.z);
   
    rec.id = atoi(vc[7].c_str());

    rec.stipo = vc[5];
    rec.tipo_id = atoi(vc[6].c_str());

    rec.estado_id=atoi(vc[0].c_str());
    rec.municipio_id=atoi(vc[1].c_str());
    rec.localidad_id=atoi(vc[2].c_str());

    vRec.push_back(rec);
}
