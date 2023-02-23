// Joga uma moeda e conta o número de jogadas, o número de caras e coroas

#include <iostream>
#include <cstdlib>
using namespace std;

bool flip(){
    srand(time(0));
    int r = rand() % 2;

    if (r == 0){
        return true; 
    }
    else{
        return false;
    }
    
}

//---------------------------------------------------

int main(){
    char resposta;
    int cara = 0, coroa = 0, tentativa = 0;

    cout << "--------------------" << endl;
    cout << "" << endl;
    cout << "Jogar moeda? S/N: ";
    cin >> resposta;

    while (resposta == 'S'){
        bool resultado = flip();
        if (resultado == true){
            cara++;
            cout << "A moeda deu cara" << endl;
        }
        else {
            coroa++;
            cout << "A moeda deu coroa" << endl;
        }
        cout << "" << endl;
        cout << "--------------------" << endl;
        cout << "" << endl;
        cout << "Numero de jogadas: " << tentativa << endl;
        cout << "Numero total de caras: " << cara << endl;
        cout << "Numero total de coroas: " << coroa << endl;

        cout << "" << endl;
        cout << "Quer continuar? S/N: ";
        cin >> resposta;
    }

    return 0;
}
