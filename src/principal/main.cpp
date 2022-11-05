#include <thread>
#include "distlocrecam.hpp"
#include "../salidas/Salida.hpp"



unsigned int NUM_HILOS = 8;

vector<Recurso> vRec;
vector<Localidad> vLoc;
vector<Manzana> vMnz;
vector<ManzanaDato> vMnzD;
//vector<Ageb> vAgeb;
vector<LocalidadC> vCorr;

size_t tamRec;
size_t tamLoc;
size_t tamMnz;
size_t tamMnzD;


string sarchivo_locs = "/home/alfonso/devel/renic/renic.git/utiles/cac2/localidades2020_final.txt";
string sarchivo_recs = "/home/alfonso/devel/renic/renic.git/utiles/cac7/salida_ipc2.txt";
//string sarchivo_agebs = "/fhome/alfonso/devel/CPV2020/MGM/salidas_agebs_ints.txt";
string sarchivo_mnz = "/fhome/alfonso/devel/CPV2020/MGM/mnz/todos.int";
string sarchivo_mnz_dato = "/home/alfonso/devel/renic/renic.git/utiles/cac8/datos_mnz_2020.txt";


extern void generaRedLocalidad(size_t id);
extern void generaRedManzana(size_t id);
extern void calculaCorreccion(size_t id);
extern void recuperaPobMnz(int id);


/**
 * @brief Función que carga toda la información requerida 
 * 
 */
void cargadores(){

    string sp1 = "EPSG:4326";
    string sp2 = "EPSG:6372";

    CCG2CCL c2c(sp1, sp2);

    Convierte2Dto3D c2to3;

    cout << "Incia carga ..."<<endl;

    LectorRec lecrec(sarchivo_recs," ",vRec,c2to3);
    lecrec.inicia();
    tamRec = vRec.size();
    cout <<"Recursos: "<< tamRec<<endl;

    LectorLoc lecloc(sarchivo_locs," ",vLoc,c2to3);
    lecloc.inicia();
    tamLoc = vLoc.size();
    cout << "Localidades: "<< tamLoc<<endl;

    LectorMNZ lecmnz(sarchivo_mnz,"|",vMnz,c2to3,c2c);
    lecmnz.inicia();
    tamMnz = vMnz.size();
    cout << "Manzanas: "<< tamMnz<<endl;

    LectorMNZDato lecmnzd(sarchivo_mnz_dato," ",vMnzD);
    lecmnzd.inicia();
    tamMnzD = vMnzD.size();
    cout << "Manzanas datos: "<< tamMnzD <<endl;
    
    cout << "Finaliza carga ..."<<endl;
}

/**
 * @brief 
 * 
 * @return int 
 */
int main() {

    unsigned int n = thread::hardware_concurrency();

    if (n > 0) {
        NUM_HILOS = n;
    }

    cout << "Total de hilos posibles: " << NUM_HILOS << endl;

    cargadores();

    cout<< "Comienza el calculo de localidades ..."<<endl;
    vector<thread> vthreads;
    for (size_t i=0;i<NUM_HILOS;i++){
        vthreads.emplace_back(generaRedLocalidad,i);
    }

    for (auto &th: vthreads) {
        th.join();
    }

    vthreads.clear();

    Salida sal;

    sal.imprimeSalidaLoc("./resultados/locrec.txt",vLoc,vRec);




    cout<< "Comienza el calculo de manzanas ..."<<endl;
    
    for (size_t i=0;i<NUM_HILOS;i++){
        vthreads.emplace_back(recuperaPobMnz,i);
    }

    for (auto &th: vthreads) {
        th.join();
    }

    vthreads.clear();


    for (size_t i=0;i<NUM_HILOS;i++){
        vthreads.emplace_back(generaRedManzana,i);
    }

    for (auto &th: vthreads) {
        th.join();
    }

    vthreads.clear();



    cout<< "Cálculo de correcciones ..."<<endl;

    for (size_t i=0;i<NUM_HILOS;i++){
        vthreads.emplace_back(calculaCorreccion,i);
    }

    for (auto &th: vthreads) {
        th.join();
    }

    vthreads.clear();

    sal.imprimeSalidaLoc("./resultados/locrec2.txt",vLoc,vRec);

    return 0;
}

