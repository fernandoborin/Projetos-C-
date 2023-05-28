#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct structFlor{
    float comprimentoFlor = 0;
    float larguraFlor = 0;
    string nomeFlor;
};

// Conta o número de linhas do arquivo
void contadorNumLinhas(int& numLinha, string linhaArquivo){
    ifstream irisPetalas("iris_petalas.csv", ios::in);

    while (getline(irisPetalas, linhaArquivo)){
        numLinha++;
    }

    irisPetalas.close();
}

// Lê o arquivo e preenche a struct com os dados encontrados
void preencherStructFlores(int numLinha, string linhaArquivo, string dadosFlor, string* bufferDadosFlor, structFlor*& structFlores){
    ifstream irisPetalas("iris_petalas.csv", ios::in);

    structFlores = new structFlor[numLinha]; // Aloca o número de linhas que o arquivo original possui

    int i = 0, j = 0;

    while (getline(irisPetalas, linhaArquivo)){ // Lê a atual linha do arquivo
        stringstream linhaAtual(linhaArquivo);

        while (getline(linhaAtual, dadosFlor, ',')){ // Distribui os dados no buffer 
            bufferDadosFlor[i] = dadosFlor;

            if (bufferDadosFlor[i].back() == '"'){ // Identifica o nome da espécie
                structFlores[j].nomeFlor = bufferDadosFlor[i];

            }

            else { // Converte o comprimento e largura para float
                stringstream strParaFloat(bufferDadosFlor[i]);

                if (structFlores[j].comprimentoFlor == 0){
                    strParaFloat >> structFlores[j].comprimentoFlor;
                }

                else {
                    strParaFloat >> structFlores[j].larguraFlor;
                }

            }
            
            i++;
        }

        i = 0;
        j++;

    }

    irisPetalas.close();
}

int main(){
    int numLinha = 0;

    string linhaArquivo, dadosFlor;
    string* bufferDadosFlor = new string[3]; 

    structFlor* structFlores = new structFlor[numLinha];

    contadorNumLinhas(numLinha, linhaArquivo);

    preencherStructFlores(numLinha, linhaArquivo, dadosFlor, bufferDadosFlor, structFlores);

    for (int i = 1; i < numLinha; i++){
        cout << "Flor " << i << endl
             << "Comprimento struct float:" << structFlores[i].comprimentoFlor << endl
             << "Largura struct float: " << structFlores[i].larguraFlor << endl
             << "Nome struct string: " << structFlores[i].nomeFlor << endl << endl;
    }
    delete[] structFlores;
}