// Usa referencia por ponteiro para calcular o fatorial de um numero por recursividade

#include <iostream>
using namespace std;

int fatorialPointer(int x){
    if (x == 1){
        return 1;
    }
    return x * fatorialPointer(x - 1);
}

int main(){
    int num;
    int *ptr;  

    cout << "Digite um numero: ";
    cin >> num;

    ptr = &num;

    cout << fatorialPointer(*ptr);
}