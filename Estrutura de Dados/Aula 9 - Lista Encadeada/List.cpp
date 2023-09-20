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

void List::Clear(){
    ListPointer q;

    while (head != NULL){
        q = head;
        head = head->NextNode;
        delete q;
    }

    count = 0;
}

bool List::Empty(){
    return count == 0;
}

bool List::Full(){
    return false;
}

int List::Size(){
    return count;
}

void List::SetPosition(int p, ListPointer &current){
    current = head;

    for (int i = 2; i <= p; i++){
        current = current->NextNode;
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

void List::Delete(int p, int &x){
    if (p < 1 || p > count){
        cout << "Posicao de remocao invalida!" << endl;

        return;
    }

    if (Empty()){
        cout << "Estrutura vazia!" << endl;

        return;
    }

    ListPointer current, Node;

    if (p == 1){
        Node = head;
        head = head->NextNode;
    }else{
        SetPosition(p - 1, current);
    
        Node = current->NextNode;
        current->NextNode = Node->NextNode;
    }

    x = Node->Entry;

    delete Node;

    count--;
}