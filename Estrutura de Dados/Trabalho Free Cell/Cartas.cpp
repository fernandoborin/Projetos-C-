//AUGUSTO HENRIQUE PERNA - 2105087
//FERNANDO PEREZ BORIN - 2125219
//MARCUS PAULO DIB LOPES - 2147404

#include "Cartas.h"
#include <iostream>
#include <time.h>
using namespace std;

Stack::Stack(){ //vai garanatir que todos os tops das colunas iniciem com 0
    count = 0;
    for(int i = 0; i < 8; i++){
        top[i]=0;
    }
     for(int i = 0; i < 8; i++){
        Entry[i][i] = 0;
     }

    }


Stack::~Stack(){
    cout<<"Pilha Destruida"<<endl;
    count == 0;
    for(int i = 0; i < 8; i++){
        while(top[i] > 0){
        top[i]--;}
    }
}

bool Stack::Full(){
    return count == MaxElements;
}

bool Stack::Empty(){
    return count == 0;
}

void Stack::Push(int coluna, int x, char y){ //funcao Push implementada com uma mattriz, onde cada coluna tem seu top
    if(Full()){
        cout<<"Pilha cheia, nao foi possivel inserir o elemento"<<endl;
        return;
    } 
    count++;  
    top[coluna]++;
    Entry[top[coluna]][coluna] = x; //usamos top[coluna] para definir a linha, pois ela representa a ultima linha de cada coluna
    Letra[top[coluna]][coluna] = y;
   
   
   
}

void Stack::Pop(int coluna ){ //retira cartas do topo de cada coluna
    if(Empty()){
        cout<<"Pilha vazia, nao foi possivel remover um elemento"<<endl;
        return;
    } 
    if(top[coluna] == 0){
        cout<<"Pilha vazia, nao foi possivel remover um elemento"<<endl;
        return;
    }
    
    
    Entry[top[coluna]][coluna] = 0;
    
    count--;
    Entry[top[coluna]][coluna] = 15; //muda o valor pra 15, para que o codigo da main (funcao preencherjogo) nao leia
    top[coluna]--;
    
        
}

void Stack::Top(int coluna, int &x, char &y){ //usado para retornar a carta do topo de cada coluna
    if(Empty()){
        cout<<"Pilha vazia, nao ha elementos no topo"<<endl;
        return;
    }
    x = Entry[top[coluna]][coluna];
    y = Letra[top[coluna]][coluna];
}

void Stack::Read(int coluna, int indice){ //indice é linha //funcao usada para imprimir uma carta especifica (determinado pelas linhas e colunas)
     if(Empty()){
        cout<<"Pilha vazia, nao ha elementos no topo"<<endl;
        return;
    }
     if (Entry[indice][coluna] == 1){
         cout<<"["<<"A"<<" "<<Letra[indice][coluna]<<"]"<<" "; // imprime A (as) ao inves de 1
    }else if(Entry[indice][coluna] > 1 && Entry[indice][coluna] < 10){ // esse if serve para dar um espaço se a carta tem valor menor do que 9
        cout<<"["<<Entry[indice][coluna]<<" "<<Letra[indice][coluna]<<"]"<<" ";
    } else if(Entry[indice][coluna] == 10){ // esse if serve nao dar espaço se a carta for igual a 10
        cout<<"["<<Entry[indice][coluna]<<Letra[indice][coluna]<<"]"<<" ";
    } else if(Entry[indice][coluna] == 11){ // imprime J (valete) ao inves de 1
        cout<<"["<<"J"<<" "<<Letra[indice][coluna]<<"]"<<" ";
    } else if (Entry[indice][coluna] == 12){ // imprime Q (dama) ao inves de 1
        cout<<"["<<"Q"<<" "<<Letra[indice][coluna]<<"]"<<" ";
    } else if (Entry[indice][coluna] == 13){ // imprime K (rei) ao inves de 1
        cout<<"["<<"K"<<" "<<Letra[indice][coluna]<<"]"<<" ";
    }
}

