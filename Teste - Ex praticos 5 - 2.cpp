// Le a quantidade de alunos, a media e idade de cada um, e usa
// funcoes para criar e exibir as estruturas dentro da array

#include <iostream>
#include <cstdlib>
using namespace std;

int numalunos = 0;

struct DadosAluno{
    float media;
    int idade;
};

DadosAluno alunos[0];

void ler_alunos(int x){

    for (int i = 1; i <= x; i++){

        cout << "Digite a media do aluno " << i << ": ";
        cin >> alunos[i].media;

        cout << "Digite a idade do aluno " << i << ": ";
        cin >> alunos[i].idade;

        cout << endl;

    }
}

void exibir_alunos(int y){

    for (int i = 1; i <= y; i++){

        cout << "Aluno " << i << ": " << endl;
        cout << "Media: " << alunos[i].media << endl;
        cout << "Idade: " << alunos[i].idade << endl << endl;

    }

}

int main(){

    cout << "Digite o numero de alunos: ";
    cin >> numalunos;

    ler_alunos(numalunos);

    cout << endl << "Exibindo informacoes: " << endl << endl;

    exibir_alunos(numalunos);

    return 0;
}