#include "Convierte2Dto3D.hpp"

void Convierte2Dto3D::lonlat2xyz(double lon,double lat, double &x, double &y, double &z){

    lon = convierteDeg2Rad(lon);
    lat = convierteDeg2Rad(lat);

    x=sin(lon)*cos(lat);
    y=cos(lon)*cos(lat);
    z=sin(lat);

    double  r = pow(x,2.0)+pow(y,2.0)+pow(z,2.0);
    r= sqrt(r);

    x/=r;
    y/=r;
    z/=r;
}