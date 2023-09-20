//AUGUSTO HENRIQUE PERNA - 2105087
//FERNANDO PEREZ BORIN - 2125219
//MARCUS PAULO DIB LOPES - 2147404

#include "Cartas.h"
#include <iostream>
#include <time.h>
using namespace std;


Stack um;
char cornaipe;


struct freecell{
    int cartas[9]; //representa as 4 cartas das freecels e as 4 da pilha final (1 a 4 freecells e 5 a 8 as da pilha final)  
    char naipe[9];//representa o naipe das 4 cartas das freecels e as 4 de pilha final (1 a 4 freecells e 5 a 8 as da pilha final)
};
typedef struct freecell freecell;
freecell freecells;


                         ///// FUNÇÃO PARA DEFINIR A COR DE CADA NAIPE /////
void retornarcor(char a, char *cor){
    if(a == 'C' || a == 'O'){ //SE COPAS OU OUROS
        *cor = 'V'; //COR VERMELHA
    } else if(a == 'P' || a == 'E'){ // SE PAUS OU ESPADAS 
        *cor = 'P'; // COR PRETA
    }
}

                    ////// FUNÇAO PARA VERIFICAR SE UM MOVIMENTO ENTRE CARTAS FORA DA PILHA FINAL É POSSIVEL /////
void movimentopossivel(int valor, int valoratual, char cor, char coratual, int *contador){
    if(valor == (valoratual -1) && coratual != cor){
    } else {
        *contador++; // se a jogada nao for possivel, ele incremeta o contador
    }
}   
                  ///// FUNÇÃO PARA VERIFICAR SE É POSSIVEL COLOCAR A CARTA ESCOLHIDA NA PILHA DE SAÍDA //////
void movimentofinalpossivel(int valor, int valoratual, char cor, char coratual, int *contador){
    if(valor == (valoratual +1) && coratual == cor){
        *contador++;
    }
} 

                          ///// FUNÇÃO PARA VERIRIFCAR FIM DE JOGO /////
void verificarfimdejogo(bool *fimdejogo){
    //verifica vitoria
    if( freecells.cartas[9] == 13 && freecells.cartas[8] == 13 && freecells.cartas[7] == 13 && freecells.cartas[6] == 13){
        cout<<"PARABÉNS, VOCÊ VENCEU!!!"<<endl;
        *fimdejogo = true;
    }

    // verifica se existe movimentos possiveis com as freecells
    int valor;
    int possiveljogar = 0;
    char naipe, corfreecell[4], corjogo[8];
        //verifica se é possivel alguma freecell entrar na pilha se jogo
    if( freecells.cartas[1] > 0 && freecells.cartas[2] > 0 && freecells.cartas[3] > 0 && freecells.cartas[4] > 0){
        retornarcor(freecells.naipe[1], &corfreecell[1]);
        retornarcor(freecells.naipe[2], &corfreecell[2]);
        retornarcor(freecells.naipe[3], &corfreecell[3]);
        retornarcor(freecells.naipe[4], &corfreecell[4]);
        for (int i = 0; i < 8; i++){
            um.Top((i+1), valor, naipe);
            retornarcor(naipe, &corjogo[1]);
            // verifica se alguma das freecells pode se encaixar no topo da coluna (desculpa a gambiarra)
            if (freecells.cartas[1] != (valor-1) && corfreecell[1] == corjogo[1] && freecells.cartas[2] != (valor-1) && corfreecell[2] == corjogo[1] && 
            freecells.cartas[3] != (valor-1) && corfreecell[3] == corjogo[1] && freecells.cartas[4] != (valor-1) && corfreecell[4] == corjogo[1]){
                possiveljogar = possiveljogar+1;
            }
        }
        //verifica se alguma das freecells pode ser colocada na pilha da saida
        for (int i = 0; i < 4; i++){
            if(freecells.cartas[1] == (freecells.cartas[(i+5)] + 1) && freecells.naipe[1] == freecells.naipe[(i+5)]){
                if(freecells.cartas[2] == (freecells.cartas[(i+5)] + 1) && freecells.naipe[2] == freecells.naipe[(i+5)]){
                    if(freecells.cartas[3] == (freecells.cartas[(i+5)] + 1) && freecells.naipe[3] == freecells.naipe[(i+5)]){
                        if(freecells.cartas[4] == (freecells.cartas[(i+5)] + 1) && freecells.naipe[4] == freecells.naipe[(i+5)]){
                            possiveljogar = possiveljogar + 1;
                        }
                    }
                }
            }
        }
        
    }
    
    int valor2[8]; //vai receber o valor do topo de cada coluna de jogo
    int contador = 0;
    char naipea[8]; ////vai receber o naipe do topo de cada coluna de jogo
    
    for(int i = 0; i < 8; i++){
        um.Top((i+1), valor2[i], naipea[i]);
        retornarcor(naipea[i], &corjogo[i]);
    }

    //percorre a pilha de jogo, verificando se há jogadas possiveis
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            movimentopossivel(valor2[j], valor2[i], naipea[j], naipea[i], &contador);
            if (contador == 8){ // se contador for igual a 8, quer dizer nenuhma coluna de jogo pode receber a carta de topo da coluna i
                for(int k = 0; k < 4; k++){
                    movimentofinalpossivel(valor2[i], freecells.cartas[(k+5)], naipea[i], freecells.naipe[(k+5)], &contador); //verifica se a carta topo da coluna i pode entrar nume pilha final
                }
            if (contador == 12){
                possiveljogar++;
            }
            }
        } 
        contador = 0;
    }

    
    if (possiveljogar == 12){
        *fimdejogo = true;
    }

}

                        ///// FUNÇAO PARA IMPRIMIR AS CARTAS NAS POSIÇÕES INICIAIS ( 8 colunas, 4 com 7 cartas e 4 com 6)
