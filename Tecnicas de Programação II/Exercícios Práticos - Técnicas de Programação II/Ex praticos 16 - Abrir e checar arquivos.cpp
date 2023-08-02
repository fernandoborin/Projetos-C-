// Incompleto

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream dadosAlunos("Alunos.dat", ios::in);
    cout << "Digite os dados dos novos alunos para o arquivo: " << endl;

    int numero;
    float nota1, nota2;
    string nome, curso;

    int numero_r;
    float nota1_r, nota2_r;
    string nome_r, curso_r;
    int flag = 0;

    while (dadosAlunos >> numero_r >> curso_r >> nota1_r >> nota2_r){
        cout << "Numero: ";
        cin >> numero;
        cin.ignore();

        if (numero == numero_r){
            flag = 1;
            
            cout << "Este numero de matricula ja esta cadastrado!";

            dadosAlunos.close();

        } else {
            ofstream dadosAlunos_w("Alunos.dat", ios::app);

            cout << "Nome: ";
            getline(cin, nome);

            cout << "Curso: ";
            getline(cin, curso);

            cout << "Primeira nota: ";
            cin >> nota1;

            cout << "Segunda nota: ";
            cin >> nota2;

            dadosAlunos_w << numero << ", " << nome << ", " << curso << ", "
                    << nota1 << ", " << nota2 << endl;
        }

    }

}