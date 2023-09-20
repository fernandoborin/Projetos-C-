#include "Queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue Fila1, Fila2;

    Fila1.Append(3);
    Fila1.Append(5);
    Fila1.Append(8);

    int x;

    Fila1.Serve(x);
    cout << "Valor servido de Fila1: " << x << endl;

    Fila1.Rear(x);
    cout << "Valor de tail em Fila1: " << x << endl;

    Fila1.Front(x);
    cout << "Valor de head em Fila1: " << x << endl;
}