#ifndef MANZANA_HPP
#define MANZANA_HPP

#include <string>


using std::string;

struct Manzana{

    string mid;
    long pob;

    double lon;
    double lat;

    double x;
    double y;
    double z;

    int estado_id;
    int municipio_id;
    int localidad_id;

    string sestado_id;
    string smunicipio_id;
    string slocalidad_id;
    string sageb_id;
    string smanzana_id;

    vector<size_t> vidrec;
    vector<double> vdist;
};



#endif