void preencherjogoinicio(){
cout<<"BEM VINDO AO FREECELL"<<endl<<endl;

cout<<"Objetivo do jogo: "<<endl;
cout<<"Mover todas as cartas das pilhas de jogo para as pilhas de saida"<<endl<<endl;
cout<<" Para mover as cartas das pilhas de jogo para as pilhas de saIda, o jogador"<<endl;
cout<<"podera fazer uso de 4 posicoes auxiliares (as free cells) para guardar"<<endl;
cout<<"temporariamente uma carta."<<endl;
cout<<" IMPORTANTE: cada free cell pode ter no maximo"<<endl;
cout<<"uma carta em qualquer momento do jogo e qualquer carta pode ser"<<endl;
cout<<"colocada nessas posicoes."<<endl;
cout<<" O jogador fara quantos movimentos quiser, entre as pilhas que quiser,"<<endl;
cout<<"respeitando as seguintes regras:"<<endl;
cout<<"  > Para uma free cell desocupada: qualquer carta do topo de uma pilha"<<endl;
cout<<"    de jogo;"<<endl;
cout<<"  > Para uma das pilhas de saida: qualquer carta de uma free cell ou do"<<endl;
cout<<"    topo de uma pilha de jogo. Movimentos para uma pilha de saida"<<endl;
cout<<"    devem ser feitos em ordem do menor para o maior, sempre de"<<endl;
cout<<"    mesmo naipe. Assim, temos uma pilha de saida para cada um dos 4"<<endl;
cout<<"    naipes. Ases sempre podem ser movidos para uma pilha de saida"<<endl;
cout<<"    vazia;"<<endl;
cout<<"  > Para o topo de uma pilha de jogo: qualquer carta de uma das free"<<endl;
cout<<"    cells ou do topo de uma outra pilha de jogo. Movimentos para uma"<<endl;
cout<<"    pilha de jogo devem ser feitos em ordem do maior para o menor,"<<endl;
cout<<"    alternando a cor do naipe. Por exemplo: se o topo de uma pilha de"<<endl;
cout<<"    jogo contém um 4 de paus (que é preto), podemos mover para o topo"<<endl;
cout<<"    dessa pilha um 3 de copas ou de ouro (que são vermelhos)."<<endl;
cout<<endl<<"INSTRUCOES DE USO"<<endl;
cout<<" Para mover as cartas, o jogador deve digitar primeiro o indice da pilha"<<endl;
cout<<"onde de encontra a carta que ele quer RETIRAR , seguida de um ESPACO"<<endl;
cout<<"e colocar o indice da pilha que ele quer INSERIR a carta"<<endl;
cout<<" Exemplo: O comando 5 6 move a carta de topo da coluna 5 para o topo"<<endl;
cout<<"da coluna 6"<<endl<<endl;
cout<<"!!! BOA SORTE !!!"<<endl;
cout<<endl;
cout<<"       FREECELLS       "<<"||"<<"    PILHA DE SAIDA   |"<<endl;
cout<<"[ 9 ]"<<" "<<"[10 ]"<<" "<<"[11 ]"<<" "<<"[12 ]"<<"||";
cout<<"        [13]         |"<<endl;
cout<<"     "<<" "<<"     "<<" "<<"     "<<" "<<"     "<<"||";
cout<<"     "<<" "<<"     "<<" "<<"     "<<" "<<"     "<<endl;

cout<<"-----------------------------------------------"<<endl;
cout<<"-----------------------------------------------"<<endl;

cout<<"              PILHAS DE JOGO        "<<endl;
cout<<"[ 1 ]"<<" "<<"[ 2 ]"<<" "<<"[ 3 ]"<<" "<<"[ 4 ]"<<" ";
cout<<"[ 5 ]"<<" "<<"[ 6 ]"<<" "<<"[ 7 ]"<<" "<<"[ 8 ]"<<endl;
cout<<"-----"<<" "<<"-----"<<" "<<"-----"<<" "<<"-----"<<" ";
cout<<"-----"<<" "<<"-----"<<" "<<"-----"<<" "<<"-----"<<endl;

for(int i = 0; i < 7; i++){ //linhas
    for(int j = 0; j < 8; j++){ //colunas
    if(i == 6 && j == 4){
        j = 8;       
    } else {
        um.Read(j, (i+1));
    }}
    cout<<endl;
}
}

