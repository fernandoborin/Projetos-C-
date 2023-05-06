// Lê o numero de linhas e coluna, cria e aloca memória para a matriz, lê
// os valores para cada posição e faz uma soma entre eles

#include <iostream>
using namespace std;

void criarColunas(int **matriz, int linhas, int colunas){ // Aloca "vetores" colunas em cada linha da matriz
    for (int i = 0; i < linhas; i++){
        matriz[i] = new int[colunas];
    }
}

void digitarValor(int **matriz, int linhas, int colunas){ // Digita cada valor da posicao da matriz
    for (int i = 0; i <  linhas; i++){
        for (int j = 0; j < colunas; j++){
            cout << "Digite o valor para a posicao [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void imprimirMatriz(int **matriz, int linhas, int colunas){ // Imprime os valores de cada posicao do vetor
    for (int i = 0; i < linhas; i++){
    for (int j = 0; j < colunas; j++){
        cout << matriz[i][j] << " ";
    }
    cout << endl;
    }
}

void somarMatriz(int **matriz, int linhas, int colunas, int soma){ // Faz a soma dos termos da matriz
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            soma += matriz[i][j];
        }
    }

    cout << endl << "A soma dos valores da matriz e: " << soma;
}

int main(){
    int linhas, colunas, soma = 0;
    int **matriz;

    cout << "Digite a quantidade de linhas: ";
    cin >> linhas;

    cout << "Digite a quantidade de colunas: ";
    cin >> colunas;

    matriz = new int*[linhas];

    criarColunas(matriz, linhas, colunas);

    digitarValor(matriz, linhas, colunas);

    cout << endl;

    imprimirMatriz(matriz, linhas, colunas);

    somarMatriz(matriz, linhas, colunas, soma);

    for (int i = 0; i < linhas; i++){ // Libera individualmente a memoria alocada de cada vetor de linhas
        delete[] matriz[i];   
    }

    delete[] matriz; // Libera a memoria alocada do vetor final como um todo
}