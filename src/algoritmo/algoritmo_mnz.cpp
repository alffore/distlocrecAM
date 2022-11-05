#include "../principal/distlocrecam.hpp"

extern unsigned int NUM_HILOS;

extern vector<Recurso> vRec;
extern vector<Localidad> vLoc;
extern vector<Manzana> vMnz;
extern vector<ManzanaDato> vMnzD;
extern vector<LocalidadC> vCorr;

extern size_t tamRec;
extern size_t tamLoc;
extern size_t tamMnz;
extern size_t tamMnzD;


/**
 * @brief 
 * 
 * @param id 
 */
void recuperaPobMnz(int id){

    for(size_t i=id;i<tamMnz;i+=NUM_HILOS){
        Manzana &mnz = vMnz[i];
        for(size_t j = 0 ; j<tamMnzD;j++){
            ManzanaDato &mnzd = vMnzD[j];
            if(mnz.conapo_id == mnzd.conapo_id){
                mnz.pob = mnzd.pob;
                break;
            }
        }

        if(i%10000==0){
            cout <<"Avance Población -> Mnz: "<<(double)i*100.00/(double)tamMnz<<"% "<<endl;
        }
    }
}


/**
 * @brief 
 * 
 * @param mnz 
 * @param rec 
 * @return double 
 */
double distanciaMnzRec(Manzana mnz,Recurso rec){
    double res = mnz.x*rec.x + mnz.y*rec.y + mnz.z*rec.z;

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
    for(size_t j=0; j<tamRec; j++){
        int tipo_id = vRec[j].tipo_id;

        for(size_t i=id; i<tamMnz; i+=NUM_HILOS){
            
            daux = distanciaMnzRec(vMnz[i],vRec[j]);

            if(vMnz[i].vdist[tipo_id] > daux){
                vMnz[i].vdist[tipo_id] = daux;
                vMnz[i].vidrec[tipo_id] = j;
            }        

        }

    }
}

/**
 * @brief 
 * 
 * @param id 
 */
void calculaCorreccion(size_t id){

    for(size_t i=id;i<tamLoc;i+=NUM_HILOS){
        LocalidadC loc_corr;
        loc_corr.conapo_id = vLoc[i].conapo_id;
        loc_corr.sumpob=0;

        for(size_t k=0;k<CANT_TIPOREC;k++){
            loc_corr.vdist.push_back(0);                    
        }

        for(auto &mnz: vMnz){
            if(mnz.conapo_id == vLoc[i].conapo_id){
                loc_corr.sumpob += mnz.pob;
                for(size_t j=0; j<CANT_TIPOREC; j++){
                    loc_corr.vdist[j] += mnz.vdist[j]*mnz.pob;                    
                }
            }
        }

        if(loc_corr.sumpob > 0){
            for(size_t j=0; j<CANT_TIPOREC; j++){
                loc_corr.vdist[j] /= loc_corr.sumpob;
                vLoc[i].vdist[j] = loc_corr.vdist[j];
            }
            vCorr.push_back(loc_corr);
        }        
    }

}


