#include "bag.h"
#include <iostream>
using namespace std;

int main(){
    Bag b1;

    int tamanho, opcao;

    cout << "Qual o tamanho da bag? ";
    cin >> tamanho;

    b1.criarBag(tamanho);

    while (opcao != 0){
        cout << "Escolha uma opcao: " << endl
             << "1 - Inserir numero" << endl
             << "2 - Verificar numero" << endl
             << "3 - Remover numero" << endl
             << "4 - Verificar bag" << endl
             << "0 - Sair" << endl << endl;

        cin >> opcao;

        if (opcao == 1){
            b1.inserirNumero();
        } 

        if (opcao == 2){
            b1.verificarNumero();
        }
    }

    b1.imprimirBag();
}