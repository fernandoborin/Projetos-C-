#include <iostream>
#include <string>

using namespace std;

int main(){
    string stringOriginal = "Eu sou aluno da escola X";

    cout << stringOriginal << endl << endl;

    stringOriginal.erase(7, 6); // Apaga as palavras "aluno" e "escola"
    stringOriginal.erase(10, 7);

    stringOriginal.insert(7, "estudante "); // Insere as palavras"estudante" e "universidade"
    stringOriginal.insert(20, "universidade ");

    cout << stringOriginal << endl;

    return 0;
}