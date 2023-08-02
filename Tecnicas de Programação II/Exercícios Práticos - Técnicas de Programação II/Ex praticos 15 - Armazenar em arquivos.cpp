#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream Alunos("Alunos_CC.txt", ios::out);
    cout << "Digite o numero de matricula, nome e email do aluno:" << endl;

    char resposta;
    int matricula;
    string nome;
    string email;

    while (resposta != 'N'){
        cin >> matricula;
        cin.ignore();
        getline(cin, nome);
        getline(cin, email);

        Alunos << matricula << ", " << nome << ", " << email << endl;

        cout << "Cadastrar outro aluno? S/N: " ;
        cin >> resposta;
    }
}