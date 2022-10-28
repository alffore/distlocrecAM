#ifndef CCG2CCL_HPP
#define CCG2CCL_HPP


#include <iostream>
#include <string>
#include <proj.h>

using namespace std;

class CCG2CCL {

private:

    string sproyec1;
    string sproyec2;

    PJ_CONTEXT *C;
    PJ *P;
    PJ *norm;



public:
    CCG2CCL(string sproyec1, string sproyec2);

    virtual ~ CCG2CCL();



    void convierte(double lon, double lat, double&este, double& norte);
};


#endif