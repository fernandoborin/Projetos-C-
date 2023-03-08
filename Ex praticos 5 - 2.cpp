#include <iostream>
#include <cstdlib>
using namespace std;

int numalunos;

struct DadosAluno{
    float media;
    int idade;
};

int main(){

    cout << "Digite o numero de alunos: ";
    cin >> numalunos;

    DadosAluno alunos[numalunos];

    for (int i = 1; i <= numalunos; i++){

        cout << "Digite a media do aluno " << i << ": ";
        cin >> alunos[i].media;

        cout << "Digite a idade do aluno " << i << ": ";
        cin >> alunos[i].idade;

        cout << endl;

    }

    cout << endl << "Exibindo informacoes: " << endl << endl;

    for (int i = 1; i <= numalunos; i++){

        cout << "Aluno " << i << ": " << endl;
        cout << "Media: " << alunos[i].media << endl;
        cout << "Idade: " << alunos[i].idade << endl << endl;

    }

    return 0;
}