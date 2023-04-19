// Exercício 2 - Dado a sequência de Fibonacci, onde se inicia por 0 e 1 e o próximo valor sempre será a soma
// ds 2 valores anteriores, escreva um programa na linguagem que desejar onde, informado um número, ele calcule
// a sequência de Fibonacci e retorne uma mensagem avisando se o número informado pertence ou não a sequência 

#include <iostream>
using namespace std;

void fibonacci(int n, int termoAtual, int termoAnterior, int termoPenultimo){
    cout << endl << "Exibindo a sequencia de Fibonacci: " << termoAtual;

    while (termoAtual < n){
        termoAtual = termoAnterior + termoPenultimo;
        termoPenultimo = termoAnterior;
        termoAnterior = termoAtual;
        cout << ", " << termoAtual;
    }

    if (termoAtual == n){
        cout << endl << "O numero " << n << " faz parte da sequencia de Fibonacci";
    } else{
        cout << endl << "O numero " << n << " nao faz parte da sequencia de Fibonacci";
    }
}

int main(){
    int n, termoAtual = 1, termoAnterior = 1, termoPenultimo = 0;

    cout << "Digite um numero: ";
    cin >> n;

    fibonacci(n, termoAtual, termoAnterior, termoPenultimo);

}