#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream Alunos("Alunos_CC.txt", ios::in);

    int matricula;
    string nome;
    string email;

    while (Alunos >> matricula >> nome >> email){
        cout << matricula << nome << email;

    }

}