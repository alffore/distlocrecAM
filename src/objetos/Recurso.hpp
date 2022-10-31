#ifndef RECURSO_H
#define RECURSO_H

#include <string>

struct Recurso{

    double lon;
    double lat;

    double x;
    double y;
    double z;

    int id;
    string stipo;
    int tipo_id;

    int estado_id;
    int municipio_id;
    int localidad_id;
};

#endif