// VARIAVEIS DE APOIO ÀS PRÓXIMAS FUNÇÕES
int valorretirar;
char naiperetirar, corfuncao;

                        ///// FUNÇAO PARA RETIRAR CARTAS DO JOGO //////
void funcaoretirar(int retirar, int *valorretirar, char *naiperetirar){ //RECEBE A COLUNA DE ONDE SAIRA A CARTA SEU VALOR E SEU NAIPE

    if(retirar > 0 && retirar < 9){ //se for menor do que 9 retira da pilha de jogo
        um.Top((retirar-1), *valorretirar, *naiperetirar);
        um.Pop((retirar-1));
    } else if (retirar > 8 && retirar < 13){ //se for entre 9 e 12 retiras das freecells
        *valorretirar = freecells.cartas[(retirar-8)];
        *naiperetirar = freecells.naipe[(retirar-8)];
        freecells.cartas[(retirar-8)] = 0; //assim que retira, define o valor para 0, assim não imprimirá nada
        freecells.naipe[(retirar-8)] = ' ';
    }
}

                            /////FUNÇAO PARA COLOCAR CARTAS NO JOGO/////
void funcaocolocar(int retirar, int colocar, int valorcolocar, char naipecolocar){
   
    int valorauxiliar; // auxiliar para o valor da carta (pois vamos precisar resgatar o valor de outra carta)
    char naipeauxiliar, cortopo; // auxiliar para o naipe da carta (pois vamos precisar resgatar o naipe de outra carta), e cor da carta do topo

    retornarcor(naipecolocar, &corfuncao);

    if(valorcolocar == 0){ //se o valor da carta a ser colocada for igual a 0, quer dizer que a pilha está vazia, então retorna um erro
        cout<<"!!! ERRO !!!"<<endl;
        cout<<"Pilha vazia, tente novamente"<<endl;
        return;
        }
      
    ///// COLOCAR CARTAS NA PILHA PRINCIPAL DE JOGO /////
    if(colocar < 9 && colocar > 0){ 
        um.Top((colocar-1), valorauxiliar, naipeauxiliar); // nos da o valor da carta de topo
        retornarcor(naipeauxiliar, &cortopo); 
        if(corfuncao == cortopo){ // verifica se a carta a ser colocada tem a mesma cor da topo
            cout<<"!!! ERRO !!!"<<endl;
            cout<<"Cor do naipe das cartas sao iguais, tente novamente"<<endl;
            if(retirar < 9){ // para desfazer a retirada da carta
                um.Push((retirar-1), valorcolocar, naipecolocar);
                return;
            } else if (retirar < 13){ // para desfazer a retirada da carta
                freecells.cartas[(retirar-8)] = valorcolocar;
                freecells.naipe[(retirar-8)] = naipecolocar;
                return;
            }
        } else if (valorcolocar ==  (valorauxiliar-1) || valorauxiliar == 0){ //veririfca se o valor a ser colocado é igual ao valor da carta do topo -1
            um.Push((colocar-1), valorcolocar, naipecolocar); 
        } else if (retirar < 9){ //se for da pilha de jogo
        
            cout<<"!!! ERRO !!!"<<endl;
            cout<<"Valor da carta a ser colocada, nao e anterior ao valor da carta de topo, tente novamente"<<endl;
            um.Push((retirar-1), valorcolocar, naipecolocar);
            return;
        } else if(retirar < 13){ //se for da freecell
            cout<<"!!! ERRO !!!"<<endl;
            cout<<"Valor da carta a ser colocada, nao e anterior ao valor da carta de topo, tente novamente"<<endl;
            freecells.cartas[(retirar-8)] = valorcolocar;
            freecells.naipe[(retirar-8)] = naipecolocar;
            return;
        }

        ///// COLOCAR CARTAS NAS FREECELLS /////
          
    } else if (colocar > 8 && colocar < 13){ 
        if (freecells.cartas[(colocar-8)] == 0){ //verifica se casa esta disponivel para receber uma nova carta
            if(retirar > 8 && retirar < 13){ //verifica se a pilha de destino também é uma freecell
                cout<<"!!! ERRO !!!"<<endl;
                cout<<"Movimento invalido, nao e possivel mover cartas entre freecells"<<endl;
                freecells.cartas[(retirar-8)] = valorcolocar;
                freecells.naipe[(retirar-8)] = naipecolocar;
                return;
            }
        freecells.cartas[(colocar-8)] = valorcolocar;
        freecells.naipe[(colocar-8)] = naipecolocar;
    } else { //se a casa de destino nao esta disponivel, ele recoloca as cartas em seu devido lugar de acordo com o indice passado antes
        cout<<"!!! ERRO !!!"<<endl;
        cout<<"Casa de FreeCell cheia, tente novamente"<<endl;        
        if(retirar < 9){
            um.Push((retirar-1), valorcolocar, naipecolocar);
            return;
        } else if(retirar < 13){
            freecells.cartas[(retirar-8)] = valorcolocar;
            freecells.naipe[(retirar-8)] = naipecolocar;
        }
        return;
    }
                                   ///// COLOCAR CARTAS NAS PILHAS DE SAIDA /////
    }else if (colocar == 13){
        if(naipecolocar == 'C' && valorcolocar == (freecells.cartas[(colocar-8)]+1)){ //verifica se carta que esta entrando é de naipe igual e é a proxima da que já está lá
            freecells.cartas[(colocar-8)] = valorcolocar;
            freecells.naipe[(colocar-8)] = naipecolocar;
        } else if (naipecolocar == 'O' && valorcolocar == (freecells.cartas[(colocar-7)]+1)){
            freecells.cartas[(colocar-7)] = valorcolocar;
            freecells.naipe[(colocar-7)] = naipecolocar;
        } else if (naipecolocar == 'P' && valorcolocar == (freecells.cartas[(colocar-6)]+1)){
            freecells.cartas[(colocar-6)] = valorcolocar;
            freecells.naipe[(colocar-6)] = naipecolocar;
        } else if (naipecolocar == 'E' && valorcolocar == (freecells.cartas[(colocar-5)]+1)){
            freecells.cartas[(colocar-5)] = valorcolocar;
            freecells.naipe[(colocar-5)] = naipecolocar;
        }else { //se não é imprime um erro
            cout<<"!!! ERRO !!!"<<endl;
            cout<<"Esta carta nao pode entrar na pilha de saida agora, pois nao e a proxima da atual"<<endl;
            if(retirar < 9){ //recoloca as cartas na pilha
                um.Push((retirar-1), valorcolocar, naipecolocar);
            } else if (retirar > 9 && retirar < 13){
                freecells.cartas[(retirar-8)] = valorcolocar;
                freecells.naipe[(retirar-8)] = naipecolocar;
                return;
            }
    } }     
}

