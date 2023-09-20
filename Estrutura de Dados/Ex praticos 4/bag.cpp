#include "bag.h"
#include <iostream>
using namespace std;

void Bag::criarBag(int t){
    bag[t + 1];
}

void Bag::inserirNumero(){
    int numero;

    cout << "Digite um numero: ";
    cin >> numero;

    bag[slotUsado] = numero;
    slotUsado++;
}

int Bag::verificarNumero(){
    int numero;

    cout << "Digite um numero: ";
    cin >> numero;

    for (int i = 0; i <= slotUsado; i++){
        if (bag[i] == numero){
            cout << "Este numero ja esta dentro da bag!" << endl;
        }
    }
}

void Bag::imprimirBag(){
    for (int i = 0; i <= slotUsado; i++){
        cout << "Numero na posicao " << i << "da bag: " << bag[i] << endl;
    }
}