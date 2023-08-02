#include <iostream>
using namespace std;

void trocarValor(int *pA, int *pB, int *pC){
    int *temp = *pA;

    *pA = *pC;
    *pC = *pB;
    *pB = *temp;
}

int main(){
    int A = 5, B = 7, C = 9;

    cout << "Valor de A: " << A << endl 
         << "Valor de B: " << B << endl
         << "Valor de C: " << C << endl << endl;

    trocarValor(&A, &B, &C);

    cout << "Valor de A: " << A << endl 
         << "Valor de B: " << B << endl
         << "Valor de C: " << C << endl;

}