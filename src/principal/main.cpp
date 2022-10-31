#include <thread>
#include <vector>
#include <string>
#include <iostream>

#include "distlocrecam.hpp"




using namespace std;


unsigned int NUM_HILOS = 8;

vector<Recurso> vRec;
vector<Localidad> vLoc;
vector<Manzana> vMnz;
//vector<Ageb> vAgeb;

string sarchivo_locs = "/home/alfonso/devel/renic/renic.git/utiles/cac2/localidades2020_final.txt";
string sarchivo_recs = "/home/alfonso/devel/renic/renic.git/utiles/cac7/salida_ipc2.txt";
//string sarchivo_agebs = "/fhome/alfonso/devel/CPV2020/MGM/salidas_agebs_ints.txt";
string sarchivo_mnz = "/fhome/alfonso/devel/CPV2020/MGM/mnz/todos.int";
string sarchivo_mnz_dato = "/home/alfonso/devel/renic/renic.git/utiles/cac8/datos_mnz_2020.txt";




void cargadores(){

    string sp1 = "EPSG:4326";
    string sp2 = "EPSG:6372";

    CCG2CCL c2c(sp1, sp2);

    Convierte2Dto3D c2to3;


    LectorRec lecrec(sarchivo_recs," ",vRec,c2to3);
    lecrec.inicia();
    cout <<"Recursos: "<< vRec.size()<<endl;

    LectorLoc lecloc(sarchivo_locs," ",vLoc,c2to3);
    lecloc.inicia();
    cout << "Localidades: "<< vLoc.size()<<endl;

    LectorMNZ lecmnz(sarchivo_mnz,"|",vMnz,c2to3,c2c);
    lecmnz.inicia();
    cout << "Manzanas: "<< vMnz.size()<<endl;

}


int main() {

    unsigned int n = thread::hardware_concurrency();

    if (n > 0) {
        NUM_HILOS = n;
    }

    cout << "Total de hilos posibles: " << NUM_HILOS << endl;

    cargadores();


    return 0;
}

