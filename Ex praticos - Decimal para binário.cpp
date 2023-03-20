// Usa recursividade para converter um numero decimal para binario

#include <iostream>
using namespace std;

int conversorBinario(int x){
    if (x == 0){
        return 0;
    } else {
        return x % 2 + 10 * (conversorBinario(x / 2));
    }

}

int main(){
    int numdecimal;

    cout << "Digite um numero: ";
    cin >> numdecimal;

    cout << conversorBinario(numdecimal);

}