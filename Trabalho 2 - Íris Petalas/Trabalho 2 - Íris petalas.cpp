// Fernando Perez Borin - 2125219
// Júlio Fábio dos Santos Melo - 2165170

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

struct structFlor{
    double comprimentoFlor = 0;
    double larguraFlor = 0;
    string especieFlor;
    bool representanteGrupo = 0;
    int numeroGrupo;

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
void escolherRepresentantes(structFlor*& structFlores, int*& vetorFloresRepresentantes, int k, int numLinha){
    srand(time(0));

    vetorFloresRepresentantes = new int[k + 1];
    int representanteSelecionado;

    for (int i = 1; i <= k; i++){
        representanteSelecionado = 1 + rand() % numLinha;

        structFlores[representanteSelecionado].representanteGrupo = 1;

        vetorFloresRepresentantes[i] = representanteSelecionado;

    }

    for (int i = 1; i <= k; i++){
        cout << "Representante na variavel do grupo " << i << ": " << vetorFloresRepresentantes[i] << endl;

    }
}

// Aloca o vetor bidimensional que calcula a distância euclidiana
void alocarVetorDistanciaEuclidiana(double**& vetorDistanciaEuclidiana, int k, int numLinha){
    for (int i = 1; i <= k + 1; i++){
        vetorDistanciaEuclidiana[i] = new double[numLinha];
    }
}

// Calcula a distância euclidiana entre o representante e as outras flores
void distanciaEuclidiana(structFlor*& structFlores, int*& vetorFloresRepresentantes, double**& vetorDistanciaEuclidiana, int k, int numLinha){

    for (int l = 1; l <= k; l++){
        for (int j = 1; j < numLinha; j++){
            vetorDistanciaEuclidiana[l][j] = sqrt(pow(structFlores[vetorFloresRepresentantes[l]].comprimentoFlor - structFlores[j].comprimentoFlor, 2) + 
            pow(structFlores[vetorFloresRepresentantes[l]].larguraFlor - structFlores[j].larguraFlor, 2));

        }
    }
}

// Cria o novo arquivo
void criarNovoArquivo(structFlor*& structFlores, int numLinha){
    ofstream irisPetalas2("iris_petalas_2.csv", ios::out);

    for (int i = 0; i < numLinha; i++){
        irisPetalas2 << structFlores[i].comprimentoFlor << "," << structFlores[i].larguraFlor << "," << structFlores[i].especieFlor << endl;

    }

    irisPetalas2.close();
}

int main(){
    int numLinha = 0, k, x;
    int* vetorFloresRepresentantes = new int[0];

    double** vetorDistanciaEuclidiana;

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

    escolherRepresentantes(structFlores, vetorFloresRepresentantes, k, numLinha);

    alocarVetorDistanciaEuclidiana(vetorDistanciaEuclidiana, k, numLinha);

    distanciaEuclidiana(structFlores, vetorFloresRepresentantes, vetorDistanciaEuclidiana, k, numLinha);

    criarNovoArquivo(structFlores, numLinha);

    //for (int i = 1; i < numLinha; i++){ // Imprime as structs para testes
    //    cout << "Flor " << i << " (Linha " << i + 1 << ")" << endl
    //         << "Comprimento:" << structFlores[i].comprimentoFlor << endl
    //         << "Largura: " << structFlores[i].larguraFlor << endl
    //         << "Especie: " << structFlores[i].especieFlor << endl
    //         << "Representante: " << structFlores[i].representanteGrupo << endl << endl;

    for (int i = 1; i <= k; i++){ // Teste distancia euclidiana
        for (int j = 1; j < numLinha; j++){
            cout << "Distancia Euclidiana entre o representante " << i << " e a flor " << j << ": "
                 << vetorDistanciaEuclidiana[i][j] << endl;

        }
    }

    delete[] vetorFloresRepresentantes;
    delete[] bufferDadosFlor;
    delete[] structFlores;
}