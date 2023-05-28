#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream dadosAluno("Alunos.dat", ios::in);

    int numero;
    float nota1, nota2;
    char nome[30], curso[30];

    while(!dadosAluno.eof()){
        dadosAluno >> numero >> nome >> curso >> nota1 >> nota2;
        cout << "Numero: " << numero << endl
             << "Nome: " << nome << endl
             << "Curso: " << curso << endl
             << "Primeira nota: " << nota1 << endl
             << "Segunda nota: " << nota2 << endl;
    }

}