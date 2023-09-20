#include <iostream>
#include "esfera.h"
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

void Esfera::insereRaio(double r){
    if (r < 0){
        cout << "Raio informado é negativo" << endl;
        abort();

    }
    
    raio = r;
}

double Esfera::retornaRaio(){
    return raio;
}

double Esfera::calculaArea(){
    return 4 * M_PI * raio * raio;
}

double Esfera::calculaVolume(){
    return (4 * M_PI * raio * raio * raio) / 3;
}