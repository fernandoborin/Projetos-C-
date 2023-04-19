#include <iostream>
using namespace std;

void fibonacci(int n, int termoAtual, int termoAnterior, int termoPenultimo){
    cout << "Exibindo os primeiros " << n << " termos da sequencia de Fibonacci: " << termoAtual;

    for (int i = 0; i <= n - 2; i++){
        termoAtual = termoAnterior + termoPenultimo;
        termoPenultimo = termoAnterior;
        termoAnterior = termoAtual;
        cout << ", " << termoAtual;
    }
}

int main(){
    int n, termoAtual = 1, termoAnterior = 1, termoPenultimo = 0;

    cout << "Digite o numero de termos: ";
    cin >> n;

    fibonacci(n, termoAtual, termoAnterior, termoPenultimo);

}