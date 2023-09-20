#include "Stack.h"
#include <iostream>
using namespace std;

int main(){
    Stack s1, s2;

    int x, y;

    s1.Push(3); // Insere numeros na pilha
    s1.Push(5);
    s1.Push(8);

    s2.Push(50);

    s1.Top(x);
    cout << "Topo da pilha s1: " << x << endl;

    s1.Pop(x);
    cout << x << endl;

    s2.Push(x);

    s2.Top(y);
    cout << "Topo da pilha s2: " << y << endl;
}