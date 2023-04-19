#include <iostream>
using namespace std;

struct caixa{
    int num;
    caixa *ptr;
};

typedef struct caixa caixa;

int main(){
    caixa caixa1, caixa2, caixa3;

    caixa1.num = 10;
    caixa2.num = 20;
    caixa3.num = 30;

    caixa1.ptr = &caixa3;
    caixa2.ptr = &caixa1;
    caixa3.ptr = &caixa2;

}