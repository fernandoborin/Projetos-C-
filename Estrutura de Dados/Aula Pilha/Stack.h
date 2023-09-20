#ifndef STACK_H // Se Stack não estiver definido, definir tudo que está entre #ifndef e #endif
#define STACK_H

const int maxElements = 100;

class Stack{
    public:
    Stack(); // Construtor e destrutor devem ter o nome da classe
    ~Stack();
    void Push(int x);
    void Pop(int &x);
    void Top(int &x);
    bool Full();
    bool Empty();
    int Size();

    private:
    int top;
    int entry[maxElements + 1];
};
#endif