// FUNÇÃO QUE LE A STRUCT QUE CONTEM AS FREECELLS E A PILHA DE SAIDA
void lerstruct(int x){
    if (freecells.cartas[x] == 1){
         cout<<"["<<"A"<<" "<<freecells.naipe[x]<<"]"<<" "; // imprime A (as) ao inves de 1
    }else if(freecells.cartas[x] > 1 && freecells.cartas[x] < 9){ // esse if serve para dar um espaço se a carta tem valor menor do que 9
        cout<<"["<<freecells.cartas[x]<<" "<<freecells.naipe[x]<<"]"<<" ";
    } else if(freecells.cartas[x] == 10){ // esse if serve nao dar espaço se a carta for igual a 10
        cout<<"["<<freecells.cartas[x]<<freecells.naipe[x]<<"]"<<" ";
    } else if(freecells.cartas[x] == 11){ // imprime J (valete) ao inves de 1
        cout<<"["<<"J"<<" "<<freecells.naipe[x]<<"]"<<" ";
    } else if (freecells.cartas[x] == 12){ // imprime Q (dama) ao inves de 1
        cout<<"["<<"Q"<<" "<<freecells.naipe[x]<<"]"<<" ";
    } else if (freecells.cartas[x] == 13){ // imprime K (rei) ao inves de 1
        cout<<"["<<"K"<<" "<<freecells.naipe[x]<<"]"<<" ";
    } else {
        cout<<"      ";
    }
}


