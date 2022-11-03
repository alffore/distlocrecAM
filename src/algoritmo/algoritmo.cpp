#include "../principal/distlocrecam.hpp"

extern unsigned int NUM_HILOS;

extern vector<Recurso> vRec;
extern vector<Localidad> vLoc;

extern size_t tamRec;
extern size_t tamLoc;

/**
 * @brief 
 * 
 * @param loc 
 * @param rec 
 * @return double 
 */
double distanciaLocRec(Localidad loc,Recurso rec){
    double res=loc.x*rec.x + loc.y*rec.y + loc.z*rec.z;

    res=(res<-1.0)?-1.0:res;
    res=(res>1.0)?1.0:res;

    return acos(res);
}

/**
 * @brief 
 * 
 * @param id 
 */
void generaRedLocalidad(size_t id){
    double daux;
    for(size_t j=0;j<tamRec;j++){
        int tipo_id = vRec[j].tipo_id;

        for(size_t i=id;i<tamLoc;i+=NUM_HILOS){
            daux = distanciaLocRec(vLoc[i],vRec[j]);
            if(vLoc[i].vdist[tipo_id] > daux){
                vLoc[i].vdist[tipo_id] = daux;
                vLoc[i].vidrec[tipo_id] = j;
            }        
        }

    }
}