// Solicita o número de termos e faz a média entre eles

#include <iostream>
#include <cstdlib>
using namespace std;

int i = 0, numtermos = 0, num = 0, total = 0;
float media = 0;

//------------------------

int main(){
    cout << "Quer calcular a media de quantos numeros?" << endl;
    cin >> i;
    numtermos = i;

    for (i; i > 0; --i){
        cout << "Digite um numero: " << endl;
        cin >> num;
        total = total + num;
    }

    media = total / numtermos;
    cout << "A media entre os valores informados é" << media;

    return 0;
}