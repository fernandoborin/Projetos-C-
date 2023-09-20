#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
    head = tail = NULL;
}

bool Queue::Empty(){
    return head == NULL;
}

bool Queue::Full(){ // Opcional, já que por se tratar de uma alocação dinâmica, sempre irá retornar false
    return false;
}

void Queue::Append(int x){
    QueueNode * p;

    p = new QueueNode;

    if (p == NULL){
        cout << "Fila cheia! Nao ha espaco para o novo elemento!" << endl;

        return;
    }

    p->Entry = x;

    if (Empty()){
        head = tail = p;
    }else{
        tail->NextNode = p;
        tail = p;
    }

    p->NextNode = NULL;
}

void Queue::Serve(int &x){
    if (Empty()){
        cout << "Fila vazia!" << endl;

        return;
    }

    QueueNode *p;

    x = head->Entry;
    p = head;
    head = head->NextNode;

    delete p;

    if (head == NULL){
        tail = NULL;
    }
}

Queue::~Queue(){
    int x;

    while (!Empty()){
        Serve(x);
    }
}

void Queue::Front(int &x){
    if (Empty()){
        cout << "Fila vazia! Nao ha elementos em head" << endl;
        
        return;
    }

    x = head->Entry;
}

void Queue::Rear(int &x){
    if (Empty()){
        cout << "Fila vazia! Nao ha elementos em tail" << endl;

        return;
    }

    x = tail->Entry;
}

int Queue::Size(){
    int count = 0;
    QueueNode * p;
    p = head;

    while (p != NULL){
        count++;
        p = p->NextNode;
    }

    return count;
}

void Queue::Clear(){
    int x;

    while (Empty()){
        Serve(x);
    }
}