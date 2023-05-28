#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct structFlor{
    float comprimentoFlor = 0;
    float larguraFlor = 0;
    string especieFlor;
    bool representanteGrupo = 0;
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
void preencherStructFlores(structFlor*& structFlores, int numLinha, string linhaArquivo, string dadosFlor, string* bufferDadosFlor){
    ifstream irisPetalas("iris_petalas.csv", ios::in);

    structFlores = new structFlor[numLinha]; // Aloca o número de linhas que o arquivo original possui

    int i = 0, j = 0;

    while (getline(irisPetalas, linhaArquivo)){ // Lê a atual linha do arquivo
        stringstream linhaAtual(linhaArquivo);

        while (getline(linhaAtual, dadosFlor, ',')){ // Distribui os dados no buffer 
            bufferDadosFlor[i] = dadosFlor;

            if (bufferDadosFlor[i].back() == '"'){ // Identifica a espécie
                structFlores[j].especieFlor = bufferDadosFlor[i];

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

// Seleciona aleatoriamente k representantes de grupo
void escolherRepresentantes(structFlor*& structFlores, int k, int numLinha){
    srand(time(0));

    for (int i = 0; i < k; i++){
        structFlores[1 + rand() % numLinha].representanteGrupo = 1;
    }

}

int main(){
    int numLinha = 0, k, x;

    string linhaArquivo, dadosFlor;
    string* bufferDadosFlor = new string[3]; 

    structFlor* structFlores = new structFlor[numLinha];

    do {
        cout << "Digite o numero de grupos (k): ";
        cin >> k;

        cout << "Numero de atualizacoes do representante (x): ";
        cin >> x;

        if (k < 1){
            cout << "Ao menos um grupo deve ser digitado!" << endl;
        }

    } while (k < 1);

    contadorNumLinhas(numLinha, linhaArquivo);

    preencherStructFlores(structFlores, numLinha, linhaArquivo, dadosFlor, bufferDadosFlor);

    escolherRepresentantes(structFlores, k, numLinha);

    for (int i = 1; i < numLinha; i++){ // Imprime as structs para testes
        cout << "Flor " << i << " (Linha " << i + 1 << ")" << endl
             << "Comprimento:" << structFlores[i].comprimentoFlor << endl
             << "Largura: " << structFlores[i].larguraFlor << endl
             << "Especie: " << structFlores[i].especieFlor << endl
             << "Representante: " << structFlores[i].representanteGrupo << endl << endl;
    }

    cout << endl;

    for (int i = 0; i <= numLinha; i++){ // Imprime os representantes para testes
        if (structFlores[i].representanteGrupo == 1){
            cout << "A Flor " << i << " (Linha " << i + 1 << ") e representante de grupo!" << endl;
        }
    }

    delete[] bufferDadosFlor;
    delete[] structFlores;
}