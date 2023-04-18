#include <iostream> 
#include <string>

using namespace std;

int main(){
    string frase;

    cout << "Digite uma frase: ";
    cin >> frase;

    size_t localizacaoTeclado = frase.find("teclado");

    if (localizacaoTeclado == 0){
        cout << "A frase digitada não contem a palavra 'teclado'" << endl;

    } else{
        cout << localizacaoTeclado;
    }

    cout << frase;

    return 0;
}