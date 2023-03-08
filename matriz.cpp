// Gera uma matriz com valores aleatórios e número de linhas e colunas fornecidos pelo usuário
// e fornece uma série de informações sobre a matriz em questão

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int linhas, colunas, maiorvalor, maiorvalorsecundaria, somadiagonal = 0;
int maiori, maiorj;

//--------------------------------------------------//

int main(){

    srand(time(0));

    cout << "Digite o numero de linhas da matriz: ";
    cin >> linhas;

    cout << "Digite o numero de colunas da matriz: ";
    cin >> colunas;

    int colunadiagonalsecundaria = colunas;

    int matriz[linhas][colunas]; 

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            
            matriz[i][j] = rand()%100; // Gera um valor para a posição determinada

            if (matriz[i][j] < 10){
                cout << " " << setfill('0') << setw(2) << matriz[i][j] << " "; // Por estética, adiciona um 0 na frente
            }                                                                  // caso o valor tenha apenas um digito
            else{
                cout << " " << matriz[i][j] << " ";
            }

            if (j == colunas - 1){
                cout << endl;
            }   

            if (matriz[i][j] > maiorvalor){ // Seleciona o maior valor e sua posição até então
                maiorvalor = matriz[i][j];
                maiori = i, maiorj = j;
            }

            if (linhas == colunas){
                if (i == j)
                {
                    somadiagonal = matriz[i][j] + somadiagonal; // Soma os valores da diagonal principal
                }

                if (matriz[i][colunadiagonalsecundaria] > maiorvalorsecundaria)
                {
                    maiorvalorsecundaria = matriz[i][colunadiagonalsecundaria];
                }

                colunadiagonalsecundaria = colunadiagonalsecundaria - 1;
            }
              
        }
    }

    cout << "O maior valor foi o da matriz [" << maiori << "][" << maiorj << "]: " << maiorvalor << endl;
    
    if (linhas == colunas){
        cout << "O maior valor da matriz secundaria foi: " << maiorvalorsecundaria << endl;
        cout << "A soma dos valores da diagonal principal e: " << somadiagonal;
    }

    return 0;
}