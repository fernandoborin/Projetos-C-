#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double comprimento1, comprimento2, largura1, largura2;

    cout << "x1: ";
    cin >> comprimento1 >> largura1;

    cout << "x2: ";
    cin >> comprimento2 >> largura2;

    cout << sqrt(pow(comprimento2 - comprimento1, 2) + 
    pow(largura2 - largura1, 2));
}