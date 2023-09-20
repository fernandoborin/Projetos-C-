#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
    count = 0;
    tail = 0;
    head = 1;
}

Queue::~Queue(){ 
    cout << "Fila destruida!" << endl;
}

bool Queue::Empty(){
    return count == 0;
}

bool Queue::Full(){
    return count == maxQueue;
}

void Queue::Append(int x){
    if (Full()){
        cout << "Fila cheia!" << endl;

        return;
    }

    count++;
    tail = (tail % maxQueue) + 1;
    Entry[tail] = x;
}

int Queue::Size(){
    if (Empty()){
        cout << "Fila vazia!" << endl;
    }

    return count;
}

void Queue::Serve(int &x){
    if (Empty()){
        cout << "Fila vazia!" << endl;

        return;
    }

    x = Entry[head];
    count--;
    head = (head % maxQueue) + 1;
}

void Queue::Rear(int &x){
    if (Empty()){
        cout << "Fila vazia! Nao ha elemento em tail" << endl;

        return;
    }

    x = Entry[tail];
}

void Queue::Front(int &x){
    if (Empty()){
        cout << "Fila vazia! Nao ha elemento em tail" << endl;

        return;
    }

    x = Entry[head];
}

void Queue::Clear(){
    count = 0;
    head = 1;
    tail = 0;
}