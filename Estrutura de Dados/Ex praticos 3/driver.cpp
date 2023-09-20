#include <iostream>
#include "esfera.h"
using namespace std;

int main(){
    Esfera E1, E2;

    E1.insereRaio(10.0);
    E2.insereRaio(2.0);

    cout << "Volume da Esfera 1: " << E1.calculaVolume() << endl;
    cout << "Volume da Esfera 2: " << E2.calculaVolume() << endl;
}