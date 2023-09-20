#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){
    top = NULL;
}

bool Stack::Empty(){
    return top == NULL;
}

bool Stack::Full(){
    return false;
}

void Stack::Push(int x){
    StackNode* p;

    p = new StackNode; // Aloca um espaço do tamanho de "StackNode"

    if (p == NULL){
        cout << "Pilha cheia!" << endl;

        return;
    }

    p->Entry = x; // p.Entry = x
    p->NextNode = top; // p.NextNode = top
    top = p;
}

void Stack::Top(int &x){
    x = top->Entry; // x = top.Entry
}

void Stack::Pop(int &x){
    if (Empty()){
        cout << "Pilha vazia!" << endl;
        
        return;
    }

    StackNode* p;

    p = top;
    x = top->Entry;
    top = top->NextNode;
    // x = p->Entry;
    
    delete p;
}

Stack::~Stack(){

}