void preencherjogo(){ //essa aqui imprime toda vez que o jogador realiza uma jogada, atualizando as posições

cout<<"       FREECELLS       "<<"||"<<"     PILHA FINAL     |"<<endl;
cout<<"[ 9 ]"<<" "<<"[10 ]"<<" "<<"[11 ]"<<" "<<"[12 ]"<<"||";
cout<<"         13          |"<<endl;

lerstruct(1);
lerstruct(2);
lerstruct(3);
lerstruct(4);
lerstruct(5);
lerstruct(6);
lerstruct(7);
lerstruct(8);

cout<<endl<<"-----------------------------------------------"<<endl;
cout<<"-----------------------------------------------"<<endl;

cout<<"              PILHAS PRINCIPAIS        "<<endl;
cout<<"[ 1 ]"<<" "<<"[ 2 ]"<<" "<<"[ 3 ]"<<" "<<"[ 4 ]"<<" ";
cout<<"[ 5 ]"<<" "<<"[ 6 ]"<<" "<<"[ 7 ]"<<" "<<"[ 8 ]"<<endl;
cout<<"-----"<<" "<<"-----"<<" "<<"-----"<<" "<<"-----"<<" ";
cout<<"-----"<<" "<<"-----"<<" "<<"-----"<<" "<<"-----"<<endl;

int maior, valorauxiliar;
char naipeauxiliar;
um.MaiorTop(maior);

for(int i = 0; i < maior; i++){ //linhas
    for(int j = 0; j < 8; j++){ //colunas

    um.Retrieve(j, (i+1), valorauxiliar, naipeauxiliar);

    if (valorauxiliar > 14 || valorauxiliar == 0){
        cout<<"      ";
    }else {
        um.Read(j, (i+1));        
    }
    }
    cout<<endl;
}}

void jogoprincipal(){
    
int retirar, colocar, valor;
char naipe;
bool final = false;

while(final == false){
cout<<"Qual movimento deseja fazer? -> ";
cin>>retirar>>colocar;
cout<<endl<<endl;
cout<<"       A JOGADA ESCOLHIDA FOI      "<<endl;
cout<<"Retirar a carta "<<valor<<naipe<<endl;
cout<<"E colocar no topo da coluna "<<colocar<<endl<<endl;
if (retirar < 1 || retirar > 12){ //checa se a posicao de saisa é valida
    cout<<"!!! ERRO !!!"<<endl;
    cout<<"Posicao de saida invalida, tente novamente"<<endl;
    valor = 0; //zera as variaveis para nao ficar armazenada para uma primoa jogada
    naipe = ' ';
 } else {
funcaoretirar(retirar, &valor, &naipe);} 
if (colocar < 1 || colocar > 13){ //checa se a posição de entrada é valida
    cout<<"!!! ERRO !!!"<<endl;
    cout<<"Posicao de entrada invalida, tente novamente"<<endl;
    um.Push((retirar-1), valor, naipe); //recoloca a carta em sua posição antes da retirada
} else {
funcaocolocar(retirar, colocar, valor, naipe);}
cout<<endl;


verificarfimdejogo(&final);

preencherjogo();

    }



}

int main(){

char jogo = 'S';
while (jogo == 'S'){
um.Preencher();

preencherjogoinicio();
jogoprincipal();
cout<<endl<<endl<<"Deseja jogar novamente? ( S / N )"<<endl;
cin>>jogo;}

cout<<endl<<endl;
cout<<"FIM DE JOGO, OBRIGADO POR JOGAR";
um.~Stack();

}