#include "Salida.hpp"

void Salida::imprimeSalidaLoc(string sarchivo,vector<Localidad> &vLoc, vector<Recurso> &vRec){

    ofstream ofs(sarchivo);

    for(auto &loc: vLoc){

        for(size_t i=0;i<CANT_TIPOREC;i++){
            auto &rec = vRec[loc.vidrec[i]];
            double d = RT * loc.vdist[i];

            ofs.unsetf(std::ios::fixed | std::ios::scientific);

            ofs<<loc.estado_id<<","<<loc.municipio_id<<","<<loc.localidad_id<<",";
            ofs<<rec.stipo<<","<<(long)loc.pob<<",";
            ofs<<std::setprecision(5)<<d<<","; 
            
            ofs<<rec.estado_id<<","<<rec.municipio_id<<","<<rec.localidad_id<<","<<rec.id;
            ofs<<endl;
        }
        
    }
}