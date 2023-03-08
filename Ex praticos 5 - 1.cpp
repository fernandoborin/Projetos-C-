#include <iostream>
#include <cstdlib>
using namespace std;

struct DadosAluno{
    float media;
    int idade;
};

int main(){

    DadosAluno aluno1;

    cout << "Informe a media do aluno: ";
    cin >> aluno1.media;

    cout << "Informe a idade do aluno: ";
    cin >> aluno1.idade;

    cout << "Media do aluno: " << aluno1.media << endl;
    cout << "Idade do aluno: " << aluno1.idade << endl;

    return 0;
}