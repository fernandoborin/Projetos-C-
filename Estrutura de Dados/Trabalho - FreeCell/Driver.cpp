#include "List.h"
#include <iostream>
using namespace std;
List jogo;
int m, valor, cartafora, cartadentro = 0;
char naipe;
int telajogo [12][8]; //VETOR COM OS VALORES DE CADA CARTA
char naipetelajogo[12][8]; //VETOR COM OS NAIPES DE CADA CARTA
int posicaolist[12][8]; //vetor que guarda a posição daquela carta, na list (para poder remover)
int topodecoluna[8];
int tamanhocoluna[7];
int ultimalinha, contagemelementos;


struct freecell{
    int valor;
    char naipe;
};
typedef struct freecell freecell;
freecell freecelljogo[4];

struct pilhafinal{
    int valor;
    char naipe;
};
typedef struct pilhafinal pilhafinal;
pilhafinal pilhafinaljogo[4];

void primeiropreenchimento(){

    for(int i = 0; i < 4; i++){
        freecelljogo[i].valor = 0;
        freecelljogo[i].naipe = '-';
        pilhafinaljogo[i].valor = 0;
        pilhafinaljogo[i].naipe = '-';
    }
      for(int i = 0; i < 8; i++){
        ultimalinha++;
    for(int j = 0; j < 8; j++){   
        tamanhocoluna[j] = j+1;
        contagemelementos++;
      jogo.Retrieve(m, valor, naipe);
      telajogo[i][j] = valor;
      naipetelajogo[i][j] = naipe;
      posicaolist[i][j] = m;
      topodecoluna[j] = m;
      m++;
      if(m == jogo.Size()){
        i = 8;
        j = 9;
      }
      
    }
  }
}

//funçao para tirar a carta do jogo      NAO FUNCIONA
void tiraracartajogo(int linha){
    //cout<<"O elemento escolhido foi "<<telajogo[linha][x-1]<<naipetelajogo[linha][x-1]<<endl;
    telajogo[tamanhocoluna[linha]][linha] = 0;
    naipetelajogo[tamanhocoluna[linha]][linha]= ' ';
}


//funcao para colocar a carta em jogo
void colocarcartajogo(int valor, char naipe, int linha){
    telajogo[linha][linha-1] = valor;
    naipetelajogo[linha][linha-1]= naipe;
}

void preencherjogo(){

cout<<endl<<"[9 ]"<<" "<<"[10]"<<" "<<"[11]"<<" "<<"[12]"<<" ";
cout<<"[13 ]"<<" "<<"[14]"<<" "<<"[15]"<<" "<<"[16]"<<" "<<endl;

for(int i = 0; i < 4; i++){
    if(freecelljogo[i].valor < 10){
      cout<<"["<<freecelljogo[i].valor<<" "<<freecelljogo[i].naipe<<"]"<<" ";  
    } else {
        cout<<"["<<freecelljogo[i].valor<<freecelljogo[i].naipe<<"]"<<" "; 
    }
}

for(int i = 0; i < 4; i++){
    if(pilhafinaljogo[i].valor < 10){
      cout<<"["<<pilhafinaljogo[i].valor<<" "<<pilhafinaljogo[i].naipe<<"]"<<" ";  
    } else {
        cout<<"["<<pilhafinaljogo[i].valor<<pilhafinaljogo[i].naipe<<"]"<<" "; 
    }
}

cout<<endl<<endl;
m = contagemelementos;
//MOSTRA O INDICE DE CADA COLUNA PARA O JOGADOR
cout<<"[ 1 ]"<<" "<<"[ 2 ]"<<" "<<"[ 3 ]"<<" "<<"[ 4 ]"<<" ";
cout<<"[ 5 ]"<<" "<<"[ 6 ]"<<" "<<"[ 7 ]"<<" "<<"[ 8 ]"<<endl;
cout<<"-----"<<" "<<"-----"<<" "<<"-----"<<" "<<"-----"<<" ";
cout<<"-----"<<" "<<"-----"<<" "<<"-----"<<" "<<"-----"<<endl;

  
//MOSTRA TODOS OS ELEMENTOS PRO JOGADOR
   for(int i = 0; i < 8; i++){  
    for(int j = 0; j < 8; j++){ 
      m--;
      if(telajogo[i][j] < 10){
      cout<<"["<<telajogo[i][j]<<" "<<naipetelajogo[i][j]<<"]"<<" ";  
    } else {
        cout<<"["<<telajogo[i][j]<<naipetelajogo[i][j]<<"]"<<" "; 
    }
      if(m == 0){
        i = 7;
        j = 7;
      }
    }
    cout<<endl;
  }
 
}

int main(){
 
  jogo.Fill(); //PREENCHE A LIST
  jogo.Shuffle(); //EMBARALHA A LIST
  int valor;
  char naipe2;

primeiropreenchimento();
preencherjogo();
 int linha;
cout<<"De qual coluna deseja tirar a carta? ";
cin>>cartafora;

jogo.Delete(topodecoluna[cartafora-1], valor, naipe2);
//cout<<valor<<naipe2;
linha = tamanhocoluna[cartafora-1];
tiraracartajogo(linha);

preencherjogo();

cout<<"A qual coluna deseja adicionar a carta? ";
cin>>cartadentro;

jogo.Insert(topodecoluna[cartadentro], valor, naipe2);
linha = tamanhocoluna[cartadentro-1];
colocarcartajogo(valor, naipe2, linha);

preencherjogo();





    
}