void Stack::Preencher(){ //preenche a stack com 52 elementos de valor (1 a 13) e seus respectivos naipes
    int vetor[52];
    int valor;
    char naipe;
    
    for (int i = 0; i < 52; i++){
        vetor[i] = i+1;
    }
    
    srand(time(NULL));
    
    for (int i = 0; i < 52; i++){
        int aux, random;
        random = rand() % 52;
        aux = vetor[i];
        vetor[i] = vetor[random];
        vetor[random] = aux;
    }
    
    for(int i = 0; i < 7; i++){ //preenche a 1° coluna de entry com 7 elementos, todos copas
        if(vetor[i] < 14){
            valor = vetor[i];
            naipe = 'C';
        } else if(vetor[i] > 13 && vetor[i] < 27){
            valor = (vetor[i] - 13);
            naipe = 'O';
        } else if (vetor[i] > 26 && vetor[i] < 40){
            valor = (vetor[i] - 26);
            naipe = 'P';
        } else {
            valor = (vetor[i] - 39);
            naipe = 'E';
        }
        Push(0, valor, naipe);}
    
    for(int i = 7; i < 14; i++){ //preencher a 2° coluna de entry com 6 elementos de copas e um de ouros 
       if(vetor[i] < 14){
            valor = vetor[i];
            naipe = 'C';
        } else if(vetor[i] > 13 && vetor[i] < 27){
            valor = (vetor[i] - 13);
            naipe = 'O';
        } else if (vetor[i] > 26 && vetor[i] < 40){
            valor = (vetor[i] - 26);
            naipe = 'P';
        } else {
            valor = (vetor[i] - 39);
            naipe = 'E';
        }
        Push(1, valor, naipe);
    }

    for(int i = 14; i < 21; i++){ //preenche a 3° coluna de entry com 7 elementos de copas ( 2 ao 8)
        if(vetor[i] < 14){
            valor = vetor[i];
            naipe = 'C';
        } else if(vetor[i] > 13 && vetor[i] < 27){
            valor = (vetor[i] - 13);
            naipe = 'O';
        } else if (vetor[i] > 26 && vetor[i] < 40){
            valor = (vetor[i] - 26);
            naipe = 'P';
        } else {
            valor = (vetor[i] - 39);
            naipe = 'E';
        }
        Push(2, valor, naipe);
    }

    for(int i = 21; i < 28; i++){ //preenche a 4° coluna de entry com 5 elementos de copas e 2 de espadas
       if(vetor[i] < 14){
            valor = vetor[i];
            naipe = 'C';
        } else if(vetor[i] > 13 && vetor[i] < 27){
            valor = (vetor[i] - 13);
            naipe = 'O';
        } else if (vetor[i] > 26 && vetor[i] < 40){
            valor = (vetor[i] - 26);
            naipe = 'P';
        } else {
            valor = (vetor[i] - 39);
            naipe = 'E';
        }
        Push(3, valor, naipe);
    }

    for(int i = 28; i < 34; i++){ //preenche a 5° coluna de entry com 6 elementos de espadas ( 3 ao 8 )
        if(vetor[i] < 14){
            valor = vetor[i];
            naipe = 'C';
        } else if(vetor[i] > 13 && vetor[i] < 27){
            valor = (vetor[i] - 13);
            naipe = 'O';
        } else if (vetor[i] > 26 && vetor[i] < 40){
            valor = (vetor[i] - 26);
            naipe = 'P';
        } else {
            valor = (vetor[i] - 39);
            naipe = 'E';
        }
        Push(4, valor, naipe);
    }   

    for(int i = 34; i < 40; i++){ //peenche a 6° coluna de entry com 5 elementos de espadas e 1 de paus
        if(vetor[i] < 14){
            valor = vetor[i];
            naipe = 'C';
        } else if(vetor[i] > 13 && vetor[i] < 27){
            valor = (vetor[i] - 13);
            naipe = 'O';
        } else if (vetor[i] > 26 && vetor[i] < 40){
            valor = (vetor[i] - 26);
            naipe = 'P';
        } else {
            valor = (vetor[i] - 39);
            naipe = 'E';
        }
        Push(5, valor, naipe);
    } 

    for(int i = 40; i < 46; i++){ //preenche a 7° coluna de entry com 6 elementos de espadas
        if(vetor[i] < 14){
            valor = vetor[i];
            naipe = 'C';
        } else if(vetor[i] > 13 && vetor[i] < 27){
            valor = (vetor[i] - 13);
            naipe = 'O';
        } else if (vetor[i] > 26 && vetor[i] < 40){
            valor = (vetor[i] - 26);
            naipe = 'P';
        } else {
            valor = (vetor[i] - 39);
            naipe = 'E';
        }
        Push(6, valor, naipe);
        
    }

     for(int i = 46; i < 52; i++){ //preenche a 8° coluna de entry com 6 elementos de espadas
        if(vetor[i] < 14){
            valor = vetor[i];
            naipe = 'C';
        } else if(vetor[i] > 13 && vetor[i] < 27){
            valor = (vetor[i] - 13);
            naipe = 'O';
        } else if (vetor[i] > 26 && vetor[i] < 40){
            valor = (vetor[i] - 26);
            naipe = 'P';
        } else {
            valor = (vetor[i] - 39);
            naipe = 'E';
        }
        Push(7, valor, naipe);
         
     }


}

void Stack::Retrieve(int coluna, int linha, int &y, char &n){ //usado para retornar o valor e naipe de qualquer carta da stack
     if(Empty()){
        cout << "Lista Vazia" << endl;
        return;
    }
    y = Entry[linha][coluna];
    n = Letra[linha][coluna];
}

void Stack::MaiorTop(int &x){
        if(Empty()){
        cout << "Lista Vazia" << endl;
        return;
    }
    int temp = top[0];

    for(int i = 1; i < 8; i++){
        if(top[i] > temp){
            temp = top[i];
        }
    }

   x = temp;

}

void Stack::TopColuna(int coluna, int &x){ //usado para saber qual a ultima linha (topo) de cada coluna
    x = top[coluna];
}

void Stack::Cor(int coluna, char &cor){ //usado para verificar a cor da carta de todo de uma coluna especifica da stack
       if(Empty()){
        cout << "Lista Vazia" << endl;
        return;
    }

    if(Letra[top[coluna]][coluna] == 'C' || Letra[top[coluna]][coluna] == 'O' ){
        cor = 'V';
    } else {
        cor = 'P';
    }

}

int Stack::Size(){
    return count;
}
