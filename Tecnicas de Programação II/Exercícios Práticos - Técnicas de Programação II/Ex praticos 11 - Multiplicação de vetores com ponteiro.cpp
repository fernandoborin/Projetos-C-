// Multiplica os valores de dois vetores entre si usando ponteiros

#include <iostream>
using namespace std;

void imprimirVetor(int *vetor, int *tamanho){
    for (int i = 0; i < *tamanho; i++){
        cout << vetor[i] << " ";
    }

    cout << endl << endl;
}

void multiplicarVetores(int *vetor1, int *vetor2, int *tamanho){
    for (int i = 0; i < *tamanho; i++){
        *(vetor1 + i) = *(vetor1 + i) * (*(vetor2 + i));
    }
}

int main(){
    int tamanho = 4;
    int vet1[tamanho] = {2, 4, 5, 9},
        vet2[tamanho] = {3, 5, 7, 8};

    cout << "Primeiro vetor: ";
    imprimirVetor(vet1, &tamanho);

    cout << "Segundo vetor: ";
    imprimirVetor(vet2, &tamanho); 

    multiplicarVetores(vet1, vet2, &tamanho);

    cout << "Terceiro vetor: ";
    imprimirVetor(vet1, &tamanho);

}