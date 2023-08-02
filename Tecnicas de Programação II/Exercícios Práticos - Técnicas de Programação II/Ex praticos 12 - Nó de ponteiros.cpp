#include <iostream>
using namespace std;

struct caixa{
    int num;
    caixa *ptr;
};

typedef struct caixa caixa;

int main(){
    caixa caixa1, caixa2, caixa3;
    caixa *ptrCaixa;

    caixa1.num = 10;
    caixa2.num = 20;
    caixa3.num = 30;

    ptrCaixa = &caixa1;
    caixa1.ptr = &caixa2;
    caixa2.ptr = &caixa3;
    caixa3.ptr = &caixa1;

    cout << "Endereco de Caixa1: " << &caixa1 << endl   
         << "Numero guardado em Caixa1: " << caixa1.num << endl
         << "Endereco do ponteiro guardado em Caixa1: " << caixa1.ptr << endl << endl;

    cout << "Endereco de Caixa2: " << &caixa2 << endl   
         << "Numero guardado em Caixa2: " << caixa2.num << endl
         << "Endereco do ponteiro guardado em Caixa2: " << caixa2.ptr << endl << endl;

    cout << "Endereco de Caixa3: " << &caixa3 << endl   
         << "Numero guardado em Caixa3: " << caixa3.num << endl
         << "Endereco do ponteiro guardado em Caixa3: " << caixa3.ptr << endl << endl;

}