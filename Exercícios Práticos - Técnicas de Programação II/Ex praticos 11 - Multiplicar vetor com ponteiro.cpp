#include <iostream>
using namespace std;

void multiplicarVetor(int *vet, int tamanho, int multiplicador){
    for (int i = 0; i < tamanho; i++){
        *(vet + i) = *(vet + i) * multiplicador;
        cout << *(vet + i) << " ";
    } 

    cout << endl;
}

int main(){
    int multiplicador = 5, tamanho = 4;
    int vet[tamanho] = {2, 4, 5, 9};

    for (int i = 0; i < tamanho; i++){
        cout << vet[i] << " ";
    }

    cout << endl;

    multiplicarVetor(vet, tamanho, multiplicador);

}