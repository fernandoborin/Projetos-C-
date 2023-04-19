// Exercício 1 - Ao final do processamento, qual será o valor da variável SOMA?
// Imprimir a variável SOMA no final do código vai retornar o valor 91

#include <iostream>
using namespace std;

int main(){
    int INDICE = 13, SOMA = 0, K = 0;

    while(K < INDICE){
        K = K + 1;
        
        SOMA = SOMA + K;
    }

    cout << SOMA;
}