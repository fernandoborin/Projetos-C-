// Fernando Perez Borin - 2125219
// Júlio Fábio dos Santos Melo - 2165170

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

struct structFlor{
    int numeroFlor;
    double comprimentoFlor = 0;
    double larguraFlor = 0;
    double distanciaEuclidiana;
    string especieFlor;
    bool representanteGrupo = 0;
    int numeroGrupo;

};

struct structGrupo{

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
void preencherStructFlores(structFlor*& structFlores, int& numLinha, string linhaArquivo, string dadosFlor, string* bufferDadosFlor){
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

    for (int i = 1; i < numLinha; i++){ // Preenche o numero da flor na struct
        structFlores[i].numeroFlor = i;
    }

    irisPetalas.close();
}

// Seleciona aleatoriamente k representantes de grupo
void escolherRepresentantes(structFlor*& structFlores, int*& vetorRepresentantes, int k, int numLinha){
    srand(time(0));

    vetorRepresentantes = new int[k + 1];
    int representanteSelecionado;

    for (int i = 1; i <= k; i++){
        representanteSelecionado = 1 + rand() % numLinha;

        structFlores[representanteSelecionado].representanteGrupo = 1;

        vetorRepresentantes[i] = representanteSelecionado;

    }

    for (int i = 1; i <= k; i++){
        cout << "Representante do grupo " << i << ": " << vetorRepresentantes[i] << endl;

    }
}

// Aloca o vetor bidimensional que calcula a distância euclidiana
void alocarVetorDistanciaEuclidiana(double**& vetorDistanciaEuclidiana, int k, int numLinha){
    for (int i = 1; i <= k + 1; i++){
        vetorDistanciaEuclidiana[i] = new double[numLinha];
    }
}

// Calcula a distância euclidiana entre o representante e as outras flores
void distanciaEuclidiana(structFlor*& structFlores, int*& vetorRepresentantes, double**& vetorDistanciaEuclidiana, int k, int numLinha){
    for (int l = 1; l <= k; l++){
        for (int j = 1; j < numLinha; j++){
            vetorDistanciaEuclidiana[l][j] = sqrt(pow(structFlores[vetorRepresentantes[l]].comprimentoFlor - structFlores[j].comprimentoFlor, 2) + 
            pow(structFlores[vetorRepresentantes[l]].larguraFlor - structFlores[j].larguraFlor, 2));

        }
    }
}

// Distribui as flores entre os grupos pela primeira vez
void distribuirGrupos(structFlor*& structFlores, double**& vetorDistanciaEuclidiana, int k, int numLinha){
    for (int i = 1; i <= k; i++){
        for (int j = 1; j < numLinha; j++){
            structFlores[j].distanciaEuclidiana = vetorDistanciaEuclidiana[i][j];
            structFlores[j].numeroGrupo = i;
        }
    }

    for (int i = 1; i <= k; i++){
        for (int j = 1; j < numLinha; j++){
            if (structFlores[j].distanciaEuclidiana > vetorDistanciaEuclidiana[i][j]){
                structFlores[j].distanciaEuclidiana = vetorDistanciaEuclidiana[i][j];
                structFlores[j].numeroGrupo = i;
            }
        }
    }
}

// Faz a media dos grupos e estabelece o novo representante
void novoRepresentante(structFlor*& structFlores, double*& vetorMedia, int k, int numLinha){
    vetorMedia = new double[k + 1];
    int numFlores = 0;

    for (int i = 1; i <= k; i++){
        for (int j = 1; j < numLinha; j++){
            if (structFlores[j].numeroGrupo == i){
                vetorMedia[i] = vetorMedia[i] + structFlores[j].distanciaEuclidiana;
                numFlores++;
            }
        }

        vetorMedia[i] = vetorMedia[i] / numFlores;
    }
}

// Cria o novo arquivo
void criarNovoArquivo(structFlor*& structFlores, int numLinha){
    ofstream irisPetalas2("iris_petalas_2.csv", ios::out);

    irisPetalas2 << "Comprimento, Largura, Especie, Grupo" << endl;

    for (int i = 1; i < numLinha; i++){
        irisPetalas2 << structFlores[i].comprimentoFlor << "," << structFlores[i].larguraFlor
                     << "," << structFlores[i].especieFlor << "," << structFlores[i].numeroGrupo << endl;

    }

    irisPetalas2.close();
}

int main(){
    int numLinha = 0, k, x;
    int* vetorRepresentantes = new int[0];

    double** vetorDistanciaEuclidiana;
    double* vetorMedia = new double[0];

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

    escolherRepresentantes(structFlores, vetorRepresentantes, k, numLinha);

    alocarVetorDistanciaEuclidiana(vetorDistanciaEuclidiana, k, numLinha);

    distanciaEuclidiana(structFlores, vetorRepresentantes, vetorDistanciaEuclidiana, k, numLinha);

    distribuirGrupos(structFlores, vetorDistanciaEuclidiana, k, numLinha);

    novoRepresentante(structFlores, vetorMedia, k, numLinha);

    criarNovoArquivo(structFlores, numLinha);

    for (int i = 1; i <= k; i++){ // Deleta os vetores antes de deletar o vetor totalmente 
        for (int j = 0; j < numLinha; j++){
            delete[] vetorDistanciaEuclidiana[j];
        }
    }

    delete[] vetorDistanciaEuclidiana;
    delete[] vetorMedia;
    delete[] vetorRepresentantes;
    delete[] bufferDadosFlor;
    delete[] structFlores;
}