#include <iostream>
using namespace std;

int num = 0;

unsigned int iteFatorial(int n){
    int produto = 1;

    for (int i = 0; i <= n; i++){
        produto *= produto * i;
    };

    if (n == 0){
        return 1;
    } else {
        return n * iteFatorial(n - 1);
    };
};

int main(){

    cout << "Digite um numero: ";
    cin >> num;

    iteFatorial(num);

    return 0;
}