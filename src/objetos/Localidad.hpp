#ifndef LOCALIDAD_HPP
#define LOCALIDAD_HPP

#include <vector>

using namespace std;

struct Localidad{

    double lon;
    double lat;

    double x;
    double y;
    double z;

    long conapo_id;

    double pob;
   
    int estado_id;
    int municipio_id;
    int localidad_id;

    vector<size_t> vidrec;
    vector<double> vdist;
};

#endif