#include <iostream>
#include <fstream>
using namespace std;


int main(){
    ofstream dadosAlunos("Alunos.dat", ios::out);
    cout << "Digite os dados do aluno: " << endl;

    char resposta;
    int numero;
    float nota1, nota2;
    string nome, curso;

    while (resposta != 'N'){
        cout << "Numero: ";
        cin >> numero;
        cin.ignore();

        cout << "Nome: ";
        getline(cin, nome);

        cout << "Curso: ";
        getline(cin, curso);

        cout << "Primeira nota: ";
        cin >> nota1;

        cout << "Segunda nota: ";
        cin >> nota2;

        dadosAlunos << numero << ", " << nome << ", " << curso << ", "
                    << nota1 << ", " << nota2 << endl;

        cout << endl << "Cadastrar outro aluno? S/N: ";
        cin >> resposta; 
        cout << endl;
    }

}