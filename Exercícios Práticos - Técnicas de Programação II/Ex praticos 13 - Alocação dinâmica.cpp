#include <iostream>
using namespace std;

struct caixa{
    int num;
    caixa *proximo;
};

typedef struct caixa caixa;

int main(){
    caixa *primeiro;

    primeiro = new caixa;
    primeiro -> num = 1;

    primeiro -> proximo = new caixa;
    primeiro -> proximo -> num = 2;

    primeiro -> proximo -> proximo = new caixa;
    primeiro -> proximo -> proximo -> num = 3;
    primeiro -> proximo -> proximo -> proximo = primeiro;

    // A e B
    cout << primeiro -> num << endl
         << primeiro -> proximo -> num << endl;

    // C
    primeiro -> proximo -> proximo -> proximo -> proximo = new caixa;
    primeiro -> proximo -> proximo -> proximo -> num = 4;
    primeiro -> proximo -> proximo -> proximo -> proximo = primeiro;

    // D
    primeiro = primeiro -> proximo;
    delete primeiro -> proximo -> proximo -> proximo;
    primeiro -> proximo -> proximo -> proximo = primeiro;
    
}