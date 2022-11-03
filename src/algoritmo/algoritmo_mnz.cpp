#include "../principal/distlocrecam.hpp"

extern unsigned int NUM_HILOS;

extern vector<Recurso> vRec;
extern vector<Localidad> vLoc;
extern vector<Manzana> vMnz;

extern size_t tamRec;
extern size_t tamLoc;
extern size_t tamMnz;

/**
 * @brief 
 * 
 * @param mnz 
 * @param rec 
 * @return double 
 */
double distanciaMnzRec(Manzana mnz,Recurso rec){
     double res=mnz.x*rec.x + mnz.y*rec.y + mnz.z*rec.z;

    res=(res<-1.0)?-1.0:res;
    res=(res>1.0)?1.0:res;

    return acos(res);
}

/**
 * @brief 
 * 
 * @param id 
 */
void generaRedManzana(size_t id){
    double daux;
    for(size_t j=0;j<tamRec;j++){
        int tipo_id = vRec[j].tipo_id;

        for(size_t i=id;i<tamMnz;i+=NUM_HILOS){
            daux = distanciaMnzRec(vMnz[i],vRec[j]);
            if(vMnz[i].vdist[tipo_id] > daux){
                vMnz[i].vdist[tipo_id] = daux;
                vMnz[i].vidrec[tipo_id] = j;
            }        
        }

    }
}


