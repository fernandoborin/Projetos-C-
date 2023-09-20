//AUGUSTO HENRIQUE PERNA - 2105087
//FERNANDO PEREZ BORIN - 2125219
//MARCUS PAULO DIB LOPES - 2147404

#ifndef STACK_H
#define STACK_H

const int coluna = 8;
const int linha = 12;
const int MaxElements = 53;

class Stack{
    public:
        Stack();
        ~Stack();
        void Push(int coluna, int x, char y); //colocar elementos
        void Pop(int coluna); //tirar elementos
        void Top(int coluna, int &x, char &y); //retornar a carta do topo de cada coluna
        void MaiorTop(int &x); //usada para retornar qual a coluna com o maior top (qual tem mais cartas)
        bool Full(); //verifica se esta cheia
        bool Empty(); //verifica se esta vazia
        int Size(); //retorna o tamanho da Stack 
        void Read(int coluna, int indice); //usada para ler um carta especifica
        void Preencher(); //preenche toda a stack 
        void Retrieve(int coluna, int linha, int &y, char &n); //retorna uma carta especifica
        void TopColuna(int coluna, int &x); //usada para saber qual o tamanho de top de uma coluna (ultima linha)
        void Cor(int coluna, char &cor); //usada para verificar qual a cor do naipe de uma carta top

    private:
        int top[coluna+1];
        int Entry[linha+1][coluna+1];
        char Letra[linha+1][coluna+1];
        int count;
};

#endif