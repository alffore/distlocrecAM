#ifndef AGEB_H
#define AGEB_H

#include <string>


using std::string;

struct Ageb{

    string aid;
    long pob;

    double lon;
    double lat;

    float x;
    float y;
    float z;

    int estado_id;
    int municipio_id;
    int localidad_id;
    int ageb_id;
};

#endif