#include <thread>
#include <vector>
#include <string>
#include <iostream>

#include "distlocrecam.hpp"

using namespace std;


unsigned int NUM_HILOS = 8;

vector<Recurso> vRec;
vector<Manzana> vMnz;



int main() {

    unsigned int n = thread::hardware_concurrency();

    if (n > 0) {
        NUM_HILOS = n;
    }

    cout << "Total de hilos posibles: " << NUM_HILOS << endl;




    return 0;
}