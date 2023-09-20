#ifndef QUEUE_H
#define QUEUE_H

const int maxQueue = 100;

class Queue{
    public:
    Queue();
    ~Queue();
    void Append(int x); // Adição 
    void Serve(int &x); // Remoção
    bool Empty();
    bool Full();
    void Front(int &x);
    void Rear(int &x);
    int Size();
    void Clear();

    private:
    int count;
    int tail;
    int head;
    int Entry[maxQueue + 1];
};
#endif