#include "List.h"
#include <iostream>
using namespace std;

List::List(){
    count = 0;
    head = NULL;
}

List::~List(){
    ListPointer q;

    while (head != NULL){
        q = head;
        head = head->NextNode;
        
        delete q;
    }
}

void List::Insert(int p, int x){
    if (p < 1 || p > count + 1){
        cout << "Posicao invalida para insercao!" << endl;

        return;
    }

    ListPointer NewNode;
    NewNode = new ListNode;

    if (NewNode = NULL){
        cout << "Falha na alocacao dinamica!" << endl;

        return;
    }

    NewNode->Entry = x;
    ListPointer current;

    if (p == 1){
        NewNode->NextNode = head;
        head = NewNode;
    }else{
        SetPosition(p - 1, current);

        NewNode->NextNode = current;
        current->NextNode = NewNode;
    }

    count++;
}

void List::printList(){
    
}