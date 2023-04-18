#include <iostream>
using namespace std;

int fatorial(int x){
    if (x == 1){
        return 1;
    } else{
        return x * fatorial(x - 1); // Chama a função fatorial dentro dela mesma até que x seja igual a 1,
    }                               // depois executa a multiplicação dos termos até o resultado final
}

int main(){
    int x = 5;

    cout << fatorial(x);

    return 0;
}
