#include <iostream>
using namespace std;

void persistencia(int num, int numCaracteres){
    int divisor = 1, numPersistencia = 0;
    int vetNum[numCaracteres];

    do {
        for (int i = 0; i < numCaracteres; i++){
        vetNum[i] = num / divisor % 10;

        divisor *= 10;

        }

        cout << num << endl;
        num = 1;

        for (int i = 0; i < numCaracteres; i++){

            num *= vetNum[i];
        }

        numPersistencia++;

    } while (num > 10);
    
    cout << "Persistencia: " << numPersistencia;

    for (int i = 0; i < numCaracteres; i++){
        cout << vetNum[i] << endl;
    }

}

int main(){
    int num, numCaracteres;

    cout << "Digite um numero: ";
    cin >> num;

    cout << "Digite o numero de caracteres do numero: ";
    cin >> numCaracteres;

    persistencia(num, numCaracteres);

}