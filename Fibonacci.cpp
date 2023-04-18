// Imprime uma sequência de Fibonacci até o termo recebido

#include <iostream>
using namespace std;

int n, termoAtual, termoAnterior = 1, termoPenultimo = 0;

void fibonacci(int x){
    cout << "Exibindo os primeiros " << x << " termos da sequencia de Fibonacci: " 
         << termoAtual;

    for (int i = 0; i <= x - 2; i++){
        termoAtual = termoAnterior + termoPenultimo;
        termoPenultimo = termoAnterior;
        termoAnterior = termoAtual;
        cout << ", " << termoAtual;
    }
}

int main(){
    cout << "Digite o numero de termos: ";
    cin >> n;

    fibonacci(n);

}