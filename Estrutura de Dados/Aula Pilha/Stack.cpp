#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){ // Inicia automaticamentr as variaveis do programa
    top = 0;
}

Stack::~Stack(){ // E chamado automaticamente ao final do programa
    cout << "Pilha destruida!" << endl;
}

bool Stack::Full(){ // Retorna true caso a pilha esteja cheia
    return top == maxElements;
}

bool Stack::Empty(){ // Retorna true caso a pilha esteja vazia
    return top == 0;
}

void Stack::Push(int x){
    if (Full()){
        cout << "Pilha cheia, nao e possivel inserir um novo elemento :(" << endl;
        
        return; // Retorna para o codigo
    }

    top++; // "Sobe" a pilha
    entry[top] = x; // Adiciona no topo a pilha o que está na "mão"
}

void Stack::Pop(int &x){
    if (Empty()){
        cout << "Pilha vazia, nao e possivel retirar o elemento :(" << endl;

        return;
    }

    x = entry[top]; // Pega de volta o que estava no topo
    top--; // Atualiza o novo topo da pilha
}

void Stack::Top(int &x){
    if (Empty()){
        cout << "Pilha vazia. Nao ha elementos no topo :(" << endl;

        return;
    }

    x = entry[top];
}