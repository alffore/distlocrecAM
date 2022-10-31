#ifndef CONVIERTE2DTO3D_HPP
#define CONVIERTE2DTO3D_HPP

#include <cmath>

class Convierte2Dto3D{

public:
    Convierte2Dto3D(){};

    inline double convierteDeg2Rad(double d){return d*M_PI/180.00;};

    void lonlat2xyz(double lon,double lat, double &x, double &y, double &z);

};



#endif