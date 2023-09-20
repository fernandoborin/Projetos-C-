#include "List.h"
#include <iostream>
using namespace std;

List::List(){
    head = NULL ;
    count = 0;
}

List::~List(){
    ListPointer q;
    while(head != NULL){
        q = head;
        head = head->NextNode;
        delete q;
    }
}  

void List::Clear(){
    ListPointer q;
    while(head != NULL){
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
    for(int i = 2; i <=p ;i++){
        current = current ->NextNode;
    }
}

void List::Insert(int p, int x, char z){
    if(p < 1 || p > count+1){
        cout<<"Insercao invalida"<<endl;
        return;
        //abort();
    }

    ListPointer NewNode;
    NewNode = new ListNode;
    if(NewNode == NULL){
        cout<<"Falha na alocacao dinamica!"<<endl;
        return;
        //abort();
    }
    NewNode->Entry = x;
    NewNode->Naipe = z;
    ListPointer current;
    if(p==1){
        NewNode->NextNode = head;
        head = NewNode;
    }
    SetPosition(p-1, current);
    NewNode->NextNode = current->NextNode;
    current->NextNode = NewNode;

    count++;
}

void List::Delete(int p, int &x, char &c){
    if(p < 1 || p > count){
        cout << "Exclusao Invalida" << endl;
        return;
    }
    if(Empty()){
        cout<<"Estrutura vazia"<<endl;
        return;
    }
    ListPointer current, Node;
    if(p==1){
        Node = head;
        head = head->NextNode;
    } else {
    SetPosition(p-1, current);
    Node = current->NextNode;
    current->NextNode = Node->NextNode;
    }
    
    x = Node->Entry;
    c = Node->Naipe;
    delete Node;
    count--;

}

void List::Fill(){
    for(int i = 1; i < 14; i++){
        Insert(i, i, 'C');
    }
    for(int i = 14; i < 27; i++){
        Insert(i, (i-12), 'O');
    }
    for(int i = 27; i < 40; i++){
        Insert(i, (i-25), 'P');
    }
    for(int i = 40; i < 53; i++){
        Insert(i, (i-39), 'E');
    }
    //cout<<count;
}

void List::Shuffle(){
    if(Empty()){
        cout << "Lista Vazia" << endl;
        return;
    }
    
    int r, a;
    char n;
    srand(time(NULL));
    ListPointer current, Node;
    current =  new ListNode;
    Node = new ListNode;
    for(int i = 0; i < count+1; i++){
        SetPosition(i, current);
        r = (rand() % count+1);
        SetPosition(r, Node);

        a = current->Entry;
        n = current->Naipe;
        current->Entry = Node->Entry;
        current->Naipe = Node->Naipe;
        Node->Entry = a;
        Node->Naipe = n;
        
    }   
   
}

void List::Read(int x){
     if(Empty()){
        cout<<"Pilha vazia, nao ha elementos no topo"<<endl;
        return;
    }

    ListPointer current;
    current =  new ListNode;
    SetPosition(x, current);
    if(current->Entry < 10){
      cout<<"["<<current->Entry<<" "<<current->Naipe<<"]"<<" ";  
    } else {
        cout<<"["<<current->Entry<<current->Naipe<<"]"<<" "; 
    }
    
}

void List::Retrieve(int p, int &x, char &c){
     if(Empty()){
        cout << "Lista Vazia" << endl;
        return;
    }
    ListPointer current;
    current =  new ListNode;
    SetPosition(p, current);

    x = current->Entry;
    c = current->Naipe;
}
